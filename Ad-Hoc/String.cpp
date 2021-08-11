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

ifstream fin("string.in");
ofstream fout("string.out");

int n, mx, ans, num, cnt = 0;
string og;
bitset<500010> st, vis;
int pw[40];
int bs(int l, int r)
{
    int mid = (l+r)/2;
    if(l >= r) return l;
    vis.reset();
    num = cnt = 0;
    for(int i = 0; i < mid; i ++)
        num += (int)st[i] * pw[i];
    vis[num] = 1; cnt++;
    for(int i = mid; i < n; i ++)
    {
        num >>= 1;
        num += (int)st[i] * pw[mid-1];
        if(!vis[num]) cnt++;
        vis[num] = 1;
    }
    if(cnt == pw[mid]) return bs(mid+1, r);
    return bs(l, mid);
}
int main()
{
    fin >> n >> og;
    mx = log2(n)+1;
    for(int i = 0; i < n; i ++)
        st[i] = (og[i]=='a');
    pw[0] = 1;
    for(int i = 1; i < 31; i ++)
        pw[i] = pw[i-1] * 2;
    ans = bs(1, mx);
    fout << ans << "\n";
    vis.reset();
    num = cnt = 0;
    for(int i = 0; i < ans; i ++)
        num += (int)st[i] * pw[i];
    vis[num] = 1;
    for(int i = ans; i < n; i ++)
    {
        num >>= 1;
        num += (int)st[i] * pw[ans-1];
        vis[num] = 1;
    }
    for(int i = 0; i < pw[ans]; i ++)
        if(!vis[i])
        {
            string out = ""; out.reserve(ans);
            for(int j = 0; j < ans; j ++)
            {
                if(i%2) out += "a";
                else out += "b";
                i/=2;
            }
            fout << out << "\n";
            return 0;
        }
}
