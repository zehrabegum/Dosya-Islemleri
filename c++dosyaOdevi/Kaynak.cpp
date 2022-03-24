/***********************************************************************************************************************************
 SAKARYA ÜNÝVERSÝTESÝ
 BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
 PROGRAMLAMAYA GÝRÝÞ DERSÝ
 2019-2020 YAZ DÖNEMÝ
 ADI:ZEHRA BEGÜM  SOYADI:AKTOLGA   NUMARASI:B191210062   GRUP:1A GRUBU 1.ÖÐRETÝM
/***********************************************************************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<cstring>
#include<Windows.h>
#include<iomanip>
#include <cstdio>

using namespace std;

int main()
{
    //ürün.txt dosyasý.
    string UrunNo;
    string UrunAdi;
    string Birim;
    string BirimTuru;
    string BirimFiyati;
    string Markasi;
    //proje.txt dosyasý.
    string ProjeNo;
    string ProjeAdi;
    string ProjeYurutucuFirma;
    string ProjeSorumlusu;
    string ProjeKontrolu;
    //hakediþ.txt dosyasý.
    string Donem;

    //Girilen seçim numarasýna göre döngüden çýkýp iþlemi yapmayý saðlar.
    int secim;
    char cevap = 'e';
    do {
        cout << " Ne yapmak istiyorsunuz: " << endl;
        cout << " 1) Urun dosyasina gitmek." << endl;
        cout << " 2) Proje dosyasina gitmek." << endl;
        cout << " 3) Hakedis dosyasina gitmek." << endl;
        cin >> secim;
    } while (secim != 1 && secim != 2 && secim != 3);

    if (secim == 1)
    {
        int secim1;
        do {
            cout << " Ne yapmak istiyorsunuz: " << endl;
            cout << " 1) Urun ekleme." << endl;
            cout << " 2) Urun silme." << endl;
            cout << " 3) Urun arama." << endl;
            cout << " 4) Raporlama." << endl;
            cin >> secim1;
        } while (secim1 != 1 && secim1 != 2 && secim1 != 3 && secim1 != 4);

        if (secim1 == 1)
        {
            ofstream UrunDosyasi("Ürün.txt", ios::app);
            ifstream UrunDosyaOku("Ürün.txt", ios::in);

            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
            string sayi, sayi1, sayi2;

            cout << " UrunNo:"; cin >> UrunNo;
            cout << " UrunAdi:"; cin >> UrunAdi;
            cout << " Birim:"; cin >> Birim;
            cout << " BirimTuru:(kg,adet...)"; cin >> BirimTuru;
            cout << " BirimFiyati:"; cin >> BirimFiyati;
            cout << " Markasi:"; cin >> Markasi;

            //Ürün dosyasýný baþtan sona kadar okumayý saðlar.
            while (!UrunDosyaOku.eof())
            {
                UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6;
                if (UrunNo == sayi)
                {
                    cout << "Ayni urun numarasinda urun var.Ekleme yapamazsiniz!" << endl;
                    cout << "Cikmak icin c' ye basin." << endl;
                    cin >> cevap;
                }
            }
            //Yeni eklenen ürün numarasý dosyadaki ürün numaralarýndan farklýysa ürünü ekler.
            if (cevap != 'c')
            {
                UrunDosyasi << "UrunNo:" << " " << UrunNo << " "
                    << "Birim:" << " " << Birim << " " << BirimTuru << " "
                    << "BirimFiyati:" << " " << BirimFiyati << " "
                    << "UrunAdi:" << " " << UrunAdi << " "
                    << "Markasi:" << " " << Markasi << "\n";
            }
            UrunDosyasi.close();
        }

        if (secim1 == 2)
        {
            string No;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
            string sayi, sayi1, sayi2;
            cout << "Silmek istediginiz urunun numarasini girin:";
            cin >> No;

            ifstream UrunDosyaOku("Ürün.txt", ios::in);
            ofstream UrunDosyasi("Urun.txt", ios::app);

            //Ürün dosyasýný baþtan sona kadar okumayý saðlar.
            while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
            {
                //Girilen numarayla dosyadaki ürün numarasý tutuyorsa silme iþlemi gerçekleþir.
                if (No == sayi)
                {
                    cout << "Silinen Urun Bilgileri" << endl;
                    cout << kelime << sayi << " "
                        << kelime1 << sayi1 << " " << kelime7 << " "
                        << kelime2 << sayi2 << " "
                        << kelime3 << kelime4 << " "
                        << kelime5 << kelime6 << "\n";
                }
                else
                {
                    UrunDosyasi << kelime << " " << sayi << " "
                        << kelime1 << " " << sayi1 << " " << kelime7 << " "
                        << kelime2 << " " << sayi2 << " "
                        << kelime3 << " " << kelime4 << " "
                        << kelime5 << " " << kelime6 << "\n";
                }
            }
            UrunDosyaOku.close();
            UrunDosyasi.close();
            remove("Ürün.txt");
            rename("Urun.txt", "Ürün.txt");
        }
        if (secim1 == 3)
        {

            string No;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
            string sayi, sayi1, sayi2;

            cout << "Bulmak istediginiz urunun numarasini giriniz:";
            cin >> No;

            ifstream UrunDosyaOku("Ürün.txt", ios::in);

            //Ürün dosyasýný baþtan sona kadar okumayý saðlar.
            while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
            {
                //Girilen numarayla dosyadaki ürün numarasý tutuyorsa ürün bilgilerine ulaþýlýr.
                if (No == sayi)
                {
                    cout << "Urun Bilgileri" << endl;
                    cout << kelime << sayi << " "
                        << kelime1 << sayi1 << " " << kelime7 << " "
                        << kelime2 << sayi2 << " "
                        << kelime3 << kelime4 << " "
                        << kelime5 << kelime6 << "\n";
                }
            }
            UrunDosyaOku.close();
        }
        if (secim1 == 4)
        {
            ifstream UrunDosyaOku("Ürün.txt", ios::in);

            int secim2;
            do
            {
                cout << "1) Urun numarasina gore raporlama." << endl;
                cout << "2) Urun birimine gore raporlama.(kg,adet...)" << endl;
                cin >> secim2;
            } while (secim2 != 1 && secim2 != 2);

            if (secim2 == 1)
            {
                string No;
                string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
                string sayi, sayi1, sayi2;
                cout << "Raporlamak istediginiz urunun numarasini giriniz:";
                cin >> No;

                //Ürün dosyasýný baþtan sona kadar okumayý saðlar.
                while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
                {
                    //Seçilen raporlama tipine göre ürün numarasýyla raporlamayý saðlar.
                    if (No == sayi)
                    {
                        cout << "Rapor Bilgileri" << endl;
                        cout << kelime << sayi << " "
                            << kelime1 << sayi1 << " " << kelime7 << " "
                            << kelime2 << sayi2 << " "
                            << kelime3 << kelime4 << " "
                            << kelime5 << kelime6 << "\n";
                    }
                }
                UrunDosyaOku.close();
            }
            if (secim2 == 2)
            {
                string Birim;
                string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
                string sayi, sayi1, sayi2;
                cout << "Raporlamak istediginiz birim turundeki birimi giriniz:";
                cin >> Birim;

                //Ürün dosyasýný baþtan sona kadar okumayý saðlar.
                while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
                {
                    //Seçilen raporlama tipine göre ürün birim türüyle raporlamayý saðlar.
                    if (Birim == kelime7)
                    {
                        cout << "Rapor Bilgileri" << endl;
                        cout << kelime << sayi << " "
                            << kelime1 << sayi1 << " " << kelime7 << " "
                            << kelime2 << sayi2 << " "
                            << kelime3 << kelime4 << " "
                            << kelime5 << kelime6 << "\n";
                    }
                }
                UrunDosyaOku.close();
            }
        }
    }

    if (secim == 2)
    {
        ifstream UrunDosyaOku("Ürün.txt", ios::in);

        int secim1;
        do {
            cout << " Ne yapmak istiyorsunuz: " << endl;
            cout << " 1) Proje ekleme." << endl;
            cout << " 2) Proje silme. " << endl;
            cout << " 3) Proje arama." << endl;
            cout << " 4) Raporlama." << endl;
            cin >> secim1;
        } while (secim != 1 && secim != 2 && secim != 3 && secim != 4);

        if (secim1 == 1)
        {
            ofstream ProjeDosyasi("Proje.txt", ios::app);
            ifstream ProjeDosyaOku("Proje.txt", ios::in);

            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6;
            string sayi, sayi1, sayi2;

            cout << "ProjeNo projede kullanilacak urun icin UrunNo ile ayni olmalidir." << endl;
            cout << "Sadece yeni bir proje eklemek istiyorsaniz ProjeNo UrunNo dan farkli girebilirsiniz." << endl;

            cout << "ProjeNo:"; cin >> ProjeNo;
            cout << "ProjeYurutucuFirma:"; cin >> ProjeYurutucuFirma;
            cout << "ProjeAdi:"; cin >> ProjeAdi;
            cout << "ProjeSorumlusu:"; cin >> ProjeSorumlusu;
            cout << "ProjeKontrolu:"; cin >> ProjeKontrolu;

            //Proje dosyasýný baþtan sona kadar okumayý saðlar.
            while (!ProjeDosyaOku.eof())
            {
                ProjeDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6;
                if (ProjeNo == sayi)
                {
                    cout << "Ayni proje numarasinda proje var.Ekleme yapamazsiniz!" << endl;
                    cout << "Cikmak icin c'ye basin." << endl;
                    cin >> cevap;
                }
            }
            //Yeni eklenen proje numarasý dosyadaki proje numaralarýndan farklýysa ekleme yapar.
            if (cevap != 'c')
            {
                ProjeDosyasi << "ProjeNo:" << " " << ProjeNo << " "
                    << "ProjeYurutucuFirma:" << " " << ProjeYurutucuFirma << " "
                    << "ProjeAdi:" << " " << ProjeAdi << " "
                    << "ProjeSorumlusu:" << " " << ProjeSorumlusu << " "
                    << "ProjeKontrolu:" << " " << ProjeKontrolu << "\n";
            }
            ProjeDosyasi.close();
        }
        if (secim1 == 2)
        {
            string No;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6;
            string sayi, sayi1, sayi2;
            ifstream HakedisDosyasiOku("Hakedis.txt", ios::in);
            string Kelime, Kelime1, Kelime2, Kelime3, Kelime4, Kelime5, Kelime6, Kelime7, Kelime8;
            string Sayi, Sayi1, Sayi2, Sayi3;

            cout << "Silmek istediginiz projenin numarasini girin:";
            cin >> No;

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (HakedisDosyasiOku >> Kelime >> Sayi >> Kelime1 >> Sayi1 >> Kelime2 >> Sayi2 >> Kelime8 >> Kelime3 >> Sayi3 >> Kelime4 >> Kelime5 >> Kelime6 >> Kelime7)
            {
                //Girilen proje numarasýndaki ürün fiyatlarýnýn ödenmiþ mi ödenmemiþ mi olduðunu bulur.
                if (Sayi1 == No)
                {
                    cout << "Odenmemis projeleri silebilirsiniz!" << endl;
                    cout << "Bu projeyi silemezsiniz urun fiyati odenmistir! Cikmak icin c'ye basin.";
                    cin >> cevap;
                }
            }
            HakedisDosyasiOku.close();


            //Proje numarasýndaki ürün ödenmemiþse silme iþlemi gerçekleþir.
            if (cevap != 'c')
            {
                ifstream ProjeDosyaOku("Proje.txt", ios::in);
                ofstream ProjeDosyasi("pro.txt", ios::app);

                //Proje dosyasýný baþtan sona kadar okumayý saðlar.
                while (ProjeDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
                {
                    //Girilen numarayla dosyadaki proje numarasý tutuyorsa silme iþlemi gerçekleþir.
                    if (No == sayi)
                    {
                        cout << "Silinen Proje Bilgileri" << endl;
                        cout << kelime << sayi << " "
                            << kelime1 << sayi1 << " "
                            << kelime2 << sayi2 << " "
                            << kelime3 << kelime4 << " "
                            << kelime5 << kelime6 << "\n";
                    }
                    else
                    {
                        ProjeDosyasi << kelime << " " << sayi << " "
                            << kelime1 << " " << sayi1 << " "
                            << kelime2 << " " << sayi2 << " "
                            << kelime3 << " " << kelime4 << " "
                            << kelime5 << " " << kelime6 << "\n";
                    }
                }
                ProjeDosyaOku.close();
                ProjeDosyasi.close();
                remove("Proje.txt");
                rename("pro.txt", "Proje.txt");
            }
        }
        if (secim1 == 3)
        {
            string No;
            string Kelime, Kelime1, Kelime2, Kelime3, Kelime4, Kelime5, Kelime6;
            string Sayi, Sayi1, Sayi2;
            cout << "Bulmak istediginiz projenin numarasini giriniz:";
            cin >> No;

            ifstream ProjeDosyaOku("Proje.txt", ios::in);

            //Proje dosyasýný baþtan sona kadar okumayý saðlar.
            while (ProjeDosyaOku >> Kelime >> Sayi >> Kelime1 >> Sayi1 >> Kelime2 >> Sayi2 >> Kelime3 >> Kelime4 >> Kelime5 >> Kelime6)
            {
                //Girilen numarayla dosyadaki proje numarasý tutuyorsa proje bilgilerine ulaþýlýr.
                if (No == Sayi)
                {
                    cout << "Proje Bilgileri" << endl;
                    cout << Kelime << Sayi << " "
                        << Kelime1 << Sayi1 << " "
                        << Kelime2 << Sayi2 << " "
                        << Kelime3 << Kelime4 << " "
                        << Kelime5 << Kelime6 << "\n";
                }
            }
            ProjeDosyaOku.close();
        }
        if (secim1 == 4)
        {
            string No;
            string Kelime, Kelime1, Kelime2, Kelime3, Kelime4, Kelime5, Kelime6;
            string Sayi, Sayi1, Sayi2;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
            string sayi, sayi1, sayi2;
            cout << "Raporlamak istediginiz projenin numarasini giriniz:";
            cin >> No;

            ifstream ProjeDosyaOku("Proje.txt", ios::in);

            //Ürün dosyasýný baþtan sona kadar okumayý saðlar.
            while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> Kelime3 >> kelime4 >> kelime5 >> kelime6)
            {
                //Girilen numara proje numarasýyla tutuyorsa o proje bilgilerine ve o projenin ürün bilgilerine ulaþýlýr.
                if (No == sayi)
                {
                    cout << "Rapor Bilgileri" << endl
                        << kelime << sayi << " "
                        << kelime1 << sayi1 << " " << kelime7 << " "
                        << kelime2 << sayi2 << " "
                        << kelime3 << kelime4 << " "
                        << kelime5 << kelime6 << "\n";
                }
            }
            //Proje dosyasýný baþtan sona kadar okumayý saðlar.
            while (ProjeDosyaOku >> Kelime >> Sayi >> Kelime1 >> Sayi1 >> Kelime2 >> Sayi2 >> Kelime3 >> Kelime4 >> Kelime5 >> Kelime6)
            {
                //Girilen numara proje numarasýyla tutuyorsa o proje bilgilerine ve o projenin ürün bilgilerine ulaþýlýr.
                if (No == Sayi)
                {
                    cout << Kelime << Sayi << " "
                        << Kelime1 << Sayi1 << " "
                        << Kelime2 << Sayi2 << " "
                        << Kelime3 << Kelime4 << " "
                        << Kelime5 << Kelime6 << "\n";
                }
            }
            ProjeDosyaOku.close();
            UrunDosyaOku.close();
        }
    }
    if (secim == 3)
    {
        int secim1;
        do {
            cout << " Ne yapmak istiyorsunuz: " << endl;
            cout << " 1) Hakedis donemini ve proje ile urun bilgilerini eklemek." << endl;
            cout << " 2) Kullaninlan urunleri ve adetlerinin fiyatlarini ogrenmek." << endl;
            cout << " 3) Kullanilan urunleri silmek." << endl;
            cout << " 4) Kullanilan urunleri guncellemek." << endl;
            cout << " 5) Kullanilan urunleri listelemek." << endl;
            cout << " 6) Kullanilan urunlerden birisini arama." << endl;
            cout << " 7) Projelerin belirtilen donem icin hakedis tutar raporu." << endl;
            cin >> secim1;
        } while (secim1 != 1 && secim1 != 2 && secim1 != 3 && secim1 != 4 && secim1 != 5 && secim1 != 6 && secim1 != 7);

        if (secim1 == 1)
        {
            ifstream HakedisDosyasiOku("Hakedis.txt", ios::in);
            ofstream HakedisDosyasi("Hakedis.txt", ios::app);

            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7, kelime8;
            string sayi, sayi1, sayi2, sayi3;

            cout << " HakedisDonemi:"; cin >> Donem;
            cout << " ProjeNo:"; cin >> ProjeNo ;
            cout << " Birim:"; cin >> Birim ;
            cout << " BirimTuru:(kg,adet...)"; cin >> BirimTuru;
            cout << " BirimFiyati:"; cin >> BirimFiyati ;
            cout << " UrunAdi:"; cin >> UrunAdi;
            cout << " Markasi:"; cin >> Markasi;

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (!HakedisDosyasiOku.eof())
            {
                HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7;
                if (Donem == sayi)
                {
                    cout << "Ayni hakedis doneminde proje var.Ekleme yapamazsiniz!" << endl;
                    cout << "Cikmak icin c' ye basin." << endl;
                    cin >> cevap;
                }
            }
            //Yeni eklenen hakediþ dönemi dosyadaki hakediþ dönemlerinden farklýysa hakediþe projeyi ekler.
            if (cevap != 'c')
            {
                HakedisDosyasi <<"HakedisDonemi:"<<" "<< Donem<<" "
                    << "ProjeNo:" << " " << ProjeNo << " "
                    << "Birim:" << " " << Birim << " " << BirimTuru << " "
                    << "BirimFiyati:" << " " << BirimFiyati << " "
                    << "UrunAdi:" << " " << UrunAdi << " "
                    << "Markasi:" << " " << Markasi << "\n";

            }
            HakedisDosyasi.close();
        }

        if (secim1 == 2)
        {
            ifstream HakedisDosyasiOku("Hakedis.txt", ios::in);
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7, kelime8;
            string sayi, sayi1, sayi2, sayi3;

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                cout << "Kullanilan urunler ve adetlerinin fiyati:" << endl;
                cout << kelime2 << " " << sayi2 << " " << kelime8 << " " << kelime3 << " " << sayi3 << " " << kelime4 << " " << kelime5 << endl;
            }
            HakedisDosyasiOku.close();
        }

        if (secim1 == 3)
        {
            string No;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7, kelime8;
            string sayi, sayi1, sayi2, sayi3;

            cout << "Silmek istediginiz urunun hakedis donemini giriniz:";
            cin >> No;

            ifstream HakedisDosyasiOku("Hakedis.txt");
            ofstream HakedisDosyasi("Ha.txt");

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen dönemle dosyadaki hakediþ dönemi tutuyorsa silme iþlemi gerçekleþir.
                if (No == sayi)
                {
                    cout << "Silinen Urun Bilgileri" << endl;
                    cout << kelime << sayi << " "
                        << kelime1 << sayi1 << " "
                        << kelime2 << sayi2 << " " << kelime8 << " "
                        << kelime3 << sayi3 << " "
                        << kelime4 << kelime5 << " "
                        << kelime6 << kelime7 << "\n";
                }
                else
                {
                    HakedisDosyasi << kelime << " " << sayi << " "
                        << "ProjeNo:" << " " << sayi1 << " "
                        << kelime2 << " " << sayi2 << " " << kelime8 << " "
                        << kelime3 << " " << sayi3 << " "
                        << kelime4 << " " << kelime5 << " "
                        << kelime6 << " " << kelime7 << "\n";
                }
            }
            HakedisDosyasiOku.close();
            HakedisDosyasi.close();
            remove("Hakedis.txt");
            rename("Ha.txt", "Hakedis.txt");
        }

        if (secim1 == 4)
        {
            string No;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7, kelime8;
            string sayi, sayi1, sayi2, sayi3;

            cout << "Guncellemek istediginiz urunun proje numarasini giriniz:";
            cin >> No;

            ifstream HakedisDosyasiOku("Hakedis.txt");
            ofstream HakedisDosyasi("Hak.txt");

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen numarayla dosyadaki ürün numarasý tutuyorsa güncelleme iþlemi gerçekleþir.
                if (No == sayi1)
                {
                    cout << "Guncellenen Urun Bilgileri" << endl;
                    cout << kelime1 << sayi1 << " "
                        << kelime2 << sayi2 << " " << kelime8 << " "
                        << kelime3 << sayi3 << " "
                        << kelime4 << kelime5 << " "
                        << kelime6 << kelime7 << "\n";
                    cout << "Degismek istediginiz bilgileri tekrar girin. " << endl;
                    cout << " UrunNo:"; cin >> sayi1;
                    cout << " UrunAdi:"; cin >> kelime5;
                    cout << " Birim:"; cin >> sayi2;
                    cout << " BirimTuru:(kg,adet...)"; cin >> kelime8;
                    cout << " BirimFiyati:"; cin >> sayi3;
                    cout << " Markasi:"; cin >> kelime7;
                    cout << endl;

                    HakedisDosyasi << kelime << " " << sayi << " "
                        << "ProjeNo:" << " " << sayi1 << " "
                        << kelime2 << " " << sayi2 << " " << kelime8 << " "
                        << kelime3 << " " << sayi3 << " "
                        << kelime4 << " " << kelime5 << " "
                        << kelime6 << " " << kelime7 << "\n";
                }
                else
                {
                    HakedisDosyasi << kelime << " " << sayi << " "
                        << "ProjeNo:" << " " << sayi1 << " "
                        << kelime2 << " " << sayi2 << " " << kelime8 << " "
                        << kelime3 << " " << sayi3 << " "
                        << kelime4 << " " << kelime5 << " "
                        << kelime6 << " " << kelime7 << "\n";
                }
            }
            HakedisDosyasiOku.close();
            HakedisDosyasi.close();
            remove("Hakedis.txt");
            rename("Hak.txt", "Hakedis.txt");
        }
        if (secim1 == 5)
        {
            ifstream HakedisDosyasiOku("Hakedis.txt", ios::in);
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7, kelime8;
            string sayi, sayi1, sayi2, sayi3;

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                cout << "Kullanilan urunlerin listesi" << endl;
                cout << kelime1 << sayi1 << " " << kelime2 << sayi2 << " " << kelime8 << " " << kelime3 << sayi3 << " " << kelime4 << kelime5 << " " << kelime6 << kelime7 << endl;
            }
            HakedisDosyasiOku.close();
        }
        if (secim1 == 6)
        {
            ifstream HakedisDosyasiOku("Hakedis.txt", ios::in);
            string No;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7, kelime8;
            string sayi, sayi1, sayi2, sayi3;
            cout << "Bulmak istediginiz urunun proje numarasini giriniz:";
            cin >> No;

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen numarayla dosyadaki proje numarasý tutuyorsa ürün bilgilerine ulaþýlýr.
                if (No == sayi1)
                {
                    cout << "Urun Bilgileri" << endl;
                    cout << kelime1 << sayi1 << " "
                        << kelime2 << sayi2 << " " << kelime8 << " "
                        << kelime3 << sayi3 << " "
                        << kelime4 << kelime5 << " "
                        << kelime6 << kelime7 << "\n";
                }
            }
            HakedisDosyasiOku.close();
        }

        if (secim1 == 7)
        {
            ifstream HakedisDosyasiOku("Hakedis.txt", ios::in);
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7, kelime8;
            string sayi, sayi1, sayi2, sayi3;
            int toplam = 0;
            string donem;

            cout << "Tutarini ogrenmek istediginiz hakedis donemini giriniz:" << endl;
            cin >> donem;

            cout << "Projelerin belirtilen donem icin hakedis tutar raporu:" << endl;

            //Hakediþ dosyasýný baþtan sona kadar okumayý saðlar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen dönemle dosyadaki hakediþ dönemi tutuyorsa girilen dönemin hakediþ tutar raporu bulunur.
                if (donem == sayi)
                {
                    cout << "Toplam tutar:";
                    toplam = (stoi(sayi2) * stoi(sayi3));
                    cout << toplam<<" "<< "TL" << endl;
                }
            }
            HakedisDosyasiOku.close();
        }
    }
}