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

ifstream fin("bile5.in");
ofstream fout("bile5.out");

int t, n, mx, st, en, hi, st2, en2, tmp;
pii nums[15010];
pii cur[15010];
int val[15010];
int take(int num)
{
    int ans = 0;
    memset(val, 0, sizeof(val)); ans = 0;
    for(int i = 0; i < n; i ++) cur[i] = nums[i];
    val[0] += num; cur[0].f -= num;
    for(int i = 0; i < n; i ++)
    {
        tmp = min(cur[i].s-val[i], cur[(i+n-1)%n].f);
        val[i] += tmp; cur[(i+n-1)%n].f -= tmp;
        //if(cur[i].f == cur[i].s) continue;
        if(i != 0)
        {
            tmp = min(cur[i].s-val[i], cur[i].f);
            val[i] += tmp; cur[i].f -= tmp;
        }
        ans += val[i];
    }
    return ans;
}
int main()
{
    fin >> t;
    while(t--)
    {
        fin >> n;
        for(int i = 0; i < n; i ++)
            fin >> nums[i].f >> nums[i].s;
        mx = min(nums[0].f, nums[0].s); st = take(0); en = take(mx);
        hi = take((mx + en - st + 1) >> 1);
        st2 = hi - st; en2 = mx + en - hi;
        for(int i = 0; i < st2; i ++)
            fout << st + i << '\n';
        for(int i = st2; i <= en2; i ++)
            fout << hi << '\n';
        for(int i = en2 + 1; i <= mx; i ++)
            fout << hi + en2 - i << '\n';
    }
}
