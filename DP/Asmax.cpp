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

ifstream fin("asmax.in");
ofstream fout("asmax.out");

int ansans = -2000000000;
int ans[16010];
vector<int> adj[16010];
int nums[16010];
void dfs(int cur, int par)
{
    ans[cur] = nums[cur];
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
        ans[cur] = max(ans[cur], ans[cur] + ans[it]);
    }
    ansans = max(ansans, ans[cur]);
}
int main()
{
    int n, a, b;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i < n-1; i ++)
    {
        fin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1);
    fout << ansans << "\n";
}
