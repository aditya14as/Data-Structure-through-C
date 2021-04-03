// Aditya Kumar Vidhyarthi
// Roll:- 1916578
// B.tech(ECE,4th Sem)

#include <stdio.h>

int BinarySearch(int arr[10], int size, int element)
{
    int low = 0, high = size - 1, i;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int x, arr[10] = {16, 19, 20, 23, 45, 56, 78, 90, 96, 100}, size = 10, element = 19;
    x = BinarySearch(arr, size, element);
    if (x == -1)
        printf("Element is not present");
    else
        printf("Element %d is present at index %d", element, x);
}