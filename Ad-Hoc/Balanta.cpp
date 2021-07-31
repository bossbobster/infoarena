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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ifstream fin("balanta.in");
ofstream fout("balanta.out");

int nums[1030][1030];
bitset<1030> b[2][1030];
bitset<1030> cur[2];
int res[1030];
int main()
{
    int n, m, k;
    fin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        fin >> k;
        for(int j = 0; j < k*2; j ++)
        {
            fin >> nums[i][j];
            b[j/k][i][nums[i][j]] = 1;
        }
        fin >> res[i];
    }
    cur[0].flip(); cur[1].flip();
    for(int i = 0; i < m; i ++)
    {
        if(res[i] == 1)
        {
            cur[0] &= b[0][i]; cur[1] &= b[1][i];
            b[0][i].flip(); b[1][i].flip();
            cur[1] &= b[0][i]; cur[0] &= b[1][i];
        }
        else if(res[i] == 2)
        {
            cur[1] &= b[0][i]; cur[0] &= b[1][i];
            b[0][i].flip(); b[1][i].flip();
            cur[0] &= b[0][i]; cur[1] &= b[1][i];
        }
        else
        {
            b[0][i].flip(); b[1][i].flip();
            cur[0] &= b[0][i]; cur[1] &= b[1][i];
            cur[1] &= b[0][i]; cur[0] &= b[1][i];
        }
    }
    if((cur[0].count() == 1 && cur[1].count() == 0) || (cur[0].count() == 0 && cur[1].count() == 1))
    {
        for(int i = 1; i <= n; i ++)
            if(cur[0][i] || cur[1][i])
                fout << i << "\n";
        
    }
    else
        fout << "0\n";
}
