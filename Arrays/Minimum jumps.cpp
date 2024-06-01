int minimumJumps(vector<int> &arr, int n)
{
    int pos=0;
    int dest=0;
    int jump=0;

    if (arr[0]==0)
        return -1;
    for (int i=0;i<n-1;i++)
    {

        dest=max(dest,arr[i]+i);
        if(dest<=i)
        {
            return -1;
        }
        if(pos==i)
        {
            pos=dest;
            jump++;
        }

    }
    return jump;
}
