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
			if(u==18)
                printf("S <--");
            else if (u==19)
                printf("T <---");
            else
                printf("%c <--",u + 'A' - 2);
		}
		printf("\tFlow is : %d\n\n",inc);
		max_flow+=inc;
	}
	return max_flow;
}


int main()
{
	int i,j;
	char s, t;
	int no_weights, edge_weight;
	char source_vertex, destination_vertex, new_line;


	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			capacity[i][j]=0;
		}
	}


    FILE *in_file  = fopen("Algo_Lab_Q2_Input.txt", "r");
    if (in_file == NULL)
    {
              printf("Error! Could not open file\n");
              exit(-1);
    }
    fscanf(in_file, "%d", &no_weights);
    fflush(stdin);
    fscanf(in_file, "%c", &new_line);
    fscanf(in_file, "%c%c%d", &source_vertex, &destination_vertex, &edge_weight);
    printf("%c %c %d",source_vertex, destination_vertex, edge_weight);

    for( i=0; i<no_weights ; i++)
    {
        fflush(stdin);
        fscanf(in_file, "%c", &new_line);
        fscanf(in_file, "%c%c%d", &source_vertex, &destination_vertex, &edge_weight);
        printf("\n%c %c %d",source_vertex, destination_vertex, edge_weight);

        //if ((source_vertex >= 'O' && source_vertex <= 'A' && destination_vertex >= 'O' && destination_vertex <= 'A')|| (source_vertex=='S' )||(destination_vertex=='S') || (source_vertex =='T')|| (destination_vertex =='T' ))
        //{
        //    printf("Vertices have to be named between A and O or S or T\n");
        //    return 0;
        //}
        if(source_vertex == destination_vertex)
        {
            printf("No self-loops allowed.\n");
            return 0;
        }

        //if(capacity[destination_vertex- 'A'][source_vertex- 'A']!= -1)
        //{
        //    printf("There already exists an edge between the %c and the %c\n", destination_vertex, source_vertex);
        //    return 0;
        //}
        printf("\n%d", source_vertex-'A');
        capacity[source_vertex-'A'][destination_vertex-'A'] = edge_weight;
    }

    int flag;

    //Checking if there is at least one source and sink

	printf("\nMaximum Flow: %d",ford(18,19));

	return 0;
}

