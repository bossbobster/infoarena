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

ifstream fin("atac2.in");
ofstream fout("atac2.out");

struct pq
{
    int len, par, cur;
    const bool operator>(const pq& other) const
    {
        return len > other.len;
    }
};

int starts[80];
vector<int> adjOG[10010], adj[150];
queue<pii> q2;
int bfs[10010];
priority_queue<pq, vector<pq>, greater<pq>> nextInLine;
bitset<10010> visited;
int lim[150][150], cur[150][150], cost[150][150], par[150], dist[150], upDist[150], len[150];
queue<int> q;
int main()
{
    int n, m, u, x, a, b, d, st, en, curN, curD, curP, curF, flow = 0;
    fin >> n >> m >> u >> x;
    for(int i = 0; i < u; i ++)
        fin >> starts[i];
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b;
        adjOG[a].push_back(b); adjOG[b].push_back(a);
    }
    for(int i = 0; i < u; i ++)
    {
        q2.push({starts[i], 0});
        visited.reset();
        fill(bfs, bfs+n+1, 2000000000);
        bfs[starts[i]] = 0;
        while(!q2.empty())
        {
            curN = q2.front().f; curD = q2.front().s;
            q2.pop();
            if(visited[curN]) continue;
            visited[curN] = 1;
            bfs[curN] = curD;
            for(auto it : adjOG[curN])
                if(!visited[it])
                    q2.push({it, curD+1});
        }
        for(int j = 0; j < adjOG[x].size(); j ++)
            adj[i+1].push_back(j+u+1), adj[j+u+1].push_back(i+1), lim[i+1][j+u+1] ++, cost[i+1][j+u+1] += bfs[adjOG[x][j]], cost[j+u+1][i+1] -= bfs[adjOG[x][j]];
    }
    for(int i = 0; i < u; i ++)
        adj[0].push_back(i+1), adj[i+1].push_back(0), lim[0][i+1] ++;
    for(int i = 0; i < adjOG[x].size(); i ++)
        adj[i+u+1].push_back(2*u+1), adj[2*u+1].push_back(i+u+1), lim[i+u+1][2*u+1] ++;
    st = 0, en = 2*u+1;
    for(int i = 0; i < 150; i ++)
        dist[i] = 2000000000;
    dist[st] = 0; nextInLine.push({0, -1, st});
    while(!nextInLine.empty())
    {
        curN = nextInLine.top().cur; curD = nextInLine.top().len;
        nextInLine.pop();
        if(dist[curN] < curD) continue;
        for(auto it : adj[curN])
            if(lim[curN][it])
                if(dist[curN] + cost[curN][it] < dist[it])
                    dist[it] = dist[curN] + cost[curN][it], nextInLine.push({dist[it], -1, it});
    }
    while(true)
    {
        nextInLine.push({0, -1, st});
        visited.reset();
        fill(upDist, upDist+150, 2000000000); fill(len, len+150, 2000000000);
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
        for(int i = 0; i < 150; i ++)
            dist[i] += upDist[i];
    }
    fout << flow << "\n";
}
