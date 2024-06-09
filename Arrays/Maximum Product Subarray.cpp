//OPTIMAL
#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{

    int maxi=INT_MIN;
    int prefix=1;
    int start=0;
    int end=n-1;
    int suffix=1;

    while(start<n && end>=0)
    {
        if(prefix==0)
        {
            prefix=1;
        }
        if(suffix==0)
        {
            suffix=1;
        }
        prefix*=arr[start++];
        suffix*=arr[end--];
        maxi=max(maxi,max(prefix,suffix));

    }

    return maxi;
}


#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
    int maxi=INT_MIN;
    int prefix=1;
    int suffix=1;

    for (int i=0;i<n;i++)
    {
        if(prefix==0)
        {
            prefix=1;
        }
        if(suffix==0)
        {
            suffix=1;
        }
        prefix=prefix*arr[i];
        suffix=suffix*arr[n-i-1];
        maxi=max(maxi,max(prefix,suffix));

    }

    return maxi;
}
