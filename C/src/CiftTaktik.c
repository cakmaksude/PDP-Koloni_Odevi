/** 
* @file ./src/CiftTaktik.cpp
* @description CiftTaktik yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 18.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "CiftTaktik.h"

CiftTaktik CiftTakOlustur(int miktar){  //kurucu fonksiyon
	CiftTaktik this;
	this = (CiftTaktik)malloc(sizeof(struct CIFTTAKTIK));
	this->super = new_Taktik(miktar);   //kalıtım alınan yapı
	this->super->savas = &Savas;
	this->super->kalitimyoket = &CiftTakYoket; 
	this->yoket = &CiftTakYoket;
	return this;
}
int Savas(const Taktik this, int aktif_populasyon){  // 1 ile 1000 arası değer döndür
	int deger = rand() + (this->baslangic_populasyon+aktif_populasyon)*2;
	deger = abs(deger);
	deger = deger%1000;
		if (deger <= 1) return 2;  //0 ya da 1 ihtimaline karşı
		else return deger;
}
void CiftTakYoket(const CiftTaktik this){  //yıkıcı fonksiyon
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}