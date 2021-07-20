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
 
ifstream fin("joc4.in");
ofstream fout("joc4.out");
 
int n, m, l, r, a, b, curN, curF, ans = 0, one, two;
vector<int> adj[510];
queue<int> nextInLine;
bitset<510> visited;
int cur[510][510], lim[510][510], par[510];
int main()
{
    input();
    fin >> n >> m >> l >> r; l--; r--;
    for(int i = 0; i < n; i ++)
        if(i != l && i != r)
            adj[i*2].push_back(i*2+1), adj[i*2+1].push_back(i*2), lim[i*2][i*2+1] ++;//, lim[i*2+1][i*2] ++;
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b; a--; b--;
        if(a == l || a == r) one = a*2;
        else one = a*2+1;
        if(b == l || b == r) two = b*2;
        else two = b*2+1;
        adj[one].push_back(b*2); adj[b*2].push_back(one); adj[two].push_back(a*2); adj[a*2].push_back(two);
        lim[one][b*2] ++; lim[two][a*2] ++;
    }
    l *= 2; r *= 2;
    par[l] = -1;
    while(true)
    {
        nextInLine.push(l);
        visited.reset(); visited[l] = true;
        while(!nextInLine.empty())
        {
            curN = nextInLine.front();
            nextInLine.pop();
            if(curN == r) continue;
            for(auto it : adj[curN])
                if(cur[curN][it] != lim[curN][it] && !visited[it])
                {
                    nextInLine.push(it);
                    visited[it] = true;
                    par[it] = curN;
                }
        }
        if(!visited[r]) break;
        for(auto it : adj[r])
        {
            if(!visited[it] || cur[it][r] == lim[it][r]) continue;
            curF = 2000000000; par[r] = it; curN = r;
            while(curN != l)
                curF = min(curF, lim[par[curN]][curN] - cur[par[curN]][curN]), curN = par[curN];
            curN = r;
            while(curN != l)
                cur[par[curN]][curN] += curF, cur[curN][par[curN]] -= curF, curN = par[curN];
            ans += curF;
        }
    }
    fout << ans << "\n";
}
