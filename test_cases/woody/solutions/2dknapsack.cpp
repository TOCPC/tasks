#include<bits/stdc++.h>
using namespace std;
#define MAXL 1000000000000000000ll
int n, x, y;
array<int, 3> arr[1010];
long long dp[2][550][550];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            dp[0][i][j] = MAXL;
        }
    }
    dp[0][0][0] = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            for(int k = 0; k <= y; k++){
                dp[(i+1)%2][j][k] = dp[i%2][j][k];
            }
        }
        for(int j = 0; j <= x; j++){
            for(int k = 0; k <= y; k++){
                dp[(i+1)%2][min(j+arr[i][0], x)][min(k+arr[i][1], y)] = min(dp[(i+1)%2][min(j+arr[i][0], x)][min(k+arr[i][1], y)], dp[i%2][j][k] + arr[i][2]); 
            }
        }
    }
    long long ans = dp[n%2][x][y];
    cout << ((ans == MAXL)?-1:ans) << '\n';
    return 0;
}