#include<iostream>
#include<iomanip>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string w, Uretici, EkranCiktisi, UrunKodu, TeminSuresi, UretimTarihiGun, UretimTarihiAy, UretimTarihiYıl, Fiyat, KDVoranı, StokAdedi, KodKontrol, EkranCiktisiS, geciciKod, geciciKod2, geciciFirma,
		Gecici, firmaKodu, firmaAdi, firmaYetkili, kodKontrol, ekranCiktisi, firmaAdres, musteriSiparis, urunSiparis, siparisAdet, r = "123asd", siparisKodu, siparisKontrol, SiparisKontrol;
	char cevap = '1';
	long firmaTelefon;
	int control = 1, ctr1 = 0, ctr2 = 0, paha, miktar, siparisTutari, gecStok, gecstok2, gecstok3;

	do//kullanıcı cikis diyene kadar sistemin calismasi icin
	{

		/////////   MENU    /////////
		{
			cout << "_________________________" << "Yahya.lom magaza uygulamasi" << "_________________________" << endl;
			cout << '\t' << '\t' << "///////////    Urun islemleri blogu   //////////" << endl;
			cout << '\t' << "Urun ekleme icin        ==> 1 \n" << '\t' << "Urun arama icin         ==> 2 \n " << '\t' << "Urun listeleme icin     ==> 3 \n "
				<< '\t' << "Urun duzeltme icin      ==> 4 \n " << '\t' << "Urun silme icin         ==> 5\n" << endl << endl << endl;
			cout << '\t' << '\t' << "/////////// Musteri islemleri blogu //////////" << endl;
			cout << '\t' << "Musteri ekleme icin     ==> 6 \n" << '\t' << "Musteri arama icin      ==> 7 \n " << '\t' << "Musteri duzeltme icin   ==> 8 \n "
				<< '\t' << "Musteri silme icin      ==> 9 \n " << endl << endl << endl;
			cout << '\t' << '\t' << "/////////// Siparis islemleri blogu //////////" << endl;
			cout << '\t' << "Siparis olusturmak icin ==> 10 \n" << '\t' << "Siparis arama icin      ==> 11 \n " << '\t' << "Siparis silme icin      ==> 12 \n "
				<< '\t' << "Siparis duzeltme icin   ==> 13 \n " << '\t' << "Siparis raporlama icin  ==> 14" << endl << endl << endl;
			cout << '\t' << "Cikis icin ---> x" << endl << endl;
			cout << '\t' << "Yapmak istediginiz islemin numarasini tuslayiniz  ==> ";

		}
		/////////   MENU    /////////          ekran kontrolü


		////// SECIM KONTROL //////
		do
		{
			cin >> w;
			if (w == "1" || w == "2" || w == "3" || w == "4" || w == "5" || w == "6" || w == "7" || w == "8" || w == "9" || w == "10" || w == "11" || w == "12" || w == "13" || w == "14" || w == "x")
				cout << setw(10) << endl;
			else
				cout << '\t' << "Hatali veya eksik tuslama yaptiniz ! " << endl;

		} while (!(w == "1" || w == "2" || w == "3" || w == "4" || w == "5" || w == "6" || w == "7" || w == "8" || w == "9" || w == "10" || w == "11" || w == "12" || w == "13" || w == "14" || w == "x"));
		////// SECIM KONTROL //////


		///// Urun Ekleme Menusu /////              //ekran kontrolü
		if (w == "1")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Urun ekleme modulu acildi..." << endl;

			///// Urun Bilgilerini Dosyaya Yazma Dongusu/////
			ofstream DosyaYaz;

			do//kullanıcı pespese urun ekleyebilsin diye
			{
				DosyaYaz.open("Urun.txt", ios::app);  //dosya yazmak icin acildi 
				cout << '\t' << " \n Urun Kodu           : "; cin >> UrunKodu;
				geciciKod = UrunKodu;
				ifstream DosyaOku("Urun.txt", ios::in);  // dosya okunmak icin acildi
				while (!DosyaOku.eof())  //urun kodu taramasii yapacak urun dosyasinin tamami bitene kadar decam eder
				{
					DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >> UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >> KDVoranı >> StokAdedi;
					if (UrunKodu == KodKontrol) //urun kodu varsa eklenmesine izin vermez
					{
						cout << " Bu urun zaten ekli" << endl;
						DosyaOku.close();
						break;
					}
					else if (DosyaOku.eof())  //urun kodu eslesmesi olmaz ise diger bilgiler eklensin diye
					{
						UrunKodu = geciciKod;
						cout << '\t' << " \n Uretici             : "; cin >> Uretici;
						cout << '\t' << " \n Temin Suresi (gun)  : "; cin >> TeminSuresi;
						cout << '\t' << " \n Uretim Tarihi(gun)  : "; cin >> UretimTarihiGun;
						cout << '\t' << " \n Uretim Tarihi(ay)   : "; cin >> UretimTarihiAy;
						cout << '\t' << " \n Uretim Tarihi(yil)  : "; cin >> UretimTarihiYıl;
						cout << '\t' << " \n Fiyat               : "; cin >> Fiyat;
						cout << '\t' << " \n KDV orani           : "; cin >> KDVoranı;
						cout << '\t' << " \n Stok Adedi          : "; cin >> StokAdedi;
						DosyaYaz << UrunKodu << "\t" << Uretici << "\t" << TeminSuresi << "\t" <<
							UretimTarihiGun << "\t" << UretimTarihiAy << "\t" << UretimTarihiYıl << "\t" << Fiyat << "\t" <<
							KDVoranı << "\t" << StokAdedi << "\n";
						DosyaYaz.close();
						DosyaOku.close();
					}
				}

				cout << "\n Baska kayit yapacak misin?(e/h) "; cin >> cevap;

			} while (!(cevap == 'h'));

			cout << endl << endl;
		}
		///// Urun Ekleme Menusu /////


		///// Urun Arama Menusu /////               ekran kontrolü
		if (w == "2")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Urun arama modulu acildi..." << endl;
			cout << "Aramak istediginiz urun kodunu giriniz : "; cin >> KodKontrol;
			ifstream DosyaOku("Urun.txt", ios::in);
			while (!DosyaOku.eof()) //dosya sonu gelene kadar verileri sira sira okumasi icin 
			{
				DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >> UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >> KDVoranı >> StokAdedi;
				if (UrunKodu == KodKontrol) //aranan urun kodu var ise dongu calisir ve urun bilgileri yazdirilir
				{
					cout << "Urun bulundu" << endl;
					cout << '\t' << " \n Uretici             : " << Uretici;
					cout << '\t' << " \n Temin Suresi (gun)  : " << TeminSuresi;
					cout << '\t' << " \n Uretim Tarihi(gun)  : " << UretimTarihiGun;
					cout << '\t' << " \n Uretim Tarihi(ay)   : " << UretimTarihiAy;
					cout << '\t' << " \n Uretim Tarihi(yıl)  : " << UretimTarihiYıl;
					cout << '\t' << " \n Fiyat               : " << Fiyat;
					cout << '\t' << " \n KDV orani           : " << KDVoranı;
					cout << '\t' << " \n Stok Adedi          : " << StokAdedi << endl << endl;

					DosyaOku.close();
					break;
				}
				else if (DosyaOku.eof()) //aranan urun kodu yoksa calisip uyarir.
				{
					cout << "Hatali veya eksik urun kodu..." << endl;
					DosyaOku.close();
				}
			}
			cout << endl << endl;
		}
		///// Urun Arama Menusu ///// 


		////// Urun Listeleme Menusu///////              ekran konrtolü  
		if (w == "3")
		{
			cout << "*******************************************************************************" << endl;
			cout << '\t' << "Urun listeleme modulu acildi..." << endl;
			//	cout << "Listelemek istediginiz urun kodunu giriniz : "; cin >> KodKontrol;
			ifstream DosyaOku("Urun.txt", ios::in);
			cout << "        Kodu  Uretici  Temin   U.Gun   U.Ay    U.Yil   Fiyat    KDV    Stok" << endl; //ekran duzeni
			while (!DosyaOku.eof())  // dosya sonu gelene kadar songu calissin diye
			{
				getline(DosyaOku, EkranCiktisi); // satir satir okur ve degiskene atar
				cout << "\t" << EkranCiktisi << endl; // degisken ekrana yazdirilir

			}
			cout << "*******************************************************************************" << endl << endl << endl;
		}
		////// Urun Listeleme Menusu/////// 




		///////// Urun Duzeltme Menusu//////      ekran kontrolü 
		if (w == "4")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Urun duzeltme modulu acildi..." << endl;
			cout << "Duzeltmek istediginiz urun kodunu giriniz : "; cin >> KodKontrol;
			ifstream DosyaOku("Urun.txt", ios::in);
			while (!DosyaOku.eof()) //dosya sonu gelene kadar okusun diye
			{
				DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >> UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >> KDVoranı >> StokAdedi;
				if (UrunKodu == KodKontrol) //kod kontrolü yapiliyor eslesme olursa düzeltme yapmak icin calisacak
				{
					cout << "Urun bulundu" << endl;
					DosyaOku.close();
					ofstream tutucuYaz;
					DosyaOku.open("Urun.txt");
					tutucuYaz.open("tutucu.txt", ios::app); //gecici olarka dosya aciyoruz duzeltilecek haric sirayla kopyalar
					if (DosyaOku.is_open())
						cout << " !!!!!!!!!!!!!  Urun dosyasi acildi         !!!!!!!!!!!" << endl; //dosyalar acildi mi kontrolü
					if (tutucuYaz.is_open())
						cout << " !!!!!!!!!!!!!  Urun duzeltme metodu acildi !!!!!!!!!!!" << endl;
					while (!(DosyaOku.eof()))
					{
						DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >>
							UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >>
							KDVoranı >> StokAdedi;
						if (!(DosyaOku.eof()))
						{
							if (KodKontrol == UrunKodu) //düzeltilecek urun koduna geldiğinde onun yerine kullanicin girdiği yeni bilgileri yazar
							{

								cout << '\t' << " \n Urun Kodu -> " << KodKontrol << " Olan urun icin islem yapiliyor." << endl;
								cout << '\t' << " \n Uretici             : "; cin >> Uretici;
								cout << '\t' << " \n Temin Suresi  (gun) : "; cin >> TeminSuresi;
								cout << '\t' << " \n Uretim Tarihi(g,a,y): "; cin >> UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl;
								cout << '\t' << " \n Fiyat               : "; cin >> Fiyat;
								cout << '\t' << " \n KDV orani           : "; cin >> KDVoranı;
								cout << '\t' << " \n Stok Adedi          : "; cin >> StokAdedi;

								tutucuYaz << UrunKodu << "\t" << Uretici << "\t" << TeminSuresi << "\t" <<
									UretimTarihiGun << "\t" << UretimTarihiAy << "\t" << UretimTarihiYıl << "\t" << Fiyat << "\t" <<
									KDVoranı << "\t" << StokAdedi << "\n";

							}
							else
							{
								tutucuYaz << UrunKodu << "\t" << Uretici << "\t" << TeminSuresi << "\t" <<
									UretimTarihiGun << "\t" << UretimTarihiAy << "\t" << UretimTarihiYıl << "\t" << Fiyat << "\t" <<
									KDVoranı << "\t" << StokAdedi << "\n";
							}
						}



					}
					DosyaOku.close();
					tutucuYaz.close();
					if (!(DosyaOku.is_open()))
						cout << " !!!!!!!!!!!!!!!! Urun dosyasi kapandi         !!!!!!!!!!!!" << endl;
					if (!(tutucuYaz.is_open()))
						cout << " !!!!!!!!!!!!!!!! Urun duzeltme metodu kapandi !!!!!!!!!!!!" << endl;
					break;
				}
				else if (DosyaOku.eof()) //kullanicin girdiği urun kodu yoksa uyarir
				{
					cout << "Hatali veya eksik urun kodu..." << endl;
					DosyaOku.close();
				}
				cout << endl << endl;
			}
			system("del Urun.txt");
			rename("tutucu.txt", "Urun.txt");
			cout << endl << endl;

		}
		///////// Urun duzeltme menusu////////



		/////////  Urun Silme Menusu //////        ekran kontrolü 
		if (w == "5")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Urun silme modulu acildi..." << endl;
			cout << "Silmek istediginiz urun kodunu giriniz : "; cin >> KodKontrol;
			ifstream DosyaOku("Urun.txt", ios::in);
			while (!DosyaOku.eof())
			{
				DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >> UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >> KDVoranı >> StokAdedi;
				if (UrunKodu == KodKontrol)
				{
					cout << "Urun kodu eslesmesi saglandi" << endl;
					DosyaOku.close();
					ofstream siliciYaz;
					DosyaOku.open("Urun.txt");
					siliciYaz.open("silici.txt", ios::app);
					if (DosyaOku.is_open())
						cout << "!!!!!!!!!!! Urun dosyasi acildi      !!!!!!!!!" << endl;
					if (siliciYaz.is_open())
						cout << "!!!!!!!!!!! Urun silme metodu acildi !!!!!!!!!" << endl;
					while (!(DosyaOku.eof()))
					{
						DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >>
							UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >>
							KDVoranı >> StokAdedi;
						if (!(DosyaOku.eof()))
						{
							if (KodKontrol == UrunKodu) {
								cout << "Silme basarili..." << endl; continue; //düzeltme ile aynı sadece girilen koda sira geldiğinde dongü bir sonrakine gecerek silme islemi yapiliyor
							}
							else
							{
								siliciYaz << UrunKodu << "\t" << Uretici << "\t" << TeminSuresi << "\t" <<
									UretimTarihiGun << "\t" << UretimTarihiAy << "\t" << UretimTarihiYıl << "\t" << Fiyat << "\t" <<
									KDVoranı << "\t" << StokAdedi << "\n";
							}
						}
					}
					DosyaOku.close();
					siliciYaz.close();
					if (!(DosyaOku.is_open()))
						cout << "!!!!!!!!!!! Urun dosyasi kapandi      !!!!!!!!!!!" << endl;
					if (!(siliciYaz.is_open()))
						cout << "!!!!!!!!!!! Urun silme metodu kapandi !!!!!!!!!!!" << endl;

					break;
				}
				else if (DosyaOku.eof())
				{
					cout << "Hatali veya eksik urun kodu..." << endl;
					DosyaOku.close();
				}
			}
			system("del Urun.txt");
			rename("silici.txt", "Urun.txt");
			cout << endl << endl;

		}
		/////////  Urun Silme Menusu //////




		////// Musteri Ekleme Menusu //////       ekran kontrolü 
		if (w == "6")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Musteri ekleme modulu acildi..." << endl;
			ofstream dosyaYaz2;

			do //tekrar tekrar musteri ekleyebilmek icin
			{
				dosyaYaz2.open("cari.txt", ios::app);
				cout << '\t' << " \n Firma Kodu           : "; cin >> firmaKodu;
				geciciKod2 = firmaKodu;
				ifstream dosyaOku2("cari.txt", ios::in);
				while (!(dosyaOku2.eof())) //müsteri kodu kontrolu yaparak ayni koda sahip musteriler olmasini engelliyor
				{
					dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
					if (firmaKodu == kodKontrol)
					{
						cout << "Bu musteri zaten ekli" << endl;
						dosyaOku2.close();
						break;
					}
					else if (dosyaOku2.eof())  //yeni musteri kodu yoksa dosyada diegr bilgilerin girilmesini saglar
					{
						firmaKodu = geciciKod2;
						cout << '\t' << " \n Firma Adi            : "; cin >> firmaAdi;
						cout << '\t' << " \n Firma Telefonu       : "; cin >> firmaTelefon;
						cout << '\t' << " \n Firma Yetkili        : "; cin >> firmaYetkili;
						cout << '\t' << " \n Firma Adresi         : "; cin >> firmaAdres;

						dosyaYaz2 << firmaKodu << "\t" << firmaAdi << "\t" << firmaTelefon << "\t" << firmaYetkili << "\t" << firmaAdres << "\n";
						dosyaYaz2.close();
						dosyaOku2.close();
					}
				}
				cout << "\n Baska kayit yapacak misin?(e/h) "; cin >> cevap;
				cout << endl << endl << endl;
			} while (!(cevap == 'h'));

		}
		////// Musteri Ekleme Menusu //////



		////////  Musteri Arama Menusu //////     ekran kontrolü 
		if (w == "7")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Musteri arama modulu acildi..." << endl << endl;
			ifstream dosyaOku2("cari.txt", ios::in);
			cout << "Aramak istediginiz firma kodunu giriniz : "; 		cin >> kodKontrol;
			while (!dosyaOku2.eof())
			{
				dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
				if (firmaKodu == kodKontrol)  //urun arama ile aynı 
				{
					cout << "Musteri kodu eslesmesi saglandi" << endl;
					cout << '\t' << " \n Firma Kodu           : " << firmaKodu;
					cout << '\t' << " \n Firma Adi            : " << firmaAdi;
					cout << '\t' << " \n Firma Telefonu       : " << firmaTelefon;
					cout << '\t' << " \n Firma Yetkili        : " << firmaYetkili;
					cout << '\t' << " \n Firma Adresi         : " << firmaAdres << endl << endl;
					dosyaOku2.close();
					break;
				}
				else if (dosyaOku2.eof())
				{
					cout << "Hatali veya eksik musteri kodu ..." << endl;
					dosyaOku2.close();
				}
			}
			cout << endl << endl;
		}
		////////  Musteri Arama Menusu //////


		/////// Musteri Duzeltme Menusu //////
		if (w == "8")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Musteri duzeltme modulu acildi..." << endl;
			cout << "Duzeltmek istediginiz Musteri Kodunu giriniz : "; cin >> kodKontrol;
			ifstream dosyaOku2("cari.txt", ios::in);
			while (!dosyaOku2.eof())
			{
				dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
				if (firmaKodu == kodKontrol) //urun ile ayni
				{
					cout << "Musteri kodu eslesmesi saglandi" << endl;
					dosyaOku2.close();
					ofstream tutucuYaz2;
					dosyaOku2.open("cari.txt");
					tutucuYaz2.open("tutucuMusteri.txt", ios::app);
					while (!(dosyaOku2.eof()))
					{
						dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
						if (!(dosyaOku2.eof()))
						{
							if (kodKontrol == firmaKodu)
							{

								cout << '\t' << " \n Urun Kodu  " << kodKontrol << " Olan urun icin islem yapiliyor." << endl;
								cout << " \n Firma Adı            : "; cin >> firmaAdi;
								cout << " \n Firma Telefonu       : "; cin >> firmaTelefon;
								cout << " \n Firma Yetkili        : "; cin >> firmaYetkili;
								cout << " \n Firma Adresi         : "; cin >> firmaAdres;


								tutucuYaz2 << kodKontrol << "\t" << firmaAdi << "\t" << firmaTelefon << "\t" << firmaYetkili << "\t" << firmaAdres << "\n";

							}
							else
							{
								tutucuYaz2 << firmaKodu << "\t" << firmaAdi << "\t" << firmaTelefon << "\t" << firmaYetkili << "\t" << firmaAdres << "\n";
							}
						}



					}
					dosyaOku2.close();
					tutucuYaz2.close();
					break;
				}
				else if (dosyaOku2.eof())
				{
					cout << "Hatali veya eksik musteri kodu ..." << endl;
					dosyaOku2.close();
				}
			}
			system("del cari.txt");
			rename("tutucuMusteri.txt", "cari.txt");
			cout << endl << endl << endl;
		}
		/////// Musteri Duzeltme Menusu //////      ekran konrtolü


		/////// Musteri silme Menusu //////            ekran kontrolü
		if (w == "9")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Musteri silme modulu acildi..." << endl;
			cout << "Silmek  istediginiz musteri kodunu giriniz : "; cin >> kodKontrol;
			ifstream dosyaOku2("cari.txt", ios::in);
			while (!dosyaOku2.eof())
			{
				dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
				if (firmaKodu == kodKontrol)  //urun ile ayni
				{
					cout << "Musteri kodu eslesmesi saglandi" << endl;
					dosyaOku2.close();

					ofstream silici2;
					dosyaOku2.open("cari.txt");
					silici2.open("siliciMusteri.txt", ios::app);
					while (!(dosyaOku2.eof()))
					{
						dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
						if (!(dosyaOku2.eof()))
						{
							if (kodKontrol == firmaKodu)
							{
								continue;
							}
							else
							{
								silici2 << firmaKodu << "\t" << firmaAdi << "\t" << firmaTelefon << "\t" << firmaYetkili << "\t" << firmaAdres << "\n";
							}
						}



					}
					dosyaOku2.close();
					silici2.close();
					break;
				}
				else if (dosyaOku2.eof())
				{
					cout << "Hatali veya eksik musteri kodu ..." << endl;
					dosyaOku2.close();
				}
			}
			system("del cari.txt");
			rename("siliciMusteri.txt", "cari.txt");
			cout << endl << endl << endl;
		}
		/////// Musteri silme Menusu ////// 


		//////// siparis olusturma ///////      ekran kontrolü
		if (w == "10")
		{
			cout << "*****************************************************************************" << endl;
			cout << '\t' << "Siparis olusturma modulu acildi..." << endl;
			ifstream dosyaOku2("cari.txt", ios::in);
			while (!(dosyaOku2.eof()))
			{
				if (!(dosyaOku2.eof()))
				{
					dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
					if (!(r == firmaKodu))
					{

						cout << '\t' << " \n Firma Kodu           : " << firmaKodu;
						cout << '\t' << " \n Firma Adi            : " << firmaAdi;
						cout << '\t' << " \n Firma Telefonu       : " << firmaTelefon;
						cout << '\t' << " \n Firma Yetkili        : " << firmaYetkili;
						cout << '\t' << " \n Firma Adresi         : " << firmaAdres << endl << endl;
						r = firmaKodu;
					}

				}
			}
			dosyaOku2.close();
			cout << "Siparis veren firma kodunu giriniz      : "; cin >> musteriSiparis;
			//ifstream dosyaOku2("cari.txt", ios::in);
			dosyaOku2.open("cari.txt");
			while (!dosyaOku2.eof())
			{
				dosyaOku2 >> firmaKodu >> firmaAdi >> firmaTelefon >> firmaYetkili >> firmaAdres;
				if (firmaKodu == musteriSiparis)  //urun arama ile aynı 
				{
					cout << "Musteri kodu eslesmesi saglandi. Musteri bilgileri ..." << endl;
					cout << '\t' << " \n Firma Kodu           : " << firmaKodu;
					cout << '\t' << " \n Firma Adi            : " << firmaAdi;
					geciciFirma = firmaAdi;
					cout << '\t' << " \n Firma Telefonu       : " << firmaTelefon;
					cout << '\t' << " \n Firma Yetkili        : " << firmaYetkili;
					cout << '\t' << " \n Firma Adresi         : " << firmaAdres << endl << endl;

					dosyaOku2.close();

					break;
				}
				else if (dosyaOku2.eof())
				{
					cout << "Hatali veya eksik musteri kodu ..." << endl;
					dosyaOku2.close();
				}
			}
			dosyaOku2.close();
			ifstream DosyaOku("Urun.txt", ios::in);
			cout << "        Kodu  Uretici  Temin   U.Gun   U.Ay    U.Yil   Fiyat    KDV    Stok" << endl; //ekran duzeni
			while (!DosyaOku.eof())  // dosya sonu gelene kadar songu calissin diye
			{
				getline(DosyaOku, EkranCiktisi); // satir satir okur ve degiskene atar
				cout << "\t" << EkranCiktisi << endl; // degisken ekrana yazdirilir
				ctr1 = 1;
			}
			cout << "*******************************************************************************" << endl << endl << endl;
			DosyaOku.close();
			cout << musteriSiparis << " kodlu firmanin siparis ettigi urun kodunu giriniz..."; cin >> urunSiparis;
			//ifstream DosyaOku("Urun.txt", ios::in);
			DosyaOku.open("Urun.txt");
			while (!(DosyaOku.eof())) //dosya sonu gelene kadar verileri sira sira okumasi icin 
			{
				DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >> UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >> KDVoranı >> StokAdedi;
				if (control == 1)
				{
					if (UrunKodu == urunSiparis) //aranan urun kodu var ise dongu calisir ve urun bilgileri yazdirilir
					{
						cout << "Urun bulundu, Urun bilgileri..." << endl;
						cout << '\t' << " \n Uretici             : " << Uretici;
						cout << '\t' << " \n Temin Suresi (gun)  : " << TeminSuresi;
						cout << '\t' << " \n Uretim Tarihi(gun)  : " << UretimTarihiGun;
						cout << '\t' << " \n Uretim Tarihi(ay)   : " << UretimTarihiAy;
						cout << '\t' << " \n Uretim Tarihi(yıl)  : " << UretimTarihiYıl;
						cout << '\t' << " \n Fiyat               : " << Fiyat;
						cout << '\t' << " \n KDV orani           : " << KDVoranı;
						cout << '\t' << " \n Stok Adedi          : " << StokAdedi << endl << endl;
						do {
							cout << "Siparis adeti    : "; cin >> siparisAdet;
							control = 0;
							if (siparisAdet > StokAdedi || siparisAdet <= "0")
							{
								control = 1;
								cout << "Stok adedini kontrol edin ve uygun miktarda siparis veriniz." << endl;
							}

							ctr2 = 1;

						} while (control);
						DosyaOku.close();

						continue;
					}
					else if (DosyaOku.eof()) //aranan urun kodu yoksa calisip uyarir.
					{
						cout << "Hatali veya eksik urun kodu..." << endl;
						DosyaOku.close();
					}
				}
				//cout << ctr2 << setw(10) << ctr1;
			}
			if (ctr1 == 1 && ctr2 == 1)
			{
				ofstream siparisYaz;
				siparisYaz.open("Siparis.txt", ios::app);
				cout << "Siparis kodunu giriniz   :";
				cin >> siparisKodu;
				firmaAdi = geciciFirma;
				paha = stoi(Fiyat);
				miktar = stoi(siparisAdet);
				siparisTutari = miktar * paha;
				siparisYaz << siparisKodu << '\t' << musteriSiparis << '\t' << firmaAdi << '\t' << urunSiparis << '\t' << siparisAdet << '\t' << siparisTutari << "\n";
				siparisYaz.close();
				ifstream DosyaOku("Urun.txt", ios::in);
				while (!DosyaOku.eof()) //dosya sonu gelene kadar okusun diye
				{
					DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >> UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >> KDVoranı >> StokAdedi;
					if (UrunKodu == urunSiparis) //kod kontrolü yapiliyor eslesme olursa düzeltme yapmak icin calisacak
					{
						cout << "Urun bulundu" << endl;
						DosyaOku.close();
						ofstream tutucuYaz;
						DosyaOku.open("Urun.txt");
						tutucuYaz.open("tutucu.txt", ios::app); //gecici olarka dosya aciyoruz duzeltilecek haric sirayla kopyalar

						while (!(DosyaOku.eof()))
						{
							DosyaOku >> UrunKodu >> Uretici >> TeminSuresi >>
								UretimTarihiGun >> UretimTarihiAy >> UretimTarihiYıl >> Fiyat >>
								KDVoranı >> StokAdedi;
							gecStok = stoi(StokAdedi);
							gecstok2 = gecStok - miktar;
							if (!(DosyaOku.eof()))
							{

								if (urunSiparis == UrunKodu) //düzeltilecek urun koduna geldiğinde onun yerine kullanicin girdiği yeni bilgileri yazar
								{
									StokAdedi = to_string(gecstok2);
									tutucuYaz << UrunKodu << "\t" << Uretici << "\t" << TeminSuresi << "\t" <<
										UretimTarihiGun << "\t" << UretimTarihiAy << "\t" << UretimTarihiYıl << "\t" << Fiyat << "\t" <<
										KDVoranı << "\t" << StokAdedi << "\n";

								}
								else
								{
									tutucuYaz << UrunKodu << "\t" << Uretici << "\t" << TeminSuresi << "\t" <<
										UretimTarihiGun << "\t" << UretimTarihiAy << "\t" << UretimTarihiYıl << "\t" << Fiyat << "\t" <<
										KDVoranı << "\t" << StokAdedi << "\n";
								}
							}



						}
						DosyaOku.close();
						tutucuYaz.close();

						break;
					}
					else if (DosyaOku.eof()) //kullanicin girdiği urun kodu yoksa uyarir
					{
						cout << "Hatali veya eksik urun kodu..." << endl;
						DosyaOku.close();
					}
					cout << endl << endl;
				}
				system("del Urun.txt");
				rename("tutucu.txt", "Urun.txt");
				cout << endl << endl;

			}
			DosyaOku.close();



		}
		//////// siparis olusturma /////////




		////////// siparis arama menusu //////////      ekran kontrolü
		if (w == "11")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Siapris arama modulu acildi..." << endl;
			cout << "Aramak istediginiz siparis kodunu giriniz : "; cin >> siparisKontrol;
			ifstream siparisOku("Siparis.txt", ios::in);
			while (!siparisOku.eof()) //dosya sonu gelene kadar verileri sira sira okumasi icin 
			{
				siparisOku >> siparisKodu >> musteriSiparis >> firmaAdi >> urunSiparis >> siparisAdet >> siparisTutari;
				if (siparisKodu == siparisKontrol) //aranan urun kodu var ise dongu calisir ve urun bilgileri yazdirilir
				{
					cout << "Siparis bulundu" << endl;
					cout << '\t' << " \n Siparis Kodu        : " << siparisKodu;
					cout << '\t' << " \n Firma Kodu          : " << musteriSiparis;
					cout << '\t' << " \n Firma Adi           : " << firmaAdi;
					cout << '\t' << " \n Urun kodu           : " << urunSiparis;
					cout << '\t' << " \n Siparis Adeti       : " << siparisAdet;
					cout << '\t' << " \n Tutar               : " << siparisTutari << endl << endl;
					siparisOku.close();
					break;
				}
				else if (siparisOku.eof()) //aranan urun kodu yoksa calisip uyarir.
				{
					cout << "Hatali veya eksik siparis kodu..." << endl;
					siparisOku.close();
				}
			}
			cout << endl << endl;
		}
		/////////// siparis arama menusu  //////////



		///////// siparis silme menusu /////////      ekran kontrolü
		if (w == "12")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Siparis silme modulu acildi..." << endl;
			cout << "Silmek istediginiz siparis kodunu giriniz : "; cin >> siparisKontrol;
			ifstream siparisOku("Siparis.txt", ios::in);
			while (!siparisOku.eof())
			{
				siparisOku >> siparisKodu >> musteriSiparis >> firmaAdi >> urunSiparis >> siparisAdet >> siparisTutari;
				if (siparisKodu == siparisKontrol)
				{
					cout << "Siparis kodu eslesmesi saglandi" << endl;
					siparisOku.close();
					ofstream siparisSilci;
					siparisOku.open("Siparis.txt");
					siparisSilci.open("siparisSilici.txt", ios::app);
					while (!(siparisOku.eof()))
					{
						siparisOku >> siparisKodu >> musteriSiparis >> firmaAdi >> urunSiparis >> siparisAdet >> siparisTutari;
						if (!(siparisOku.eof()))
						{
							if (siparisKontrol == siparisKodu) {
								cout << "Silme basarili..." << endl; continue; //düzeltme ile aynı sadece girilen koda sira geldiğinde dongü bir sonrakine gecerek silme islemi yapiliyor
							}
							else
							{
								siparisSilci << siparisKodu << '\t' << musteriSiparis << 't' << firmaAdi << '\t' << urunSiparis << '\t' << siparisAdet << '\t' << siparisTutari << "\n";
							}
						}
					}
					siparisOku.close();
					siparisSilci.close();

					break;
				}
				else if (siparisOku.eof())
				{
					cout << "Hatali veya eksik urun kodu..." << endl;
					siparisOku.close();
				}
			}
			system("del Siparis.txt");
			rename("siparisSilici.txt", "Siparis.txt");
			cout << endl << endl;
		}
		///////// siparis silme menusu ////////



		//////// siparis duzeltme menusu/////////      ekran kontrolü
		if (w == "13")
		{
			cout << "******************************************************" << endl;
			cout << '\t' << "Siparis duzeltme modulu acildi..." << endl;
			cout << "Duzeltmek istediginiz siparis Kodunu giriniz : "; cin >> SiparisKontrol;
			ifstream siparisOku2("Siparis.txt", ios::in);
			while (!siparisOku2.eof())
			{
				siparisOku2 >> siparisKodu >> musteriSiparis >> firmaAdi >> urunSiparis >> siparisAdet >> siparisTutari;
				if (siparisKodu == SiparisKontrol) //urun ile ayni
				{
					cout << "Siparis kodu eslesmesi saglandi" << endl;
					siparisOku2.close();
					ofstream siparisTutucu;
					siparisOku2.open("Siparis.txt");
					siparisTutucu.open("tutucuSiparis.txt", ios::app);
					while (!(siparisOku2.eof()))
					{
						siparisOku2 >> siparisKodu >> musteriSiparis >> firmaAdi >> urunSiparis >> siparisAdet >> siparisTutari;
						if (!(siparisOku2.eof()))
						{
							if (SiparisKontrol == siparisKodu)
							{

								cout << '\t' << " \n Siparis Kodu  " << SiparisKontrol << " Olan siparis icin islem yapiliyor." << endl;
								cout << " \n Firma Adı            : "; cin >> firmaAdi;
								cout << " \n Firma Telefonu       : "; cin >> firmaTelefon;
								cout << " \n Firma Yetkili        : "; cin >> firmaYetkili;
								cout << " \n Firma Adresi         : "; cin >> firmaAdres;


								siparisTutucu << siparisKodu << '\t' << musteriSiparis << 't' << firmaAdi << '\t' << urunSiparis << '\t' << siparisAdet << '\t' << siparisTutari << "\n";

							}
							else
							{
								siparisTutucu << siparisKodu << '\t' << musteriSiparis << 't' << firmaAdi << '\t' << urunSiparis << '\t' << siparisAdet << '\t' << siparisTutari << "\n";
							}
						}



					}
					siparisOku2.close();
					siparisTutucu.close();
					break;
				}
				else if (siparisOku2.eof())
				{
					cout << "Hatali veya eksik musteri kodu ..." << endl;
					siparisOku2.close();
				}
			}
			system("del Siparis.txt");
			rename("tutucuSiparis.txt", "Siparis.txt");
			cout << endl << endl << endl;
		}
		//////////siparis duzeltme menusu ///////////



		///////// siparis listeleme ///////////      ekran kontrolü
		if (w == "14")
		{
			cout << "*******************************************************************************" << endl;
			cout << '\t' << "Siparis listeleme modulu acildi..." << endl;
			//	cout << "Listelemek istediginiz urun kodunu giriniz : "; cin >> KodKontrol;
			ifstream siparisOku("Siparis.txt", ios::in);
			cout << "        Kodu   F.Kodu  F.Adi   U.Kodu   Adet   Tutar     " << endl; //ekran duzeni
			while (!siparisOku.eof())  // dosya sonu gelene kadar songu calissin diye
			{
				getline(siparisOku, EkranCiktisiS); // satir satir okur ve degiskene atar
				cout << "\t" << EkranCiktisiS << endl; // degisken ekrana yazdirilir

			}
			cout << "*******************************************************************************" << endl << endl << endl;
		}
		///////// siparis listeleme ///////////

		//////////// cikis ////////////
		if (w == "x") { break; }
		//////////// cikis ////////////
	} while (true);
}