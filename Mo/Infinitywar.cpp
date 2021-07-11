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

ifstream fin("infinitywar.in");
ofstream fout("infinitywar.out");
 
struct st
{
    int a, b, idx;
};
int sq;
bool comp(st s1, st s2)
{
    if(s1.a/sq != s2.a/sq) return s1.a < s2.a;
    return s1.b < s2.b;
}
vector<int> nums[50010];
st qs[100010];
bitset<10010> bs, tmp;
bitset<10010> all[310];
int ans[100010], idxs[50010];
void rangeF(int l, int r)
{
    if(l > r) swap(l, r);
    for(int i = l; i <= r; i ++)
    {
        if(nums[i].size() >= 1000)
            bs ^= all[idxs[i]];
        else
            for(int j = 0; j < nums[i].size(); j ++)
                bs.flip(nums[i][j]);
    }
}
int main()
{
    int n, q, sz, num, idx = 0;
    fin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        fin >> sz;
        if(sz >= 1000)
            idxs[i] = idx++;
        for(int j = 0; j < sz; j ++)
        {
            fin >> num;
            nums[i].push_back(num);
            if(sz >= 1000)
                all[idx-1][num] = 1;
        }
    }
    sq = sqrt(n);
    for(int i = 0; i < q; i ++)
    {
        fin >> qs[i].a >> qs[i].b;
        qs[i].a--; qs[i].b--;
        qs[i].idx = i;
    }
    sort(qs, qs+q, comp);
    rangeF(qs[0].a, qs[0].b);
    ans[qs[0].idx] = bs.count();
    for(int i = 1; i < q; i ++)
    {
        if(qs[i].a != qs[i-1].a)
        {
            if(qs[i].a < qs[i-1].a) rangeF(qs[i].a, qs[i-1].a-1);
            else rangeF(qs[i-1].a, qs[i].a-1);
        }
        if(qs[i].b != qs[i-1].b)
        {
            if(qs[i].b < qs[i-1].b) rangeF(qs[i].b+1, qs[i-1].b);
            else rangeF(qs[i-1].b+1, qs[i].b);
        }
        ans[qs[i].idx] = bs.count();
    }
    for(int i = 0; i < q; i ++)
        fout << ans[i] << "\n";
}
