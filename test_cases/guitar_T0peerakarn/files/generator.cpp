#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int MAX_P = 1000000000;

int s[N];
long long p[N][N];

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = atoi(argv[3]);

    for(int i=1 ; i<=n ; i++)
    {
        p[i][i] = 0;
        for(int j=i+1 ; j<=n ; j++) p[i][j] = p[j][i] = rnd.next(1, MAX_P);
    }
    
    for(int i=1 ; i<=m ; i++) s[i] = rnd.next(1, n);

    cout << n << ' ' << m << ' ' << k << endl;

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if(j != 1) cout << ' ';
            cout << p[i][j];
        }
        cout << endl;
    }

    for(int i=1 ; i<=m ; i++)
    {
        if(i != 1) cout << ' ';
        cout << s[i];
    }
    cout << endl;
    return 0;
}
