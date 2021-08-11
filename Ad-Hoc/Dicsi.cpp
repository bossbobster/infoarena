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

ifstream fin("dicsi.in");
ofstream fout("dicsi.out");

int n, tmp, cnt, mx = 0;
bitset<100010> composite;
vector<pii> fac[100010];
void findPrimes()
{
    for(int i = 2; i <= n; i ++)
    {
        if(composite[i]) continue;
        fac[i].push_back({i, 1});
        for(int j = 2; i*j <= n; j ++)
        {
            composite[i*j] = 1;
            tmp = j; cnt = 1;
            while(tmp%i==0)
                cnt++, tmp/=i;
            fac[i*j].push_back({i, cnt});
        }
    }
}
int ans[100010];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i ++)
        fac[i].reserve(7);
    findPrimes();
    for(int i = 1; i <= n; i ++)
    {
        cnt = 0;
        for(auto it : fac[i])
            cnt += it.s;
        ans[i] = cnt+1;
        mx = max(mx, ans[i]);
    }
    fout << mx << "\n";
    for(int i = 1; i <= n; i ++)
        fout << ans[i] << ((i==n)?'\n':' ');
}
