#include  <stdio.h>

int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
    int arr[10], n, i;
	printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("Enter |%d| element: ",i+1);
        scanf("%d",&arr[i]);
    }

    shellSort(arr, n);

    printf("\nSorted array: \n");
	printArray(arr, n);
	return 0;
}
