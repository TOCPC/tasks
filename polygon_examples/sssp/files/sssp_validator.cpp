#include "testlib.h"
#include <bits/stdc++.h>

#define long long long

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, (int)1e5, "n");
    inf.readSpace();
    int m = inf.readInt(n - 1, (int)min((long)2e5, 1ll * n * (n - 1) / 2ll), "m");
    inf.readEoln();
    for(int i = 0; i < m; i++) {
        int a = inf.readInt(1, n, "a");
        inf.readSpace();
        int b = inf.readInt(1, n, "b");
        inf.readSpace();
        int c = inf.readInt(1, (int)1e9, "c");
        inf.readEoln();
        ensure(a != b);
    }
    inf.readEof();
    
    return 0;
}
