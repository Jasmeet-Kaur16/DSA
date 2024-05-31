vector<int> rotateArray(vector<int>arr, int k) {

    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}

/*
BRUTE FORCE

vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();
    for (int i = 0; i < k; i++) {
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }

    return arr;
}
*/
