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

ifstream fin("calatorie.in");
ofstream fout("calatorie.out");

ll dp[510];
ll nk[60], hk[60];
int main()
{
    int t, n;
    ll sum = 0, ans;
    fin >> t;
    while(t--)
    {
        fin >> n;
        sum = 0;
        for(int i = 0; i < n-1; i ++)
        {
            fin >> nk[i] >> hk[i];
            sum += nk[i];
        }
        dp[0] = sum;
        for(int i = 1; i < 510; i ++)
            dp[i] = 200000000000000000;
        for(int i = 0; i < n-1; i ++)
            for(int j = 500; j > 0; j --)
                if(j-hk[i] >= 0 && dp[j-hk[i]] != 200000000000000000)
                    dp[j] = min(dp[j], dp[j-hk[i]]-nk[i]);
        ans = 200000000000000000;
        for(ll i = 0; i < 500; i ++)
            if(i*i*i*i + dp[i] < ans)
                ans = i*i*i*i + dp[i];
        fout << "Consumul minim = " << ans << ".\n";
    }
}
