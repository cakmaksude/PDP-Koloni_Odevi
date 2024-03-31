/** 
* @file ./src/Test.cpp
* @description Girilen popülasyon değerleriyle kolonileri çarpıştıran program
* @course 1. öğretim B grubu
* @assignment 2. Ödev
* @date 21.05.2023
* @author Sude Çakmak sude.cakmak1@ogr.sakarya.edu.tr
*/

#include "Oyun.h"
#include "time.h"


int main(){
	srand(time(NULL));  //kaynak dosyalarındaki rand fonksiyonlarının her seferinde farklı değer üretmesi için 
	printf("Bosluklar ile ayrilmis kodu giriniz: ");
	char sayilar[10000];   //kullanıcıdan girilen değeri okumak için 
	gets(sayilar);
	char* token = strtok(sayilar, " ");  //girilen char dizisini boşluklara göre ayırmak için 
	Oyun o = OyunOlustur();
	int sem = 128;   //koloni sembollerini ascii kodunda 128'e karşılık gelen karakterden başlattım
	int sayi = 0;    //tek sayıya göre mi çift sayıya göre mi taktik ve üretim yapısı alacağını belirlemek için 
	CiftTaktik ct ;
	CiftUretim cu;
	TekUretim tu;
	TekTaktik tt;
	int pop;   
	while( token != NULL){
		sscanf(token, "%d" , &pop);  //okunan değeri int olarak pop değişkenine yaz
		if(sayi%2 == 0){   //çift indisli koloniler için 
			cu = CiftUrtOlustur(pop);
			ct = CiftTakOlustur(pop);
			Koloni k = KoloniOlustur(pop,sem,ct->super,cu->super);
			o->KoloniEkle(o,k);
		}
		else {  //tek indisli koloniler için 
			tu= TekUrtOlustur(pop);
			tt = TekTakOlustur(pop);
			Koloni k = KoloniOlustur(pop,sem,tt->super,tu->super);
			o->KoloniEkle(o,k);
		}
		sem++;  //sembolde bir sonraki karaktere geç
		if(sem == 255) sem = 65; //karakter tablosundan çıkarsa 'A' ya dönmesi için
		sayi++;
		token = strtok(NULL, " "); 
	}
	o->Oynat(o);  //Oyunu başlat 
	o->yoket;   //Oyun sonlandır hafızadan aldığın yerleri iade et
	
	
	return 0;
}