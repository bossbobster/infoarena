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

ifstream fin("ksecv.in");
ofstream fout("ksecv.out");

int nums[100010], dp[2][100010];
stack<pii> st;
int main()
{
    int n, k, mn;
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i];
        dp[0][i] = max(dp[0][max(0, i-1)], nums[i]);
    }
    for(int i = 1; i < k; i ++)
    {
        for(int j = 0; j < n; j ++) dp[i%2][j] = 2000000000;
        while(st.size()) st.pop();
        for(int j = i; j < n; j ++)
        {
            mn = dp[(i+1)%2][j-1];
            while(st.size() && st.top().s <= nums[j])
            {
                mn = min(mn, st.top().f); st.pop();
            }
            if(st.empty() || st.top().f+st.top().s >= mn+nums[j])
                st.push({mn, nums[j]});
            dp[i%2][j] = st.top().f + st.top().s;
        }
    }
    fout << dp[(k+1)%2][n-1] << "\n";
}
