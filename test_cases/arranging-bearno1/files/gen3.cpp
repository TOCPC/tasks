#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char* argv[])
{
    registerGen(argc,argv,1);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int rat = atoi(argv[3]);
    printf("%d %d\n",n,k);
    for(int i=1;i<=n-5;i++)
    {
        if(i>1)printf(" ");
        if(rnd.next(1,n)<n/rat)
        {
            printf("%d",rnd.next(1,n-1));
        }
        else printf("1");
    }
    printf(" %d %d %d %d 1",n,n,n,n);
    printf("\n");
}
