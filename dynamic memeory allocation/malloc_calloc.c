#include <stdio.h>
int main()
{
  int n, i, *ptr, sum = 0;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int));

  printf("Enter elements: ");

  for(i = 0; i < n; ++i)
  {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);
  return 0;
}

/*
calloc
#include <stdio.h>
int main()
{
  int n, i, *ptr, sum = 0;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) calloc(n, sizeof(int));

  printf("Enter elements: ");
  for(i = 0; i < n; ++i)
  {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);
  return 0;
}*/
