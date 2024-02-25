/*#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter nummber of rows: ";
    cin>>m;
    cout<<"enter nummber of coloumns: ";
    cin>>n;
    int k=1;
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<k;
        k++;
    }k=1;
    cout<<"\n";
    
   }
}*/

//without using third variable:
#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter nummber of rows: ";
    cin>>m;
    cout<<"enter nummber of coloumns: ";
    cin>>n;
   for(int i=0;i<m;i++){
    for(int j=1;j<=n;j++){
        cout<<j;
    }
    cout<<"\n";
    
   }
}