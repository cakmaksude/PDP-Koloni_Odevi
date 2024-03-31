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

public class CiftUretim extends Uretim {   //Uretim abstract sınıfından kalıtım alıyor
	public CiftUretim(int miktar) {
		super(miktar);    //abstract sınıfın yapıcı metodunu çağır
	}
	
	@Override       //soyut sınıftaki metodun gerçeklemesi
	public int Uret() {   //1 ile 10 arası rastgele değer döndürür
		Random r = new Random();        //döndüreceği sayıya rastgelelik katmak için
		int rastgele = this.baslangic_populasyon*4;     //diğer sınıfın metodundan farkı olsun diye
		int rand = r.nextInt(100);
		rastgele += rand;
		rastgele = (rastgele % 10) ;    // 0'dan 10'a kadar değer verir (0 dahil 10 dahil değil)
		if(1 < rastgele && rastgele < 10) return rastgele;
		else return 2;  //0 ya da 1 gelme ihtimaline karşılık (1-10 arasında sayı istendiği için 1 ve 10 dahil değil)
	}
}
