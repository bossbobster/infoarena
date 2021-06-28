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

ifstream fin("secv10.in");
ofstream fout("secv10.out");

int t, x, idx1, idx2;
ll sum, ans;
string S, st, dr, s1, s2;
int kmp1[200010], kmp2[200010];
vector<int> v1, v2;
int main()
{
    S.reserve(200000); st.reserve(200000); dr.reserve(200000); s1.reserve(200000); s2.reserve(200000); v1.reserve(200000); v2.reserve(200000);
    fin >> t;
    while(t--)
    {
        fin >> S >> st >> dr;
        s1 = st + S; s2 = dr + S;
        kmp1[0] = -1; kmp1[1] = 0;
        for(int i = 1; i < s1.length(); i ++)
        {
            x = kmp1[i];
            while(x != -1 && s1[x] != s1[i])
                x = kmp1[x];
            kmp1[i+1] = x+1;
            if(kmp1[i+1] > st.length())
                kmp1[i+1] = kmp1[kmp1[i+1]];
        }
        kmp2[0] = -1; kmp2[1] = 0;
        for(int i = 1; i < s2.length(); i ++)
        {
            x = kmp2[i];
            while(x != -1 && s2[x] != s2[i])
                x = kmp2[x];
            kmp2[i+1] = x+1;
            if(kmp2[i+1] > dr.length())
                kmp2[i+1] = kmp2[kmp2[i+1]];
        }
        v1.clear(); v2.clear();
        for(int i = (int)st.length()*2; i <= (int)s1.length(); i ++)
            if(kmp1[i] == st.length())
                v1.push_back(i - (int)st.length());
        for(int i = (int)dr.length()*2; i <= (int)s2.length(); i ++)
            if(kmp2[i] == dr.length())
            {
                if(dr.length() > st.length())
                    v2.push_back(i - (int)dr.length() - (int)dr.length() + (int)st.length());
                else
                    v2.push_back(i - (int)dr.length());
            }
        idx1 = idx2 = sum = ans = 0;
        for(int i = 0; i <= v2.back(); i ++)
        {
            if(v1[idx1] == i)
            {
                sum ++; idx1 ++;
            }
            if(v2[idx2] == i)
            {
                ans += sum; idx2 ++;
            }
        }
        fout << ans << "\n";
    }
}
