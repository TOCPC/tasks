#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> vec;
    scanf("%d", &n);
    for(int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        vec.emplace_back(a);
    }
    sort(vec.begin(), vec.end());
    for(int x : vec) printf("%d ", x);
    printf("\n");

    return 0;
}
