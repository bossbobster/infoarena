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
#include <valarray>
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
typedef long double ld;
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

ifstream fin("reconst.in");
ofstream fout("reconst.out");

int n, m, a, b, c;
vector<pii> adj[2010];
bitset<2010> visited;
int val[2010];
void dfs(int cur)
{
    if(visited[cur]) return;
    visited[cur] = true;
    for(auto it : adj[cur])
    {
        val[it.f] = val[cur] + it.s;
        dfs(it.f);
    }
}
int main()
{
    fin >> n >> m;
    int cur = 0;
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b >> c;
        adj[a-1].push_back({b, c}); adj[b].push_back({a-1, -c});
    }
    for(int i = 0; i < n; i ++)
        dfs(i);
    for(int i = 1; i <= n; i ++)
    {
        if(!visited[i]) fout << "0";
        else fout << val[i]-cur, cur = val[i];
        fout << ((i==n)?"\n":" ");
    }
}
