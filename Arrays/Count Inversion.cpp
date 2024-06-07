//BRUTE
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    
    long long count=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                count++;
            }
        }
    }

    return count;
}

//OPTIMAL ----MERGE SORT
#include <bits/stdc++.h>

long long merge(long long *arr, int low, int mid, int high)
{
    long long count=0;
    int n = high - low + 1;
    vector<long long> temp(n);
    int left = low;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            count += (mid - left + 1);
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < n; ++i)
    {
        arr[low + i] = temp[i];
    }
    return count;
}

long long merge_sort(long long *arr, int low, int high)
{
    long long count=0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        count+=merge_sort(arr, low, mid);
        count+=merge_sort(arr, mid + 1, high);
        count+=merge(arr, low, mid, high);
    }
    return count;
}

long long getInversions(long long *arr, int n)
{
    long long count=0;
    count=merge_sort(arr, 0, n - 1);
    return count;
}
