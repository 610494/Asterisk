#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int32_t t , n , k;
vector <int32_t> v;
int32_t F(int32_t n , int32_t k) {
    int32_t re = 0 , l = 0 , r = v.size()-1;
    while(l <= r) {
        int32_t mid = (l+r) / 2;
        //cout << v[mid] << " ";
        if(v[mid] <= k) {
            re = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    //cout << "\n";
    return v[re];
}

int main(){
    cin >> t;
    while(t-- && cin >> n >> k) {
        for(int32_t i=1;i<=sqrt(n);i++) {
            if(n%i == 0) {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        cout << n / F(n,k) << "\n";
        v.clear();
    }
    return 0;
}
/**
4 5 3 6 3 2 1 1 1
*/
