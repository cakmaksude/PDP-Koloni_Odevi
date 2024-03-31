/** 
* @file ./include/Koloni.h
* @description Koloni yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 19.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef KOLONI_H
#define KOLONI_H

#include "Taktik.h"
#include "CiftTaktik.h"
#include "TekTaktik.h"
#include "CiftUretim.h"
#include "TekUretim.h"
#include "string.h"

struct KOLONI{
	int populasyon;
	char sembol;
	int kazanma;
	int kaybetme;
	int yemek_stogu;
	char durum;   // erzağı veya popülasyonu bitip bitmediğini gösterir
	Taktik taktik;  //TekTaktik->super şeklinde atama yap
	Uretim uretim;   //CiftUretim->super şeklinde atama
	
	void (*SavasKazan)(struct KOLONI*,int);
	int (*SavasKaybet)(struct KOLONI*,int);
	void (*TurSonu)(struct KOLONI*);
	void (*toString)(struct KOLONI*);
	void (*yoket)(struct KOLONI*);

};
typedef struct KOLONI* Koloni;

Koloni KoloniOlustur(int,int, const Taktik, const Uretim);
void SavasKazan(const Koloni, int);
int SavasKaybet(const Koloni , int);
void TurSonu();
void toString(const Koloni);
void KoloniYoket(const Koloni);

#endif