/**
*
* @author Sude Çakmak / sude.cakmak1@ogr.sakarya.edu.tr
* @since 30.05.2023
* <p>
* Üretim için kullanılan sınıflardan biri (1-10 arası rastgele değer döndürür)
* </p>
*/
package odev;

import java.util.Random;

public class TekUretim extends Uretim {  //Uretim soyut sınıfından kalıtım alıyor
	public TekUretim(int miktar) {
		super(miktar);    //soyut sınıfın yapıcısını çağırıyor
	}
	
	@Override  //soyut sınıftaki metodun gerçeklemesi
	public int Uret() {   //1 ile 10 arasında rastgele değer döndürür
		Random r = new Random();    //döndüreceği değere rastgelelik katmak için
		int rastgele = this.baslangic_populasyon*13;      //bu sınıfa özgü bir tarafı olması için
		int rand = r.nextInt(100);
		rastgele += rand;
		rastgele = (rastgele % 10) ;   // 0 ile 10 arasında sayı gelmesi için (0 dahil 10 dahil değil)
		if(1 < rastgele && rastgele < 10) return rastgele;
		else return 5;  //0 ya da 1 gelme ihtimaline karşılık (1-10 arasında sayı istendiği için 1 ve 10 dahil değil)
	}
}
