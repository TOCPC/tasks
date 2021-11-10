#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int n,u,v;
vector<int> adj[N];
string s;
int val[N],sum[N][N],mn[N][N];
long long ans;

void dfs(int u,int p,int k)
{
    sum[k][u] = sum[k][p]+val[u];
    mn[k][u] = min(mn[k][p],sum[k][u]);
    for(int v : adj[u]) if(v!=p) dfs(v,u,k);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> u >> v;
    for(int i = 0;i < n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    for(int i = 1;i <= n;i++) if(s[i-1]=='(') val[i] = 1; else val[i] = -1;
    for(int i = 1;i <= n;i++) dfs(i,0,i);
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) 
        if(sum[u][i]+sum[j][v]==0 and mn[u][i]>=0 and sum[u][i]>=abs(mn[j][v])) ans++; 
    cout << ans;
}
