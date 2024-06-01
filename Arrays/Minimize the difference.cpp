#include <bits/stdc++.h> 
int minimizeIt(vector<int> A, int K)
{
	sort(A.begin(),A.end());
	int diff=A[A.size()-1]-A[0];

	int mi=0,ma=0;

	int smallest=A[0]+K;
	int largest=A[A.size()-1]-K;

	for(int i=0;i<A.size();i++)
	{
		mi=min(smallest,A[i+1]-K);
		ma=max(largest,A[i]+K);
		if(mi<0)
			continue;
		diff=min(diff,ma-mi);
	}
	return diff;

}
