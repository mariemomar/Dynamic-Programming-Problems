/*
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 <= n <= 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 -> 20 -> 18 -> 10 -> 9 -> 0.
 */


#include <bits/stdc++.h>
using namespace std;

int RemovingDigit(int n) {
  vector<int> dp(n +1 , INT_MAX);
  dp[0]=0; // base case

  for (int i = 1 ; i <= n ; i++) {

    int temp = i ;

    while (temp !=  0) {

      int digit = temp % 10;
      temp = temp / 10;
      if (digit == 0 ) {
        continue;
      }
      dp[i] = min(dp[i], dp[i - digit] + 1);


    }
  }
  return dp[n];
  }




int main(){
  int number ;
  cin>>number;

  cout << RemovingDigit(number) ;
}

/*
 *
*   int cnt =  0 ;
  while (n != 0 ) {
    int temp = n ;

      vector<int> digits;
      while (temp != 0) {
        digits.push_back(temp % 10);
        temp /= 10;
      }
    int max = digits[0];
    for (int i =0; i < digits.size(); i++) {
      if (digits[i] > max) {
        max = digits[i];
      }
    }
     n -= max;
     cnt++;
    }

    return  cnt ;
 */