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
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            if(vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
    for(int x : vec) printf("%d ", x);
    printf("\n");

    return 0;
}
