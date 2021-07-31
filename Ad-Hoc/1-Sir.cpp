#include <fstream>
using namespace std;

ifstream fin("1-sir.in");
ofstream fout("1-sir.out");

int dp[256*255+1];
int main()
{
    int i, j, n, m;
    fin >> n >> m;
    dp[0] = 1;
    if(m > n*(n-1)/2 || m < -(n*(n-1)/2))
    {
        fout << "0\n";
        return 0;
    }
    for(i = 1; i < n; i ++)
        for(j = i*(i-1); j >= 0; j --)
            dp[j+i+i] = (dp[j+i+i] + dp[j]) % 194767;
    fout << dp[m+n*(n-1)/2] << "\n";
}
