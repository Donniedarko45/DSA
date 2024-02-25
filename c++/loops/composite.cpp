#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number to check whether it is composite or not: ";
    cin>>n;
    bool flag=true;  // if true then number is prime

    for(int i=2;i<=n/2;i++){
      if(n%i==0){
        flag=false;  //false-->composite
        break;
      }
    }
    if(n==1)  cout<<"neither prime nor composite";
    else if(flag==true){
        cout<<n<<" is prime";
    }
    else{
        cout<<n<<" is composite";
    }
}