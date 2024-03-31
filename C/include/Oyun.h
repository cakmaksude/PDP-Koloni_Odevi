/** 
* @file ./include/Oyun.h
* @description Oyun yapısının başlık dosyası
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 20.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef OYUN_H
#define OYUN_H

#include "Koloni.h"

struct OYUN{
	Koloni* koloniler ;  //tüm kolonileri tutan dizi
	Koloni* oyundakiKoloniler ;  //aktif olarak savaşan kolonileri tutan dizi
	int turSayisi;
	int koloniKapasite;   //dizi kapasitesi
	int koloniSayisi;   //toplam koloni sayısı
	int aktifKoloniSayisi;  //aktif savaşan koloni sayısı
	
	void (*KoloniEkle)(struct OYUN*, struct KOLONI*);
	void (*reserve)(struct OYUN*);
    void (*yasayanlariBelirle)(struct OYUN*);
    void (*Savastir)(struct OYUN*);
	void (*toString)(struct OYUN*);
	void (*Oynat)(struct OYUN*);
	void (*yoket)(struct OYUN*);
	
};
typedef struct OYUN* Oyun;

Oyun OyunOlustur();
void KoloniEkle(const Oyun, const Koloni);
void reserve(const Oyun);
void yasayanlariBelirle(const Oyun);
void Savastir(const Oyun);
void ToString(const Oyun);
void Oynat(const Oyun);
void OyunYoket(const Oyun);


#endif