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

ifstream fin("poly.in");
ofstream fout("poly.out");

int arr[7] = {2, 3, 7, 11, 19, 23, 37};
int nums[30010];
int dp[150];
bitset<7> b;
int main()
{
    int n, ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        b.reset();
        for(int j = 0; j < 7; j ++)
            if(nums[i] % arr[j] == 0)
                b[j] = 1;
        for(int j = 0; j < 128; j ++)
            if(!(j & b.to_ullong()))
                dp[b.to_ullong()] = max(dp[b.to_ullong()], dp[j]+1);
        ans = max(ans, dp[b.to_ullong()]);
    }
    fout << ans << "\n";
}
