/** 
* @file ./include/Uretim.h
* @description Uretim yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 17.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef URETIM_H
#define URETIM_H

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"


struct URETIM{
	int baslangic_populasyon;

	
	int (*uret)();
	void (*yoket)(struct URETIM*);
	void (*kalitimyoket)(); //koloni yapısındayken çocuk sınıfları da yoketmek için
};
typedef struct URETIM* Uretim;

Uretim new_Uretim(int);
void UretimYoket(const Uretim);



#endif