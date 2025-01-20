#include <bits/stdc++.h>

using namespace std;


int fib(int n , vector<int> memo){
   if (memo[n] != -1 ) {
       return memo[n];
   }
    if (n<=1) {
        memo[n] = n ;
        return n ;
    }
    else {
       int sum =  fib(n-1 , memo) + fib(n-2 , memo);
        memo[n] = sum ;
        return sum ;
    }

}


int main(){
   while (true) {
       int n  ;
       cout << "Enter the number :" << endl;
       cin >> n;
       vector<int> memo(n+1 , -1) ;
       cout << "The Fibonacci of it is : "<<fib(n , memo) << endl;
   }

}