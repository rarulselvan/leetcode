int findPeakElement(int* arr, int n)
{
    // If only one element  return zero
    if (n == 1)
        return 0;
    //first element is peak? check it out
    if (arr[0] >= arr[1])
        return 0;
    //last element is peak? check it out
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;

    // check for every other element
    for (int i = 1; i < n - 1; i++) {

        // check if the neighbors are smaller
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
    return -1;
}