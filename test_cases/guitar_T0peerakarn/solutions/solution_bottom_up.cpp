#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int s[N];
long long p[N][N], dp[N][N];

int main()
{
    int n, m, k;
    long long ans = 1e18;

    scanf(" %d %d %d",&n,&m,&k);
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) scanf(" %lld",&p[i][j]);
    for(int i=1 ; i<=m ; i++) scanf(" %d",&s[i]);

    for(int i=0 ; i<=m+1 ; i++) for(int j=0 ; j<=k ; j++) dp[i][j] = 1e18;
    dp[0][0] = 0;
    for(int i=0 ; i<=m ; i++) for(int j=0 ; j<=k ; j++) for(int l=0 ; j+l<=k && i+l+1<=m+1 ; l++) dp[i+l+1][j+l] = min(dp[i+l+1][j+l], dp[i][j] + p[s[i]][s[i+l+1]]);
    for(int i=0 ; i<=k ; i++) ans = min(ans, dp[m+1][i]);

    printf("%lld\n",ans);
    return 0;
}
