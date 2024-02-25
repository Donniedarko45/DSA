#include <iostream>
using namespace std;
int main(){
    int x=3,y,z;
    y=x=10; //yahan right to left chalta hai pehle x=10 fir y=x hoga jisse x=y=10 ho jayegi
    z=x<10; // 10<10 ye false hai toh false hoga kyunki conditional(>,<,<=,>=,!=) true or false dete hai aur iss case me false aayega jo in computer language 0 hota hai jisse z=0 ho jayega
    cout<<x<<" "<<y<<" "<<z;