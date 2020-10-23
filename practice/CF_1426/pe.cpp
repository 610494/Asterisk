#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define maxn 1005
const int64_t INF = 1e9+5;

int64_t S = 0, T = 13;
int64_t N , M;
struct node
{
    int64_t from ;
    int64_t to;
    int64_t cal;
    int64_t flow;
    node(int64_t a,int64_t b,int64_t c,int64_t d)
    {
        from = a, to = b , cal = c, flow = d;//应该是cap ，见谅- -。
    }

};
vector<int64_t>G[maxn];
vector<node>Edges;

int64_t vis[maxn];
int64_t deep[maxn];
int64_t iter[maxn];

void edg_add(int64_t from,int64_t to,int64_t cal)
{
    Edges.push_back(node(from,to,cal,0));
    Edges.push_back(node(to,from,0,0));
    int64_t size = Edges.size();
    G[to].push_back(size-1);
    G[from].push_back(size-2);
}

int64_t BFS()
{
    memset(vis,0,sizeof(vis));
    deep[S] = 1;

    queue<int64_t>Q;
    Q.push(S);
    vis[S] = 1;
    //cout << "1\n";
    while( !Q.empty() )
    {
        int64_t u = Q.front();Q.pop();

        for(int64_t i = 0 ; i < G[u].size() ; ++i)
        {
            node &e = Edges[G[u][i]];
            if ( !vis[e.to] && e.cal > e.flow )
            {
                vis[e.to] = 1;
                deep[e.to] = deep[u] + 1;
                Q.push(e.to);
            }
        }
    }
    return vis[T];
}

int64_t DFS(int64_t u,int64_t a)
{
    if(u == T || a == 0)
		return a;
	int64_t f , flow = 0;
	for(int64_t& i = iter[u]; i < (int64_t)G[u].size(); ++i)//防止每次都从0开始
	{
		node & e = Edges[G[u][i]];
		if(deep[e.to] == deep[u] + 1 && (f = DFS(e.to , min(a,e.cal - e.flow))) > 0 )
		{
			e.flow += f;
			Edges[G[u][i]^1].flow -= f;
			flow += f;
			a -= f;
			if( a == 0 )break;
		 }
	}
	return flow;
}

int64_t Dinic()
{
    int64_t res = 0;
    while(BFS())
    {
        //cout << "bfs\n";
        memset(iter,0,sizeof(iter));
        res += DFS(S,INF);
        //cout << "dfs\n";
    }
    return res;
}

int main() {
	int64_t  a[3] , b[3] , n;
	cin >> n;
	//cout << "get n~\n";
	for(int64_t i=0;i<3;i++) {
        cin >> a[i];
        edg_add(i+1,i+4,a[i]);
        edg_add(S,i+1,INF);
	}
	//cout << "get a~\n";
	for(int64_t i=0;i<3;i++) {
        cin >> b[i];
        edg_add(i+7,i+10,b[i]);
        edg_add(i+10,T,INF);
	}
	//cout << "get b~\n";
	edg_add(4,7,INF); edg_add(4,9,INF);
	edg_add(5,7,INF); edg_add(5,8,INF);
	edg_add(6,8,INF); edg_add(6,9,INF);
	//cout << "answer:\n";
    cout << n - Dinic() << " " << min(a[0],b[1]) + min(a[1],b[2]) + min(a[2],b[0]) <<"\n";

	return 0;
}
