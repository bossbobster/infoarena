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
 
ifstream fin("knumere.in");
ofstream fout("knumere.out");
 
int og[1000010], nums[1000010];
deque<pii> q;
int main()
{
    int n, m, k, ans = 2000000000;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> og[i];
    for(int i = 0; i < n-1; i ++)
        nums[i] = og[i+1]-og[i];
    n--; k = n-m;
    for(int i = 0; i < k; i ++)
    {
        while(!q.empty() && nums[i] >= q.back().f) q.pop_back();
        q.push_back({nums[i], i});
    }
    ans = min(ans, q.front().f);
    for(int i = k; i < n; i ++)
    {
        if(!q.empty() && q.front().s == i - k) q.pop_front();
        while(!q.empty() && nums[i] >= q.back().f) q.pop_back();
        q.push_back({nums[i], i});
        ans = min(ans, q.front().f);
    }
    fout << ans << '\n';
}
