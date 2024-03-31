/** 
* @file ./src/Oyun.cpp
* @description Oyun yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 20.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "Oyun.h"
#include "time.h"

Oyun OyunOlustur(){
	Oyun this;
	this = (Oyun)malloc(sizeof(struct OYUN));
	this->turSayisi=0;
	this->koloniKapasite = 50;  //dizi kapasitesini 50 ile başlat
	this->koloniSayisi = 0;
	this->aktifKoloniSayisi = 0;
	this->koloniler = malloc(sizeof(struct KOLONI)*50);  //50 elemanlık dizi 
	this->oyundakiKoloniler = malloc(sizeof(struct KOLONI)*50);
	this->KoloniEkle = &KoloniEkle;
	this->reserve = &reserve;
    this->yasayanlariBelirle = &yasayanlariBelirle;
    this->Savastir = &Savastir;
	this->toString = &ToString;
	this->Oynat = &Oynat;
	this->yoket = &OyunYoket;
	return this;
}
void KoloniEkle(const Oyun this, const Koloni yeni){
	if(this->koloniSayisi == this->koloniKapasite) this->reserve(this); //dizide yer kalmazsa 
	this->koloniler[this->koloniSayisi] = yeni; 
	this->koloniSayisi ++ ;
}
void reserve(const Oyun this){  //dizide yer kalmazsa iki katı büyüklüğünde yeni diziye verileri aktar
	int yeni_kapasite = this->koloniKapasite * 2;
	Koloni* tmp = malloc(sizeof(struct KOLONI) * yeni_kapasite);
	for(int i=0; i < this->koloniSayisi; i++){
		tmp[i] = this->koloniler[i];
		this->koloniler[i] = NULL;
	}
	free(this->koloniler);
	this->koloniler = tmp;
	this->koloniKapasite = yeni_kapasite;
}
void yasayanlariBelirle(const Oyun this){  //aktif durumdaki kolonileri savaştırmak için belirler
	this->aktifKoloniSayisi = 0;
	for(int i=0 ; i < this->koloniSayisi ; i++){
		if(this->koloniler[i]->durum == 'A'){
			this->oyundakiKoloniler[this->aktifKoloniSayisi] = this->koloniler[i];
			this->aktifKoloniSayisi ++ ;
		}
	}
}
void Savastir(const Oyun this){   //tüm koloniler birbirleriyle savaşır
	this->yasayanlariBelirle(this);
	int degeri;
	int degerj;
	//Taktik yapısından dönen değerlere göre savaşı kimin kazanacağı 
	for(int i = 0; i < this->aktifKoloniSayisi; i++){
		for(int j= i+1; j < this->aktifKoloniSayisi; j++){
			degeri = this->oyundakiKoloniler[i]->taktik->savas(this->oyundakiKoloniler[i]->taktik,this->oyundakiKoloniler[i]->populasyon);
			degerj = this->oyundakiKoloniler[j]->taktik->savas(this->oyundakiKoloniler[j]->taktik,this->oyundakiKoloniler[j]->populasyon);
			if(degeri > degerj) {
				int yuzde = (degeri-degerj)/1000;
				int yemek = this->oyundakiKoloniler[j]->SavasKaybet(this->oyundakiKoloniler[j],yuzde);
				this->oyundakiKoloniler[i]->SavasKazan(this->oyundakiKoloniler[i],yemek);
			}
			else if(degeri < degerj){
				int yuzde = (degerj-degeri)/1000;
				int yemek = this->oyundakiKoloniler[i]->SavasKaybet(this->oyundakiKoloniler[i],yuzde);
				this->oyundakiKoloniler[j]->SavasKazan(this->oyundakiKoloniler[j],yemek);
			}
			else {
				if(this->oyundakiKoloniler[i]->populasyon > this->oyundakiKoloniler[j]->populasyon){
					int yuzde = (degeri-degerj)/1000;
					int yemek = this->oyundakiKoloniler[j]->SavasKaybet(this->oyundakiKoloniler[j],yuzde);
					this->oyundakiKoloniler[i]->SavasKazan(this->oyundakiKoloniler[i],yemek);
				}
				else if(this->oyundakiKoloniler[i]->populasyon < this->oyundakiKoloniler[j]->populasyon){
					int yuzde = (degerj-degeri)/1000;
					int yemek = this->oyundakiKoloniler[i]->SavasKaybet(this->oyundakiKoloniler[i],yuzde);
					this->oyundakiKoloniler[j]->SavasKazan(this->oyundakiKoloniler[j],yemek);
				}
				else {  //hem savaş fonksiyonlarının döndürdüğü değer hem popülasyonları eşitse
					int yuzde = (degeri-degerj)/1000;
					int yemek = this->oyundakiKoloniler[j]->SavasKaybet(this->oyundakiKoloniler[j],yuzde);
					this->oyundakiKoloniler[i]->SavasKazan(this->oyundakiKoloniler[i],yemek);
				}
			}
		}
	}
}
void ToString(const Oyun this){
	printf("Koloni Populasyon\tYemek Stogu\tKazanma Kaybetme\n"); //başlık
	for(int i = 0; i < this->koloniSayisi; i++){  //tüm kolonileri yaz
		this->koloniler[i]->toString(this->koloniler[i]);
	}
}
void Oynat(const Oyun this){  
	do{ //0. turda başlangıç durumlarını yazar
		printf("-------------------------------------------------------------\n");
		printf("Tur Sayisi: %d\n",this->turSayisi);
		this->toString(this); //kolonilerin yazımı
		printf("\n");
		this->turSayisi++;
		this->Savastir(this);  //koloniler birbirleriyle savaşır 
		for(int i = 0; i < this->aktifKoloniSayisi; i++){  //Tur bitiminde kolonilere ilgili işlemleri yaptır
			this->oyundakiKoloniler[i]->TurSonu(this->oyundakiKoloniler[i]);
		}
	}while(this->aktifKoloniSayisi > 1);  //1'den fazla koloni olduğu sürece devam et
	printf("-------------------------------------------------------------\n");	
}
void OyunYoket(const Oyun this){
	if(this == NULL) return;
	for(int i=0; i < this->koloniSayisi ; i++){  //kolonilerin hepsini yok et 
		if(this->koloniler[i] == NULL) continue;
		this->koloniler[i]->yoket(this->koloniler[i]);
	}
	free(this->koloniler);  //dizileri iade et
	free(this->oyundakiKoloniler);
	free(this);   //struct'ı iade et 
}