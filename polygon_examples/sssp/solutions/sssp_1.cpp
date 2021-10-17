#include <bits/stdc++.h>

#define long long long
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 5;

int n, m;
long dp[N];
bool vis[N];
vector<pii> g[N];

void dfs(int u, int p, long d) {
    dp[u] = d;
    for(pii v : g[u]) if(!vis[v.x]) {
        vis[v.x] = true;
        dfs(v.x, u, d + v.y);
    }
}

int main() {
    fill_n(dp, N, 1e18);

    scanf("%d %d", &n, &m);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    vis[1] = true;
    dfs(1, 0, 0); 
    for(int i = 1; i <= n; i++) printf("%lld ", dp[i]);
    printf("\n");

    return 0;
}
