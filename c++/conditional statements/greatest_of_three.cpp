#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter the first number";
    cin>>a;
    cout<<"enter the second number";
    cin>>b;
    cout<<"enter the third number";
    cin>>c;
    if(a>b&&a>c){
        cout<<"a is greatest";
    }
    if(c>b&&c>a){
        cout<<"c is greatest";
    }
    else{
        cout<<"b is greatest";
    }
    
}