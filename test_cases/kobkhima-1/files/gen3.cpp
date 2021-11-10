#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1000, x = 500, y = 0;
    int maxx = rnd.next(1, 500), maxy = rnd.next(1, 500);
    cout << n << ' ' << x << ' ' << y << '\n';
    for(int i = 0; i < n; i++){
        cout << rnd.next(1, maxx) << ' ' << rnd.next(1, maxy) << ' ' << rnd.next(1, 1000000000) << '\n'; 
    }
    return 0;
}