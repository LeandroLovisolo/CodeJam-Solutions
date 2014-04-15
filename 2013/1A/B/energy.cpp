#include <iostream>
#include <vector>
#include <cmath>

typedef long long energy;

using namespace std;

energy solve(int E, int R, const vector<int> &v) {
    vector<vector<energy> > dp(v.size(), vector<energy>(E + 1, 0));

    for(int i = v.size() - 1; i >= 0; i--) {
        // cout << "i = " << i << endl;
        for(int e = 0; e <= E; e++) {
            // if(e % 1000 == 0) cout << "e = " << e << endl;

            if(i == v.size() - 1) dp[i][e] = v[i] * e;
            else {
                if(e == 0) dp[i][e] = dp[i + 1][R];
                else dp[i][e] = max(dp[i][e - 1] + v[i], dp[i + 1][min(e + R, E)]);

                // for(int f = 0; f <= e; f++) {
                //    energy candidate = v[i] * f + dp[i + 1][min(e - f + R, E)];
                //    dp[i][e] = max(dp[i][e], candidate);
                // }
            }
        }
    }

    return dp[0][E];
}

int main() {
    int test_cases;
    cin >> test_cases;

    for(int i = 1; i <= test_cases; i++) {
        int E, R, N;
        cin >> E >> R >> N;

        vector<int> v(N);
        for(int j = 0; j < N; j++) cin >> v[j];

        int solution = solve(E, R, v);
        cout << "Case #" << i << ": " << solution << endl;
    }

    return 0;
}