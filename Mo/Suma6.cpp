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

ifstream fin("suma6.in");
ofstream fout("suma6.out");

struct st
{
    int a, b, idx;
};
int n, q, S, sq;
ll cur = 0;
bool comp(st s1, st s2)
{
    if(s1.a/sq != s2.a/sq) return s1.a < s2.a;
    return s1.b < s2.b;
}
int nums[100010];
st qs[200010];
ll cnt[1000010];
void add(int l, int r)
{
    if(l > r) swap(l, r);
    for(int i = l; i <= r; i ++)
        if(nums[i] <= S)
        {
            cur += cnt[S-nums[i]];
            cnt[nums[i]]++;
        }
}
void sub(int l, int r)
{
    if(l > r) swap(l, r);
    for(int i = l; i <= r; i ++)
        if(nums[i] <= S)
        {
            cnt[nums[i]]--;
            cur -= cnt[S-nums[i]];
        }
}
ll ans[200010];
int main()
{
    fin >> n >> S;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    sq = sqrt(n);
    fin >> q;
    for(int i = 0; i < q; i ++)
    {
        fin >> qs[i].a >> qs[i].b;
        qs[i].a--; qs[i].b--;
        qs[i].idx = i;
    }
    sort(qs, qs+q, comp);
    add(qs[0].a, qs[0].b);
    ans[qs[0].idx] = cur;
    for(int i = 1; i < q; i ++)
    {
        if(qs[i].a != qs[i-1].a)
        {
            if(qs[i].a < qs[i-1].a) add(qs[i].a, qs[i-1].a-1);
            else sub(qs[i-1].a, qs[i].a-1);
        }
        if(qs[i].b != qs[i-1].b)
        {
            if(qs[i].b < qs[i-1].b) sub(qs[i].b+1, qs[i-1].b);
            else add(qs[i-1].b+1, qs[i].b);
        }
        ans[qs[i].idx] = cur;
    }
    for(int i = 0; i < q; i ++)
        fout << ans[i] << '\n';
}
