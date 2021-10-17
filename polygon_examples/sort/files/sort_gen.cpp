#include "genlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    printf("%d\n", n);
    for(int i = 0; i < n; i++) {
        printf("%d", rnd.next(0, (int)1e9));
        if(i != n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
