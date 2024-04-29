// if you want to skip a particular round
#include<iostream>
using namespace std;
int main(){
    //we have to print 0 to 20 except 3 and 7
    for(int i=0;i<=20;i++){
        if(i==3 || i==7)  continue;
        cout<<i<<" ";
    }
}