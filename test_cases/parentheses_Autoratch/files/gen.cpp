#include <bits/stdc++.h>
#include "testlib.h"
#include "genlib.h"
using namespace std;

int main(int argc,char *argv[])
{
    registerGen(argc,argv,1);
    int n = atoi(argv[1]);
    int t = atoi(argv[2]); 
    /* type: 
    1: tree
    2: line graph; v-u-x-x-x-x-x-x----
    3: u
       |
---x-x-v-x-x-x---
       |
       x
       |
       |
    */
    int u = rnd.next(1,n),v = rnd.next(1,n);
    while(v==u) v = rnd.next(1,n);
    cout << n << ' ' << u << ' ' << v << endl;    

    if(t==1) // tree
    {
        vector<pair<int,int> > edges = gen_connected_graph(n,n-1);
        for(auto [u,v] : edges) cout << u+1 << ' ' << v+1 << endl;
    }
    else if(t==2) // line graph; v-u-x-x-x-x-x-x----
    {
        vector<int> nodes;
        for(int i = 1;i <= n;i++) if(i!=u and i!=v) nodes.push_back(i);
        shuffle(nodes.begin(),nodes.end());
        cout << v << ' ' << u << endl;
        cout << u << ' ' << nodes[0] << endl;
        for(int i = 0;i < n-3;i++) cout << nodes[i] << ' ' << nodes[i+1] << endl;
    }
    else
    {
/*     u
       |
---x-x-v-x-x-x---
       |
       x
       |
       |
*/
        vector<pair<int,int> > edges = gen_connected_graph(n-1,n-2);
        for(auto[u,v] : edges) cout << u+2 << ' ' << v+2 << endl;
        cout << "1 " << rnd.next(2,n) << endl;
    }
    
    for(int i = 0;i < n;i++) 
    {
        if(i+1==u) cout << '('; 
        else if(i+1==v) cout << ')'; 
        else if(rnd.next(1,2)==1) cout << '('; 
        else cout << ')';
    }
    cout << endl;
    
    return 0;
}
