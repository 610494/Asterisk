#include <iostream>
#include <vector>
using namespace std;
int t , n , arr[105];
int main(){
    cin >> t;
    while(t-- && cin >> n) {
        vector <int> v;
        for(int i=0;i<2*n;i++) cin >> arr[i];
        for(int i=0;i<2*n;i++) {
            if(arr[i] == -1) continue;
            v.push_back(arr[i]);
            int j = 0;
            for(j=i+1;arr[i] != arr[j];j++) {}
            arr[j] = -1;
        }
        for(int i=0;i<v.size();i++) cout << v[i] << " ";
        cout << "\n";

    }
    return 0;
}
/**
x == a || x == b

y == a || y == c

z == b || z == c

*/
