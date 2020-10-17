#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int32_t t , n , m;
set <string> s;
string str;
void OUT() {
    string use = *s.begin();
    for(int i=0;i<m;i++) {
        if(use[i] != '*') cout << use[i];
        else cout << 'a';
    }
    cout << "\n";
}

int main(){
    cin >> t;
    while(t-- && cin >> n >> m) {
        cin >> str;   s.insert(str);
        for(int i=0;i<m;i++) {
            string use = str;
            use[i] = '*';
            s.insert(use);
        }
        for(int i=1;i<n;i++) {
            cin >> str;
            set <string> era , s2;
            for(set <string>::iterator it = s.begin();it!=s.end();it++) {
                int32_t num = 0; string use = *it; int32_t id = -1;
                for(int j=0;j<m;j++) {
                    if(use[j] != '*' && use[j] != str[j]) num++;
                    if(use[j] == '*') id = j;
                }
                if(num > 1) era.insert(*it);
                else if(num == 1 && id != -1) {
                    era.insert(*it);
                    use[id] = str[id];
                    s2.insert(use);
                }
            }
            for(set <string>::iterator it = era.begin();it!=era.end();it++) s.erase(*it);
            for(set <string>::iterator it = s2.begin();it!=s2.end();it++) s.insert(*it);
        }
        if(s.empty()) cout << "-1\n";
        else OUT();
        s.clear();
    }
    return 0;
}
/**
4 5 3 6 3 2 1 1 1
*/
