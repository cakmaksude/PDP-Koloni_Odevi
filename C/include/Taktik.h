/** 
* @file ./include/Taktik.h
* @description Taktik yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 18.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef TAKTIK_H
#define TAKTIK_H

#include "Uretim.h"

struct TAKTIK{
	int baslangic_populasyon;
	
	int (*savas)();
	void (*yoket)(struct TAKTIK*);
	void (*kalitimyoket)();  //çocuk yapıyı yok etmek için
};
typedef struct TAKTIK* Taktik;

Taktik new_Taktik(int);
void TaktikYoket(const Taktik);


#endif