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
 
ifstream fin("ttg.in");
ofstream fout("ttg.out");
 
vector<pii> t;
map<int, int, greater<int>> cur;
int main()
{
    int m, n, sz, num, tmp;
    map<int, int>::iterator it, it2;
    fin >> m >> n;
    for(int i = 0; i < m; i ++)
    {
        fin >> sz; tmp = -1;
        while(sz--)
        {
            fin >> num;
            if(tmp > num) t.push_back({tmp, num});
            tmp = num;
        }
    }
    sort(t.begin(), t.end(), greater<pii>());
    cur[t[0].s] = t[0].f;
    for(int i = 1; i < t.size(); i ++)
    {
        it = cur.lower_bound(t[i].f); it2 = cur.lower_bound(t[i].s);
        if(it2 == cur.end()) cur[t[i].s] = max(it->s, t[i].f);
    }
    while(n--)
    {
        fin >> num;
        fout << max(num, cur.lower_bound(num)->s) << "\n";
    }
}
