#include<iostream>
using namespace std;
int main(){
    int rev=0,num,rem=0;
    cout<<"enter a number which you want to reverse: ";
    cin>>num;
    while(num>0){
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    cout<<"reverse of a number is: "<<rev;
    return 0;
}