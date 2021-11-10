#include<bits/stdc++.h>
using namespace std;
#define MAXL 1000000000000000000ll
int n, x, y;
array<int, 3> arr[1010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    long long ans = MAXL;
    for(int i = 0; i < n; i++){
        if(arr[i][0] >= x && arr[i][1] >= y){
            ans = min(ans, 1ll*arr[i][2]);
        }
        for(int j = i+1; j < n; j++){
            if(arr[i][0] + arr[j][0] >= x && arr[i][1] + arr[j][1] >= y){
                ans = min(ans, 1ll*arr[i][2] + arr[j][2]);
            }
            for(int k = j+1; k < n; k++){
                if(arr[i][0] + arr[j][0] + arr[k][0] >= x && arr[i][1] + arr[j][1] + arr[k][1] >= y){
                    ans = min(ans, 1ll*arr[i][2] + arr[j][2] + arr[k][2]);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}