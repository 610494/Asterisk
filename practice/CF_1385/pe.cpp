#include <iostream>
#include <stdint.h>
#include <vector>
#include<queue>
#include<memory.h>
using namespace std;
const int64_t maxn = 200005;
struct Edge {
    int32_t u, v, id;
}edge[maxn];
int32_t t, n, m, tapo[maxn], tapo_id, num[maxn];
vector <int32_t> v[maxn];
queue <int32_t> q;
void Tapo() {
    tapo_id = 0;
    memset(tapo,0,sizeof(tapo));
    for (int i = 1; i <= n; i++) {
        if (!num[i]) q.push(i);
    }
    while (q.size()) {
        int32_t now = q.front();
        q.pop();
        tapo[now] = tapo_id++;
        //cout << tapo_id - 1 << "  " << now << "\n";
        for (int i = 0; i < v[now].size(); i++) {
            int32_t next = v[now][i];
            num[next]--;
            if (!num[next]) q.push(next);


        }

    }
}

int main() {
    cin >> t;
    while (t-- && cin >> n >> m) {
        int e_n = 0;
        bool ans = 1;
        memset(num, 0, sizeof(num));
        for (int i = 0; i < m; i++) {
            cin >> edge[i].id >> edge[i].u >> edge[i].v;
            if (edge[i].id) {
                v[edge[i].u].push_back(edge[i].v);
                num[edge[i].v]++;
            }
        }
        Tapo();
        for(int i=0;i<m;i++) {
            if(edge[i].id == 0) continue;
            if (!(tapo[edge[i].u] < tapo[edge[i].v])) {
                cout << "NO\n";
                ans = 0;
                break;
            }
        }

        if(ans) {
            cout << "YES\n";
            for (int i = 0; i < m; i++) {
                if (edge[i].id) cout << edge[i].u << " " << edge[i].v << "\n";
                else if (tapo[edge[i].u] < tapo[edge[i].v]) cout << edge[i].u << " " << edge[i].v << "\n";
                else cout << edge[i].v << " " << edge[i].u << "\n";
            }
        }
        for (int i = 1; i <= n; i++) v[i].clear();
    }
    return 0;

}
