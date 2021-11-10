#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

int n, m, k, x[1000005], ty[1000005];
int dp[1000005][3], ls[1000005][3], mx[1000005][2], mn[1000005][2];
vector<pair<int, pair<int, int>>> v[1000005];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    if (ty[x[i]] == 0) {
      mx[x[i]][0] = i;
      mx[x[i]][1] = i;
      mn[x[i]][0] = i;
      mn[x[i]][1] = i;
    } else {
      mx[x[i]][1] = mx[x[i]][0];
      mx[x[i]][0] = i;
      if (ty[x[i]] == 1)
        mn[x[i]][1] = i;
    }
    ty[x[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (ty[i] == 0)
      continue;
    else if (ty[i] == 1)
      v[mx[i][0]].pb({mn[i][0] - 1, {1, 0}});
    else {
      v[mx[i][0]].pb({mn[i][0] - 1, {ty[i], 0}});
      v[mx[i][1]].pb({mn[i][0] - 1, {ty[i] - 1, 1}});
      v[mx[i][0]].pb({mn[i][1] - 1, {ty[i] - 1, 1}});
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j].S.S == 1) {
        for (int cc = 1; cc < 3; cc++) {
          if (dp[i][cc] < dp[v[i][j].F][cc - 1] + v[i][j].S.F &&
              ls[v[i][j].F][cc - 1] != x[i]) {
            dp[i][cc] = dp[v[i][j].F][cc - 1] + v[i][j].S.F;
            ls[i][cc] = x[i];
          }
        }
      } else {
        for (int cc = 0; cc < 3; cc++) {
          if (dp[i][cc] < dp[v[i][j].F][cc] + v[i][j].S.F) {
            dp[i][cc] = dp[v[i][j].F][cc] + v[i][j].S.F;
          }
        }
      }
    }
    for (int cc = 0; cc < 3; cc++) {
      if (dp[i][cc] < dp[i - 1][cc]) {
        dp[i][cc] = dp[i - 1][cc];
        ls[i][cc] = ls[i - 1][cc];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= k; i++)
    ans = max(ans, dp[n][i]);
  printf("%d", n - ans);
}
