void swap(int *a,int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void maxHeapify(int arr[], int i, int N)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
 
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, largest, N);
    }
}


int findKthLargest(int* arr, int N, int k)
{
    for (int i = (N / 2) -1; i >= 0; i--)
        maxHeapify(arr, i, N);
    
    for(int i=0; i<k-1; i++)
    {
        arr[0]=arr[N-1-i];//move(overwrite) the last element into arr[0]
        maxHeapify(arr, 0, N-i);//we are loosing elements
    }
    return arr[0];
}