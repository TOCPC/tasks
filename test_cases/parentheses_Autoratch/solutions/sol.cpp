#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,u,v;
vector<int> adj[N];
string s;
int val[N],sum[N][2],mn[N][2];
vector<int> st[N << 1];
long long ans;

void dfs(int u,int p,int t)
{
    sum[u][t] = sum[p][t]+val[u];
    if(!t) mn[u][t] = min(mn[p][t],sum[u][t]);
    else mn[u][t] = min(0,mn[p][t]+val[u]);
    for(int v : adj[u]) if(v!=p) dfs(v,u,t);
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
    dfs(u,0,0);
    dfs(v,0,1);
    for(int i = 1;i <= n;i++) st[sum[i][1]+N].push_back(abs(mn[i][1]));
    for(int i = 0;i < (N << 1);i++) sort(st[i].begin(),st[i].end());
    for(int i = 1;i <= n;i++) if(mn[i][0]>=0)
    {
        auto it = upper_bound(st[-sum[i][0]+N].begin(),st[-sum[i][0]+N].end(),sum[i][0]);
        ans+=(int)(it-st[-sum[i][0]+N].begin());
    }
    cout << ans;
}
