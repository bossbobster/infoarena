#include <iostream>
#include <string.h>
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

ifstream fin("pscpld.in");
ofstream fout("pscpld.out");

int dp[2000010];
ll ans = 0;
int main()
{
    string st = "."; st.reserve(2000010);
    int mx = -1, idx = -1, j;
    string og; fin >> og;
    for(int i = 0; i < og.length(); i ++)
        st += og[i], st += ".";
    for(int i = 0; i < st.length(); i ++)
    {
        if(i > mx)
        {
            for(j = 1; i-j >= 0 && i+j < st.length() && st[i-j] == st[i+j]; j ++) {}
            j --; dp[i] = j;
            mx = i+j; idx = i;
        }
        else
        {
            if(dp[idx*2-i]+i < mx)
                dp[i] = dp[idx*2-i];
            else
            {
                for(j = 1; 2*i-mx-j >= 0 && mx+j < st.length() && st[2*i-mx-j] == st[mx+j]; j ++) {}
                j --; dp[i] = mx+j-i;
                mx += j; idx = i;
            }
        }
    }
    for(int i = 0; i < st.length(); i ++)
    {
        if(i%2)
            ans += dp[i]/2+1;
        else
            ans += (dp[i]+1)/2;
    }
    fout << ans << "\n";
}
