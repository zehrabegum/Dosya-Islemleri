/***********************************************************************************************************************************
 SAKARYA �N�VERS�TES�
 B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
 B�LG�SAYAR M�HEND�SL��� B�L�M�
 PROGRAMLAMAYA G�R�� DERS�
 2019-2020 YAZ D�NEM�
 ADI:ZEHRA BEG�M  SOYADI:AKTOLGA   NUMARASI:B191210062   GRUP:1A GRUBU 1.��RET�M
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
    //�r�n.txt dosyas�.
    string UrunNo;
    string UrunAdi;
    string Birim;
    string BirimTuru;
    string BirimFiyati;
    string Markasi;
    //proje.txt dosyas�.
    string ProjeNo;
    string ProjeAdi;
    string ProjeYurutucuFirma;
    string ProjeSorumlusu;
    string ProjeKontrolu;
    //hakedi�.txt dosyas�.
    string Donem;

    //Girilen se�im numaras�na g�re d�ng�den ��k�p i�lemi yapmay� sa�lar.
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
            ofstream UrunDosyasi("�r�n.txt", ios::app);
            ifstream UrunDosyaOku("�r�n.txt", ios::in);

            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
            string sayi, sayi1, sayi2;

            cout << " UrunNo:"; cin >> UrunNo;
            cout << " UrunAdi:"; cin >> UrunAdi;
            cout << " Birim:"; cin >> Birim;
            cout << " BirimTuru:(kg,adet...)"; cin >> BirimTuru;
            cout << " BirimFiyati:"; cin >> BirimFiyati;
            cout << " Markasi:"; cin >> Markasi;

            //�r�n dosyas�n� ba�tan sona kadar okumay� sa�lar.
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
            //Yeni eklenen �r�n numaras� dosyadaki �r�n numaralar�ndan farkl�ysa �r�n� ekler.
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

            ifstream UrunDosyaOku("�r�n.txt", ios::in);
            ofstream UrunDosyasi("Urun.txt", ios::app);

            //�r�n dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
            {
                //Girilen numarayla dosyadaki �r�n numaras� tutuyorsa silme i�lemi ger�ekle�ir.
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
            remove("�r�n.txt");
            rename("Urun.txt", "�r�n.txt");
        }
        if (secim1 == 3)
        {

            string No;
            string kelime, kelime1, kelime2, kelime3, kelime4, kelime5, kelime6, kelime7;
            string sayi, sayi1, sayi2;

            cout << "Bulmak istediginiz urunun numarasini giriniz:";
            cin >> No;

            ifstream UrunDosyaOku("�r�n.txt", ios::in);

            //�r�n dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
            {
                //Girilen numarayla dosyadaki �r�n numaras� tutuyorsa �r�n bilgilerine ula��l�r.
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
            ifstream UrunDosyaOku("�r�n.txt", ios::in);

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

                //�r�n dosyas�n� ba�tan sona kadar okumay� sa�lar.
                while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
                {
                    //Se�ilen raporlama tipine g�re �r�n numaras�yla raporlamay� sa�lar.
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

                //�r�n dosyas�n� ba�tan sona kadar okumay� sa�lar.
                while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
                {
                    //Se�ilen raporlama tipine g�re �r�n birim t�r�yle raporlamay� sa�lar.
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
        ifstream UrunDosyaOku("�r�n.txt", ios::in);

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

            //Proje dosyas�n� ba�tan sona kadar okumay� sa�lar.
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
            //Yeni eklenen proje numaras� dosyadaki proje numaralar�ndan farkl�ysa ekleme yapar.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (HakedisDosyasiOku >> Kelime >> Sayi >> Kelime1 >> Sayi1 >> Kelime2 >> Sayi2 >> Kelime8 >> Kelime3 >> Sayi3 >> Kelime4 >> Kelime5 >> Kelime6 >> Kelime7)
            {
                //Girilen proje numaras�ndaki �r�n fiyatlar�n�n �denmi� mi �denmemi� mi oldu�unu bulur.
                if (Sayi1 == No)
                {
                    cout << "Odenmemis projeleri silebilirsiniz!" << endl;
                    cout << "Bu projeyi silemezsiniz urun fiyati odenmistir! Cikmak icin c'ye basin.";
                    cin >> cevap;
                }
            }
            HakedisDosyasiOku.close();


            //Proje numaras�ndaki �r�n �denmemi�se silme i�lemi ger�ekle�ir.
            if (cevap != 'c')
            {
                ifstream ProjeDosyaOku("Proje.txt", ios::in);
                ofstream ProjeDosyasi("pro.txt", ios::app);

                //Proje dosyas�n� ba�tan sona kadar okumay� sa�lar.
                while (ProjeDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime3 >> kelime4 >> kelime5 >> kelime6)
                {
                    //Girilen numarayla dosyadaki proje numaras� tutuyorsa silme i�lemi ger�ekle�ir.
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

            //Proje dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (ProjeDosyaOku >> Kelime >> Sayi >> Kelime1 >> Sayi1 >> Kelime2 >> Sayi2 >> Kelime3 >> Kelime4 >> Kelime5 >> Kelime6)
            {
                //Girilen numarayla dosyadaki proje numaras� tutuyorsa proje bilgilerine ula��l�r.
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

            //�r�n dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (UrunDosyaOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime7 >> kelime2 >> sayi2 >> Kelime3 >> kelime4 >> kelime5 >> kelime6)
            {
                //Girilen numara proje numaras�yla tutuyorsa o proje bilgilerine ve o projenin �r�n bilgilerine ula��l�r.
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
            //Proje dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (ProjeDosyaOku >> Kelime >> Sayi >> Kelime1 >> Sayi1 >> Kelime2 >> Sayi2 >> Kelime3 >> Kelime4 >> Kelime5 >> Kelime6)
            {
                //Girilen numara proje numaras�yla tutuyorsa o proje bilgilerine ve o projenin �r�n bilgilerine ula��l�r.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
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
            //Yeni eklenen hakedi� d�nemi dosyadaki hakedi� d�nemlerinden farkl�ysa hakedi�e projeyi ekler.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen d�nemle dosyadaki hakedi� d�nemi tutuyorsa silme i�lemi ger�ekle�ir.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen numarayla dosyadaki �r�n numaras� tutuyorsa g�ncelleme i�lemi ger�ekle�ir.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen numarayla dosyadaki proje numaras� tutuyorsa �r�n bilgilerine ula��l�r.
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

            //Hakedi� dosyas�n� ba�tan sona kadar okumay� sa�lar.
            while (HakedisDosyasiOku >> kelime >> sayi >> kelime1 >> sayi1 >> kelime2 >> sayi2 >> kelime8 >> kelime3 >> sayi3 >> kelime4 >> kelime5 >> kelime6 >> kelime7)
            {
                //Girilen d�nemle dosyadaki hakedi� d�nemi tutuyorsa girilen d�nemin hakedi� tutar raporu bulunur.
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