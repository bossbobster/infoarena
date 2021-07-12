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

ifstream fin("adn.in");
ofstream fout("adn.out");

struct p
{
    int len, pre;
};

string st[20];
vector<string> nums;
bool bad[20];
int kmp[60010];
int cnt[20][20];
int dp[300010][20];
p par[300010][20];
int main()
{
    int n, x, ans = 2000000000, f = 0, cur, tmp;
    bool good;
    string s1, ansans = ""; ansans.reserve(6000000);
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> st[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            if(bad[i] || bad[j] || i==j) continue;
            if(st[i] == st[j])
                bad[j] = true;
            else
            {
                s1 = st[j] + st[i];
                kmp[0] = -1; kmp[1] = 0;
                for(int i = 1; i < s1.length(); i ++)
                {
                    x = kmp[i];
                    while(x != -1 && s1[x] != s1[i])
                        x = kmp[x];
                    kmp[i+1] = x+1;
                    if(kmp[i+1] >= st[j].length())
                    {
                        bad[j] = true;
                        break;
                    }
                }
                cnt[i][j] = (int)st[j].length() - min((int)st[j].length(), kmp[s1.length()]);
            }
        }
    for(int i = 0; i < (1<<n); i ++)
        fill(dp[i], dp[i]+n, 2000000000);
    for(int i = 0; i < n; i ++)
    {
        dp[1<<i][i] = (int)st[i].length();
        par[1<<i][i] = {(int)st[i].length(), -1};
    }
    for(int i = 1; i < 1<<n; i ++)
    {
        good = true;
        for(int j = 0; j < n; j ++)
            if(bad[j] && (i & (1<<j)))
            {
                good = false;
                break;
            }
        if(!good) continue;
        if(((bitset<18>)i).count() > 1)
            for(int j = 0; j < n; j ++)
                if(i & (1<<j))
                    for(int k = 0; k < n; k ++)
                        if((i ^ (1<<j)) & (1<<k))
                        {
                            if(dp[i^(1<<j)][k] + cnt[k][j] < dp[i][j])
                            {
                                dp[i][j] = dp[i^(1<<j)][k] + cnt[k][j];
                                par[i][j] = {cnt[k][j], k};
                            }
                        }
    }
    for(int i = 0; i < n; i ++)
        if(!bad[i])
            f |= (1<<i);
    for(int i = 0; i < n; i ++)
        if(dp[f][i] < ans)
        {
            ans = dp[f][i];
            cur = i;
        }
    while(f)
    {
        ansans = st[cur].substr(st[cur].length() - par[f][cur].len, par[f][cur].len) + ansans;
        tmp = cur; cur = par[f][cur].pre;
        f = f ^ (1<<tmp);
    }
    fout << ansans << "\n";
}
