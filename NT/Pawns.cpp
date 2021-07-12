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

ifstream fin("pawns.in");
ofstream fout("pawns.out");

vector<int> adj[510], rev[510];
int in[510];
queue<int> nextInLine;
vector<int> ord;
bool visited[510];
bitset<510> taken;
int dp[510];
int main()
{
    int n, m, t, a, b, cur, num, ans;
    fin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        fin >> a >> b; a--; b--;
        adj[a].push_back(b); rev[b].push_back(a);
        in[a] ++;
    }
    for(int i = 0; i < n; i ++)
        if(in[i] == 0)
            nextInLine.push(i);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        ord.push_back(cur);
        for(auto it : rev[cur])
        {
            in[it] --;
            if(!in[it])
                nextInLine.push(it);
        }
    }
    for(int i = 0; i < n; i ++)
    {
        cur = ord[i];
        taken.reset();
        for(auto it : adj[cur])
            taken[dp[it]] = 1;
        for(int j = 0; j <= 500; j ++)
            if(!taken[j])
            {
                dp[cur] = j;
                break;
            }
    }
    fin >> t;
    while(t--)
    {
        ans = 0;
        for(int i = 0; i < n; i ++)
        {
            fin >> num;
            ans ^= (num%2) * dp[i];
        }
        fout << ((ans==0)?0:1) << "\n";
    }
}
