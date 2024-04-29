#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
 // 1,2,4,8,16,32 
 int n;
 cout<<"enter number: ";
 cin>>n;
 cout<<"GP series is: ";
 for(int i=0;i<=n;i++){
    cout<<pow(2,i)<<" ";
 }

}