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
 
ll T = 1,M,K,N, i,j, t = 1, sum, _sum, _M, Ans;
string S, s;

vector <vector <int>> mat, dp;
vector <vector <bool>> vis;

int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void init(){
    mat.clear();
    mat.assign(N + 1, vector <int> (M + 1));

    dp.clear();
    dp.assign(N + 1, vector <int> (M + 1, INF));

    vis.clear();
    vis.assign(N + 1, vector <bool> (M + 1, false));

    Ans = 0;
    _M = 0;
}

bool isValid(int r, int c){
    if(r <= 0 || c <= 0 || r > N || c > M) return false;

    return true;
}

void solve(){
    cin >> N >> M;

    init();

    for(i = 1;i <= N;i++){
        for(j = 1;j <= M;j++){
            cin >> mat[i][j];

            _M = max(_M,(ll)mat[i][j]);
        }
    }

    queue <pii> Q;

    for(i = 1;i <= N;i++){
        for(j = 1;j <= M;j++) if(mat[i][j] == _M){
            Q.push({i, j});
            dp[i][j] = 0;
        }
    }

    while(!Q.empty()){
        auto u = Q.front();
        Q.pop();

        // cout << u.first << " " << u.second << "\n";
        // cout << dp[u.first][u.second] << "\n";

        for(i = 0;i < 8;i++){   
            int r = u.first + dRow[i];
            int c = u.second + dCol[i];

            if(isValid(r, c) && dp[u.first][u.second] + 1 < dp[r][c]){
                dp[r][c] = dp[u.first][u.second] + 1;

                Q.push({r, c});
            }
        }
    }

    // for(i = 1;i <= N;i++){
    //     for(j = 1;j <= M;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(i = 1;i <= N;i++){
        for(j = 1;j <= M;j++) Ans = max(Ans,(ll)dp[i][j]);
    }

    cout << Ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}