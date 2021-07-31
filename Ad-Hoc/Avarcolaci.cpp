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

ifstream fin("avarcolaci.in");
ofstream fout("avarcolaci.out");

int nums[1000010];
int main()
{
    int t, n, cur, cnt = 0;
    fin >> t;
    while(t--)
    {
        fin >> n;
        fin >> nums[0]; cur = nums[0]; cnt = 1;
        for(int i = 1; i < n*2; i ++)
        {
            fin >> nums[i];
            if(nums[i] == cur) cnt ++;
            else cnt --;
            if(cnt < 0)
                cur = nums[i], cnt = 1;
        }
        cnt = 0;
        for(int i = 0; i < n*2; i ++)
            if(cur == nums[i])
                cnt ++;
        if(cnt > n) fout << cur << "\n";
        else fout << "Mozart\n";
    }
}
