#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
int cc[1000005];
int main(int argc, char* argv[])
{
    registerGen(argc,argv,1);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++)
    {
        while(cc[k=rnd.next(1,n)]==2);
        cc[k]++;
        if(i>1)printf(" ");
        printf("%d",k);
    }
    printf("\n");
}
