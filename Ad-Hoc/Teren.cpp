#include <iostream>
#include <string.h>
#include <random>
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
#include <valarray>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
ifstream fin("teren.in");
ofstream fout("teren.out");

short board[310][310];
short pre[310][310];
int main()
{
    int n,m,x,idx1,idx2,cur,ans=0;
    fin >> n >> m >> x;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            fin >> board[i][j], pre[i][j+1] = pre[i][j] + board[i][j];
    for(int i = 0; i < m; i ++)
        for(int j = i; j < m; j ++)
        {
            idx1 = idx2 = cur = 0;
            while(idx2 < n)
            {
                cur += pre[idx2][j+1] - pre[idx2][i]; idx2++;
                while(cur > x) cur -= pre[idx1][j+1] - pre[idx1][i], idx1++;
                ans = max(ans, (j-i+1)*(idx2-idx1));
            }
        }
    fout << ans << '\n';
}
