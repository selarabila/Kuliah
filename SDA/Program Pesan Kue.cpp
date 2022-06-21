#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

int jmlData = 7;

struct cake {
	int id;
	string nama;
	int harga;
};

cake kue[7];

void databaseKue() {
	//isi id
	for (int i=0; i<jmlData; i++) {
		kue[jmlData].id = jmlData;
	}
	
	//isi nama
	kue[0].nama = "BLACK FOREST    ";
	kue[1].nama = "CHEESE CAKE     ";
	kue[2].nama = "PAVLOVA         ";
	kue[3].nama = "RED VELVET      ";
	kue[4].nama = "TIRAMISSU       ";
	kue[5].nama = "TRES LECHES CAKE";
	kue[6].nama = "VICTORIA SPONGE ";
	
	//isi harga
	kue[0].harga = 413000;
	kue[1].harga = 330000;
	kue[2].harga = 300000;
	kue[3].harga = 315000;
	kue[4].harga = 468000;
	kue[5].harga = 483000;
	kue[6].harga = 433000;	
}

//fungsi & prosedur
void login();
void daftarKueNama();
void daftarKueHarga();
void menu();
void murah();
void mahal();
void beli();
void resi();
void keluar();

//variable
char nama[30];
int save = 0;

int main() {
	databaseKue();
	login();
}

void login() {
	cout<<"\t======================================="<<endl;
	cout<<"\t=        PROGRAM PEMBELIAN KUE        ="<<endl;
	cout<<"\t======================================="<<endl<<endl<<endl;
	
	cout<<"Nama Pelanggan : "; gets(nama);
	system("cls");
	menu();
}

void daftarKueNama() {
	cout<<"========================================"<<endl;
	cout<<"=                                      ="<<endl;
	cout<<"=              DAFTAR KUE              ="<<endl;
	cout<<"=                                      ="<<endl;
	cout<<"========================================"<<endl;
	
	for(int i=0; i<jmlData; i++) {
		cout<<" "<<i+1<<". "<<kue[i].nama<<"\t\t"<<kue[i].harga<<endl;
	}
	cout<<"========================================"<<endl<<endl;
}

void daftarKueHarga() {
	int swap;
	string namaKue;
	cout<<"========================================"<<endl;
	cout<<"=                                      ="<<endl;
	cout<<"=              DAFTAR KUE              ="<<endl;
	cout<<"=                                      ="<<endl;
	cout<<"========================================"<<endl;
	
	for(int i=0; i<jmlData-1; i++) {
		if (kue[i].harga > kue[i+1].harga) {
			//swap harga
			swap = kue[i].harga;
			kue[i].harga = kue[i+1].harga;
			kue[i+1].harga = swap;
			
			//swap nama kue
			namaKue = kue[i].nama;
			kue[i].nama = kue[i+1].nama;
			kue[i+1].nama = namaKue;
		}
	}
	
	for(int i=0; i<jmlData; i++) {
		cout<<" "<<i+1<<". "<<kue[i].nama<<"\t\t"<<kue[i].harga<<endl;
	}
	
	cout<<"========================================"<<endl<<endl;
}

void menu(){
	int pilih;
	do {
		cout<<endl;
		cout<<"\t******************"<<endl;
		cout<<"\t*      MENU      *"<<endl;
		cout<<"\t******************"<<endl;
		cout<<"1. Urutkan"<<endl;
		cout<<"2. Cari"<<endl;
		cout<<"3. Beli"<<endl;
		cout<<"4. Keluar"<<endl;
		cout<<endl;
		cout<<"Silahkan Masukkan Menu Pilihan Anda : "; cin>>pilih;
		system("cls");
		
		switch(pilih) {
			case 1 :
				int pilihUrut;
				cout<<"\n1. Urutkan by Nama"<<endl;
				cout<<"2. Urutkan by Harga"<<endl<<endl;
				cout<<"Silahkan Pilih menu pengurutannya [1-2] : "; cin>>pilihUrut;
				if (pilihUrut == 1) {
					system("cls");
					daftarKueNama();
					system("pause");
					system("cls");
				} else {
					system("cls");
					daftarKueHarga();
					system("pause");
					system("cls");
				}
				break;
			case 2 :
				int pilihCari;
				cout<<"\n\n1. Cari harga termurah"<<endl;
				cout<<"2. Cari harga termahal"<<endl<<endl;
				cout<<"Silahkan Pilih menu pencariannya [1-2] :  "; cin>>pilihCari; cout<<endl;
				if (pilihCari == 1) {
					murah();
				} else {
					mahal();
				}
				break;
			case 3:
				system("cls");
				beli();
				break;
			case 4 :
				keluar();
				break;
			default :
				cout<<"Maaf masukan angka 1-4"<<endl;
				break;
		}
	} while (pilih != 4);
}

void murah() {
	int idMin, min = kue[0].harga;
	
	for (int i=1; i<7; i++) {
		if (kue[i].harga < min) {
			min = kue[i].harga;
			idMin = i;
		}
	}
	cout<<"Kue termurah adalah "<<kue[idMin].nama<<"dengan harga Rp. "<<kue[idMin].harga<<endl<<endl;
	getch();
	system("cls");
}

void mahal() {
	int idMax, max = kue[0].harga;
	
	for (int i=1; i<7; i++) {
		if (kue[i].harga > max) {
			max = kue[i].harga;
			idMax = i;
		}
	}
	cout<<"Kue termahal adalah "<<kue[idMax].nama<<" dengan harga Rp. "<<kue[idMax].harga<<endl<<endl;
	getch();
	system("cls");
}

void beli(){
	int id, pesan;
	char lagi;
	
	daftarKueNama();
	do {
		cout<<"Masukan nomor (1-7) : "; cin>>id;
		cout<<"Masukan jumlah pesanan : "; cin>>pesan; cout<<endl<<endl;
		
		save = save + (kue[id-1].harga * pesan);
		
		cout<<"Anda memesan "<<kue[id-1].nama<<"dengan jumlah "<<pesan<<endl;
		cout<<"Total : Rp. "<<save<<endl<<endl;
		cout<<"Apakah akan memesan lagi(y/n)? "; cin>>lagi;
		cout<<endl<<endl<<endl;
		
		if(lagi == 'N' || lagi == 'n') {
			system("cls");
			resi();
		} else {
			system("cls");
			daftarKueNama();
		}
	} while (lagi != 'N' || lagi != 'n');
}

void resi() {
	char lagi;
	int uang, kembalian;
	
	cout<<"========================================"<<endl;
	cout<<"         Resi Pembelian Kue"<<endl;
	cout<<"========================================"<<endl;
	cout<<"Nama Pembeli\t\t: "<<nama<<endl;
	cout<<"Total Harga\t\t: "<<save<<endl;
	cout<<"========================================"<<endl;
	cout<<"Total Bayar\t\t: Rp. ";cin>>uang;
	
	kembalian=uang-save;
	
	cout<<"Kembalian\t\t: Rp. "<<kembalian<<endl;
	cout<<"========================================"<<endl<<endl;
	cout<<"Pesan Kue Kembali [y/n]? : ";cin>>lagi;
	if(lagi =='Y'||lagi =='y'){
		system ("cls");
		menu();	
	} else {
		system ("cls");
		keluar();	
	}
}

void keluar() {
	system("cls");
	cout<<"\n\n\t=============================="<<endl;
	cout<<"\t=        TERIMA KASIH        ="<<endl;
	cout<<"\t=============================="<<endl<<endl<<endl;
	getch();
	exit (0);
}
