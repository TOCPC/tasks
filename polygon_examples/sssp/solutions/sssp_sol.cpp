#include <bits/stdc++.h>

#define long long long
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 5;

int n, m;
long dp[N];
vector<pii> g[N];
priority_queue<pii, vector<pii>, greater<pii> > Q;

int main() {
    fill_n(dp, N, 1e18);

    scanf("%d %d", &n, &m);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    Q.emplace(dp[1] = 0, 1);
    while(!Q.empty()) {
        pii u = Q.top(); Q.pop();
        if(dp[u.y] != u.x) continue;
        for(pii v : g[u.y])
            if(u.x + v.y < dp[v.x])
                Q.emplace(dp[v.x] = u.x + v.y, v.x);
    }
    for(int i = 1; i <= n; i++) printf("%lld ", dp[i]);
    printf("\n");

    return 0;
}
