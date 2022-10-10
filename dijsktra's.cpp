#include <stdio.h>
#define INFINITY 9999
void Dijkstra(int Graph[10][10], int n, int start) 
{
  int cost[10][10], distance[10], pred[10];
  int visited[10], count, mindistance, nextnode, i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];
	for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }
  distance[start] = 0;
  visited[start] = 1;
  count = 1;
  while (count < n - 1) {
    mindistance = INFINITY;
	for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }
	visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d node: %d", i, distance[i]);
      printf("\nPath to the node will be:%d",i);
	  j=i;
 	  do
 	 {
		j=pred[j];
		printf("<-%d",j);
	 }while(j!=start);
	 printf("\n");
    }
}
int main() 
{
  int Graph[10][10], i, j, n, u;
  printf("Enter no. of vertices:");
  scanf("%d",&n);
  printf("\nEnter the elements of adjacency matrix:\n");
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  scanf("%d",&Graph[i][j]);
  printf("\nEnter the source node:");
  scanf("%d",&u);
  Dijkstra(Graph, n, u);
  return 0;
}
