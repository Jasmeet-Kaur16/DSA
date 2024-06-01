long long Cross_sum(vector <int> arr,int left, int mid, int right)
{
    long long sum=0;
    long long left_sum=LONG_MIN;
    long long right_sum=LONG_MIN;

    for(int i=mid;i>=left;i--)
    {
        sum+=arr[i];
        if(sum>left_sum)
        {
            left_sum=sum;
        }
    }

    sum=0;
    for(int i=mid+1;i<=right;i++)
    {
        sum+=arr[i];
        if(sum>right_sum)
        {
            right_sum=sum;
        }
    }

    return left_sum+right_sum;
}

long long subarraysum(vector<int> arr, int left,int right)
{
    if (left==right)
    {
        return arr[left];
    }

    int mid=left+(right-left)/2;

    long long left_sub_sum=subarraysum(arr, left, mid);
    long long right_sub_sum=subarraysum(arr, mid+1,right);
    long long cross_sub_sum=Cross_sum(arr, left,mid,right);

    return max({left_sub_sum,right_sub_sum,cross_sub_sum});

}

long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum=subarraysum(arr, 0, arr.size()-1);
    if (sum<0)
    {
        return 0;
    }
    else{
        return sum;
    }
}
