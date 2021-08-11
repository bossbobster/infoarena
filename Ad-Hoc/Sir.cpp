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
 
ifstream fin("sir.in");
ofstream fout("sir.out");
 
multiset<short> cur;
short nums[100010];
int main()
{
    int n, x, y, z, idx1 = 0, idx2 = 0, mx = 0, l, r;
    fin >> n >> x >> y >> z;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    while(idx2 < n)
    {
        cur.insert(nums[idx2]), idx2 ++;
        while(idx1 < idx2 && (*prev(cur.end()) - *cur.begin() > z || idx2 - idx1 > y))
            cur.erase(cur.find(nums[idx1])), idx1 ++;
        if(idx2 - idx1 >= mx && idx2 - idx1 >= x && idx2 - idx1 <= y)
            mx = idx2 - idx1, l = idx1+1, r = idx2;
    }
    if(!mx) fout << "-1\n";
    else fout << mx << ' ' << l << ' ' << r << '\n';
}
