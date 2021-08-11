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

ifstream fin("23.in");
ofstream fout("23.out");

pii qs[1010];
int ans[1010];
int main()
{
    int t, idx = 0, cur = 1, tmp, s1, s2;
    fin >> t;
    for(int i = 0; i < t; i ++)
        fin >> qs[i].f, qs[i].s = i;
    sort(qs, qs+t);
    s1 = s2 = 1;
    for(int i = 1; i <= qs[t-1].f; i ++)
    {
        while(idx < t && qs[idx].f == i) ans[qs[idx].s] = cur, idx++;
        tmp = i;
        s1++;
        while(tmp%2==1)
            s1--, tmp/=2;
        tmp = i;
        s2++;
        while(tmp%3==2)
            s2-=2, tmp/=3;
        if(s1 == s2) cur++;
    }
    for(int i = 0; i < t; i ++)
        fout << ans[i] << ((i==t-1)?'\n':' ');
}
