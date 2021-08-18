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
 
ifstream fin("strabunica.in");
ofstream fout("strabunica.out");
 
stack<pll> s;
ll nums[200010], r[200010], l[200010];
int main()
{
    int n; ll ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i < n; i ++) l[i] = -1, r[i] = n;
    for(int i = 0; i < n; i ++)
    {
        while(!s.empty() && s.top().f > nums[i])
        {
            r[s.top().s] = i;
            s.pop();
        }
        s.push({nums[i], i});
    }
    while(!s.empty()) s.pop();
    for(int i = n-1; i >= 0; i --)
    {
        while(!s.empty() && s.top().f > nums[i])
        {
            l[s.top().s] = i;
            s.pop();
        }
        s.push({nums[i], i});
    }
    for(int i = 0; i < n; i ++)
        ans = max(ans, nums[i] * (r[i]-l[i]-1));
    fout << ans << "\n";
}
