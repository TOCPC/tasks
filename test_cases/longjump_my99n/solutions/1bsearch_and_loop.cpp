#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) x.begin(), x.end()

map<int, vector<int>> wallx, wally;
map<pair<int,int>, int> vis;
queue<pair<int,pair<int,int>>> q;

bool iswall(int x, int y) {
  if (wallx[x].size() == 0) return false;
  return *lower_bound(all(wallx[x]), y) == y;
}

bool check (pair<int,int> f, pair<int,int> t) {
  if (f.y == t.y) {
    for (int i = 0; i < wally[f.y].size(); i++) {
      bool a = (wally[f.y][i] < f.x);
      bool b = (wally[f.y][i] < t.x);
      bool c = (wally[f.y][i] > f.x);
      bool d = (wally[f.y][i] > t.x);
      if (a != b or c != d) return false;
    }
    return true;
  }
  if (f.x == t.x) {
    for (int i = 0; i < wallx[f.x].size(); i++) {
      bool a = (wallx[f.x][i] < f.y);
      bool b = (wallx[f.x][i] < t.y);
      bool c = (wallx[f.x][i] > f.y);
      bool d = (wallx[f.x][i] > t.y);
      if (a != b or c != d) return false;
    }
    return true;
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, w; cin >> n >> m >> w;
  int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

  for (int i = 0; i < w; i++) {
    int x, y; cin >> x >> y;
    wallx[x].push_back(y);
    wally[y].push_back(x);
  }

  q.push({0, {ex, ey}});
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    if (vis[t.y]) continue;
    vis[t.y] = 1;

    // cerr << t.x << ' ' << t.y.x << ' ' << t.y.y << endl;

    if (t.y == make_pair(sx, sy)) {
      cout << t.x << endl;
      return 0;
    }

    int l,r;

    // x axis, fix y
    l = t.y.x+1, r = n;
    while (l < r) {
      int mid = (l+r+1)/2;
      if (check(t.y, {mid, t.y.y})) l = mid;
      else r = mid-1;
    }
    if (l == r and !iswall(l, t.y.y)) q.push({t.x+1, {l, t.y.y}});

    l = 1, r = t.y.x-1;
    while (l < r) {
      int mid = (l+r)/2;
      if (check(t.y, {mid, t.y.y})) r = mid;
      else l = mid+1;
    }
    if (l == r and !iswall(l, t.y.y)) q.push({t.x+1, {l, t.y.y}});

    // y axis, fix x
    l = t.y.y+1, r = m;
    while (l < r) {
      int mid = (l+r+1)/2;
      if (check(t.y, {t.y.x, mid})) l = mid;
      else r = mid-1;
    }
    if (l == r and !iswall(t.y.x, l)) q.push({t.x+1, {t.y.x, l}});

    l = 1, r = t.y.y-1;
    while (l < r) {
      int mid = (l+r)/2;
      if (check(t.y, {t.y.x, mid})) r = mid;
      else l = mid+1;
    }
    if (l == r and !iswall(t.y.x, l)) q.push({t.x+1, {t.y.x, l}});

  }
  cout << -1 << endl;
  return 0;
}
