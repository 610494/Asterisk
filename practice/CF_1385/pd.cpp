#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200005;
int t , n , num[30][maxn] = {};
char c[maxn];
int N(int l , int r , char id) {
    return num[id-'a'][r+1] - num[id-'a'][l];
}
int F(int l , int r , char c) {
    if(l == r) return !N(l,r,c);
    //int out = min(F(l,(r+l)/2) + (r-((r+l)/2+1)+1) - N((r+l)/2+1,r) , F((r+l)/2+1,r) + (r+l)/2 - l + 1- N(l,(r+l)/2));
    //cout << l << " " << r << "  :  " << out << "\n";
    return min(F(l,(r+l)/2,c+1) + (r-((r+l)/2+1)+1) - N((r+l)/2+1,r,c) , F((r+l)/2+1,r,c+1) + (r+l)/2 - l + 1- N(l,(r+l)/2,c));
}

int main(){
    cin >> t;
    while(t-- && cin >> n) {
        cin >> c;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<26;j++) {
                num[j][i] = num[j][i-1] + (c[i-1] == 'a' + j);
            }
        }
        cout << F(0,n-1,'a') << "\n";
    }
    return 0;
}
/**
x == a || x == b

y == a || y == c

z == b || z == c

*/
