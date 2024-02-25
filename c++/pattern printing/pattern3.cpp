/*printing...
abc
abc
abc*/

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
        int k = 97;
        for (int j = 1; j <= n; j++)
        {
            cout << (char)(k);
            k += 1;
        }
        cout << "\n";
    }
}