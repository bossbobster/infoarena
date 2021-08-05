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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ifstream fin("fibo3.in");
ofstream fout("fibo3.out");

const int lim = 80;
ll fib[90];
ll sum(ll x, ll y)
{
    if(x < 1 && y < 1) return 0;
    ll r, ans = 0;
    for(int i = 1; i < lim; i ++)
    {
        if(fib[i] >= x)
        {
            r = fib[i] - x;
            ans += min(x+1, max(0ll, y-r+1));
        }
        else
        {
            ans += min(y+1, fib[i]+1);
        }
    }
    return ans;
}
int main()
{
    ll n, x1, y1, x2, y2;
    fin >> n;
    fib[0] = 1; fib[1] = 1;
    for(int i = 2; i < lim; i ++)
        fib[i] = fib[i-1] + fib[i-2];
    while(n--)
    {
        fin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        fout << sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1) << "\n";
    }
}
