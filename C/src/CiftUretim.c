/** 
* @file ./src/CiftUretim.cpp
* @description CiftUretim yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 17.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "CiftUretim.h"

CiftUretim CiftUrtOlustur(int miktar){  //kurucu fonksiyon
	CiftUretim this;
	this = (CiftUretim)malloc(sizeof(struct CIFTURETIM));
	this->super = new_Uretim(miktar);  //kalıtım
	this->super->uret = &Uret;
	this->super->kalitimyoket = &CiftUretimYoket;
	this->yoket = &CiftUretimYoket;
	return this;
}
int Uret(const Uretim this, int aktif_populasyon){  //1 ile 10 arasında değer döndüren fonksiyon
	int deger = rand() + (this->baslangic_populasyon + aktif_populasyon)*2;
	deger = abs(deger);
	deger = deger%10;
	if(1<deger<10) return deger;  
	else return 2;  //0 ya da 1 gelme ihtimaline karşılık
}
void CiftUretimYoket(const CiftUretim this){  //yıkıcı fonksiyon
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}