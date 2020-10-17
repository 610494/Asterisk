#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int32_t n , x;
int16_t t;

int main(){
    cin >> t;
    while(t-- && cin >> n >> x) {
        if(n <= 2) cout << "1\n";
        else cout << (n-2) / x + 1 + ((n-2) % x?1:0) << "\n";


    }
    return 0;
}
/**
4 5 3 6 3 2 1 1 1
*/
