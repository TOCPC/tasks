#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e6 + 5;

int n, st;
pii A[N];

int main() {
    scanf("%d %d", &n, &st);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &A[i].x, &A[i].y);
    printf("%d\n", n);

    return 0;
}
