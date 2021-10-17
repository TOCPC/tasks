#include <bits/stdc++.h>

#define long long long
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 205;

int n, m;
long dp[N][N];

int main() {
    fill_n(dp[0], N * N, 1e18);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        dp[a][b] = dp[b][a] = c;
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for(int i = 1; i <= n; i++) printf("%lld ", dp[1][i]);
    printf("\n");

    return 0;
}
