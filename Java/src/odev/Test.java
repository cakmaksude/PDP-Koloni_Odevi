/**
*
* @author Sude Çakmak / sude.cakmak1@ogr.sakarya.edu.tr
* @since 31.05.2023
* <p>
* Main metodunun bulunduğu Test sınıfı
* </p>
*/
package odev;

import java.util.Scanner;
import java.util.ArrayList;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.print("Bosluklar ile ayrilmis kodu giriniz: ");   // kullanıcıdan popülasyon değerlerini iste
		ArrayList<Integer> sayilar = new ArrayList<Integer>();    //popülasyon değerlerini tutmak için int dizi
		try (Scanner giris = new Scanner(System.in)) { 
			String metin = giris.nextLine();   //kullanıcının girdiği verileri oku
			String[] dizi = metin.split(" ");  //metni boşluklara göre böl
			for(String str : dizi) {
				sayilar.add(Integer.parseInt(str));   //böldüğün metni inte çevirip int dizisine ata
			}
		} catch (NumberFormatException e) {   //kullanıcı istenilen biçimde veri girmezse hata fırlat
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int sem = 1024;   //Unicodda 1024 değerine karşılık gelen karakterden sembolleri başlat
		int tekcift = 0;   //Taktik ve üretim çeşitlerini belirlemek için
		CiftTaktik ct;  
		CiftUretim cu;
		TekTaktik tt;
		TekUretim tu;
		Oyun oyna = new Oyun();   //Oyuna başlamak için
		for(int pop:sayilar) {   //sayilar dizisini dolaş
			if(tekcift % 2 == 0) {   //tekçift değeri çift ise Uretim ve Taktikte çift için olanları kullan
				cu = new CiftUretim(pop);  //yeni üretim 
				ct = new CiftTaktik(pop);   //yeni taktik
				Koloni kln = new Koloni(pop,sem,ct,cu);   //yeni koloni
				oyna.KoloniEkle(kln);   //oluşturulan koloniyi oyuna ekle
			}
			else {   //tek değerler için
				tu = new TekUretim(pop);   //yeni üretim
				tt = new TekTaktik(pop);   //yeni taktik
				Koloni kln = new Koloni(pop,sem,tt,tu);    //yeni koloni
				oyna.KoloniEkle(kln);   //oluşturulan koloniyi oyuna ekle
			}
			sem++; //sembolde bir sonraki karaktere geç
			tekcift++; //tek çift durumunu değiştir
		}
		oyna.Oynat();  //oyunu oynat
	}

}
