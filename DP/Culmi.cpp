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
 
ifstream fin("culmi.in");
ofstream fout("culmi.out");
 
bitset<188> add(bitset<188> b1, bitset<188> b2)
{
    bitset<188> carry;
    while(b2 != 0)
    {
        carry = b1 & b2;
        b1 ^= b2;
        b2 = carry << 1;
    }
    return b1;
}
string addS(string s1, string s2)
{
    if(s1.length() < s2.length()) swap(s1, s2);
    int carry = 0, res;
    for(int i = 0; i < s2.length(); i ++)
    {
        res = s1[s1.length()-i-1]-'0' + s2[s2.length()-i-1]-'0' + carry;
        s1[s1.length()-i-1] = (res%10)+'0';
        carry = res/10;
    }
    int idx = (int)s2.length();
    while(carry && idx < s1.length())
    {
        res = s1[s1.length()-idx-1]-'0' + carry;
        s1[s1.length()-idx-1] = (res%10)+'0';
        carry = res/10;
        idx ++;
    }
    if(carry) s1 = to_string(carry) + s1;
    return s1;
}
 
bitset<188> dp[2][110][110][2]; //index i, j peaks, k = number of + used, l = 0 last char was '/', l = 1 last char was '\'
int main()
{
    int n, k;
    string mult = "1", ans = "0";
    fin >> n >> k;
    for(int i = 0; i < 2; i ++) for(int j = 0; j < 110; j ++) for(int k = 0; k < 110; k ++) for(int l = 0; l < 2; l ++) dp[i][j][k][l] = 0;
    dp[0][0][1][0] = 1;
    for(int i = 1; i < 2*n; i ++)
    {
        for(int j = 0; j <= n; j ++) for(int k = 0; k <= i+1; k ++) dp[i%2][j][k][0] = dp[i%2][j][k][1] = 0;
        for(int j = 0; j <= (i+1)/2; j ++)
        {
            for(int k = (i+2)/2; k <= i+1; k ++)
            {
                dp[i%2][j][k][0] = add(dp[(i-1)%2][j][k-1][0], dp[(i-1)%2][j][k-1][1]);
                if(j != 0) dp[i%2][j][k][1] = add(dp[(i-1)%2][j-1][k][0], dp[(i-1)%2][j][k][1]);
            }
        }
    }
    int carry, res;
    for(int i = 0; i < 188; i ++)
    {
        if(dp[(2*n-1)%2][k][n][1][i])
            ans = addS(ans, mult);
        carry = 0;
        for(int j = (int)mult.length()-1; j >= 0; j --)
        {
            res = (mult[j]-'0') * 2 + carry;
            mult[j] = res%10+'0';
            carry = res/10;
        }
        if(carry) mult = to_string(carry) + mult;
    }
    fout << ans << "\n";
}
