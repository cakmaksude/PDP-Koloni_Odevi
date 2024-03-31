/** 
* @file ./src/Uretim.cpp
* @description Uretim yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 17.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "Uretim.h"

Uretim new_Uretim(int miktar){  //Uretim yapısı oluşturuluyor
	Uretim this;
	this = (Uretim)malloc(sizeof(struct URETIM));
	this->baslangic_populasyon = miktar;
	this->yoket = &UretimYoket;
	return this;
}
void UretimYoket(const Uretim this){   //Yıkıcı fonksiyon
	if(this == NULL) return;
	free(this);
}