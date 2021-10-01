#include<stdio.h>
#define a 0
#define b 1
#define c 2
#define max_nodes 1000
#define o 100000000

int n,e;
int capacity[max_nodes][max_nodes];
int flow[max_nodes][max_nodes];
int color[max_nodes];
int pred[max_nodes];
int min(int x,int y)
{
	return x<y?x:y;
}
int head,tail;
int q[max_nodes+2];

void enqueue(int x)
{
	q[tail]=x;
	tail++;
	color[x]=b;
}
int dequeue()
{
	int x=q[head];
	head++;
	color[x]=c;
	return x;
}
int bfs(int start,int target)
{
	int u,v;
	for(u=0;u<n;u++)
	{
		color[u]=a;
	}
	head=0;
	tail=0;
	enqueue(start);
	pred[start]=-1;
	while(head!=tail)
	{
		u=dequeue();
		for(v=0;v<n;v++)
		{
			if(color[v]==a && capacity[u][v] - flow[u][v]>0)
			{
				enqueue(v);
				pred[v]=u;
			}
		}
	}
	return color[target]==c;
}
int ford(int source,int sink)
{
	int i,j,u;
	int max_flow=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			flow[i][j]=0;
		}
	}
	while(bfs(source,sink))
	{
		int inc=o;
		for(u=n-1;pred[u]>=0;u=pred[u])
		{
			inc=min(inc,capacity[pred[u]][u]-flow[pred[u]][u]);
		}
		for(u=n-1;pred[u]>=0;u=pred[u])
		{
			flow[pred[u]][u]+=inc;
			flow[u][pred[u]]-=inc;
			printf("%d <------",u);
        }
        printf("%d \tFlow is : %d\n\n",u,increment);

		max_flow+=inc;
	}
	return max_flow;
}
int main()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			capacity[i][j]=0;
		}
	}
	n=6;
	e=7;
	//capacity[0][1]=8;
	//capacity[0][4]=3;
	//capacity[1][2]=9;
	//capacity[2][4]=7;
	//capacity[2][5]=2;
	//capacity[3][5]=5;
	//capacity[3][2]=7;
	//capacity[4][3]=4;
	int s=0;
	int t=5;
	int no_weights;
	int source_vertex, destination_vertex, edge_weight;
	printf("Please enter number of weights: ");
    scanf("%d", &no_weights);
	for( i=0; i< no_weights ; i++)
    {
        printf("Please enter source vertex: ");
        scanf("%d", &source_vertex);
        printf("Please enter destination vertex: ");
        scanf("%d", &destination_vertex);
        printf("Please enter weight of edge: ");
        scanf("%d", &edge_weight);
        capacity[source_vertex][destination_vertex] = edge_weight;
    }
    for (i = 0; i < N; i++) {
		scanf("%c %c %d\n", &s, &e, &w);
		if (e == 'T') {
			e = 'P';
		}
		if (s == 'S') {
			graph[0][e - 64] = w;
		}
		else {

			graph[s - 64][e - 64] = w;
		}
	}
    printf("Please enter source: ");
    scanf("%d", &s);
    printf("Please enter destination: ");
    scanf("%d", &t);
	printf("Maximum Flow: %d",ford(s,t));

	return 0;
}

