#include<bits/stdc++.h>
int findDuplicate(vector<int> &arr) 
{
    int x=0;
    int n=arr.size();
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
        if(m[arr[i]]>1)
        {
            x=arr[i];
            break;
        }
    }
    return x;
	
}

//OR

#include<bits/stdc++.h>
int findDuplicate(vector<int> &arr) 
{
    int n=arr.size();
    int x=0;
    for(int i=0;i<n;i++)
    {
        x=x^i;
    }
    for(int i=0;i<n;i++)
    {
        x=x^arr[i];
    }
    return x;
}
