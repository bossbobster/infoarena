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

ifstream fin("sabotaj.in");
ofstream fout("sabotaj.out");
 
vector<pii> adj[210];
queue<int> nextInLine;
bitset<210> visited;
int cur[210][210], lim[210][210], par[210];
set<int> v, ansV;
int main()
{
    int n, m, a, b, c, curN, curF, ans = 0, ansans = 2000000000;
    fin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b >> c;
        adj[a].push_back({b, i+1}); adj[b].push_back({a, i+1});
        lim[a][b] += c; lim[b][a] += c;
    }
    for(int en = 2; en <= n; en ++)
    {
        par[1] = -1; ans = 0;
        memset(cur, 0, sizeof(cur));
        while(true)
        {
            nextInLine.push(1);
            visited.reset(); visited[1] = true;
            while(!nextInLine.empty())
            {
                curN = nextInLine.front();
                nextInLine.pop();
                if(curN == en) continue;
                for(auto it : adj[curN])
                    if(cur[curN][it.f] != lim[curN][it.f] && !visited[it.f])
                    {
                        nextInLine.push(it.f);
                        visited[it.f] = true;
                        par[it.f] = curN;
                    }
            }
            if(!visited[en])
            {
                v.clear();
                for(int i = 1; i <= n; i ++)
                    for(auto it : adj[i])
                        if(visited[i] && !visited[it.f])
                            v.insert(it.s);
                break;
            }
            for(auto it : adj[en])
            {
                if(!visited[it.f] || cur[it.f][en] == lim[it.f][en]) continue;
                curF = 2000000000; par[en] = it.f; curN = en;
                while(curN != 1)
                    curF = min(curF, lim[par[curN]][curN] - cur[par[curN]][curN]), curN = par[curN];
                curN = en;
                while(curN != 1)
                    cur[par[curN]][curN] += curF, cur[curN][par[curN]] -= curF, curN = par[curN];
                ans += curF;
            }
        }
        if(ans < ansans)
            ansans = ans, ansV = v;
    }
    fout << ansans << " " << ansV.size() << "\n";
    for(auto it : ansV)
        fout << it << "\n";
}
