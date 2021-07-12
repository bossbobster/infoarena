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

ifstream fin("dreptpal.in");
ofstream fout("dreptpal.out");

int nums[1010][2010];
int dp[1010][2010];
int l[1010], r[1010];
stack<pii> cur;
int main()
{
    int n, m, mx, len, j, idx, ans = 0;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            fin >> nums[i][j*2+1];
    len = m*2+1;
    for(int row = 0; row < n; row ++)
    {
        mx = idx = -1;
        for(int i = 0; i < len; i ++)
        {
            if(i > mx)
            {
                for(j = 1; i-j >= 0 && i+j < len && nums[row][i-j] == nums[row][i+j]; j ++) {}
                j --; dp[row][i] = j;
                mx = i+j; idx = i;
            }
            else
            {
                if(dp[row][idx*2-i]+i < mx)
                    dp[row][i] = dp[row][idx*2-i];
                else
                {
                    for(j = 1; 2*i-mx-j >= 0 && mx+j < len && nums[row][2*i-mx-j] == nums[row][mx+j]; j ++) {}
                    j --; dp[row][i] = mx+j-i;
                    mx += j; idx = i;
                }
            }
        }
    }
    for(int i = 0; i < len; i ++)
    {
        fill(l, l+n, -1); fill(r, r+n, n);
        while(cur.size()) cur.pop();
        for(int j = 0; j < n; j ++)
        {
            while(!cur.empty() && cur.top().f > dp[j][i])
            {
                r[cur.top().s] = j;
                cur.pop();
            }
            cur.push({dp[j][i], j});
        }
        while(!cur.empty()) cur.pop();
        for(int j = n-1; j >= 0; j --)
        {
            while(!cur.empty() && cur.top().f > dp[j][i])
            {
                l[cur.top().s] = j;
                cur.pop();
            }
            cur.push({dp[j][i], j});
        }
        for(int j = 0; j < n; j ++)
            ans = max(ans, dp[j][i] * (r[j]-l[j]-1));
    }
    fout << ans << "\n";
}
