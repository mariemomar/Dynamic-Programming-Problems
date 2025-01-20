#include <bits/stdc++.h>
using namespace std;

int coinChangeCombinations(vector<int>& coins, int amount) {
    // Initialize a DP table with 0
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case: There's one way to make amount 0 (by using no coins)

    // Fill the DP table
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter the number of coins: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Enter the target amount: ";
    cin >> amount;

    int result = coinChangeCombinations(coins, amount);
    cout << "The number of possible combinations to make the amount: " << result << endl;

    return 0;
}
