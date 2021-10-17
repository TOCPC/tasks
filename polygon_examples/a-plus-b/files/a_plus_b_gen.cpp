#include "genlib.h"
#include <bits/stdc++.h>

#define long long long

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int mode = atoi(argv[1]);

    if(mode == 0) {
        printf("%d %d\n", rnd.next((int)-1e9, (int)1e9), rnd.next((int)-1e9, (int)1e9));
    } else {
        printf("%lld %lld\n", rnd.next((long)-1e18, (long)1e18), rnd.next((long)-1e18, (long)1e18));
    }

    return 0;
}
