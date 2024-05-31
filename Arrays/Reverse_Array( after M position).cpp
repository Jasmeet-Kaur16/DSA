void reverseArray(vector<int> &arr, int m) {
    int start_i=m+1;
    int end_i=arr.size()-1;
    while(start_i<=end_i)
    {
        swap(arr[start_i],arr[end_i]);
        start_i++;
        end_i--;
    }
}
