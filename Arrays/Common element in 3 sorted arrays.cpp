#include <bits/stdc++.h> 
//THREE POINTER APPROACH
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> vec;
    set<int> st;
    int n=a.size();
    int m=b.size();
    int p=c.size();

    int i=0,j=0,k=0;
    while(i<n && j<m && k<p)
    {
        if (a[i]==b[j] && b[j]==c[k])
        {
            st.insert(a[i]);  
            i++;
            j++;
            k++;         
        }

        else if(a[i]<b[j])
        {
            i++;
        }

        else if(b[j]<c[k])
        {
            j++;
        }
        else if(c[k]<a[i])
        {
            k++;
        }
    }

    for(auto it:st)
    {
        vec.push_back(it);
    }

    return vec;
}
