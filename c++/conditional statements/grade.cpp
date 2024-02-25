// else-if statement
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter marks: ";
    cin >> n;
    if (n >= 81 and n <= 100)
    {
        cout << "very good";
    }
    else if(n >= 61)
    {
        cout << "good";
    }
    else if(n >= 41)
    {
        cout << "average";
    }
    else if(n <= 40)
    {
        cout << "fail";
    }
}