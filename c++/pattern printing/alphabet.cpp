#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter number of rows: ";
    cin>>m;
    cout<<"enter number of coloumns: ";
    cin>>n;
   for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        cout<<(char)(j+64);
    }
    cout<<"\n";
    
   }
}