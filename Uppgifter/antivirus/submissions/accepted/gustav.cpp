#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;

int main(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    vl b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    vi c(n, 1);

    ll ans = 0;
    set<pair<ll, int>> pq;
    for(int i = 0; i < n; i++) pq.emplace(-b[i], i);
    ll sincejoin = 0;
    while(1){
        int from = (*pq.begin()).second;
        ll best = b[from];
        if(-(*pq.rbegin()).first >= 0){
            cout << ans << endl;
            return 0;
        }
        if(best <= 0){
            cout << "never" << endl;
            return 0;
        }

        int dest = a[from];
        int dist = c[from];
        int prevdest = from;
        
        while(prevdest != 0 && dest != 0 && b[dest] == 0){
            prevdest = dest;
            dist += c[dest];
            dest = a[dest];
        }
        sincejoin++;
        if(b[dest]) sincejoin = 0;
        if(sincejoin > 2*n+3){
            cout << "never" << endl;
            return 0;
        }

        pq.erase(pq.begin());
        pq.emplace(0, from);
        pq.erase({-b[dest], dest});
        b[dest] += b[from];
        pq.emplace(-b[dest], dest);
        b[from] = 0;

        ans+=dist;

        while(dist){
            int nxt = a[from];
            int nd = c[from];
            a[from] = dest;
            c[from] = dist;
            from = nxt;
            dist -= nd;
        }
    }
}
