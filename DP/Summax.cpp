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

ifstream fin("summax.in");
ofstream fout("summax.out");
 
int type, n, st, dr;
vector<uint>* nums[2010];
vector<uint> dp[2010];
vector<uint> cnt[2010];
void path(int idx)
{
    int c = 0;
    fout << 1 << " ";
    for(int i = 1; i < n; i ++)
    {
        if(cnt[i][c] < idx)
        {
            idx -= cnt[i][c];
            c ++;
        }
        fout << c+1 << ((i == n-1)?"\n":" ");
    }
}
int main()
{
    uint ans = 0;
    fin >> type >> n >> st >> dr;
    for(int i = 0; i < n; i ++)
    {
        nums[i] = new vector<uint>(i+1, 0); dp[i].resize(i+1, 0);
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= i; j ++)
            fin >> (*nums[i])[j];
    dp[0][0] = (*nums[0])[0];
    for(int i = 1; i < n; i ++)
        for(int j = 0; j <= i; j ++)
            dp[i][j] = max(dp[i-1][max(0, j-1)], dp[i-1][min(i-1, j)]) + (*nums[i])[j];
    for(int i = 0; i < n; i ++)
        ans = max(ans, dp[n-1][i]);
    cnt[n-1].resize(n, 0);
    for(int i = 0; i < n; i ++)
        if(dp[n-1][i] == ans)
            cnt[n-1][i] = 1;
    for(int i = n-1; i > 0; i --)
    {
        cnt[i-1].resize(i, 0);
        for(int j = 0; j <= i; j ++)
        {
            if(j == 0) cnt[i-1][j] = cnt[i][j];
            else
            {
                if(dp[i-1][j-1] == dp[i][j] - (*nums[i])[j])
                    cnt[i-1][j-1] = min(cnt[i-1][j-1] + cnt[i][j], (uint)2000000001);
                if(dp[i-1][j] == dp[i][j] - (*nums[i])[j])
                    cnt[i-1][j] = min(cnt[i-1][j] + cnt[i][j], (uint)2000000001);
            }
        }
        delete nums[i];
    }
    if(type == 1)
    {
        fout << cnt[0][0] << "\n";
        return 0;
    }
    for(int i = st; i <= dr; i ++)
        path(i);
}
