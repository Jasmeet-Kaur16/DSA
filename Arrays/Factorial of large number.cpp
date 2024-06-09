#include <bits/stdc++.h>
int multiply(vector <int>&arr, int size,int multiplier)
{
    int carry=0;

    for(int i=0;i<size;i++)
    {
        int prod=arr[i]*multiplier+carry;
        arr[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        arr[size++]=carry%10;
        carry=carry/10;
    }
    return size;
}
string calculateFactorial(int n)
{
    vector<int> arr(10000,0);
    int size=1;
    arr[0]=1;
    for(int multiplier=2;multiplier<=n;multiplier++)
    {
        size=multiply(arr,size,multiplier);
    }

    string ans="";

    for(int i=size-1;i>=0;i--)
    {
        ans+=to_string(arr[i]);
    }

    return ans;
}
