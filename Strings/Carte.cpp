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

ifstream fin("carte.in");
ofstream fout("carte.out");
 
int kmp[6010];
bitset<10000010> can;
int dp[3010];
int main()
{
    input();
    int t, n, x;
    string st, s1, d;
    fin >> t;
    while(t--)
    {
        fin >> st >> n;
        can.reset();
        for(int i = 0; i < n; i ++)
        {
            fin >> d;
            if(d.length() > st.length()) continue;
            s1 = d + st;
            kmp[0] = -1; kmp[1] = 0;
            for(int j = 1; j < s1.length(); j ++)
            {
                x = kmp[j];
                while(x != -1 && s1[x] != s1[j])
                    x = kmp[x];
                kmp[j+1] = x+1;
                while(kmp[j+1] > d.length())
                    kmp[j+1] = kmp[kmp[j+1]];
            }
            for(int j = (int)d.length()*2; j <= (int)s1.length(); j ++)
                if(kmp[j] == d.length())
                    can[(j-(int)d.length()-1) * (int)st.length() + (j - (int)d.length()*2)] = true;
        }
        for(int i = 0; i <= (int)st.length(); i ++)
            dp[i] = 2000000000;
        dp[0] = 0;
        for(int i = 1; i <= (int)st.length(); i ++)
        {
            dp[i] = dp[i-1]+1;
            for(int j = i; j > 0; j --)
                if(can[(i-1) * (int)st.length() + (j-1)])
                    dp[i] = min(dp[i], dp[j-1]);
        }
        fout << dp[(int)st.length()] << "\n";
    }
}
