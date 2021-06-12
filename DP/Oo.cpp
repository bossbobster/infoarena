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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);
 
ifstream fin("oo.in");
ofstream fout("oo.out");
 
int nums[100010];
int dp[100010];
int main()
{
    int n, ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    dp[0] = 0; dp[1] = nums[0] + nums[1];
    for(int i = 2; i < n-1; i ++)
        dp[i] = max({dp[max(0, i-3)], dp[max(0, i-4)], dp[max(0, i-5)]}) + nums[i-1] + nums[i];
    ans = max({dp[max(1, n-2)], dp[max(1, n-3)], dp[max(1, n-4)]});
    dp[0] = 0; dp[1] = nums[1] + nums[2];
    for(int i = 2; i < n-1; i ++)
        dp[i] = max({dp[max(0, i-3)], dp[max(0, i-4)], dp[max(0, i-5)]}) + nums[i] + nums[i+1];
    ans = max({ans, dp[max(1, n-2)], dp[max(1, n-3)], dp[max(1, n-4)]});
    dp[0] = dp[1] = 0; dp[2] = nums[2] + nums[3];
    for(int i = 3; i < n-1; i ++)
        dp[i] = max({dp[max(0, i-3)], dp[max(0, i-4)], dp[max(0, i-5)]}) + nums[i] + nums[i+1];
    ans = max({ans, dp[max(1, n-2)], dp[max(1, n-3)], dp[max(1, n-4)]});
    dp[0] = dp[2] = dp[3] = 0; dp[1] = nums[0] + nums[n-1];
    for(int i = 4; i < n-1; i ++)
        dp[i] = max({dp[max(0, i-3)], dp[max(0, i-4)], dp[max(0, i-5)]}) + nums[i-2] + nums[i-1];
    fout << max({ans, dp[max(1, n-2)], dp[max(1, n-3)], dp[max(1, n-4)]}) << "\n";
}
