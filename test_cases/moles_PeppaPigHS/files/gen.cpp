#include "genlib.h"
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int bound = 1e9;

vector<pair<int,int>> v;

// n, a, progression
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int s0 = atoi(argv[2]);
    int progression = atoi(argv[3]);
    double ansratio = atof(argv[4]);
    int t0 = 0;

    printf("%d %d\n", n, s0);

    for (int i = 0; i < n; i++) {
      int s = s0;
      while (abs(s-s0) <= 1) s = rnd.next(max(-bound, s0 - progression), min(s0 + progression, bound));
      int t;
      if (rnd.next(1, 10000) < 10000*ansratio)
        t = rnd.next(min(t0 + abs(s-s0), bound), min(t0 + abs(s-s0) + progression, bound));
      else 
        t = rnd.next(min(t0 + 1, bound), min(t0 + abs(s-s0), bound));

      s0 = s;
      t0 = t;

      v.push_back({s, t});
    }

    shuffle(v.begin(), v.end());
    for (auto [s, t] : v) printf("%d %d\n", s, t);

    return 0;
}
