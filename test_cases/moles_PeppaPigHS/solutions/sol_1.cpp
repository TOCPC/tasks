#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 5e3 + 5;

int n, st;
int dp[N], sum[N];
pii A[N];

int main() {
    scanf("%d %d", &n, &st);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &A[i].x, &A[i].y);
        sum[i] = A[i].y - A[i].x;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sum[i] < -st || A[i].x + A[i].y < st) continue;
        dp[i] = 1;
        for (int j = 1; j < i; j++) if (sum[j] <= sum[i])
            dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);

    return 0;
}
