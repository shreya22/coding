#include<iostream> 
#include<cstdio>

#define MAX 100
#define nil -1
struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
} *front= NULL;

int n;

void create_graph();
void maketree(struct edge tree[]);
void insert_pque(int i, int j, int wt);
struct edge *del_pque();
int isEmpty_pque();

using namespace std;

int main()
{
	struct edge tree[MAX];
	int wt_tree= 0;
	create_graph();
	maketree(tree);
	
	cout<<"edges to be included in minimum spanning tree are: ";
	for(int i=1; i<(n-1); i++)
	{
		cout<<tree[i].u<<" "<<tree[i].v<<endl;
		wt_tree+= tree[i].weight;
	}
	
	cout<<"weight of mst is: "<<wt_tree;
	
	
	return 0;
}


void create_graph()
{	
	cout<<"enter number of vertices in graph";
	cin>>n;
	
	int max= n*(n-1)/2;
	int s, d, wt;
	for(int i=0; i<max; ++i)
	{
		cout<<"enter source and destination indices, (-1, -1) to quit:";
		cin>>s>>d;
		
		if(s==-1 && d==-1) break;
		
		cout<<"enter weight fr this edge:";
		cin>>wt;
		
		if(s<0 || s>=n || d<0 || d>=n)
		{
			cout<<"invalid vertex";
			i--;
		}else{
			insert_pque(s, d, wt);
		}
		
	}

}

void maketree(struct edge tree[])
{
	struct edge *tmp;
	int v1, v2, root_v1, root_v2;
	
	int father[MAX]; 
	int count=0;
	
	for(int i=0; i<n; ++i)
		father[i] = nil;
		
	while(!isEmpty_pque() && count<(n-1))
	{
		tmp= del_pque();
		v1= tmp->u;
		v2= tmp->v;
		
		while(v1 != nil)
		{
			root_v1= v1;
			v1= father[v1];
		}
		
		while(v2 != nil)
		{
			root_v2= v2;
			v2= father[v2];
		}
		
		if(root_v1 != root_v2)  //insert the edge
		{
			count++;
			tree[count].u= tmp->u;
			tree[count].v= tmp->v;
			tree[count].weight= tmp->weight;
			father[root_v2] = root_v1;
		}
	}
	
	if(count< (n-1))
	{
		cout<<"graph is not connected, no spannig tree possible!";
		return;
	}
	
	
} //end of maketree


void insert_pque(int i, int j, int wt)
{
	struct edge *tmp, *q;
	
	tmp->u= i;
	tmp->v= j;
	tmp->weight= wt;
	
	if((front == NULL) || (tmp->weight < front->weight))
	{
		tmp->link = front;
		front= tmp;
	}
	else
	{
		q= front;
		
		while((q->link != NULL) || (q->link->weight < tmp->weight))
			q= q->link;
			
		tmp->link = q->link;
		q->link= tmp;
		
		if(q->link == NULL)
			tmp->link= NULL;
	}
	
} //end of insert_pque()


struct edge *del_pque()
{
	struct edge *tmp;
	tmp= front;
	
	front = front->link;
	
	return tmp;
}

int isEmpty_pque()
{
	if(front == NULL)
		return 1;
	return 0;
}
