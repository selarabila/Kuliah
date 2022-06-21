#include <iostream>
#include <conio.h>

using namespace std;

struct apa{
	int data;
	apa *next;
};

apa *head, *tail;

void push();
void view();
void pop();
void top();
void size();
void hapusStack();

int main(){
	int pilih;
	
	do{
		cout<<"\t|-------------------------|"<<endl;
		cout<<"\t|Program Stack Linked List|"<<endl;
		cout<<"\t|-------------------------|"<<endl;
		cout<<"\nMenu"<<endl;
		cout<<"\n1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Bagian Akhir Data"<<endl; 
		cout<<"4. Jumlah Stack"<<endl;
		cout<<"5. Lihat isi Stack"<<endl;
		cout<<"6. Hapus Semua Stack"<<endl;
		cout<<"\nMasukkan Pilihan : "<<endl;
		cin>>pilih;
		
		switch(pilih){
			system("cls");
			
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				top();
				break;
			case 4:
				size();
				break;
			case 5:
				view();
				break;
			case 6:
				hapusStack();
				break;
		}
	}while(pilih !=7);
}

void push(){
	int data;
	system("cls");
	cout<<"Masukan Bilangan yang Akan di Push : "<<endl;
	cin>>data;
	if(head == NULL){
		apa *baru=new apa;
		baru->data=data;
		baru->next=NULL;
		head=baru;
		tail=baru;
	}else if(head!=NULL){
		apa *baru = new apa;
		baru->data=data;
		baru->next=head;
		head=baru;
	}
	system("cls");
}

void pop(){
	system("cls");
	if(head==NULL){
		cout<<"Stack Masih Kosong!"<<endl;
	}else if(head==tail){
		cout<<"Elemen Stacknya : "<<head->data<<endl;
		cout<<"Elemen Telah di pop : "<<endl;
		delete head;
		head=NULL;
		tail=NULL;
	}else{
		apa *hapus=new apa;
		hapus=head;
		head=head->next;
		cout<<"Elemen Stacknya : "<<hapus->data<<endl;
		cout<<"Elemen Telah di Pop"<<endl;
		delete hapus;
	}
	getch();
	system("cls");
}

void top(){
	apa *cek=new apa;
	cek=head;
	system("cls");
	if(cek==NULL){
		cout<<"Stack Tidak Ada"<<endl;
	}else{
		cout<<"Elemen yang Berada Paling Atas Adalah : "<<cek->data<<endl;
	}
	getch();
	system("cls");
}

void size(){
	apa *jumlah = new apa;
	jumlah=head;
	int counter=0;
	system("cls");
	if(jumlah==NULL){
		cout<<"Jumlah Elemen Stack : "<<counter<<endl;
	}else{
		while(jumlah!=NULL){
			counter++;
			jumlah=jumlah->next;
		}
		cout<<"Jumlah Elemen Stack : "<<counter<<endl;
	}
	getch();
	system("cls");
}

void hapusStack(){
	apa *hapus= new apa;
	system("cls");
	if(head==NULL){
		cout<<"Stack Tidak Ada"<<endl;
	}else{
		while(head!=NULL){
			hapus=head;
			head=head->next;
			delete hapus;
		}
		cout<<"Stack Telah dihapus"<<endl;
	}
	getch();
	system("cls");
}

void view(){
	apa *cek= new apa;
	cek=head;
	system("cls");
	if(cek==NULL){
		cout<<"Stack Tidak Ada"<<endl;
	}else{
		cout<<"Isi Stack : "<<endl;
		while(cek!=NULL){
			cout<<cek->data<<endl;
			cek=cek->next;
		}
	}
	getch();
	system("cls");
}
