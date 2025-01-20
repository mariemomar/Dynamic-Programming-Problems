/*
* You are in a bookshop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,....,h_n: the price of each book.
The last line contains n integers s_1,s_2,....,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
Constraints

1 <= n <= 1000
1 <= x <= 10^5
1 <= h_i, s_i <= 1000

Example
Input:
4 10
4 8 5 3
5 12 8 1

Output:
13

Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.
 */



#include <bits/stdc++.h>
using namespace std;



int BookShop(vector<pair<int, int>>&  books , int totalPrice) {

    // first price
    // second pages

    int dp [books.size()+1][totalPrice+1];
    for (int i = 0 ; i <= books.size(); i++) {
        for (int j = 0; j <= totalPrice; j++) {
           if ( i == 0 || j == 0 ) {
               dp[i][j] = 0;
           }
            else {
                if (j < books[i-1].first) {
                    dp[i][j] = dp[i-1][j] ;
                }else {
                    dp[i][j] = max(books[i-1].second + dp[i-1][j-books[i-1].first], dp[i-1][j]);
                }
            }
        }

    }
    return dp[books.size()][totalPrice];
}




int main(){

int numOfBooks;
    cin>>numOfBooks;
    int totalPrice ;
    cin >> totalPrice;

    int booksPrices[numOfBooks];
    for (int i = 0; i < numOfBooks; i++) { // enter the books prices
        cin >> booksPrices[i];
    }
    int booksPages[numOfBooks];
    for (int i = 0; i < numOfBooks; i++) { // enter the books prices
        cin >> booksPages[i];
    }
    vector<pair<int,int> > books;
    for(int i=0;i<numOfBooks;i++) {

        books.push_back(make_pair(booksPrices[i],booksPages[i]));
    }
    sort(books.begin(),books.end());
    cout << BookShop(books , totalPrice);
}