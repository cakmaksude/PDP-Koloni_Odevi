/** 
* @file ./src/Koloni.cpp
* @description Koloni yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 19.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "Koloni.h"

int Uzunluk(int deger){   //Ekrana yazarken çıkan hizalama problemleri için
	char str[30];
	sprintf(str,"%d",deger);
	int uzunluk = strlen(str);
	return uzunluk;
}


Koloni KoloniOlustur(int pop, int sem, const Taktik tkt, const Uretim urt){
	Koloni this;
	this = (Koloni)malloc(sizeof(struct KOLONI));
	this->populasyon = pop;
	this->sembol = sem;   //ascii kodu verilen karekteri atama
	this->durum = 'A';  //başlangıçta aktif durumda
	this->taktik = tkt;
	this->uretim = urt;
	this->yemek_stogu = pow(pop,2);  //başlangıçtaki yemek stoğu popülasyonun karesi
	this->kazanma = 0;
	this->kaybetme = 0;
	this->SavasKazan = &SavasKazan;
	this->SavasKaybet = &SavasKaybet;
	this->TurSonu = &TurSonu;
	this->toString = &toString;
	this->yoket = &KoloniYoket;
	return this;
}
//Savaş kazanma durumunda kaybeden taraftan gelen yemek stoğunu ekle 
void SavasKazan(const Koloni this, int yemek){  
	this->yemek_stogu += yemek;
	this->kazanma ++;
}

//Savaş kaybetme durumunda karşıya yemek stoğu gönder ve popülasyonunun azalt
int SavasKaybet(const Koloni this,int yuzde){
	this->populasyon = this->populasyon - (this->populasyon * (yuzde / 100));
	int azalma = this->yemek_stogu * (yuzde / 100);
	this->yemek_stogu = this->yemek_stogu - azalma ;
	this->kaybetme ++;
	return azalma;
}

//Tur bitince istenen işlemleri gerçekleştir
void TurSonu(const Koloni this){
	this->yemek_stogu += this->uretim->uret(this->uretim,this->populasyon);  
	this->populasyon += (this->populasyon * 20 / 100);
	this->yemek_stogu -= (this->populasyon * 2);
	if(this->populasyon < 1 || this->yemek_stogu < 1) {  //yemek ya da popülasyon bittiyse oyundan çıkar
		this->durum = 'P';  //pasif duruma getirme
		return ;
	}
}  

//Koloni bilgilerini ekrana yazdır
void toString(const Koloni this){
	if(this->durum == 'A'){  //aktif durumdaysa
		//hizalamaları doğru yapmak için uzunluklara göre yaz 
		int uzunluk = Uzunluk(this->yemek_stogu);
		int popuzunluk = Uzunluk(this->populasyon);
		if(uzunluk >5 && popuzunluk <= 5) 
			printf(" %c \t %d \t\t %d \t %d \t %d \n", this->sembol, this->populasyon, this->yemek_stogu, this->kazanma, this->kaybetme);
		else if(uzunluk > 5 && popuzunluk > 5)
			printf(" %c \t %d \t %d \t %d \t %d \n", this->sembol, this->populasyon, this->yemek_stogu, this->kazanma, this->kaybetme);
		else if(popuzunluk > 5 && uzunluk <= 5)
			printf(" %c \t %d \t %d \t\t %d \t %d \n", this->sembol, this->populasyon, this->yemek_stogu, this->kazanma, this->kaybetme);
		else
			printf(" %c \t %d \t\t %d \t\t %d \t %d \n", this->sembol, this->populasyon, this->yemek_stogu, this->kazanma, this->kaybetme);
	}
	else if(this->durum == 'P'){ //pasif durumdaysa
		printf(" %c \t -- \t\t -- \t\t -- \t -- \n", this->sembol);
	}
}
void KoloniYoket(const Koloni this){  
	if(this == NULL) return;
	if(this->uretim != NULL) 
		this->uretim->kalitimyoket;  //kalitim alan yapıyla beraber yok et
	if(this->taktik != NULL){
		this->taktik->kalitimyoket;   //kalitim alan yapıyla beraber yok et
	}
	free(this);
}
