/** 
* @file ./src/TekTaktik.cpp
* @description TekTaktik yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 18.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "TekTaktik.h"

TekTaktik TekTakOlustur(int miktar){  //kurucu fonksiyon
	TekTaktik this;
	this = (TekTaktik)malloc(sizeof(struct TEKTAKTIK));
	this->super = new_Taktik(miktar);  //kalıtım alınan yapı
	this->super->savas = &savas;
	this->super->kalitimyoket = &TekTakYoket;
	this->yoket = &TekTakYoket;
	return this;
}
int savas(const Taktik this, int aktif_populasyon){  // 1 ile 1000 arasında rastgele değer
	int deger = rand() + (this->baslangic_populasyon+aktif_populasyon)*3;
	deger = abs(deger);
	deger = deger % 1000;
	if(deger <= 1 ) return 7;  //0 ya da 1 gelirse diye
	else return deger;

}
void TekTakYoket(const TekTaktik this){  //yıkıcı fonksiyon
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}