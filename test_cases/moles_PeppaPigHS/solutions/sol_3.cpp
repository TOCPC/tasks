#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e6 + 5;

int n, st;
int dp[N];
pii A[N];

int main() {
    scanf("%d %d", &n, &st);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &A[i].x, &A[i].y);
        int a = A[i].y - A[i].x;
        int b = A[i].y + A[i].x; 
        A[i] = pii(a, b);
    }
    sort(A + 1, A + n + 1);
    vector<int> lis;
    for (int i = 1; i <= n; i++) {
        if (A[i].x < -st || A[i].y < st) continue;
        if (lis.empty() || lis.back() <= A[i].y) {
            lis.emplace_back(A[i].y);
            continue;
        }
        auto it = upper_bound(lis.begin(), lis.end(), A[i].y);
        if (it == lis.end()) continue;
        *it = A[i].y;
    }
    printf("%d\n", (int) lis.size());

    return 0;
}
