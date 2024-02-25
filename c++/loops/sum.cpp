// WAP TO SUM THE DIGITS OF A NUMBER..
#include<iostream>
using namespace std;
int main(){
    int num;
    int rem=0;
    int sum=0;
    cout<<"enter a number: ";
    cin>>num;
    while(num>0){
        rem=num%10;
        sum=sum+rem;
        num=num/10;
    }
    cout<<"sum of digits is: "<<sum;
    return 0;
}