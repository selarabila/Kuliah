#include<iostream>
using namespace std;

void merge(int low,int mid,int up);
void mergeSort(int low,int up);
void quickSort(int arr[],int left,int right);
int a[50];

int MergeSorting(){
	int jumlahBil, i;
	cout<<"\nMasukkan Jumlah Data Array : ";
	cin>>jumlahBil;
	
	for(int i=0; i<jumlahBil; i++){
		cout<<"Bilangan Ke-"<<i+1<<" : ";
		cin>>a[i];
	}
	cout<<"\nHasil pengurutannya adalah : ";
	mergeSort(0, jumlahBil);
	
	for(i=1;i<=jumlahBil;i++){
		cout<<a[i]<<" ";
		cout<<endl;	
	}
	return 0;
}

void merge(int low,int mid,int up){
	int h,i,j,k;
	int b[50];
	h=low; //data kanan
	i=low; //data kiri
	j=mid+1;
	
	while((h<=mid)&&(j<=up)){
		if(a[h]<a[j]){
			b[i]=a[h];
			h++;
		}
		else{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>mid){
		for(k=j;k<=up;k++){
			b[i]=a[k];
			i++;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}
	for(k=low;k<=up;k++)
	a[k]=b[k];	
}

void mergeSort(int low,int up){
	int mid;
	if(low<up){
		mid=(low+up)/2;
		mergeSort(low,mid);
		mergeSort(mid+1,up);
		merge(low,mid,up);
	}
}

int QuickSorting(){
	int jumlahBil,i;
	cout<<"\nMasukkan jumlah bilangan array : ";
	cin>>jumlahBil;
	
	int Ar[jumlahBil];
	for(int i=0;i<jumlahBil;i++){
		cout<<"Bilangan ke="<<i+1<<" : ";
		cin>>Ar[i];
	}
	quickSort(Ar,0,jumlahBil-1);
	cout<<"\nHasil pengurutannya adalah : ";
	for(int i=0;i<jumlahBil;i++){
		cout<<Ar[i]<<" ";
	}
	return 0;
}

void quickSort(int arr[],int left,int right){
	int i=left,j=right;
	int tmp;
	int pivot=arr[(left+right)/2];
	
	while(i<=j){
		while(arr[i]<pivot)
		i++;
		while(arr[j]>pivot)
		j--;
		if(i<=j){
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;
			j--;
		}
	};
	if(left<j)
		quickSort(arr,left,j);
	if(i<right)
		quickSort(arr,i,right);
}

int main(){
	int menu;
	cout<<"\t======================="<<endl;
	cout<<"\tProgram Pengurutan Data"<<endl;
	cout<<"\t======================="<<endl;
	cout<<"\n1. Merge Sort"<<endl;
	cout<<"2. Quick Sort"<<endl;
	cout<<"\nPilih salah satu pengurutan : ";
	cin>>menu;
	switch(menu){
		case 1:
			MergeSorting();
			break;
		case 2:
			QuickSorting();
			break;
		default:
			cout<<"\nPilihan yang Anda masukkan salah";
			break;
	}
}
