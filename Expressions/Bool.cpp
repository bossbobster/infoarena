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

ifstream fin("bool.in");
ofstream fout("bool.out");

int n, idx = 0;
string og, st, str = "", change;
bool vals[26];
bool o();
bool ans()
{
    bool ret;
    if(st[idx] == '(')
        idx++, ret = o(), idx++;
    else if(st[idx] == '!')
        idx++, ret = !ans();
    else if(st[idx] == 't')
        idx++, ret = true;
    else if(st[idx] == 'f')
        idx++, ret = false;
    else if(st[idx] == ')')
        idx++;
    else
        idx++, ret = vals[st[idx-1]-'A'];
    return ret;
        
}
bool a()
{
    bool ret = ans();
    while(st[idx] == '&')
        idx ++, ret = ret & ans();
    return ret;
}
bool o()
{
    bool ret = a();
    while(st[idx] == '|')
        idx ++, ret = ret | a();
    return ret;
}
int main()
{
    st.reserve(1000);
    while(str[0] < '0' || str[0] > '9')
        fin >> str, og += str + " ";
    n = stoi(str); str = "";
    for(int i = 0; i < og.length(); i ++)
    {
        if(og[i] == ' ' || og[i] == ')')
        {
            if(str == "AND") st += "&";
            else if(str == "OR") st += "|";
            else if(str == "NOT") st += "!";
            else if(str == "TRUE") st += "t";
            else if(str == "FALSE") st += "f";
            else st += str;
            str = "";
        }
        if(og[i] >= 'A' && og[i] <= 'Z') str += og[i];
        if(og[i] == '(' || og[i] == ')') st += og[i];
    }
    fin >> change;
    for(int i = 0; i < n; i ++)
    {
        idx = 0;
        vals[change[i]-'A'] = !vals[change[i]-'A'];
        fout << (o()?1:0);
    }
    fout << "\n";
}
