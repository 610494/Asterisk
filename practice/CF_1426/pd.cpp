#include<iostream>
#include <set>
using namespace std;
const int maxn = 200005;
int32_t n , arr[maxn] , ans = 0;
int64_t sum = 0;
set <int64_t> s;

int main() {
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	s.insert(0);
	for(int i=0;i<n;i++) {
        sum += arr[i];
        if(s.find(sum) != s.end()) {
            ans++;
            s.clear();
            s.insert(0);
            sum = arr[i];
        }
        s.insert(sum);
	}
	cout << ans << "\n";
	return 0;
}
