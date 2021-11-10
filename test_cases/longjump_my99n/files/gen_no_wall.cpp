#include "genlib.h"
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

// n, m, c, d
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);

    printf("%d %d %d\n", n, m, 0);

    int sx, sy, ex, ey;

    if (c == 1) {
      sx = rnd.next(0, 1)? n: 1;
      sy = rnd.next(0, 1)? m: 1;
      ex = rnd.next(1, n);
      ey = rnd.next(1, m);
    }

    if (c == 2) {
      if (rnd.next(0, 1)) {
        sx = rnd.next(0, 1)? n: 1;
        sy = rnd.next(2, m-1);
        if (d == 0) {
          ex = rnd.next(1, n);
          ey = rnd.next(1, m);
        }
        else {
          ex = rnd.next(1, n);
          ey = sy;
        }
      }
      else {
        sx = rnd.next(2, n-1);
        sy = rnd.next(0, 1)? m: 1;
        if (d == 0) {
          ex = rnd.next(1, n);
          ey = rnd.next(1, m);
        }
        else {
          ex = sx;
          ey = rnd.next(1, m);
        }
      }
    }

    if (c == 3) {
      sx = rnd.next(2, n-1);
      sy = rnd.next(2, m-1);
      ex = rnd.next(1, n);
      ey = rnd.next(1, m);
    }

    printf("%d %d\n", sx, sy);
    printf("%d %d\n", ex, ey);

    return 0;
}
