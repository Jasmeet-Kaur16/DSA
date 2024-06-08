//BRUTE
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int diff=0;

    for(int i=prices.size()-1;i>=0;i--)
    {
       for(int j=i-1;j>=0;j--)
       {
           if(prices[i]-prices[j]>diff)
           {
               diff=max(diff,prices[i]-prices[j]);
           }
       }
    }
    return diff;
}

//OPTIMAL USING DP
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini=prices[0];
    int max_profit=0;
    int n=prices.size();

    for(int i=1;i<n;i++)
    {
        max_profit=max(max_profit,prices[i]-mini);
        mini=min(mini,prices[i]);
    }

    return max_profit;
}
