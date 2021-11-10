#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

int tab[1010][1010];
int vis[1010][1010];

queue<pair<int,pair<int,int>>> q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, w; cin >> n >> m >> w;
  int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

  for (int i = 0; i < w; i++) {
    int x, y; cin >> x >> y;
    tab[x][y] = 1;
  }

  q.push({0, {sx, sy}});
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    
    if (vis[t.y.x][t.y.y]) continue;
    vis[t.y.x][t.y.y] = 1;

    // cerr << t.x << ' ' << t.y.x << ' ' << t.y.y << endl;

    if (t.y == make_pair(ex, ey)) {
      cout << t.x << endl;
      return 0;
    }

    // fix y
    if (tab[t.y.x - 1][t.y.y] || t.y.x-1 == 0)
    for (int i = t.y.x+1; i <= n; i++) {
      if (tab[i][t.y.y]) break;
      q.push({t.x+1, {i, t.y.y}});
    }
    if (tab[t.y.x + 1][t.y.y] || t.y.x == n)
    for (int i = t.y.x-1; i >= 1; i--) {
      if (tab[i][t.y.y]) break;
      q.push({t.x+1, {i, t.y.y}});
    }
    // fix x
    if (tab[t.y.x][t.y.y - 1] || t.y.y-1 == 0)
    for (int i = t.y.y+1; i <= m; i++) {
      if (tab[t.y.x][i]) break;
      q.push({t.x+1, {t.y.x, i}});
    }
    if (tab[t.y.x][t.y.y + 1] || t.y.y == m)
    for (int i = t.y.y-1; i >= 1; i--) {
      if (tab[t.y.x][i]) break;
      q.push({t.x+1, {t.y.x, i}});
    }

  }
  cout << -1 << endl;
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/
