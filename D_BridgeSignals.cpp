#include <iostream>
#include <algorithm>
using namespace std;
int len;
int dp[40001], ports[40001];

int main() {
    int n;
    cin >> n;
    while (n--) {
        int p;
        cin >> p;
        len = 1;       
        for (int i = 1; i <= p; i++) {
            cin >> ports[i];
        }

        dp[1] = ports[1];
        for (int i = 2; i <= p; i++) {
            if (ports[i]>=dp[len]) {
                len++;
                dp[len] = ports[i];
            } else {
                int pos = lower_bound(dp+1, dp+len+1, ports[i]) - dp;
                dp[pos] = ports[i];
            }
        }
        // cout << "\nans: ";
        cout << len << endl;
    }
    return 0;
}
