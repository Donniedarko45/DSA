// if-else statement ko ekk line me likha btata hai syntax:- expression1?expression 2:expression 3;
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    // (condition)? if true: if false;
    (n%2==0)?cout<<"even number":cout<<"odd number";
}