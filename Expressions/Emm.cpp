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

ifstream fin("emm.in");
ofstream fout("emm.out");

string st, tmp;
int match[100010];
stack<int> par;
int ans(int l, int r)
{
    if(st[r] == ')')
    {
        if(match[r] == l)
            return ans(l+1, r-1);
        else
        {
            if(st[match[r]-1] == 'm') return min(ans(l, match[r]-2), ans(match[r]+1, r-1));
            else return max(ans(l, match[r]-2), ans(match[r]+1, r-1));
        }
    }
    tmp = "";
    while(st[r] >= '0' && st[r] <= '9' && l <= r) tmp = st[r]+tmp, r --;
    int num = stoi(tmp);
    if(l > r) return num;
    if(st[r] == 'm') return min(ans(l, r-1), num);
    return max(ans(l, r-1), num);
}
int main()
{
    fin >> st;
    tmp.reserve(10);
    for(int i = 0; i < st.length(); i ++)
    {
        if(st[i] == '(') par.push(i);
        if(st[i] == ')') match[i] = par.top(), par.pop();
    }
    fout << ans(0, (int)st.length()-1) << "\n";
}
