#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char* argv[])
{
    registerGen(argc,argv,1);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%d",rnd.next(1,n));
    }
    printf("\n");
}
