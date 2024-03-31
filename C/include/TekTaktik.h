/** 
* @file ./include/TekTaktik.h
* @description TekTaktik yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 18.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef TEKTAKTIK_H
#define TEKTAKTIK_H

#include "Taktik.h"


struct TEKTAKTIK{
	Taktik super; //kalıtım alınan yapı
	
	
	void (*yoket)(struct TEKTAKTIK*);
	
};
typedef struct TEKTAKTIK* TekTaktik;

TekTaktik TekTakOlustur(int);
int savas(const Taktik, int);
void TekTakYoket(const TekTaktik);

#endif