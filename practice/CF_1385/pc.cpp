#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200005;
int32_t t , n , arr[maxn] , l[maxn] , r[maxn];
struct P{
    int32_t v , id;
};
vector <P> v;

int main(){
    cin >> t;
    while(t-- && cin >> n) {
        for(int i=0;i<n;i++) cin >> arr[i];
        int Max = arr[0];
        l[0] = -1; r[n-1] = 0;
        v.push_back({maxn,-1});
        v.push_back({arr[0],0});
        for(int i=1;i<n;i++) {
            while(v.size() && v.back().v <= arr[i]) v.pop_back();
            l[i] = v.back().id;
            v.push_back({arr[i],i});
        }
        Max = arr[n-1];
        for(int i=n-1;i>=0;i--) {
            if(arr[i] >= Max) {
                Max = arr[i];
                r[i] = 0;
            }
            else r[i] = 1;
        }
        int ans = 0;
        for(int i=0;i<n;i++) if(l[i] >= 0 && r[i]) ans = max(l[i]+1 , ans);
        cout << ans << "\n";
    }

    return 0;
}
/**
x == a || x == b

y == a || y == c

z == b || z == c

*/
