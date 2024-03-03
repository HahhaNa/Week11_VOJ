#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int dp[40001][40001];

int main() {
    int n; cin >> n;
    while (n--)
    {
        int p; cin >> p;
        int i, j;
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= p; i++)
        {
             cin >> j;
            if(abs(i-j) <= 1) dp[i][j] = dp[i-1][j-1] + 1;
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
        cout << dp[i][j] << endl;
    }
    return 0;
}