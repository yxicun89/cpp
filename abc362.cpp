// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;

// vector<int> find_sequence(int n, vector<pair<int, int> > lr) {
//     vector<map<int, vector<int> > > dp(n + 1);
//     dp[0][0] = vector<int>(); 

//     for (int i = 1; i <= n; ++i) {
//         int Li = lr[i-1].first;
//         int Ri = lr[i-1].second;
//         for (const auto& p : dp[i-1]) {
//             int s = p.first;
//             for (int x = Li; x <= Ri; ++x) {
//                 int new_sum = s + x;
//                 if (dp[i].find(new_sum) == dp[i].end()) {
//                     dp[i][new_sum] = dp[i-1][s];
//                     dp[i][new_sum].push_back(x);
//                 }
//             }
//         }
//     }

//     if (dp[n].find(0) != dp[n].end()) {
//         return dp[n][0];
//     } else {
//         return vector<int>();
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<pair<int, int> > lr(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> lr[i].first >> lr[i].second;
//     }

//     vector<int> result = find_sequence(n, lr);

//     if (!result.empty()) {
//         cout << "Yes" << endl;
//         for (int x : result) {
//             cout << x << " ";
//         }
//         cout << endl;
//     } else {
//         cout << "No" << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>  // Include for std::function

using namespace std;

vector<int> find_sequence(int n, vector<vector<int>>& lr) {
    unordered_map<pair<int, int>, vector<int>> memo;

    // Define dfs function
    function<vector<int>(int, int)> dfs = [&](int index, int current_sum) -> vector<int> {
        if (index == n) {
            return (current_sum == 0) ? vector<int>() : vector<int>();
        }
        if (memo.count({index, current_sum}) > 0) {
            return memo[{index, current_sum}];
        }

        int Li = lr[index][0];
        int Ri = lr[index][1];
        for (int x = Li; x <= Ri; ++x) {
            vector<int> result = dfs(index + 1, current_sum + x);
            if (!result.empty()) {
                memo[{index, current_sum}] = vector<int>({x}) + result;
                return memo[{index, current_sum}];
            }
        }

        memo[{index, current_sum}] = vector<int>();
        return vector<int>();
    };

    vector<int> result = dfs(0, 0);
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> lr(n);
    for (int i = 0; i < n; ++i) {
        lr[i].resize(2);
        cin >> lr[i][0] >> lr[i][1];
    }

    vector<int> result = find_sequence(n, lr);

    if (!result.empty()) {
        cout << "Found sequence:";
        for (int i = 0; i < result.size(); ++i) {
            cout << " " << result[i];
        }
        cout << endl;
    } else {
        cout << "No valid sequence found" << endl;
    }

    return 0;
}
