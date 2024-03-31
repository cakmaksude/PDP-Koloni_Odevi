/** 
* @file ./include/CiftTaktik.h
* @description CiftTaktik yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 18.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef CIFTTAKTIK_H
#define CIFTTAKTIK_H

#include "Taktik.h"

struct CIFTTAKTIK{
	Taktik super;  //kalıtım alınan yapı
	
	
	void (*yoket)(struct CIFTTAKTIK*);
	
};
typedef struct CIFTTAKTIK* CiftTaktik;

CiftTaktik CiftTakOlustur(int);
int Savas(const Taktik, int);
void CiftTakYoket(const CiftTaktik);

#endif