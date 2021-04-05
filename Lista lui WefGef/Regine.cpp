#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("regine.in");
ofstream fout("regine.out");

int main()
{
    int n, r, c, ans;
    fin >> n;
    ans = (n * 2 + 1) / 3;
    fout << ans << "\n";
    c = 1; r = n - ans + 1;
    while(r <= n)
    {
        fout << r << " " << c << "\n";
        r += 2; c ++;
    }
    c = 1; r = n - ans + 2;
    while(r <= n)
    {
        fout << r << " " << (r - c + 1) << "\n";
        r += 2; c ++;
    }
}
