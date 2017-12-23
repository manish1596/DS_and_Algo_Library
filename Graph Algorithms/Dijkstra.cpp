#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct AdjListNode
{
    int dest;
    int wt;
    AdjListNode* next;
};

struct AdjList
{
    char color;
    int idx;
    int p;
    int d;
    int f;
    AdjListNode* head;
};

struct compare
 {
   bool operator()(const AdjList& l, const AdjList& r)
   {
       return l.d > r.d;
   }
 };

struct Graph
{
    int V;
    AdjList* arr;
};

AdjListNode* create_node(int x, int wt)
{
    AdjListNode* newnode;
    newnode=new AdjListNode;
    newnode->dest=x;
    newnode->wt=wt;
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
        g->arr[i].idx=i;
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

void add_edge_dir(Graph* g, int src, int dest, int wt)
{
    AdjListNode* newnode=create_node(dest,wt);
    newnode->next=g->arr[src].head;
    g->arr[src].head=newnode;
}

void add_edge_undir(Graph* g, int src, int dest, int wt)
{
    if(src==dest)
    {
        cout << "No self loops are possible in undirected graph.";
        return;
    }
    AdjListNode* newnode=create_node(dest, wt);
    newnode->next=g->arr[src].head;
    g->arr[src].head=newnode;
    newnode=create_node(src, wt);
    newnode->next=g->arr[dest].head;
    g->arr[dest].head=newnode;
}

void relax(Graph* g, int u, int v){
    AdjList u1=g->arr[u];
    AdjListNode* temp=u1.head;
    while(temp->dest!=v){
        temp=temp->next;
    }
    int wt1=temp->wt;
    if ((g->arr[v]).d > u1.d+wt1){
        g->arr[v].d=u1.d+wt1;
        g->arr[v].p=u;
    }
}

void c_lear(std::priority_queue< AdjList, std::vector<AdjList>, compare >* Q){
    while(Q->size()!=0)
        Q->pop();
}

void f_ill(std::priority_queue< AdjList, std::vector<AdjList>, compare >* Q, Graph* g, std::vector<int> vec){
    int i;
    for(i=0; i<g->V; i++){
        if(std::find(vec.begin(),vec.end(),i)==vec.end())
            Q->push(g->arr[i]);
    }
}

int main(){
    int i,j,n,sr, de, w;
    vector<int> S;
    Graph* g=new Graph;
    create_graph(g, 7);
    g->arr[0].d=0;
    AdjList temp;
    AdjListNode* tempnode;
    cout << "Enter the number of edges :";
    cin >> n;
    cout << "Enter the src, dest and the wt of the edges :";
    for(i=0; i<n; i++){
        cin >> sr >> de >> w;
        add_edge_dir(g,sr,de,w);
    }
    std::priority_queue< AdjList, std::vector<AdjList>, compare > Q;
    f_ill(&Q, g,S);
    while(Q.size()!=0){
        temp=Q.top();
        S.push_back(temp.idx);
        Q.pop();
        tempnode=temp.head;
        while(tempnode!=NULL){
            relax(g, temp.idx, tempnode->dest);
            tempnode=tempnode->next;
        }
        c_lear(&Q);
        f_ill(&Q, g,S);
    }
    for(i=1; i<g->V; i++){
        cout << g->arr[i].d << " ";
    }

}
