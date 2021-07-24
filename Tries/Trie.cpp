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

ifstream fin("trie.in");
ofstream fout("trie.out");

struct node
{
    node* arr[26];
    int cnt = 0, cntW = 0;
};

int main()
{
    int n, ans;
    bool good;
    string st;
    node* root = new node(); node* cur;
    while(fin >> n)
    {
        fin >> st;
        cur = root; ans = 0; good = true;
        for(int i = 0; i < st.length(); i ++)
        {
            if(cur->arr[st[i]-'a'] == nullptr && n == 0)
                cur->arr[st[i]-'a'] = new node();
            else if(cur->arr[st[i]-'a'] == nullptr)
                {good = false; break;}
            cur = cur->arr[st[i]-'a'];
            if(n == 0) cur->cnt ++;
            if(n == 1) cur->cnt --;
            if(n == 3 && cur->cnt) ans = i+1;
        }
        if(n == 0) cur->cntW ++;
        if(n == 1) cur->cntW --;
        if(n == 2) fout << ((good)?cur->cntW:0) << "\n";
        if(n == 3) fout << ans << "\n";
    }
}
