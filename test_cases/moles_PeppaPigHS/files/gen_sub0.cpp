#include "genlib.h"
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int bound = 1e9;

// n, a, progression
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int s0 = atoi(argv[2]);
    int progression = atoi(argv[3]);
    int t0 = 0;

    printf("%d %d\n", n, s0);

    for (int i = 0; i < n; i++) {
      int s = rnd.next(s0 - progression, min(s0 + progression, bound));
      int t = rnd.next(min(t0 + abs(s-s0), bound), min(bound, t0 + abs(s-s0) + progression));

      s0 = s;
      t0 = t;

      printf("%d %d\n", s, t);
    }

    return 0;
}
