/** 
* @file ./src/Taktik.cpp
* @description Taktik yapısının kaynak dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 18.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "Taktik.h"

Taktik new_Taktik(int miktar){  //kurucu fonksiyon
	Taktik this;
	this = (Taktik)malloc(sizeof(struct TAKTIK));
	this->baslangic_populasyon = miktar;
	this->yoket = &TaktikYoket;
	return this;
}
void TaktikYoket(const Taktik this){  //yıkıcı fonksiyon
	if(this == NULL) return;
	free(this);
}