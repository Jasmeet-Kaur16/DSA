//BETTER
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    next_permutation(permutation.begin(),permutation.end());

    return permutation;
}

//OPTIMAL
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind=-1;

    for(int i=n-2;i>=0;i--)
    {
        if(permutation[i]<permutation[i+1])
        {
            ind=i;
            break;
        }
    }

    if(ind==-1)
    {
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }

    for(int i=n-1;i>=0;i--)
    {
        if(permutation[i]>permutation[ind])
        {
            swap(permutation[i],permutation[ind]);
            break;
        }
    }

    reverse(permutation.begin()+ind+1,permutation.end());

    return permutation;

}
