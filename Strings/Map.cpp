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

ifstream fin("map.in");
ofstream fout("map.out");

string nums[2010];
int kmp[2010];
bool cur[2010][2010];
int main()
{
    int n, m, x;
    bool good;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        kmp[0] = -1; kmp[1] = 0;
        for(int j = 2; j <= m; j ++)
        {
            x = kmp[j-1];
            while(x != -1 && nums[i][x] != nums[i][j-1])
                x = kmp[x];
            kmp[j] = x+1;
        }
        x = kmp[m];
        while(x > m/2)
        {
            cur[i][x] = true;
            x = kmp[x];
        }
    }
    for(int i = m/2+1; i <= m; i ++)
    {
        good = true;
        for(int j = 0; j < n; j ++)
            if(!cur[j][i])
            {
                good = false;
                break;
            }
        if(good)
        {
            fout << i << "\n";
            return 0;
        }
    }
    fout << m << "\n";
}
