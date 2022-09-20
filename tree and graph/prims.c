#include<stdio.h>
#include<stdbool.h>

#define INF 999
#define V 7

int G[V][V] = { { 0, 28, 0, 0, 0, 10, 0 },
                { 28, 0, 16, 0, 0, 0, 14 },
                { 0, 16, 0, 12, 0, 0, 0 },
                { 0, 0, 12, 0, 22, 10, 18 },
                { 0, 0, 0, 22, 0, 25, 24 },
                { 10, 0, 0, 0, 25, 0, 0 },
                { 0, 14, 0, 18, 24, 0, 0 } };

int main()
{
  int no_edge;
  int selected[V];
  int sum=0;
  memset(selected, false, sizeof(selected));

  no_edge = 0;

  selected[0] = true;

  int x,y;

  printf("Edge : Weight\n");

  while (no_edge < V - 1)
  {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++)
    {
      if (selected[i])
      {
        for (int j = 0; j < V; j++)
        {
          if (!selected[j] && G[i][j])
          {
            if (min > G[i][j])
            {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }

    printf("%d - %d : %d\n", x, y, G[x][y]);
    sum+= G[x][y];
    selected[y] = true;
    no_edge++;
  }
  printf("\nTotal weight = %d",sum);
  return 0;
}
