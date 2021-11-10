#include <bits/stdc++.h>
using namespace std;

const int N = 201;

int n,u,v;
vector<int> adj[N];
string s;
int es,em;
int ans;

void dfs(int u,int p,int k,int now,int mn)
{
    if(s[u-1]=='(') now++;
    else now--;
    mn = min(mn,now);
    if(u==k) return (void)(es = now,em = mn);
    for(int v : adj[u]) if(v!=p) dfs(v,u,k,now,mn);
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
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
    {
        es = 0,em = 0;
        dfs(u,0,i,0,0);
        dfs(j,0,v,es,em);
        if(es==0 and em==0) ans++;
    }
    cout << ans;
}
