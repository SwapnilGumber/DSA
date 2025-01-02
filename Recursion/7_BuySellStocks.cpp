/* The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock i at price[i],
you can even buy and sell the stock on the same day. Find the maximum profit that you can get.

Note: A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int index)
{
    /// Base case
    if (index >= prices.size() - 1)
        return 0;
    // Recursive call
    int nextProfit = maxProfit(prices, index + 1);
    // Calculate profit
    if (prices[index] < prices[index + 1])
    {
        return prices[index + 1] - prices[index] + nextProfit;
    }
    return nextProfit;
}
int maximumProfit(vector<int> &prices)
{
    // code here
    return maxProfit(prices, 0);
}