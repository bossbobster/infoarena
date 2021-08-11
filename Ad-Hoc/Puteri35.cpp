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
 
ifstream fin("puteri35.in");
ofstream fout("puteri35.out");
 
ll p3[30], p5[30];
int main()
{
    int n, idx = 0, cur = 1, tmp, i1, i2, j; ll s1, s2;
    fin >> n;
    p3[0]=p5[0]=1;
    for(int i = 1; i < 22; i ++)
        p3[i]=p3[i-1]*3, p5[i]=p5[i-1]*5;
    s1=s2=i1=i2=1;
    while(i1 <= n || i2 <= n)
    {
        if(i2==n+1||(s1<=s2&& i1 <= n))
        {
            fout << s1 << '\n';
            tmp = i1; j = 0;
            while(tmp%2)
                s1-=p3[j++],tmp/=2;
            s1 += p3[j]; i1++;
        }
        if(i1==n+1||(s2 <= s1 && i2 <= n))
        {
            fout << s2 << '\n';
            tmp = i2; j = 0;
            while(tmp%2)
                s2-=p5[j++],tmp/=2;
            s2 += p5[j]; i2++;
        }
    }
}
