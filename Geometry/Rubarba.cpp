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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ifstream fin("rubarba.in");
ofstream fout("rubarba.out");

const ld pi = 3.141592653589793238462643383279;

int n;
ld mxX, mxY, mnX, mnY, sn, cs;
vector<pair<ld, ld>> nums;
vector<ld> angles;
ld ans(ld ang)
{
    mxX = mxY = -2000000000000000000; mnX = mnY = 2000000000000000000;
    sn = sin(ang), cs = cos(ang);
    for(int i = 0; i < n; i ++)
        mxX = max(mxX, nums[i].f*cs - nums[i].s*sn), mnX = min(mnX, nums[i].f*cs - nums[i].s*sn), mxY = max(mxY, nums[i].f*sn + nums[i].s*cs), mnY = min(mnY, nums[i].f*sn + nums[i].s*cs);
    ld ret = (mxX-mnX) * (mxY-mnY);
    return ret;
}
ld bs(ld l, ld r)
{
    ld mid = (l+r)/2;
    if(r - l <= 0.00000000000000001) return mid;
    if(ans(mid) > ans(mid + 0.00000000000000001))
        return bs(mid, r);
    return bs(l, mid);
}
int main()
{
    fin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i ++)
        fin >> nums[i].f >> nums[i].s;
    fout << fixed << setprecision(10) << ans(bs(0, pi/2)) << "\n";
}
