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

ifstream fin("doipe.in");
ofstream fout("doipe.out");

const int mod = 29997;
int dp[2][2010];
int main()
{
    int t, n, ans;
    char c;
    fin >> t;
    while(t--)
    {
        fin >> n;
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        for(int i = 1; i < n; i ++)
        {
            fin >> c;
            if(c == '<')
                for(int j = 1; j < i+2; j ++)
                    dp[i%2][j] = (dp[i%2][j-1] + dp[(i+1)%2][j-1]) % mod;
            else
                for(int j = i+1; j > 0; j --)
                    dp[i%2][j] = (dp[i%2][j+1] + dp[(i+1)%2][j]) % mod;
        }
        ans = 0;
        for(int j = 1; j <= n; j ++)
            ans = (ans + dp[(n+1)%2][j]) % mod;
        fout << ans << "\n";
    }
}
