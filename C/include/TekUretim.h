/** 
* @file ./include/TekUretim.h
* @description TekUretim yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 17.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef TEKURETIM_H
#define TEKURETIM_H

#include "Uretim.h"

struct TEKURETIM{
	Uretim super;
	
	
	void (*yoket)(struct TEKURETIM*);
	
};
typedef struct TEKURETIM* TekUretim;

TekUretim TekUrtOlustur(int);
int uret(const Uretim, int);
void TekUretimYoket(const TekUretim);

#endif