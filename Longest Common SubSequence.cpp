#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string A, string B) {
  int len1 = A.length(), len2 = B.length();
  int dp[len1 + 1][len2 + 1];
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
      else if (A[i - 1] == B[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];  // the diagonal on the top right side
      }
      else {
        dp[i][j] = max(dp[i-1][j] , dp[i][j - 1]); // take the max between the previous value on row and column
      }
    }
  }
  cout << dp[len1][len2] << endl;
}

int main(){
  string A, B;
  cin >> A >> B;
  longestCommonSubsequence(A,B);
}