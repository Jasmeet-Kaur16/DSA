#include <bits/stdc++.h>
using namespace std;
pair<long long, vector<int>> maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0, maxi = 0;

    int start = 0, end = 0, tempstart = 0;
    vector<int> subarray;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            tempstart = i + 1;
        }
        if (maxi < sum)
        {
            maxi = sum;
            start = tempstart;
            end = i;
        }
    }
    if (maxi < 0)
    {
        maxi = 0;
    }
    else
    {
        subarray = vector<int>(arr.begin() + start, arr.begin() + end + 1);
    }
    return {maxi, subarray};
}
int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = arr.size();
    auto result = maxSubarraySum(arr, n);
    long long max = result.first;
    vector<int> subarray = result.second;
    cout << "Sum : " << max << endl;
    cout << "Subarray : ";
    for (auto it : subarray)
    {
        cout << it << " ";
    }
    return 0;
}
