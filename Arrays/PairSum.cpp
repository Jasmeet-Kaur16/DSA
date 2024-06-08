//BRUTE
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(((arr[i]+arr[j])==target) && arr[i]!=arr[j])
			{
				count++;
			}
		}
	}

//OPTIMAL ----- 2 POINTER APPROACH
#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	int count=0;

	int start=0;
	int end=n-1;

	while(start<end)
	{
		if((arr[start]+arr[end])==target)
		{
			count++;
			start++;
			end--;
		}
		else if ((arr[start]+arr[end])>target)
			end--;
		else 
			start++;
	}

	if (count ==0)
	{
		return -1;
	}
	else{
		return count;
	}
}

// TO PRINT PAIRS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int n, int target)
{
    int start = 0;
    int end = n - 1;
    vector<vector<int>> pairs;

    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (sum == target)
        {
            pairs.push_back({arr[start], arr[end]});
            start++;
            end--;
        }
        else if (sum < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    return pairs.empty() ? vector<vector<int>>{{-1}} : pairs;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> result = pairSum(arr, arr.size(), 0);

    if (result.size() == 1 && result[0][0] == -1)
    {
        cout << "No pairs found!";
    }
    else
    {
        cout << "Pairs: ";
        for (const auto &pair : result)
        {
            cout << "(" << pair[0] << ", " << pair[1] << ") ";
        }
    }

    return 0;
}
