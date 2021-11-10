#include "genlib.h"
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int tab[1010][1010];
int vis[1010][1010];

queue<pair<int,pair<int,int>>> q;
vector<pair<int,int>> endpoints;

pair<int,int> findendpoint (int n, int m, int w, int sx, int sy, vector<pair<int,int>> input_wall, int distance_needed = -1) {
  endpoints.clear();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      tab[i][j] = 0;
      vis[i][j] = 0;
    }
  }

  for (int i = 0; i < input_wall.size(); i++) {
    int x = input_wall[i].x;
    int y = input_wall[i].y;
    tab[x][y] = 1;
  }

  q.push({0, {sx, sy}});
  int count = 0;
  int mx = 0;
  int distance = -1;
  
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    
    if (vis[t.y.x][t.y.y]) continue;
    vis[t.y.x][t.y.y] = 1;
    count += 1;
    mx = max(mx, t.x);

    if (t.x >= distance_needed) {
      endpoints.push_back(t.y);
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
  if (distance_needed == -1) {
    cerr << "maximum distance: " << mx << endl;
    return {mx, 0};
  }
  assert(endpoints.size() != 0);
  cerr << "nodes reached: " << count << " over " << n*m-w << endl;
  return endpoints[rnd.next(0, (int)endpoints.size()-1)];
}

set<pair<int,int>> wall;

// n, m, w, sx, sy, far_ratio
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int w = atoi(argv[3]);
    int sx = atoi(argv[4]);
    int sy = atoi(argv[5]);
    double far_ratio = atof(argv[6]);

    printf("%d %d %d\n", n, m, w);

    pair<int,int> start = {sx, sy};

    while (wall.size() < w) {
        pair<int,int> wallcandidate = {rnd.next(1, n), rnd.next(1, m)};
        if (wallcandidate == start) continue;
        wall.insert(wallcandidate);
    }
    vector<pair<int,int>> wall_vector(wall.begin(), wall.end());

    int max_distance = findendpoint(n, m, w, start.x, start.y, wall_vector).x;
    cerr << "the distance of endpoint wanted is " << (int)(max_distance*far_ratio) << endl;
    pair<int,int> end = findendpoint(n, m, w, start.x, start.y, wall_vector, (int)(max_distance*far_ratio));
    cerr << "the endpoint is " << end.x << ' ' << end.y << endl;

    printf("%d %d\n", start.x, start.y);
    printf("%d %d\n", end.x, end.y);

    for (int i = 0; i < w; i++) {
      printf("%d %d\n", wall_vector[i].x, wall_vector[i].y);
    }

    return 0;
}
