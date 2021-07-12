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

ifstream fin("numarare.in");
ofstream fout("numarare.out");

int dp[200010];
int og[100010];
vector<int> st;
int main()
{
    st.reserve(200010);
    int n, mx = -1, idx = -1, j;
    ll ans = 0, sum;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> og[i];
    for(int i = 0; i < n; i ++)
    {st.push_back(og[i]); st.push_back(1000000000);}
    for(int i = 0; i < st.size(); i ++)
    {
        if(i%2==0) continue;
        if(i > mx)
        {
            sum = st[i-1] + st[i+1];
            for(j = 1; i-j > -1 && i+j < st.size() && (st[i-j] + st[i+j] == sum || st[i-j] + st[i+j] == 2000000000); j ++) {}
            j --; dp[i] = j;
            mx = i+j; idx = i;
        }
        else
        {
            if(dp[idx*2-i]+i < mx)
                dp[i] = dp[idx*2-i];
            else
            {
                sum = st[2*i-mx+(mx%2)] + st[mx-(mx%2)];
                for(j = 1; 2*i-mx-j > -1 && mx+j < st.size() && (st[2*i-mx-j] + st[mx+j] == sum || st[2*i-mx-j] + st[mx+j] == 2000000000); j ++) {}
                j --; dp[i] = mx+j-i;
                mx += j; idx = i;
            }
        }
    }
    for(int i = 0; i < st.size(); i ++)
        ans += (dp[i]+1)/2;
    fout << ans << "\n";
}
