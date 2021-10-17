#include "testlib.h"

#define long long long

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    long a = inf.readLong((long)-1e18, (long)1e18, "a");
    inf.readSpace();
    long b = inf.readLong((long)-1e18, (long)1e18, "b");
    inf.readEoln();
    inf.readEof();

    return 0;
}
