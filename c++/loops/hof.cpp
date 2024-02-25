// WAP to find highest factor of a number "n" other than n
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter a number: ";
    cin >> n;
    int i, temp;
    if (n % 2 == 0)
    {
        cout << "highest factor is: " << n / 2;
    }
    else
    {
        for (int i = 1; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                temp = i;
            }
        }
        cout << "highest factor is: " << temp;
    }
}