/** 
* @file ./src/TekUretim.cpp
* @description TekUretim yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 17.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "TekUretim.h"

TekUretim TekUrtOlustur(int miktar){  //kurucu fonksiyon
	TekUretim this;
	this = (TekUretim)malloc(sizeof(struct TEKURETIM));
	this->super = new_Uretim(miktar);  //kalıtım alınan yapıyı oluştur
	this->super->uret = &uret;
	this->super->kalitimyoket = &TekUretimYoket;
	this->yoket = &TekUretimYoket;
	return this;
}
int uret(const Uretim this, int aktif_populasyon){  //1 ile 10 arasında değer döndüren fonksiyon
	int deger = rand() + (this->baslangic_populasyon + aktif_populasyon)*3;
	deger = abs(deger);
	deger = deger%10;
	if(1<deger<10) return deger;
	else return 3;  //0 ya da 1 değeri gelme ihtimaline karşılık
}
void TekUretimYoket(const TekUretim this){  //yıkıcı fonksiyon
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}