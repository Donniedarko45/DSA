#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter nummber of rows: ";
    cin>>m;
    cout<<"enter nummber of coloumns: ";
    cin>>n;
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<'*';
    }
    cout<<"\n";
    
   }
}