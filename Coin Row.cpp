/*
*
* There is a row of n coins whose values are some positive integers
c₁, c₂,...,cn, not necessarily distinct. The goal is to pick up the
maximum amount of money subject to the constraint that no two
coins adjacent in the initial row can be picked up.

E.g.: 5, 1, 2, 10, 6, 2,

the best selection is 5, 10, 2, giving the maximum amount of 17.
 * */

#include <bits/stdc++.h>
using namespace std;

int CoinRow(vector<int> &coins , int n) {
    int dp[n+1] ;
    dp[0]=0;
    dp[1]= coins[0];
    for (int i = 2 ; i <= n ; i++) {
        dp[i] = max(dp[i-1] , dp[i-2]+coins[i-1]);
    }
    cout << dp[n] << endl;
}

int main(){

    int n ;
    cin >> n ;
    vector<int> coins ;
    for (int i = 0; i < n; i++) {
        int a ;
        cin >> a ;
        coins.push_back(a);
    }

    CoinRow(coins , n);
}