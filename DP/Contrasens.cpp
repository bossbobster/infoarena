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
 
ifstream fin("contrasens.in");
ofstream fout("contrasens.out");
 
int mod = 666013;
int md(ll a, ll b)
{
    if(a < 0) return (int)((b * (abs(a) / b + 1) + a) % b);
    return (int)(a % b);
}
bitset<100010> board[4];
int dp[4][100010];
int main()
{
    int n, p, sumL = 0, sumR = 0;
    char tmp;
    fin >> n >> p;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < 2; j ++)
        {
            fin >> tmp;
            board[j+1][i] = (tmp-'0');
        }
    board[0] = board[3] = 0;
    for(int i = 0; i < 4; i ++)
        if(!board[i][0])
            dp[i][0] = 1;
    for(int j = 1; j < n; j ++)
    {
        if(j-p-1 >= 0) { sumL = md(sumL - dp[1][j-p-1], mod); sumR = md(sumR - dp[2][j-p-1], mod); }
        sumL = (sumL + dp[1][j-1]) % mod; sumR = (sumR + dp[2][j-1]) % mod;
        for(int i = 0; i < 4; i ++)
        {
            if(board[i][j]) continue;
            if(i == 0)
                dp[i][j] = sumL + (j<p);
            else if(i == 3)
                dp[i][j] = sumR + (j<p);
            else
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i][j-1] + dp[i+1][j-1]) % mod;
        }
    }
    fout << (dp[0][n-1] + dp[1][n-1] + dp[2][n-1] + dp[3][n-1]) % mod << "\n";
}
