/**
*
* @author Sude Çakmak / sude.cakmak1@ogr.sakarya.edu.tr
* @since 30.05.2023
* <p>
* Taktik türleri için hazırladığımız abstract sınıf
* </p>
*/
package odev;

public abstract class Taktik {
	protected int baslangic_populasyon;         //koloninin oyun başındaki popülasyonu 
	
	public Taktik(int miktar) {
		this.baslangic_populasyon = miktar;
	}
	
	public abstract int Savas();        //asıl sınıflarda gerçeklenmesini beklediğimiz metot
}
