#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;

int n, m;
int from, to;
int heights[100000];
int visited[100000];
vvi adj;

int main(){
    cin >> n >> m;
    cin >> from >> to;
    from--, to--;
    for(int i = 0; i < n; i++) cin >> heights[i];
    adj = vvi(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, from);
    while(1){
        ll dist;
        int pos;
        tie(dist, pos) = pq.top();
        dist = -dist;
        pq.pop();
        if(visited[pos]) continue;
        visited[pos] = 1;
        if(pos == to){
            cout << dist << "\n";
            return 0;
        }
        for(int i = 0; i < sz(adj[pos]); i++){
            pq.emplace(-dist-max(0, heights[adj[pos][i]] - heights[pos]), adj[pos][i]);
        }
    }
}
