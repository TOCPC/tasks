#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, w; cin >> n >> m >> w;
  int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

  if (sx != 1 and sx != n and sy != 1 and sy != m) cout << -1;
  else if (sx == ex and (sy == 1 or sy == m)) cout << 1;
  else if (sy == ey and (sx == 1 or sx == n)) cout << 1;
  else if (sx == 1 and (sy == 1 or sy == m)) cout << 2;
  else if (sx == n and (sy == 1 or sy == m)) cout << 2;
  else cout << -1;

  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/
