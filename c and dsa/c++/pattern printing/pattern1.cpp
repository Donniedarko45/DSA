/*printing...
1111
2222
3333*/

#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter number of rows: ";
    cin>>m;
    cout<<"enter number of coloumns: ";
    cin>>n;
    int k=1;
   for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        cout<<(int)(k);
    }
    k+=1;
    cout<<"\n";
    
   }
}