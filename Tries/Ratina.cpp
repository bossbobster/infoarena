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

ifstream fin("ratina.in");
ofstream fout("ratina.out");

struct node
{
    node* arr[26];
    bitset<10000> vis;
};
int n, m, ans, t, idx;
string st;
short nums[20];
string words[10010];
vector<node*> v[10010];
int bs(int l, int r)
{
    int mid = (l+r+1)/2;
    if(l == r) return l;
    node* tmp = v[nums[0]][mid];
    for(int k = 1; k < t; k ++)
        if(!tmp->vis[nums[k]])
            return bs(l, mid-1);
    return bs(mid, r);
}
int main()
{
    node* root = new node(); node* cur;
    bool good;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        fin >> st; words[i] = st;
        cur = root; ans = 0; good = true;
        for(int j = 0; j < st.length(); j ++)
        {
            v[i].push_back(cur);
            if(cur->arr[st[j]-'a'] == nullptr)
                cur->arr[st[j]-'a'] = new node();
            cur = cur->arr[st[j]-'a'];
            cur->vis[i] = true;
        }
        v[i].push_back(cur);
    }
    while(m--)
    {
        fin >> t;
        for(int i = 0; i < t; i ++)
            fin >> nums[i], nums[i]--;
        fout << bs(0, words[nums[0]].length()) << "\n";
    }
}
