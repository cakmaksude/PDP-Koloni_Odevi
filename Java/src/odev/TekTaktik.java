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

public class TekTaktik extends Taktik {   //Taktik abstract sınıfından kalıtım alıyor
	public TekTaktik(int miktar) {
		super(miktar);   //abstract sınıfın yapıcısını çağırıyor
	}
	
	@Override  //abstract sınıftaki metot override ediliyor
	public int Savas() {    // 1-1000 arasında değer döndüren metot
		Random r = new Random();   //dönen değere rastgelelik katması için
		int rastgele = this.baslangic_populasyon*7;     //bu metoda özgü
		int rand = r.nextInt(2000);
		rastgele += rand;
		rastgele = (rastgele % 1000) ;   // sayının 1000'e modu alınarak 0-1000 arası değer gelmesi sağlanıyor
		if(1 < rastgele && rastgele < 1000) return rastgele;
		else return 7;  //0 ya da 1 gelme ihtimaline karşılık (1-1000 arasında sayı istendiği için 1 ve 1000 dahil değil)
	}
}
