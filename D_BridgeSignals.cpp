#include <stdio.h>
#include <algorithm>
using namespace std;
int len;
int dp[40001], ports[40001];

int binary_search(int x) {
    int left = 1, right = len;
    while(right > left) {
        int mid = left + (right-left)/2;    
        if(dp[mid] > x) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        int p;
        scanf(" %d", &p);
        len = 0;       
        for (int i = 1; i <= p; i++) {
            scanf(" %d", &ports[i]);
        }
        for (int i = 1; i <= p; i++) {
            if (ports[i]>=dp[len]) {
                len++;
                dp[len] = ports[i];
            } else {
                int pos = binary_search(ports[i]);
                dp[pos] = ports[i];
            }
        }
        printf("%d\n", len);
    }
    return 0;
}
