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

ifstream fin("buline.in");
ofstream fout("buline.out");

int nums[200010];
int main()
{
    int n, n1, n2, sum = 0, cur, ans1 = -2000000000, ans2 = -2000000000, curL, l1 = 2000000000, len1, l2 = 2000000000, len2;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> n1 >> n2;
        if(n2) nums[i] = n1;
        else nums[i] = -n1;
        sum += nums[i];
    }
    cur = 0; curL = 0;
    for(int i = 0; i < n; i ++)
    {
        cur += nums[i];
        if(cur > ans1) ans1 = cur, l1 = curL, len1 = i-curL+1;
        else if(cur == ans1)
        {
            if(curL < l1) l1 = curL, len1 = i-curL+1;
            else if(curL == l1 && i-curL+1 > len1) len1 = i-curL+1;
        }
        if(cur < 0) cur = 0, curL = i+1;
    }
    for(int i = 0; i < n; i ++) nums[i] = -nums[i];
    cur = 0; curL = 0;
    for(int i = 0; i < n; i ++)
    {
        cur += nums[i];
        if(cur > ans2) ans2 = cur, l2 = curL, len2 = i-curL+1;
        if(cur <= 0) cur = 0, curL = i+1;
    }
    l2 += len2; len2 = n-len2; ans2 = sum+ans2;
    if(ans1 > ans2)
        fout << ans1 << " " << l1+1 << " " << len1 << "\n";
    else if(ans2 > ans1)
        fout << ans2 << " " << l2+1 << " " << len2 << "\n";
    else
    {
        if(l1 < l2)
            fout << ans1 << " " << l1+1 << " " << len1 << "\n";
        else
        {
            if(len1 > len2)
                fout << ans1 << " " << l1+1 << " " << len1 << "\n";
            else
                fout << ans2 << " " << l2+1 << " " << len2 << "\n";
        }
    }
}
