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

ifstream fin("qvect.in");
ofstream fout("qvect.out");
 
vector<int> nums[110];
int main()
{
    int n, q, t, sz, l, r, mid, ans, l1, l2, lq, rq, tot = 0;
    fin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        fin >> sz;
        nums[i].reserve(sz);
        for(int j = 0; j < sz; j ++)
            fin >> l, nums[i].push_back(l);
    }
    while(q--)
    {
        fin >> t >> lq >> rq; lq--; rq--;
        if(t == 1)
        {
            ans = 2000000000;
            l1 = l2 = 0;
            while(l1 < nums[lq].size() && l2 < nums[rq].size())
            {
                ans = min(ans, abs(nums[lq][l1]-nums[rq][l2]));
                if(nums[lq][l1] < nums[rq][l2]) l1 ++;
                else l2 ++;
            }
            fout << ans << '\n';
        }
        else
        {
            l = -1e9; r = 1e9; tot = 0;
            for(int i = lq; i <= rq; i ++)
                tot += nums[i].size();
            tot /= 2;
            while(l <= r)
            {
                mid = (l+r)/2;
                l1 = 0;
                for(int i = lq; i <= rq; i ++)
                    l1 += upper_bound(nums[i].begin(), nums[i].end(), mid)-nums[i].begin();
                if(l1 >= tot) { ans = mid; r = mid-1; }
                else l = mid+1;
            }
            fout << ans << '\n';
        }
    }
}
