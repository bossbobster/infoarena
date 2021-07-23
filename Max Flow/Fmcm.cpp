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

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

struct pq
{
    int len, par, cur;
    const bool operator>(const pq& other) const
    {
        return len > other.len;
    }
};

vector<int> adj[360];
priority_queue<pq, vector<pq>, greater<pq>> nextInLine;
bitset<360> visited;
int cur[360][360], lim[360][360], cost[360][360], par[360], dist[360], upDist[360], len[360];
queue<int> q;
int main()
{
    int n, m, st, en, a, b, c, d, curN, curD, curP, curF, flow = 0;
    fin >> n >> m >> st >> en; st--; en--;
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b >> c >> d; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
        lim[a][b] += c; cost[a][b] += d; cost[b][a] -= d;
    }
    for(int i = 0; i < n; i ++)
        dist[i] = 2000000000;
    dist[st] = 0; q.push(st);
    while(!q.empty())
    {
        curN = q.front(); q.pop();
        for(auto it : adj[curN])
            if(lim[curN][it])
                if(dist[curN] + cost[curN][it] < dist[it])
                    dist[it] = dist[curN] + cost[curN][it], q.push(it);
    }
    while(true)
    {
        nextInLine.push({0, -1, st});
        visited.reset();
        fill(upDist, upDist+n, 2000000000); fill(len, len+n, 2000000000);
        len[st] = 0;
        while(!nextInLine.empty())
        {
            curD = nextInLine.top().len; curP = nextInLine.top().par; curN = nextInLine.top().cur;
            nextInLine.pop();
            if(len[curN] < curD) continue;
            upDist[curN] = curD;
            par[curN] = curP;
            if(curN == en)
            {
                d = curD;
                continue;
            }
            for(int it : adj[curN])
                if(cur[curN][it] != lim[curN][it] && len[curN] + cost[curN][it] + dist[curN] - dist[it] < len[it])
                {
                    nextInLine.push({len[curN] + cost[curN][it] + dist[curN] - dist[it], curN, it});
                    len[it] = len[curN] + cost[curN][it] + dist[curN] - dist[it];
                }
        }
        if(len[en] == 2000000000) break;
        curF = 2000000000; curN = en;
        while(curN != st)
        {
            curF = min(curF, lim[par[curN]][curN] - cur[par[curN]][curN]);
            curN = par[curN];
        }
        curN = en;
        while(curN != st)
        {
            cur[par[curN]][curN] += curF;
            cur[curN][par[curN]] -= curF;
            curN = par[curN];
        }
        flow += curF * (d + dist[en]);
        for(int i = 0; i < n; i ++)
            dist[i] += upDist[i];
    }
    fout << flow << "\n";
}
