// to print ap of 4,7,0,13......
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number n: ";
    cin>>n;
    cout<<"A.P is: ";
    for(int i=2;i<=n+1;i++){
        cout<<3*i-2<<" ";
    }
}