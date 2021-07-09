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

ifstream fin("potrivire.in");
ofstream fout("potrivire.out");

vector<string> all;
vector<int> v[10010];
int kmp[20010];
int main()
{
    int n, m, x, idx = 0;
    string s1, s2, st = "";
    bool good;
    fin >> n >> m >> s1 >> s2;
    for(int i = 0; i < m; i ++)
    {
        if(s2[i] == '*')
        {
            if(st != "")
                all.push_back(st);
            st = "";
        }
        else
            st += s2[i];
    }
    if(st != "") all.push_back(st);
    for(int i = 0; i < all.size(); i ++)
    {
        st = all[i] + s1;
        kmp[0] = -1; kmp[1] = 0;
        for(int j = 1; j < st.length(); j ++)
        {
            x = kmp[j];
            while(x != -1 && st[x] != st[j])
                x = kmp[x];
            kmp[j+1] = x+1;
            if(kmp[j+1] > all[i].length())
                kmp[j+1] = kmp[kmp[j+1]];
        }
        for(int j = (int)all[i].length()*2; j <= (int)st.length(); j ++)
            if(kmp[j] == all[i].length())
                v[i].push_back(j - (int)all[i].length()*2);
    }
    for(int i = 0; i < all.size(); i ++)
    {
        good = false;
        for(int j = 0; j < v[i].size(); j ++)
            if(v[i][j] >= idx)
            {
                good = true;
                idx = v[i][j] + (int)all[i].length();
                break;
            }
        if(!good)
        {
            fout << "-1\n"; return 0;
        }
    }
    fout << v[0][0]+1 << " " << idx << "\n";
}
