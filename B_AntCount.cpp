#include <iostream>
using namespace std;


int main() {
    int types, nums, left, right;
    cin >> types >> nums >> left >> right;
    int count[1005] = {0}; // count[i]=x -> i repeat x times
    int N[100005] = {0};
    for (int i = 0; i < nums; i++) {       
        int n; cin >> n;
        count[n]++;
        N[count[n]]++;
    }

    long long ans = 1;
    int up = types+right-left;
    int down = right+1;
    for(int i = up; i >= down; i--) {
        ans *= i;
    } 
    ans = (ans+1000000) % 1000000;
    for (int i = 1; i <= up-down; i++) {
        ans /= i;
    }
    ans = (ans+1000000) % 1000000;
    if(left != right) {
        for(int i=left; i<right; i++) {
            ans += types*(N[i]);
        }   ans += N[right];    
    } else {
        ans += (types-1)*N[left];
    }
    
    ans = (ans+1000000) % 1000000;
    
    cout << ans << endl;
    return 0;
}