/**
*
* @author Sude Çakmak / sude.cakmak1@ogr.sakarya.edu.tr
* @since 30.05.2023
* <p>
* Oyundaki kolonilerin özellikklerini tutan ve bu özelliklerdeki değişimleri sağlayan sınıf
* </p>
*/
package odev;


public class Koloni {
	private int populasyon;   //koloninin popülasyon sayısı
	private char sembol;     //koloninin sembolü
	private int kazanma;  //kaç kere kazandığı
	private int kaybetme;  //kaç kere kaybettiği
	private int yemek_stogu;    //yemek stoğunun ne kadar olduğu
	private String durum;      //koloninin yaşayıp yaşamadığı
	public Taktik taktik;   //koloninin taktik yapısın
	public Uretim uretim;    //koloninin üretim yapısı
	
	public Koloni(int pop, int sem, Taktik tkt, Uretim urt) {
		this.populasyon = pop;
		this.sembol = (char)sem;    //gelen int değerin Unicode karşılığını atar
		this.durum = "aktif";      //tüm koloniler başlangıçta hayattadır
		this.taktik = tkt;   
		this.uretim = urt;
		this.yemek_stogu = pop*pop;  //başlangıçtaki yemek stoğu
		this.kazanma = 0; 
		this.kaybetme = 0;
	}
	
	public int getPopulasyon() {   //popülasyon değerinin dışarıdan görüntülenebilmesi için
		return populasyon;
	}
	
	public String getDurum() {    //popülasyonun yaşayıp yaşamadığının dışarıdan görülebilmesi için
		return durum;
	}
	
	public void SavasKazan(int miktar) {    //Savaş kazanıldığında yapılması gereken değişiklikler
		this.yemek_stogu += miktar;   //kaybeden koloninin yiyecek stoğunun bir miktarını kendine al
		this.kazanma ++;   //savaş kazanma sayını 1 arttır
	}
	
	public int SavasKaybet(int yuzde) {   //Savaş kaybedildiğinde yapılması gereken değişiklikler
		this.populasyon -= this.populasyon * (yuzde/100);   //dışarıdan gelen yüzdeye göre popülasyon miktarını azalt
		int azalma = this.yemek_stogu * (yuzde/100);   //yüzdeye göre stok miktarını azalt
		this.yemek_stogu -= azalma; 
		this.kaybetme ++;   //kaybetme sayını 1 arttır
		return azalma;   //kaybettiğin stoğu karşı koloniye gönder
	}
	
	public void TurSonu() {    //1 tur bittiğinde yapılacak değişiklikler
		this.yemek_stogu += this.uretim.Uret();   //Yemek stoğu üretimi yap
		this.populasyon += (this.populasyon * 20/100) ;   //Popülasyonunu %20 arttır
		this.yemek_stogu -= this.populasyon*2;   //Yemek stoğunu azalt
		if(this.populasyon <1 || this.yemek_stogu < 1) {   //yemek stoğu tükenen ya da nesli biten kolonilerin yaşamına son ver
			this.durum = "pasif";
		}
	}
	
	public void yazdir() {   //koloniyi uygun formatta ekrana yazdır
		if(this.durum == "aktif") {
			System.out.printf(" %-5c",sembol);
			System.out.printf(" %-16d",populasyon);
			System.out.printf(" %-15d",yemek_stogu);
			System.out.printf(" %-7d",kazanma);
			System.out.printf(" %-8d \n",kaybetme);
		}
		else {   //koloni oyundan çıktıysa
			System.out.print(" "+this.sembol+"\t--\t\t--\t\t--\t--\n");
		}
	}
}
