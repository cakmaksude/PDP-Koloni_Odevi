/**
*
* @author Sude Çakmak / sude.cakmak1@ogr.sakarya.edu.tr
* @since 30.05.2023
* <p>
* Üretim türleri için hazırladığımız abstract sınıf
* </p>
*/
package odev;

public abstract class Uretim {
	protected int baslangic_populasyon;   //koloninin oyun öncesindeki popülasyon miktarı
	
	public Uretim(int miktar) {				
		this.baslangic_populasyon = miktar;
	}
	
	public abstract int Uret();				//asıl sınıflarda olmasını beklediğimiz metot
}
