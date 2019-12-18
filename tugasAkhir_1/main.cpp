#include <iostream.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream.h>
#include <ctime>
using namespace std;

//Mendeklarasikan Variabel Global
int hrentPC, hrentPrinter, total, totalDiskon;
int jamPakaiPC, jumKertas;
char ketKertas;
time_t now = time(0);
char* dt = ctime(&now);

//Fungsi untuk mengubah posisi koordinat x dan y ( vertikal dan horizontal )
void gotoxy(unsigned int kolom, unsigned int baris)
{
	COORD posisi = {kolom, baris};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posisi);
}

//Fungsi untuk mengatur delay(jeda)
void delay(int a)
{
	for(int x=0; x<a*100; x++)
	{
		for(int y=0; y<a*100; y++)
		{
		}
	}
}

//Header Program
void headerApp()
{
	cout << "+-----------------------------------------------+" << endl;
	cout << "|*****                                     *****|" << endl;
	cout << "|             Rental PC dan Printer             |" << endl;
	cout << "|               AMANAH JAYA ABADI               |" << endl;
	cout << "|     Jl.Panjaitan RT07 RW01 Desa Nglandung     |" << endl;
	cout << "|        Kec. Geger - Kab. Madiun 63171         |" << endl;
	cout << "|*****                                     *****|" << endl;
	cout << "+-----------------------------------------------+" << endl;
}

//Fungsi untuk Pilihan menu Rental PC
void rentalPC()
{
	cout << " Masukkan jam pakai                 : ";
	cin >> jamPakaiPC;
	hrentPC = jamPakaiPC * 1500;
	
	cout << " Harga                              : " << hrentPC << endl;
}

//Fungsi untuk pilihan menu Rental Printer
void rentalPrinter()
{
	cout << " Masukkan Jumlah kertas             : ";
	cin >> jumKertas;
	cout << " Menggunakan kertas sendiri.? (y/t) : ";
	cin >> ketKertas;
	
	if(ketKertas=='y'||ketKertas=='Y')
	{
		hrentPrinter = jumKertas * 100;
	} else if(ketKertas=='t'||ketKertas=='T')
	{
		hrentPrinter = jumKertas * 200;
	}
	
	cout << " Harga                              : " << hrentPrinter << endl;
}

//Fungsi untuk pemberian diskon harga awal
void diskonHarga(int *a)
{
	if(*a<=15000){
		totalDiskon = *a;
	} else if(*a>15000){
		totalDiskon = *a * 90 / 100;
	} else if(*a>=20000){
		totalDiskon = *a * 85 / 100;
	} else if(*a>=30000){
		totalDiskon = *a * 80 / 100;
	} else if(*a>=40000){
		totalDiskon = *a * 75 / 100;
	} else if(*a>=50000){
		totalDiskon = *a * 70 / 100;
	}
}

//Fungsi untuk Mencetak Nota
void cetakNota(const char *a, int *b, int *c)
{
	getch();
	system("cls");
	cout << " Nama Pelanggan	= " << a << endl;
	cout << " Tanggal Transaksi	= " << dt << endl;
	cout << " Daftar Transaksi           : " << endl;
	
	if(*b==1)
	{
		cout << " - Jam Pakai PC             = " << jamPakaiPC << " Jam" << endl;
	} else if(*b==2) {
		cout << " - Banyak Kertas            = " << jumKertas << " Lembar" << endl;
		
		if(ketKertas=='y'||ketKertas=='Y')
		{
			cout << " - Kertas Sendiri           = Rp. 100 / Lembar " << endl;
		} else if(ketKertas=='t'||ketKertas=='T')
		{
			cout << " - Kertas Toko              = Rp. 200 / Lembar " << endl;
		}
	} else if(*b==3) {
		cout << " - Jam Pakai PC             = " << jamPakaiPC << " Jam" << endl;
		cout << " - Banyak Kertas            = " << jumKertas << " Lembar" << endl;
		
		if(ketKertas=='y'||ketKertas=='Y')
		{
			cout << " - Kertas Sendiri           = Rp. 100 / Lembar " << endl;
		} else if(ketKertas=='t'||ketKertas=='T')
		{
			cout << " - Kertas Toko              = Rp. 200 / Lembar " << endl;
		}
	}
	
	cout << endl;
	cout << " Total harga anda           = " << *c << endl;
	cout << " Total harga setelah diskon = " << totalDiskon;
}

//Fungsi Utama
int main()
{
	int menu, *pMenu;
	char namaPel[50], *nP;
	string baca;
	string baris;
	ifstream data;
	
	headerApp();
	gotoxy(0,12);
	cout << "+-----------------------------------------------+" << endl;
	gotoxy(48,11);
	cout << "|";
	gotoxy(48,8);
	cout << "|";
	gotoxy(48,9);
	cout << "|";
	gotoxy(0,8);
	cout << "|    Selamat datang di Rental PC dan Printer" << endl;
	cout << "|               Amanah Jaya Abadi" << endl;
	cout << "+-----------------------------------------------+" << endl;
	cout << "| Masukkan nama Anda : ";
	cin.getline(namaPel,50);
	nP = namaPel;
	
	//Membuat tampilan loading
	system("cls");
	gotoxy(0,10);
	cout << "=====================*********===================" << endl;
	gotoxy(0,14);
	cout << "=====================*********===================" << endl;
	for(int i=0; i<=100; i++)
	{
		delay(20);
		gotoxy(18,12);
		cout << "Loading : " << i << " % ";
	}
	
	pilmenu:
	system("cls");
	headerApp();
	gotoxy(0,18);
	cout << "+-----------------------------------------------+" << endl;
	gotoxy(48,17);
	cout << "|";
	gotoxy(48,8);
	cout << "|";
	gotoxy(48,9);
	cout << "|";
	gotoxy(0,8);
	cout << "|    Selamat datang di Rental PC dan Printer" << endl;
	cout << "|               Amanah Jaya Abadi" << endl;
	cout << "+-----------------------------------------------+" << endl;
	cout << "|                   Pilih Menu :                |" << endl;
	cout << "| [1]. Rental PC                                |" << endl;
	cout << "| [2]. Rental Printer                           |" << endl;
	cout << "| [3]. Rental PC dan Printer                    |" << endl;
	cout << "| [4]. Ketentuan                                |" << endl;
	cout << "| [5]. Keluar                                   |" << endl;
	cout << "| Masukkan Pilihan : ";
	cin >> menu;
	
	pMenu = &menu;
	
	switch(menu)
	{
	case 1:
		
		system("cls");
		headerApp();
		rentalPC();
		diskonHarga(&hrentPC);
		cout << "\n+-----------------------------------------------+" << endl;
		cout << "   Tekan sembarang tombol untuk mencetak nota";
		cetakNota(nP, pMenu, &hrentPC);
		break;
	case 2:
		system("cls");
		headerApp();
		rentalPrinter();
		diskonHarga(&hrentPrinter);
		cout << "\n+-----------------------------------------------+" << endl;
		cout << "   Tekan sembarang tombol untuk mencetak nota";
		cetakNota(nP, pMenu, &hrentPrinter);
		break;
	case 3:
		system("cls");
		headerApp();
		rentalPC();
		rentalPrinter();
		total = hrentPC + hrentPrinter;
		cout << endl;
		cout << " Harga total = " << total;
		diskonHarga(&total);
		cout << "\n+-----------------------------------------------+" << endl;
		cout << "   Tekan sembarang tombol untuk mencetak nota";
		cetakNota(nP, pMenu, &total);
		break;
	case 4:
		data.open("coba.txt"); // membuka file coba.txt
		while(!data.eof()) //membaca data secara keseluruhan
		{
			getline(data, baris);
			baca += baris + "\n";
		}
		data.close();
		system("cls");
		headerApp();
		cout << baca;
		cout << "+-----------------------------------------------+" << endl;
		break;
	case 5:
		return 0;
	default:
		gotoxy(0,18);
		cout << "|       Menu yang anda masukkan salah           |" << endl;
		cout << "|         Masukkan pilihan angka 1-5            |" << endl;
		cout << "+-----------------------------------------------+" << endl;
	}
	getch();
	goto pilmenu;//kembali ke pilmenu:

}
