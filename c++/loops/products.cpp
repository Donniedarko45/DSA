// WAP TO PRINT THE PRODUCT OF A NUMBER..
#include<iostream>
using namespace std;
int main(){
    int num;
    int rem=0;
    int product=1;
    cout<<"enter a number: ";
    cin>>num;
    while(num>0){
        rem=num%10;
        product=product*rem;
        num=num/10;
    }
    cout<<"product of digits is: "<<product;
    return 0;
}