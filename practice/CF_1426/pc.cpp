#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int32_t n , x;
int16_t t;
int64_t F(int64_t n , int64_t use) {
    if(n % use) return n / use + 1;
    return n / use;
}
//use *(x) >= ans
//x >= ans / use
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t-- && cin >> n) {
        int64_t y = 0 , ans = 1e9;
        for(int64_t use=y+1;y<min(n,63245);use=++y+1 ) {
            if(y >=ans) break;
            ans = min(ans , y + F(n-use,use));
        }
        cout << ans << "\n";
    }
    return 0;
}
/**
4 5 3 6 3 2 1 1 1
*/
