#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);
 
ifstream fin("java.in");
ofstream fout("java.out");
 
int t, n, m, k, a, b, ans = 0;
vector<int> adj[10010];
bitset<10010> visited;
int l[10010], r[10010];
bool good;
bool pairUp(int x)
{
    if(visited[x]) return false;
    visited[x] = 1;
    for(int it : adj[x])
        if(!l[it])
        {
            l[r[x]] = 0; r[x] = it; l[it] = x;
            good = true;
            return true;
        }
    for(int it : adj[x])
        if(l[it] != x && pairUp(l[it]))
        {
            l[r[x]] = 0; r[x] = it; l[it] = x;
            good = true;
            return true;
        }
    return false;
}
int main()
{
    fin >> t;
    while(t--)
    {
        fin >> n >> m >> k;
        memset(l, 0, sizeof(l)); memset(r, 0, sizeof(r));
        for(int i = 1; i <= n; i ++) adj[i].clear();
        for(int i = 0; i < k; i ++)
        {
            fin >> a >> b;
            adj[a].push_back(b);
        }
        do
        {
            good = false;
            visited.reset();
            for(int i = 1; i <= n; i ++)
                if(!r[i])
                    pairUp(i);
        } while(good);
        ans = 0;
        for(int i = 1; i <= n; i ++)
            if(r[i])
                ans ++;
        fout << ans << "\n";
    }
}
