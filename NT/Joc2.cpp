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

ifstream fin("joc2.in");
ofstream fout("joc2.out");
 
int nums[110][2];
int dp[110][110];
bool taken[110];
int main()
{
    int n, ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i][0] >> nums[i][1];
    dp[1][1] = 0; dp[1][2] = 1; dp[2][1] = 1;
    for(int i = 1; i <= 100; i ++)
        for(int j = 1; j <= 100; j ++)
        {
            memset(taken, false, sizeof(taken));
            if(i > 2 && j > 2) taken[dp[i-2][j-2]] = true;
            if(i > 2)
                for(int k = 1; k < i-1; k ++)
                    taken[dp[k][j] ^ dp[i-k-1][j]] = true;
            if(j > 2)
                for(int k = 1; k < j-1; k ++)
                    taken[dp[i][k] ^ dp[i][j-k-1]] = true;
            for(int k = 1; k < i; k ++)
                taken[dp[k][j] ^ dp[i-k][j]] = true;
            for(int k = 1; k < j; k ++)
                taken[dp[i][k] ^ dp[i][j-k]] = true;
            for(int k = 0; k < 100; k ++)
                if(!taken[k])
                {
                    dp[i][j] = dp[j][i] = k;
                    break;
                }
        }
    int x = 0;
    for(int i = 0; i < n; i ++)
        x ^= dp[nums[i][0]][nums[i][1]];
    for(int i = 0; i < n; i ++)
    {
        x ^= dp[nums[i][0]][nums[i][1]];
        if(nums[i][0] > 2 && nums[i][1] > 2) ans += (((x^dp[nums[i][0]-2][nums[i][1]-2])==0)?1:0);
        if(nums[i][0] > 2)
            for(int k = 1; k < nums[i][0]-1; k ++)
                ans += (((x^dp[k][nums[i][1]]^dp[nums[i][0]-k-1][nums[i][1]])==0)?1:0);
        if(nums[i][1] > 2)
            for(int k = 1; k < nums[i][1]-1; k ++)
                ans += (((x^dp[nums[i][0]][k]^dp[nums[i][0]][nums[i][1]-k-1])==0)?1:0);
        for(int k = 1; k < nums[i][0]; k ++)
            ans += (((x^dp[k][nums[i][1]]^dp[nums[i][0]-k][nums[i][1]])==0)?1:0);
        for(int k = 1; k < nums[i][1]; k ++)
            ans += (((x^dp[nums[i][0]][k]^dp[nums[i][0]][nums[i][1]-k])==0)?1:0);
        x ^= dp[nums[i][0]][nums[i][1]];
    }
    fout << ans << "\n";
}
