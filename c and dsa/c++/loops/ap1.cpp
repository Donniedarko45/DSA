#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number to print the series: ";
    cin >> n;
    cout<<"AP series is: ";
    for (int i = 1; i <= n; i++)
    {
        cout << 2*i - 1<<" ";
    }
}