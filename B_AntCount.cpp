#include <iostream>
using namespace std;

int dp[1005];

int main() {
    int types, nums, left, right;
    cin >> types >> nums >> left >> right;
    int count[1005]; // count[i] = x -> i repeat x times
    int N[100005]; // N[i] = x -> x types are repeated i times (or more)
    N[0] = 0;
    for (int i = 0; i < nums; i++) {       
        int n; cin >> n;
        count[n] += 1;
        N[count[n]] += 1;
    }

    int ans = 0;
    dp[0] = 1;
    for(int i=1; i<=right; i++) {
        if(i==1) dp[i] = N[i];
        else if(i==2) dp[i] = types*(types-1)/2 + N[2];
        else if(i < (nums+1)/2) {
            dp[i] = C(types, i) + N[i-1]*(types-1) + N[i];
        } 
        else {
            dp[i] = dp[nums-i];
        }
        if(i>=left && i<=right) ans += dp[i];
        ans %= 1000000;
    } 
    // for(int i=0; i<=nums; i++)
    //     cout << "in " << i << " dp: " << dp[i] << endl;
    cout << ans << endl;
    return 0;
}