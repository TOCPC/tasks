#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

set<pair<int,int>> s;
 
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
 
    long long n = inf.readInt(2, 1000000, "n");
    inf.readSpace();
    long long m = inf.readInt(2, 1000000, "m");
    inf.readSpace();
    long long w = inf.readInt(0, min(100000ll, (n+2)*(m+2)-2), "w");
    inf.readEoln();
    
    int sx = inf.readInt(1, n, "sx");
    inf.readSpace();
    int sy = inf.readInt(1, m, "sy");
    inf.readEoln();

    int ex = inf.readInt(1, n, "ex");
    inf.readSpace();
    int ey = inf.readInt(1, m, "ey");
    inf.readEoln();

    s.insert({sx, sy});
    s.insert({ex, ey});

    for (int i = 0; i < w; i++) {
      int x = inf.readInt(1, n, "x");
      inf.readSpace();
      int y = inf.readInt(1, m, "y");
      inf.readEoln();

      s.insert({x, y});
    }

    ensuref(s.size() == w+2, "Walls, starting, or endpoint intersection");
    
 
    // ensuref(sum_n <= 200, "The number of cities for all tests must not exceed 200");
    inf.readEof();
}
