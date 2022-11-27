/****************************************************************************
**					          SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				        BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**
**				ÖDEV NUMARASI…...:1
**				ÖĞRENCİ ADI...............:Yahya HALİLOĞLU
**				ÖĞRENCİ NUMARASI.:G201210012
**				DERS GRUBU…………:2C
**
**
****************************************************************************/

#include <iostream>    
#include <locale.h>
#include<time.h>
#include<iomanip>

using  namespace std;

int main()
{
	srand(time(NULL));   //her çalıştırıldığında farklı sonuç verilmesini sağlar
	setlocale(LC_ALL, "Turkish");  //türkçe kütüphane 
	string ilKONTROL = "";   //oluşturulan ili kontrol etmek için tutacak olan değişken 
	string ilRandom[15];



	string tumiller[81] = { "ADANA", "ADIYAMAN","AFYONKARAHİSAR", "AĞRI", "AMASYA", "ANKARA", "ANTALYA","ARTVİN", "AYDIN",
		"BALIKESİR","BİLECİK","BİNGÖL","BİTLİS", "BOLU", "BURDUR", "BURSA","ÇANAKKALE", "ÇANKIRI", "ÇORUM", "DENİZLİ", "DİYARBAKIR",
		"EEDİRNE","ELAZIĞ", "ERZİNCAN", "ERZURUM","ESKİŞEHİR", "GAZİANTEP", "GİRESUN", "GÜMÜŞHANE", "HAKKARİ", "HATAY" ,"ISPARTA",
		"MERSİN", "İSTANBUL", "İZMİR", "KARS", "KASTAMONU", "KAYSERİ", "KIRKLARELİ", "KIRŞEHİR", "KOCAELİ", "KONYA", "KÜTAHYA",
		"MALATYA", "MANİSA","KAHRAMANMARAŞ", "MARDİN", "MUĞLA", "MUŞ", "NEVŞEHİR","NİĞDE", "ORDU", "RİZE", "SAKARYA", "SAMSUN",
		"SİİRT", "SİNOP", "SİVAS", "TEKİRDAĞ", "TOKAT", "TRABZON", "TUNCELİ", "ŞANLIURFA", "UŞAK", "VAN", "YOZGAT", "ZONGULDAK",
		"AKSARAY", "BAYBURT", "KARAMAN", "KIRIKKALE", "BATMAN", "ŞIRNAK", "BARTIN", "ARDAHAN", "IĞRDIR", "YALOVA", "KARABÜK",
		"KİLİS", "OSMANİYE", "DÜZCE" };

	int min = tumiller[0].length();     //int min e tüm iller dizisinin ilk üyesinin harf sayısı aktarıldı.
	for (int i = 0; i < 81; i++)
	{
		if (min > tumiller[i].size())      //for döngüsü en kısa indisli ilin harf sayısını bulur.
			min = tumiller[i].size();
	}
	int max = tumiller[0].size();        //int max a dizinin ilk üyesinin harf sayısı aktarıldı.
	for (int i = 0; i < 81; i++)
	{
		if (max < tumiller[i].size())     //for döngüsü en uzun indisli ilin harf sayısını bulur.
			max = tumiller[i].size();
	}
	cout << "En kısa ilin indisi : " << min << endl; cout << "En uzun ilin indisi : " << max << endl;

	for (int i = min; i <= max; i++)   //her indis sayısı için aramanın baştan başlamasını sağlar
	{
		cout << i << " indisi için...";
		int control = 0;
		for (int j = 0; j < 100002; j++)    //bir indis için maksimum deneme sınırını ayarlar
		{


			int control = 0;
			if (j == 100001)  //maksimum deneme sınırna ulaşılırsa ekrana mesaj yazdırır.
			{
				cout << " bulunamadı.Maksimum deneme sınırna ulaşıldı." << endl;
				control = 1;
				continue;
			}
			//indis sayısı kadar il seçimi yapmaya yarar.
			for (int s = 0; s < i; s++)
			{

				ilRandom[s] = tumiller[rand() % 81];  //rastgele il seçer

			}
			int yeniKISAil = ilRandom[0].length();  //seçilen yeni iller dizisini ilk üyesinin uznuluğu değişene atanır.
			//for döngüsü seçilen yeni iller dizisinin en kısa üyesini bulur.
			for (int k = 0; k < i; k++)
			{
				if (yeniKISAil > ilRandom[k].length())
					yeniKISAil = ilRandom[k].length();
			}
			//yeni dizinin en kısa elemanının uzunluğunu sınır olarak belirler.
			for (int k = 0; k < yeniKISAil; k++)
			{
				ilKONTROL = "";

				for (int t = 0; t < i; t++)
				{
					ilKONTROL += ilRandom[t].at(k);  //yeni dizini elemanlarının harflerini indis indis konrtol değişkenine atar

				}
				//tüm iller dizisinin her elemanın sorgulanmasını sağlar
				for (int x = 0; x < 81; x++)
				{
					//kontol değişkenindeki kelime tüm iller dizesinde eşleşme var mı diye sorgulanır
					if (tumiller[x] == ilKONTROL)
					{
						cout << ilKONTROL << setw(3) << k << " indisinde bulundu" << endl;  //eşleşme var ise ekrana yazdırılır.
						//bulunnan dizinin illerini yazdırır.
						for (int y = 0; y <= i; y++)
							cout << ilRandom[y] << setw(2) << endl;

						control = 1; //eşleşme bulunursa control değişkeni yeni değer alır.
					}

				}
			}
			//değişken eşleşmesi sağlanırsa o sayılı indis için aramanın yapılmasını durdurur.
			if (control == 1)
				break;

		}
	}
}