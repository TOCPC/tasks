#include "genlib.h"
#include <bits/stdc++.h>

#define long long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m;
    int mode = atoi(argv[2]);
    vector<pii> edge;
    vector<int> w;

    int min_k = rnd.next(0, n - 1);
    int max_k = rnd.next(min_k, n - 1);

    if(mode == 0) {
        m = rnd.next(n - 1, n * (n - 1) / 2);
        edge = gen_connected_graph(n, m);
    } else if(mode == 1) {
        m = n - 1;
        edge = gen_edge_tree(n, min_k, max_k);
    } else {
        m = rnd.next((long)n - 1, min((long)2e5, 1ll * n * (n - 1) / 2ll));
        edge = gen_connected_graph(n, m);
    }
    w = pick_set(1, (int)1e9, m);

    printf("%d %d\n", n, m);
    for(int i = 0; i < m; i++)
        printf("%d %d %d\n", edge[i].x + 1, edge[i].y + 1, w[i]);

    return 0;
}
