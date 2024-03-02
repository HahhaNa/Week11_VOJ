#include <iostream>
using namespace std;

int dp[2][100002] = {0};

int main() {
    int types, nums, lower, upper;
    cin >> types >> nums >> lower >> upper;
    int count[1005] = {0}; // count[i]=x -> i repeat x times
    for (int i = 0; i < nums; i++) {       
        int n; cin >> n;
        count[n]++;
    }
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= types; i++) {
        for (int j = 1; j <= upper; j++) {
            if(j-count[i] >= 1)
                dp[i%2][j] = (dp[(i-1)%2][j] + dp[i%2][j-1] - dp[(i-1)%2][j-count[i]-1]+1000000) % 1000000;
            else dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-1];
            dp[i%2][j] = dp[i%2][j] % 1000000;
        }
    }
    int ans = 0;
    for(int i = lower; i <= upper; i++) {
        ans = (ans + dp[types%2][i]) % 1000000;
    }
    cout << ans << endl;
    return 0;
}