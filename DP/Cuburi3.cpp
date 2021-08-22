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

ifstream fin("cuburi3.in");
ofstream fout("cuburi3.out");

int n;
piii nums[4010];
int dp[4010], cnt[4010], par[4010];
int main()
{
    int ans = 0, num, ans2;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].f.s >> nums[i].f.f, nums[i].s = i;
    sort(nums, nums+n);
    for(int i = 0; i < n; i ++)
        dp[i] = nums[i].f.s, cnt[i] = 1;
    memset(par, -1, sizeof(par));
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < i; j ++)
            if(nums[i].f.s >= nums[j].f.s && dp[j] + nums[i].f.s > dp[i])
            {
                dp[i] = dp[j] + nums[i].f.s, par[i] = j, cnt[i] = cnt[j]+1;
                if(dp[i] > ans)
                    ans = dp[i], ans2 = cnt[i], num = i;
            }
    fout << ans2 << ' ' << ans << '\n';
    while(num != -1)
    {
        fout << nums[num].s+1 << '\n';
        num = par[num];
    }
}
