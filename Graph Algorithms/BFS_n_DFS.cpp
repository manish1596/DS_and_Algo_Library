#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

struct AdjListNode
{
    int dest;

    AdjListNode* next;
};

struct AdjList
{
    char color;
    int p;
    int d;
    int f;
    AdjListNode* head;
};

struct queu
{
    AdjList* q;
    int fr;
    int re;
};


struct Graph
{
    int V;
    AdjList* arr;
};

AdjListNode* create_node(int x)
{
    AdjListNode* newnode;
    newnode=new AdjListNode;
    newnode->dest=x;
    newnode->next=NULL;
    return newnode;
}

Graph* create_graph(Graph* g, int v)
{
    g->V=v;
    g->arr=new AdjList[v];
    int i;
    for(i=0; i<v; i++)
    {
        g->arr[i].head=NULL;
        g->arr[i].color='w';
        g->arr[i].p=INT_MIN;
        g->arr[i].d=INT_MAX;
        g->arr[i].f=INT_MAX;
    }
    return g;
}

void reinitGraph(Graph* g)
{
    int i;
    for(i=0; i<g->V; i++)
    {
        g->arr[i].color='w';
        g->arr[i].p=INT_MIN;
        g->arr[i].d=INT_MAX;
        g->arr[i].f=INT_MAX;
    }
}

void add_edge_dir(Graph* g, int src, int dest)
{
    AdjListNode* newnode=create_node(dest);
    newnode->next=g->arr[src].head;
    g->arr[src].head=newnode;
}

void add_edge_undir(Graph* g, int src, int dest)
{
    if(src==dest)
    {
        cout << "No self loops are possible in undirected graph.";
        return;
    }
    AdjListNode* newnode=create_node(dest);
    newnode->next=g->arr[src].head;
    g->arr[src].head=newnode;
    newnode=create_node(src);
    newnode->next=g->arr[dest].head;
    g->arr[dest].head=newnode;
}

void BFS(Graph* g, int s)
{
    AdjListNode* aln;
    int al;
    g->arr[s].color='g';
    g->arr[s].d=0;
    g->arr[s].p=INT_MIN;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        al=q.front();
        q.pop();
        //cout << "** " << al << " **";
        aln=g->arr[al].head;
        while(aln!=NULL)
        {
            if(g->arr[aln->dest].color=='w')
            {

                g->arr[aln->dest].color='g';
                g->arr[aln->dest].d=g->arr[al].d+1;
                g->arr[aln->dest].p=al;
                q.push(aln->dest);
                //cout << "&" << al << "& " << aln->dest << g->arr[aln->dest].color << g->arr[aln->dest].d << " &" << al << "&";
            }
            aln=aln->next;
        }
        g->arr[al].color='b';
    }
}

                                            //static AdjListNode** aln=new AdjListNode*[20];

void DFS_visit(Graph* g, AdjListNode* a1, int u)
{

    AdjListNode* aln1;
    //AdjList* al;
    //al=&(g->arr[u]);
    static int time=0;
    aln1=a1;
    time++;
    g->arr[u].d=time;
    cout << "***" << time << "***";
    g->arr[u].color='g';
    //cout << g->arr[u].color;
    while(aln1!=NULL)
    {
        if(g->arr[aln1->dest].color=='w')
        {
            g->arr[aln1->dest].p=u;
            DFS_visit(g, g->arr[aln1->dest].head, aln1->dest);
            //cout << "Check";

        }

        aln1=(aln1)->next;
    }
    g->arr[u].color='b';
    time++;
    g->arr[u].f=time;
    cout << "***" << time << "***";

    if(time>=2*g->V)
        time=0;
}

void DFS(Graph* g)
{
    int i;
    /*for(i=0; i<20; i++)
    {
        aln[i]->dest=0;
        aln[i]->next=NULL;
    }*/
    for(i=0; i<g->V; i++)
    {
        if(g->arr[i].color=='w')
            DFS_visit(g, g->arr[i].head, i);
    }
}

void printGraph(struct Graph* graph)
{
    int v;
    struct AdjListNode* pCrawl;
    for (v = 0; v < graph->V; ++v)
    {
        pCrawl = graph->arr[v].head;
        cout << "\n Adjacency list of vertex" << v << "\n head ";
        while (pCrawl)
        {
            cout << "-> " << pCrawl->dest;
            pCrawl = pCrawl->next;
        }
        cout << "\n";
    }
}





int main()
{
    /*queue<AdjList> q;
    AdjList a, c;
    a.color='w';
    a.p=1;
    a.d=2;
    a.head=NULL;
    q.push(a);
    AdjList b;
    b.color='b';
    b.p=1;
    b.d=2;
    b.head=NULL;
    q.push(b);
    c=q.front();
    cout << c.color << "\n";
    //cout << c.color << "\n";
    cout << q.empty();
    q.pop();
    cout << q.empty();
    c=q.front();
    cout << c.color;
    q.pop();
    cout << q.empty();*/
    Graph* g=new Graph;
    create_graph(g, 5);
    add_edge_undir(g, 0, 3);
    add_edge_undir(g, 0, 1);
    add_edge_undir(g, 0, 4);
    add_edge_undir(g, 4, 1);
    add_edge_undir(g, 3, 4);
    BFS(g, 4);
    cout << g->arr[1].d << "\n";
    cout << g->arr[1].p;
    Graph* g1=new Graph;
    create_graph(g1, 6);
    add_edge_dir(g1, 1, 4);
    add_edge_dir(g1, 1, 3);
    add_edge_dir(g1, 1, 2);
    add_edge_dir(g1, 4, 2);
    add_edge_dir(g1, 0, 1);
    add_edge_dir(g1, 2, 5);
    add_edge_dir(g1, 3, 1);
    add_edge_dir(g1, 5, 3);
    add_edge_dir(g1, 4, 0);


    printGraph(g1);
    DFS(g1);
    for(int k=0; k<6; k++)
    {
        cout << g1->arr[k].d << "/" << g1->arr[k].f;
        cout << "\n" << g1->arr[k].p;
        cout << "\n";
    }

    reinitGraph(g1);

    BFS(g1, 4);

    for(int k=0; k<6; k++)
    {
        cout << "For node "<< k << "\n" << g1->arr[k].d << "\n";
        cout << g1->arr[k].p << "\n";
    }
    Graph* g2=new Graph;
    create_graph(g2, 4);
    add_edge_undir(g2, 0, 3);
    add_edge_undir(g2, 0, 2);
    add_edge_undir(g2, 1, 3);
    add_edge_undir(g2, 1, 2);
    printGraph(g2);
    //reinitGraph(g2);
    for(int u=0; u<4; u++)
        cout << "&&&" << g2->arr[u].color << "&&&";
    DFS(g2);
    for(int k=0; k<4; k++)
    {
        cout << g2->arr[k].d << "/" << g2->arr[k].f;
        cout << "\n" << g2->arr[k].p;
        cout << "\n";
    }
    return 0;
}
