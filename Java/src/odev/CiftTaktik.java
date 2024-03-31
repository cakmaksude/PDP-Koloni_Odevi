/**
*
* @author Sude Çakmak / sude.cakmak1@ogr.sakarya.edu.tr
* @since 30.05.2023
* <p>
* Taktik için kullanılan sınıflardan biri (1-1000 arası rastgele değer döndürür)
* </p>
*/
package odev;

import java.util.Random;

public class CiftTaktik extends Taktik{    //Taktik soyut sınıfından kalıtım alıyor
	public CiftTaktik(int miktar) {
		super(miktar);   //soyut sınıfın yapıcısını çağırıyor
	}
	
	@Override  //soyut sınıftaki metodun gerçeklemesi
	public int Savas() {      // Koloniler savaşırken rastgele taktik değeri döndürerek savaşı kazandırır/kaybettirir
		Random r = new Random();       //dönecek olan değere rastgelelik katmak için
		int rastgele = this.baslangic_populasyon*2;   //bu metoda özgü bir şey olsun diye
		int rand = r.nextInt(2000);
		rastgele += rand;
		rastgele = (rastgele % 1000) ;  //0'dan 1000'e kadar bir değer (0 dahil 1000 dahil değil)
		if(1 < rastgele && rastgele < 1000) return rastgele;
		else return 4;  //0 ya da 1 gelme ihtimaline karşılık (1-1000 arasında sayı istendiği için 1 ve 1000 dahil değil)
	}
}
