#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

const int bound = 1e9;
 
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
 
    int n = inf.readInt(1, 1000000, "n");
    inf.readSpace();
    int a = inf.readInt(-bound, bound, "a");
    inf.readEoln();

    for (int i = 0; i < n; i++) {
      int x = inf.readInt(-bound, bound, "s");
      inf.readSpace();
      int y = inf.readInt(1, bound, "t");
      inf.readEoln();
    }

    // ensuref(sum_n <= 200, "The number of cities for all tests must not exceed 200");
    inf.readEof();
}
