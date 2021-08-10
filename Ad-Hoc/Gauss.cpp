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

ifstream fin("gauss.in");
ofstream fout("gauss.out");

const ld eps = 1e-11;
ld nums[310][310];
ld arr[310];
int main()
{
    int n, m, i = 0, j = 0, k;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= m; j ++)
            fin >> nums[i][j];
    while(i < n && j < m)
    {
        for(k = i; k < n; k ++)
            if(abs(nums[k][j]) > eps)
                break;
        if(k == n) { j++; continue; }
        if(k != i)
            for(int l = 0; l <= m; l ++)
                swap(nums[i][l], nums[k][l]);
        for(int l = j+1; l <= m; l ++)
            nums[i][l] /= nums[i][j];
        nums[i][j] = 1;
        for(int nx = i+1; nx < n; nx ++)
        {
            for(int l = j+1; l <= m; l ++)
                nums[nx][l] -= nums[nx][j] * nums[i][l];
            nums[nx][j] = 0;
        }
        i ++; j ++;
    }
    for(int i = n-1; i >= 0; i --)
        for(int j = 0; j <= m; j ++)
            if(abs(nums[i][j]) > eps)
            {
                if(j == m) { fout << "Imposibil\n"; return 0; }
                arr[j] = nums[i][m];
                for(k = j+1; k < m; k ++)
                    arr[j] -= arr[k] * nums[i][k];
                break;
            }
    for(int i = 0; i < m; i ++)
        fout << fixed << setprecision(10) << arr[i] << ((i==m-1)?'\n':' ');
}
