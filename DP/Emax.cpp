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

ifstream fin("emax.in");
ofstream fout("emax.out");

ll mod = 666013;
vector<ll> nums;
ll dp[100010];
double logs[100010];
int main()
{
    int n;
    ll num, mult1, mult2, mult3;
    fin >> n;
    nums.reserve(n);
    for(int i = 0; i < n; i ++)
    {
        fin >> num;
        if(num != 0) nums.push_back(abs(num));
    }
    dp[0] = nums[0]; dp[1] = max(nums[0] * nums[1], nums[0] + nums[1]);
    dp[2] = max({dp[1]+nums[2], dp[1]*nums[2], dp[0]*(nums[1]+nums[2])});
    logs[0] = log2(dp[0]); logs[1] = log2(dp[1]); logs[2] = log2(dp[2]);
    dp[2] %= mod;
    for(int i = 3; i < nums.size(); i ++)
    {
        mult1 = max({nums[i-2]+nums[i-1]+nums[i], nums[i-2]*nums[i-1]*nums[i], (nums[i-2]+nums[i-1])*nums[i], nums[i-2]*(nums[i-1]+nums[i])});
        mult2 = max(nums[i-1]+nums[i], nums[i-1]*nums[i]);
        mult3 = nums[i];
        if(logs[i-3] + log2((double)mult1) > logs[i])
        {
            logs[i] = logs[i-3] + log2((double)mult1);
            dp[i] = (dp[i-3] * mult1) % mod;
        }
        if(logs[i-2] + log2((double)mult2) > logs[i])
        {
            logs[i] = logs[i-2] + log2((double)mult2);
            dp[i] = (dp[i-2] * mult2) % mod;
        }
        if(logs[i-1] + log2((double)mult3) > logs[i])
        {
            logs[i] = logs[i-1] + log2((double)mult3);
            dp[i] = (dp[i-1] * mult3) % mod;
        }
    }
    fout << dp[nums.size()-1] << "\n";
}
