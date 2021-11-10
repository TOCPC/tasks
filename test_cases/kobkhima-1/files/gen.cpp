#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 20, x = rnd.next(1, 500), y = rnd.next(1, 500);
    cout << n << ' ' << x << ' ' << y << '\n';
    for(int i = 0; i < n; i++){
        cout << rnd.next(1, 30) << ' ' << rnd.next(1, 30) << ' ' << rnd.next(1, 100) << '\n'; 
    }
    return 0;
}