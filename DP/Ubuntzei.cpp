#include <iostream>
#include <string.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);
 
ifstream fin("ubuntzei.in");
ofstream fout("ubuntzei.out");
 
int ppl[20];
vector<pii> adj[2010];
int len[20][2010], lenOG[2010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
int dp[100010][20];
int main()
{
    int n, m, k, a, b, c, curD, curN, ans = 2000000000;
    fin >> n >> m >> k;
    for(int i = 0; i < k; i ++) { fin >> ppl[i]; ppl[i] --; }
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    for(int j = 0; j < n; j ++)
        lenOG[j] = 2000000000;
    nextInLine.push({0, 0});
    lenOG[0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().f; curN = nextInLine.top().s;
        nextInLine.pop();
        if(lenOG[curN] < curD) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(lenOG[curN] + adj[curN][i].s < lenOG[adj[curN][i].f])
            {
                lenOG[adj[curN][i].f] = lenOG[curN] + adj[curN][i].s;
                nextInLine.push({lenOG[adj[curN][i].f], adj[curN][i].f});
            }
    }
    for(int i = 0; i < k; i ++)
    {
        for(int j = 0; j < n; j ++)
            len[i][j] = 2000000000;
        nextInLine.push({0, ppl[i]});
        len[i][ppl[i]] = 0;
        while(!nextInLine.empty())
        {
            curD = nextInLine.top().f; curN = nextInLine.top().s;
            nextInLine.pop();
            if(len[i][curN] < curD) continue;
            for(int j = 0; j < adj[curN].size(); j ++)
                if(len[i][curN] + adj[curN][j].s < len[i][adj[curN][j].f])
                {
                    len[i][adj[curN][j].f] = len[i][curN] + adj[curN][j].s;
                    nextInLine.push({len[i][adj[curN][j].f], adj[curN][j].f});
                }
        }
    }
    for(int i = 0; i < (1<<k); i ++)
        for(int j = 0; j < k; j ++)
            dp[i][j] = 2000000000;
    for(int i = 1; i < (1<<k); i ++)
        if(((bitset<16>)i).count() == 1)
            dp[i][(int)log2(i)] = lenOG[ppl[(int)log2(i)]];
    for(int i = 1; i < (1<<k); i ++)
        if(((bitset<16>)i).count() != 1)
            for(int j = 0; j < k; j ++)
                if((1<<j) & i)
                    for(int l = 0; l < k; l ++)
                        if((1<<l) & (i ^ (1<<j)))
                            dp[i][j] = min(dp[i][j], dp[i ^ (1<<j)][l] + len[j][ppl[l]]);
    for(int i = 0; i < k; i ++)
        ans = min(ans, dp[(1<<k)-1][i] + len[i][n-1]);
    fout << ((k==0)?lenOG[n-1]:ans) << "\n";
}
