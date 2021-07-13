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

ifstream fin("origami2.in");
ofstream fout("origami2.out");

vector<string> nums;
vector<int> dp, dp2;
vector<int> r, c;
int pre[1000010];
bitset<1000010> can1, can2;
int mn[1000010];
int main()
{
    int n, m, mx, idx, len, h, j;
    ll hor = 0, ver = 0, ans = 0;
    string og, st, dots; st.reserve(2000000); dots.reserve(2000000);
    fin >> n >> m;
    len = m*2-1; h = n*2-1;
    dp.resize(len); dp2.resize(h);
    for(int i = 0; i < len; i ++)
        dots += ".";
    for(int i = 0; i < n; i ++)
    {
        fin >> og; st = "";
        for(int j = 0; j < m-1; j ++)
            st += og[j], st += ".";
        st += og[m-1];
        nums.push_back(st);
        if(i < n-1) nums.push_back(dots);
    }
    fill(mn, mn+len, 2000000000);
    for(int row = 0; row < h; row ++)
    {
        mx = idx = -1;
        fill(dp.begin(), dp.end(), 0);
        for(int i = 0; i < len; i ++)
        {
            if(i > mx)
            {
                for(j = 1; i-j >= 0 && i+j < len && nums[row][i-j] == nums[row][i+j]; j ++) {}
                j --; dp[i] = j;
                mx = i+j; idx = i;
            }
            else
            {
                if(dp[idx*2-i]+i < mx)
                    dp[i] = dp[idx*2-i];
                else
                {
                    for(j = 1; 2*i-mx-j >= 0 && mx+j < len && nums[row][2*i-mx-j] == nums[row][mx+j]; j ++) {}
                    j --; dp[i] = mx+j-i;
                    mx += j; idx = i;
                }
            }
            mn[i] = min(mn[i], dp[i]);
        }
    }
    for(int i = 1; i < len; i += 2)
        c.push_back((mn[i]+1)/2);
    fill(mn, mn+len, 2000000000);
    for(int col = 0; col < len; col ++)
    {
        mx = idx = -1;
        fill(dp2.begin(), dp2.end(), 0);
        for(int i = 0; i < h; i ++)
        {
            if(i > mx)
            {
                for(j = 1; i-j >= 0 && i+j < h && nums[i-j][col] == nums[i+j][col]; j ++) {}
                j --; dp2[i] = j;
                mx = i+j; idx = i;
            }
            else
            {
                if(dp2[idx*2-i]+i < mx)
                    dp2[i] = dp2[idx*2-i];
                else
                {
                    for(j = 1; 2*i-mx-j >= 0 && mx+j < h && nums[2*i-mx-j][col] == nums[mx+j][col]; j ++) {}
                    j --; dp2[i] = mx+j-i;
                    mx += j; idx = i;
                }
            }
            mn[i] = min(mn[i], dp2[i]);
        }
    }
    for(int i = 1; i < h; i += 2)
        r.push_back((mn[i]+1)/2);
    can1[0] = 1; pre[0] = 0; pre[1] = 1;
    for(int i = 0; i < c.size(); i ++)
    {
        if(pre[i+1] - pre[i+1-c[i]])
            can1[i+1] = 1;
        pre[i+2] = pre[i+1] + can1[i+1];
    }
    can2[c.size()] = true; pre[c.size()+1] = 0; pre[c.size()] = 1;
    for(int i = (int)c.size()-1; i >= 0; i --)
    {
        if(pre[i+1] - pre[i+c[i]+1])
            can2[i] = 1;
        pre[i] = pre[i+1] + can2[i];
    }
    for(int i = 0; i <= c.size(); i ++)
        if(can1[i])
            ver += pre[i];
    can1.reset(); can1[0] = 1; pre[0] = 0; pre[1] = 1;
    for(int i = 0; i < r.size(); i ++)
    {
        if(pre[i+1] - pre[i+1-r[i]])
            can1[i+1] = true;
        pre[i+2] = pre[i+1] + can1[i+1];
    }
    can2.reset(); can2[r.size()] = 1; pre[r.size()+1] = 0; pre[r.size()] = 1;
    for(int i = (int)r.size()-1; i >= 0; i --)
    {
        if(pre[i+1] - pre[i+r[i]+1])
            can2[i] = true;
        pre[i] = pre[i+1] + can2[i];
    }
    for(int i = 0; i <= r.size(); i ++)
        if(can1[i])
            hor += pre[i];
    ans = hor * ver;
    fout << ans << "\n";
    return 0;
}
