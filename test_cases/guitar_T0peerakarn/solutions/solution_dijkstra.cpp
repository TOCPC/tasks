#include <bits/stdc++.h>
using namespace std;

const int N = 305;

struct Dijkstra {
  int node;
  long long weight;
  int state;
  bool operator<(const Dijkstra &o) const { return weight > o.weight; }
};

int s[N];
long long p[N][N], dis[N][N];
bool visit[N][N];
priority_queue<Dijkstra> pq;

int main() {
  int n, m, k;

  scanf(" %d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf(" %lld", &p[i][j]);
  for (int i = 1; i <= m; i++)
    scanf(" %d", &s[i]);

  for (int i = 0; i <= m + 1; i++)
    for (int j = 0; j <= k; j++)
      dis[i][j] = 1e18;
  dis[0][k] = 0;
  pq.push({0, 0, k});
  while (!pq.empty()) {
    int nown = pq.top().node;
    long long noww = pq.top().weight;
    int nows = pq.top().state;
    pq.pop();
    if (visit[nown][nows])
      continue;
    visit[nown][nows] = true;
    if (nown == m + 1) {
      printf("%lld\n", noww);
      return 0;
    }
    for (int i = 0; i <= nows && nown + i + 1 <= m + 1; i++)
      if (dis[nown + i + 1][nows - i] > noww + p[s[nown]][s[nown + i + 1]]) {
        dis[nown + i + 1][nows - i] = noww + p[s[nown]][s[nown + i + 1]];
        pq.push({nown + i + 1, dis[nown + i + 1][nows - i], nows - i});
      }
  }
  return 0;
}
