#include <iostream>
#include <string.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ifstream fin("subsir1000.in");
ofstream fout("subsir1000.out");
 
int n;
int nums[100010];
int last[100010];
bool composite[100010];
vector<int> primes, cur;
void findPrimes()
{
    for(int i = 2; i <= n; i ++)
    {
        if(composite[i]) continue;
        primes.push_back(i);
        for(int j = 2; i*j <= n; j ++)
            composite[i*j] = true;
    }
}
int main()
{
    int ans = 1, mx;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    findPrimes();
    for(int i = 0; i < n; i ++)
    {
        cur.clear();
        for(int j = 0; primes[j] <= sqrt(nums[i]); j ++)
        {
            if(nums[i] % primes[j] == 0) cur.push_back(primes[j]);
            while(nums[i] % primes[j] == 0)
                nums[i]/=primes[j];
        }
        if(nums[i] > 1) cur.push_back(nums[i]);
        mx = 0;
        for(int j = 0; j < (int)cur.size(); j ++)
            mx = max(mx, last[cur[j]]);
        for(int j = 0; j < (int)cur.size(); j ++)
        {
            last[cur[j]] = mx+1;
            ans = max(ans, last[cur[j]]);
        }
    }
    fout << ans << "\n";
}
