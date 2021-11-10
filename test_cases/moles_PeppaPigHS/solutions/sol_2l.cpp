#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 5;

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
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i].x < -st || A[i].y < st) continue;
        dp[i] = 1;
        for (int j = 1; j < i; j++) if (A[j].y <= A[i].y)
            dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);

    return 0;
}
