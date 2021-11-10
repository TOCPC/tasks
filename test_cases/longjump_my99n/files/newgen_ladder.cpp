#include "genlib.h"
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) x.begin(), x.end()

set<pair<int,int>> wall;

map<int, vector<int>> wallx, wally;
map<pair<int,int>, int> vis;
queue<pair<int,pair<int,int>>> q;

bool iswall(int x, int y) {
  if (wallx[x].size() == 0) return false;
  return *lower_bound(all(wallx[x]), y) == y;
}

bool check (pair<int,int> f, pair<int,int> t) {
  if (f.y == t.y) {
    return upper_bound(all(wally[f.y]), f.x) == upper_bound(all(wally[f.y]), t.x) and lower_bound(all(wally[f.y]), f.x) == lower_bound(all(wally[f.y]), t.x);
  }
  if (f.x == t.x) {
    return upper_bound(all(wallx[f.x]), f.y) == upper_bound(all(wallx[f.x]), t.y) and lower_bound(all(wallx[f.x]), f.y) == lower_bound(all(wallx[f.x]), t.y);
  }
  return 0;
}

vector<pair<int,int>> endpoints;

pair<int,int> findstartpoint (int n, int m, int w, int ex, int ey, vector<pair<int,int>> input_wall, int distance_needed = -1) {
  endpoints.clear();
  vis.clear();
  wallx.clear();
  wally.clear();

  for (int i = 0; i < input_wall.size(); i++) {
    int x = input_wall[i].x;
    int y = input_wall[i].y;
    wallx[x].push_back(y);
    wally[y].push_back(x);
  }

  q.push({0, {ex, ey}});
  pair<int,int> ret = {-1, -1};
  int count = 0; 
  int mx = 0;
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    if (vis[t.y]) continue;
    vis[t.y] = 1;
    count += 1;
    mx = max(mx, t.x);

    if (t.x == distance_needed) {
      ret = t.y;
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
  if (distance_needed != -1) return ret;
  return {count, mx};
}

// n, m, w, sx, sy, far_ratio
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int w = atoi(argv[3]);
    int delta = atoi(argv[4]);
    int ex = atoi(argv[5]);
    int ey = atoi(argv[6]);

    printf("%d %d %d\n", n, m, w);

    if (ex == 1) ex++;
    if (ey == 1) ey++;

    pair<int,int> end = {ex, ey};
    pair<int,int> now = end;

    int d = 1;
    while (wall.size() < w) {
      d ^= 1;
      if (d) {
        int nw = now.y;
        while (nw == now.y) nw = rnd.next(min(now.y+1, m-2), min(now.y+delta, m-1));
        if (now.y < nw) wall.insert({now.x, nw+1});
        else            wall.insert({now.x, nw-1});
        now = {now.x, nw};
      }
      else {
        int nw = now.x;
        while (nw == now.x) nw = rnd.next(min(now.x+1, n-2), min(now.x+delta, n-1));
        if (now.x < nw) wall.insert({nw+1, now.y});
        else            wall.insert({nw-1, now.y});
        now = {nw, now.y};
      }
      
      cerr << now.x << ' ' << now.y << endl;

    }

    vector<pair<int,int>> wall_vector(wall.begin(), wall.end());

    cerr << "done" << endl;

    pair<int,int> res = findstartpoint(n, m, w, ex, ey, wall_vector);
    cerr << "cover total " << res.x << " of " << n+m+4*w << " with max depth " << res.y << endl;

    pair<int,int> start = findstartpoint(n, m, w, ex, ey, wall_vector, res.y);

    printf("%d %d\n", start.x, start.y);
    printf("%d %d\n", end.x, end.y);

    for (int i = 0; i < w; i++) {
      printf("%d %d\n", wall_vector[i].x, wall_vector[i].y);
    }

    return 0;
}
