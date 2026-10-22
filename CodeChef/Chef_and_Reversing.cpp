// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iomanip>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
 
using pii = pair<int,int>;
using pll = pair<long long, long long>;
using pd = pair<double, double>;
 
const long long Mod = 1e9 + 7;
const long long mod = 998244353;
const double pi = acos(-1);
const int INF = INT_MAX;
const int sz = 500000;
 
ll T = 1,M,K,N, i,j, t = 1, sum, _sum, _M, Ans, x, y;
string S, s;

void solve(){
    cin >> N >> M;

    vector <vector <pii>> Adj(N + 1, vector <pii> (0));
    vector <bool> vis(N + 1, false);
    vector <int> cost(N + 1, INF);

    for(i = 0;i < M;i++){
        cin >> x >> y;

        Adj[x].push_back({y, 0});
        Adj[y].push_back({x, 1});
    }

    deque <pii> Q;
    Q.push_front({1, 0});
    cost[1] = 0;

    while(!Q.empty()){
        auto &[u, _c] = Q.front();
        Q.pop_front();

        if(vis[u] == true){
            continue;
        }

        vis[u] = true;

        // cout << u << " ->";

        for(auto &[v, c] : Adj[u]) if(!vis[v]){
            // cout << v << " ";
            cost[v] = min(cost[v], cost[u] + c);

            if(c == 1) Q.push_back({v, cost[v]});
            else Q.push_front({v, cost[v]});
        }

        // cout << "\n";
    } 

    // for(auto num : cost) cout << num << " ";
    // cout << "\n";

    if(cost[N] != INF) cout << cost[N] << "\n";
    else cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> T;

    while(T--){
        solve();
    }

    return 0;
}