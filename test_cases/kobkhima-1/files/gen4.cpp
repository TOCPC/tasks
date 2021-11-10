#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1000, x = 500, y = 500;
    cout << n << ' ' << x << ' ' << y << '\n';
    for(int i = 0; i < 500; i++){
        cout << 1 << ' ' << 0 << ' ' << 1000000000 << '\n'; 
    }
    for(int i = 500; i < 1000; i++){
        cout << 0 << ' ' << 1 << ' ' << 1000000000 << '\n'; 
    }
    return 0;
}