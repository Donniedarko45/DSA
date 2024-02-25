// calculator
#include <iostream>
using namespace std;
int main(){
    int n1;
    cout<<"enter first number: ";
    cin>>n1;
    char op;
    cout<<"enter operand: ";
    cin>>op;
    int n2;
    cout<<"enter second number: ";
    cin>>n2;
    switch(op){
        case '+':
        cout<<"output: "<<n1+n2<<endl;
        break;
        case '-':
        cout<<"output: "<<n1-n2<<endl;
        break;
        case '*':
        cout<<"output: "<<n1*n2<<endl;
        break;
        case '/':
        cout<<"output: "<<n1/n2<<endl;
        break;
        default:
        cout<<"invalid operation"<<endl;
    }
}
