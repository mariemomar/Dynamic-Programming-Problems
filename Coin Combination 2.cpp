/*
 *
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 <= n <= 100
1 <= x <= 10^6
1 <= c_i <= 10^6

Example
Input:
3 9
2 3 5

Output:
3
 */



#include <bits/stdc++.h>
using namespace std;

 int coinCombiantion2(vector<long long >& coins , int number) {
      vector<long long > dp(number + 1, 0); // coins size +1 for leading 0 in the top


     dp[0] = 1;

     for (int   i = 0; i < coins.size(); i++) {
         for (int   j = 1; j <= number; j++) {
             if (coins[i] <= j) {
                 dp[j] = ( dp[j] + dp[j-coins[i]]) % 1000000007; ;
             }
         }
     }

     //     for (int j = 0; j <= number; j++) {
     //         cout<<dp[j]<<" ";
     //     }
     //
     //
     // cout << "index " << coins.size() << " and " << number << endl;
     return  dp[number];
 }

int main(){
    // cout << "Enter number of coins: " << endl;
    int numberOfCoins ;
    cin >> numberOfCoins ;
    // cout << "enter the number : "  << endl;
    int number ;
    cin >> number ;
    vector<long long> coins ;
    // cout << "Enter coins: " << endl;
    for (int i = 0; i < numberOfCoins; i++) {
        int  coin ;
        cin >> coin ;
        coins.push_back(coin) ;
    }
    sort(coins.begin(), coins.end() );
    // cout << "number of combinations is : " << coinCombiantion(coins , number ) ;
    cout << coinCombiantion2(coins, number);
}

