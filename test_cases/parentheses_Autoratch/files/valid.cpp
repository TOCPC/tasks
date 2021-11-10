#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc,char *argv[])
{
    registerValidation(argc,argv);
    int n = inf.readInt(1,100000,"N");
    inf.readSpace();
    int u = inf.readInt(1,n,"U");
    inf.readSpace();
    int v = inf.readInt(1,n,"V");
    inf.readEoln();
    ensuref(u!=v,"same U and V");
    for(int i = 0;i < n-1;i++)
    {
        int a = inf.readInt(1,n,"a");
        inf.readSpace();
        int b = inf.readInt(1,n,"b");
        inf.readEoln();
        ensuref(a!=b,"self-cycle");
    }
    string s = inf.readString();
    ensuref(s[u-1]=='(' and s[v-1]==')',"no sol");
    inf.readEof();
    return 0;
}
