#include <stdio.h>
#include <stdlib.h>

void swap(int Array[], int one, int two)
{
    int temp = Array[one];
    Array[one] = Array[two];
    Array[two] = temp;
}

int partition(int Array[], int left, int right)
{
    int pivot = Array[right];
    int leftPointer = left - 1;
    int rightPointer = right;
    for (;;)
    {
        while (Array[++leftPointer] > pivot)
        {
        }
        while (rightPointer > 0 && Array[--rightPointer] < pivot)
        {
        }
        if (leftPointer >= rightPointer)
        {
            break;
        }
        else
        {
            swap(Array, leftPointer, rightPointer);
        }
    }
    /* move pivot to partition point */
    swap(Array, leftPointer, right);
    return leftPointer;
}

void Quicksort(int Array[], int left, int right)
{
    if (left < right)
    {
        int PartitionPoint = partition(Array, left, right);
        Quicksort(Array, left, PartitionPoint - 1);
        Quicksort(Array, PartitionPoint + 1, right);
    }
}

#define MAX_SIZE 10

int main(int argc, char **argv)
{
    int i, n;
    int Array[MAX_SIZE];

    if (argc > 1)
    {
        for (n = 0; n < MAX_SIZE && n < argc - 1; n++)
        {
            Array[n] = strtol(argv[n + 1], NULL, 0);
        }
    }
    else
    {
        printf("Give %d values: ", MAX_SIZE);
        for (n = 0; n < MAX_SIZE; n++)
        {
            if (scanf("%d", &Array[n]) != 1)
                break;
        }
    }

    Quicksort(Array, 0, n - 1);
    printf("\n Descending order Output: ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", Array[i]);
    }
    printf("\n");
    return 0;
}