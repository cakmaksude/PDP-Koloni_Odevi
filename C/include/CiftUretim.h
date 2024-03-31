/** 
* @file ./include/CiftUretim.h
* @description CiftUretim yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 17.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef CIFTURETIM_H
#define CIFTURETIM_H

#include "Uretim.h"

struct CIFTURETIM{
	Uretim super;
	
	
	void (*yoket)(struct CIFTURETIM*);
	
};
typedef struct CIFTURETIM* CiftUretim;

CiftUretim CiftUrtOlustur(int);
int Uret(const Uretim, int);
void CiftUretimYoket(const CiftUretim);

#endif