/**
*
* @author Sude Çakmak / sude.cakmak1@ogr.sakarya.edu.tr
* @since 31.05.2023
* <p>
* Oyun ile ilgili işlemlerin yapıldığı sınıf
* </p>
*/
package odev;

import java.util.ArrayList;
import java.util.Random;

public class Oyun {
	private ArrayList<Koloni> koloniler = new ArrayList<Koloni>();  //oyundaki tüm koloniler 
	private ArrayList<Koloni> oyundakiKoloniler;   //tur sonunda oyuna devam eden koloniler
	private int turSayisi;
	
	
	public Oyun(){
		this.turSayisi = 0;
	}
	
	public void KoloniEkle(Koloni kln) {    //oyuna dışarıdan koloni ekle
		this.koloniler.add(kln);
	}
	
	private void yasayanlariBelirle() {    //oyuna devam eden kolonileri belirle
		this.oyundakiKoloniler = new ArrayList<Koloni>();   //her turda yeni bir liste oluştuması için
		for(Koloni kln:this.koloniler)
			if(kln.getDurum() == "aktif")    //durumu aktif olan kolonileri listeye ekle
				oyundakiKoloniler.add(kln);
		
	}
	
	private void Savastir() {   //tüm kolonileri birbirleriyle savaştır
		yasayanlariBelirle();   //savaşa başlamadan önce oyundaki kolonileri belirle
		int degeri;  
		int degerj;
		
		for(int i =0; i< oyundakiKoloniler.size(); i++) {
			for(int j = i+1; j < oyundakiKoloniler.size(); j++) {
				degeri = oyundakiKoloniler.get(i).taktik.Savas();    //seçtiğimiz ilk koloninin taktik değeri
				degerj = oyundakiKoloniler.get(j).taktik.Savas();   //seçtiğimiz ikinci koloninin taktik değeri
				if(degeri > degerj) {   //ilk taktik değeri ikinci taktik değerinden büyükse
					int yuzde = (degeri-degerj)/1000;    //taktik değerleri arasındaki fark yüzdeyi belirler
					int yemek = oyundakiKoloniler.get(j).SavasKaybet(yuzde);    //ikinci koloni kaybetti, yemek stoğunu diğer koloniye verecek
					oyundakiKoloniler.get(i).SavasKazan(yemek);   //ilk koloni kazandı
				}
				else if(degeri < degerj) {   //ikinci taktik değeri ilk taktik değerinden büyükse
					int yuzde = (degerj-degeri)/1000;
					int yemek = oyundakiKoloniler.get(i).SavasKaybet(yuzde);
					oyundakiKoloniler.get(j).SavasKazan(yemek);
				}
				else {    // iki değer birbirine eşitse popülasyonlara bakılır
					if(oyundakiKoloniler.get(i).getPopulasyon() > oyundakiKoloniler.get(j).getPopulasyon()) {  
						int yuzde = 0;  //taktik değerleri eşit olduğu için
						int yemek = oyundakiKoloniler.get(j).SavasKaybet(yuzde);
						oyundakiKoloniler.get(i).SavasKazan(yemek);
					}
					else if (oyundakiKoloniler.get(i).getPopulasyon() < oyundakiKoloniler.get(j).getPopulasyon()) {
						int yuzde = 0;   //taktik değerleri eşit olduğu için
						int yemek = oyundakiKoloniler.get(i).SavasKaybet(yuzde);
						oyundakiKoloniler.get(j).SavasKazan(yemek);
					}
					else {  //popülasyonlar da eşitse rastgele biri kazanır
						Random r = new Random();
						int rand = r.nextInt(2);  // 0 ya da 1 rastgele sayısını üret
						int yuzde = 0;   //taktik değerleri eşit olduğu için
						if(rand == 1) {   //rastgele 1 denk geldiyse ilk koloni kazansın
							int yemek = oyundakiKoloniler.get(i).SavasKaybet(yuzde);
							oyundakiKoloniler.get(j).SavasKazan(yemek);
						}
						else {   //rastgele 0 geldiyse ikinci koloni kazansın
							int yemek = oyundakiKoloniler.get(j).SavasKaybet(yuzde);
							oyundakiKoloniler.get(i).SavasKazan(yemek);
						}
					}
				}
			}
		}
	}
	
	public void Oynat() {   
		do {
			System.out.println("------------------------------------------------------------------------------------");
			System.out.println("Tur Sayisi: " + turSayisi);   //bulunduğumuz turun sayısı
			this.yazdir();   //kolonileri yazdır
			turSayisi ++ ;   //tur sayısını arttır
			Savastir();   //savaş işlemleri
			for(Koloni kln:oyundakiKoloniler)
				kln.TurSonu();   //yaşayan kolonilere tur sonu işlemlerini yaptır
		}while(oyundakiKoloniler.size()>1);    //oyunda 1'den fazla koloni olduğu sürece oyuna devam et
		System.out.println("------------------------------------------------------------------------------------");
		
	}
	
	public void yazdir() {     //Uygun formatta kolonilerin yazımı
		String ekran = "Koloni Populasyon\tYemek Stogu\tKazanma Kaybetme\n";
		System.out.print(ekran);
		for(Koloni kln:koloniler)
			kln.yazdir();
		System.out.println();
	}
}
