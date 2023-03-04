#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ans[41][1001];
char pre[41][1001];

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 1000; j++) {
            ans[i][j] = 9999;
        }
    }
    ans[0][0] = 0;
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        for(int j = 0; j <= 1000; j++) {
            if(j - x >= 0) {
                if(ans[i-1][j-x] < ans[i][j]) {
                    ans[i][j] = ans[i-1][j-x];
                    pre[i][j] = 'U';
                }
            }
            if(j + x <= 1000) {
                if(ans[i-1][j+x] < ans[i][j]) {
                    ans[i][j] = ans[i-1][j+x];
                    pre[i][j] = 'D';
                }
            }
            ans[i][j] = max(ans[i][j], j);
        }
    }
    if(ans[n][0] == 9999) {
        cout << "IMPOSSIBLE\n";
        vector<int>().swap(v);
        return;
    }
    vector<char> a;
    int x = 0;
    for(int i = n; i > 0; i--) {
        a.push_back(pre[i][x]);
        if(pre[i][x] == 'U') x -= v[i];
        else x += v[i];
    }
    reverse(a.begin(), a.end());
    for(char c : a) cout << c;
    cout << '\n';
    vector<int>().swap(v);
    vector<char>().swap(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
