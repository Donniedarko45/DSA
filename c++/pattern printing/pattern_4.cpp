/*  printing...
****
***
**
*  */

#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "enter number of rows: ";
    cin >> m;
    cout << "enter number of coloumns: ";
    cin >> n;
    for (int i = 1; i <= m; i++)
    {
        char k = '*';
        for (int j = n; j>=1; j--)
        {
            cout << k;
        }
        n--;
        cout << "\n";
    }
}