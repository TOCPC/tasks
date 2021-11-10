#include<bits/stdc++.h>
using namespace std;
#define MAXL 1000000000000000000ll
int n, x, y;
array<int, 3> arr[1100];
long long solve(int a, int b, int c){
    if(a == n){
        if(b >= x && c >= y)    return 0;
        else                    return MAXL;
    }
    long long notchosen = solve(a+1, b, c);
    long long chosen = solve(a+1, b+arr[a][0], c+arr[a][1]);
    chosen += arr[a][2];
    return min(notchosen, chosen);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    long long ans = solve(0, 0, 0);
    cout << ((ans == MAXL)?-1:ans) << '\n';
    return 0;
}