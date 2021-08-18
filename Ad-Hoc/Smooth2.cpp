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
typedef pair<float, float> pff;
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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
ifstream fin("smooth2.in");
ofstream fout("smooth2.out");
 
int cost[30];
bitset<30> vis;
int main()
{
    int n, m = 0, ans = 0, cur;
    string st;
    fin >> st;
    n = (int)st.length();
    for(int i = 0; i < n; i ++)
        vis[st[i]-'a'] = 1;
    m = (int)vis.count();
    for(int i = 1; i <= 26; i ++)
    {
        memset(cost, 0, sizeof(cost)); vis.reset();
        for(int j = 0; j < n; j ++)
        {
            vis[st[j]-'a'] = 1;
            if((j+1) % i == 0 || j == n-1)
            {
                for(int k = 0; k < 26; k ++)
                    if(vis[k])
                        cost[k]++;
                vis.reset();
            }
        }
        sort(cost, cost+26, greater<int>()); cur = 0;
        for(int j = 0; j < i; j ++)
            cur += cost[j];
        ans = max(ans, cur);
    }
    fout << n-ans << '\n';
}
