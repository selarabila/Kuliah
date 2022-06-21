#include<iostream>
using namespace std;

int data[10] = {3,0,1,8,7,2,5,4,9,6};
int minimum, min_id;
bool status;
int temp;
int Iteratif(){
	for (int i=0;i<9;i++) {
		minimum=data[i];
		for(int j=i+1;j<10;j++) {
			if(data[j]<minimum){
				minimum=data[j];
				min_id=j;
				status=true;
			}
		}
		if(status==true){
			temp=data[i];
			data[i]=data[min_id];
			data[min_id]=temp;
			status=false;
		}
		cout<<"urutan ke- "<<i<< " adalah ";
		for(int k=0;k<10;k++){
			cout<<data[k]<<" ";
		}
		cout<< endl;
	}
	cout<<"\nCreated by Sella Rabila"<<endl;
}

int minIndex(int a[],int i,int j){
    if(i==j)
        return i;
    int k=minIndex(a,i+1,j);
    return(a[i]<a[k])?i:k;
}

void Rekursif(int a[],int n,int index=0){
    if(index==n)
       return;
    int k=minIndex(a,index,n-1);
    if(k!=index)
       swap(a[k],a[index]);
    Rekursif(a,n,index+1);
}

int Rekursif(){
    int arr[]={3,0,1,8,7,2,5,4,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    Rekursif(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
	    cout<<endl;
    	return 0;
}

int main(){
	int menu;
	cout<<"\t============================="<<endl;
	cout<<"\tProgram Binary Insertion Sort"<<endl;
	cout<<"\t============================="<<endl;
	cout<<"\n1. Rekursif "<<endl;
	cout<<"2. Iteratif "<<endl;
	cout<<"\nPilih Jenis Pengurutan : ";
	cin>>menu;
	switch(menu){
		case 1:
			Rekursif();
			break;
		case 2:
			Iteratif();
			break;
		default:
			break;
	}
}
