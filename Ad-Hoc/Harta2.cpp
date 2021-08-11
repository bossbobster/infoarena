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
 
ifstream fin("harta2.in");
ofstream fout("harta2.out");

struct pt
{
    ld x, y;
};
struct comp
{
    const bool operator()(pt p1, pt p2)
    {
        if(p1.y == p2.y) return p1.x < p2.x;
        return p1.y < p2.y;
    }
};
bool comp2(pt p1, pt p2)
{
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}
ld len(pt p1, pt p2)
{
    return max(abs(p1.x - p2.x), abs(p1.y - p2.y));
}
pt nums[200010];
set<pt, comp> cur;
int main()
{
    int n, idx = 0;
    ld ans = 2000000000, dist;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].x >> nums[i].y, nums[i].x/=3;
    sort(nums, nums + n, comp2);
    cur.insert(nums[0]);
    for(int i = 1; i < n; i ++)
    {
        dist = ans+1;
        while(nums[i].x - nums[idx].x > dist) { cur.erase(nums[idx]); idx ++; }
        if(!cur.empty())
            for(auto it = cur.lower_bound({nums[i].x, nums[i].y - dist}); it != cur.upper_bound({nums[i].x, nums[i].y + dist}); ++it)
                ans = min(ans, len(*it, nums[i]));
        cur.insert(nums[i]);
    }
    fout << fixed << setprecision(5) << ans << "\n";
}
