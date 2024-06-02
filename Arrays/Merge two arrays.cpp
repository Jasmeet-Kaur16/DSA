// BRUTE FORCE (EXTRA SPACE)
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long arr3[n+m ] ;
            int i=0;
            int j=0;
            int k=0;
            while(i<n && j<m)
            {
            
                if(arr1[i]<=arr2[j])
                {
                    arr3[k]=arr1[i];
                    i++;
                    k++;
                }
                else
                {
                    arr3[k]=arr2[j];
                    k++;
                    j++;
                }
            }
            while(i<n)
            {
                arr3[k]=arr1[i];
                i++;
                k++;
            }
            while(j<m)
            {
                arr3[k]=arr2[j];
                j++;
                k++;
            }

            for(int i=0;i<n+m;i++)
            {
                arr1[i]=arr3[i];
                if(i>n-1)
                {
                    arr2[i-n]=arr3[i];
                }
            }
        } 



// OPTIMAL1 ( CONSTANT SPACE)
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=n-1,j=0;
            while(i>=0 && j<m)
            {
                if(arr1[i]>arr2[j])
                {
                    swap(arr1[i],arr2[j]);
                    i--;
                    j++;
                }
                else
                {
                    break;
                }
            }
            
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        }

// OPTIMAL2 ( CONSTANT SPACE)
void swapGreater(long long arr1[], long long arr2[], int ind1,int ind2)
        {
            if(arr1[ind1]>arr2[ind2])
            {
                swap(arr1[ind1],arr2[ind2]);
            }
        }
        
void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    int length=n+m;
    int gap=(length/2) + (length%2);
    
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        
        while(right<length)
        {
            if(left<n && right>=n) // arr1, arr2
            {
                swapGreater(arr1,arr2,left,right-n);
            }
            
            else if(left>=n)// arr2 arr2
            {
                swapGreater(arr2,arr2,left-n,right-n);
            }
            
            else // arr1 arr1
            {
                swapGreater(arr1,arr1,left,right);
            }
            
            left++;
            right++;
        }
                if (gap == 1)
{
    break; // To avoid infinite loop
}
        gap=(gap/2)+(gap%2);
    }
}

