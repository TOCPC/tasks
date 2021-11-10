#include <bits/stdc++.h>
using namespace std;

const int N = 201;

int n,u,v;
vector<int> adj[N];
string s,each;
int ans;

void dfs(int u,int p,int k,string now)
{
    now+=s[u-1];
    if(u==k) return (void)(each+=now);
    for(int v : adj[u]) if(v!=p) dfs(v,u,k,now);
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
        each = "";
        dfs(u,0,i,"");
        dfs(j,0,v,"");
        int now = 0,mn = 0;
        for(char x : each){ if(x=='(') now++; else now--; mn = min(mn,now); }
        if(now==0 and mn==0) ans++;
    }
    cout << ans;
}
