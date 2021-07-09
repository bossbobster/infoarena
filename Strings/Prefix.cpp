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

ifstream fin("prefix.in");
ofstream fout("prefix.out");

int kmp[1000010];
int main()
{
    int t, x, ans;
    string st;
    fin >> t;
    while(t--)
    {
        fin >> st;
        kmp[0] = -1; kmp[1] = ans = 0;
        for(int i = 2; i <= st.length(); i ++)
        {
            x = kmp[i-1];
            while(x != -1 && st[x] != st[i-1])
                x = kmp[x];
            kmp[i] = x+1;
            if(i % (i - kmp[i]) == 0 && kmp[i] != 0) ans = i;
        }
        fout << ans << "\n";
    }
}
