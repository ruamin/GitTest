#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *next;
	int vertex;
}node;

node *G[20];
int ViTri[20];
int n;

void Them(int vi, int vj)
{
	node *p, *q;
	q = (node*)malloc(sizeof(node));
	q->vertex = vj;
	q->next = NULL;
	if (G[vi] == NULL)
		G[vi] = q;
	else
	{
		p = G[vi];

		while (p->next != NULL)
			p = p->next;
		p->next = q;
	}
}
void DFS(int i)
{
	node *p;

	printf("\n%d", i);
	p = G[i];
	ViTri[i] = 1;
	while (p != NULL)
	{
		i = p->vertex;

		if (!ViTri[i])
			DFS(i);
		p = p->next;
	}
}

void read_graph()
{
	int i, vi, vj, index;
	printf("Nap so dinh:");

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		G[i] = NULL;
		printf("Nhap so canh:");
		scanf("%d", &index);

		for (i = 0; i < index; i++)
		{
			printf("nhap canh (u,v):");
			scanf("%d%d", &vi, &vj);
			Them(vi, vj);
		}
	}
}

int main()
{
	int i;
	read_graph();
	for (i = 0; i < n; i++)
		ViTri[i] = 0;
	DFS(0);
	system("pause");
}
