#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int s[N];
long long p[N][N], dp[N][N];

long long solve(int m, int k)
{
    if(dp[m][k] != -1) return dp[m][k];
    if(m == 0) return 0;
    long long ret = 1e18;
    for(int i=0 ; i<=k && m-i-1>=0 ; i++) ret = min(ret, solve(m-i-1, k-i) + p[s[m-i-1]][s[m]]);
    return dp[m][k] = ret;
}

int main()
{
    int n, m, k;
    long long ans = 1e18;

    scanf(" %d %d %d",&n,&m,&k);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) scanf(" %lld",&p[i][j]);
    for(int i=1 ; i<=m ; i++) scanf(" %d",&s[i]);

    memset(dp, -1, sizeof dp);
    for(int i=0 ; i<=k ; i++) ans = min(ans, solve(m+1, k));

    printf("%lld\n",ans);
    return 0;
}
