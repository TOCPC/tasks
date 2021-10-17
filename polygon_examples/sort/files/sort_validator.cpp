#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, (int)1e5, "n");
    inf.readEoln();
    for(int i = 0; i < n; i++) {
        int a = inf.readInt(0, (int)1e9, "a");
        if(i != n - 1) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
    
    return 0;
}
