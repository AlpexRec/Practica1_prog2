#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "graph.h"
#include "types.h"

int find_node_index(const Graph * g, int nId1);

struct _Graph{
    Node *pnode[MAX_NODES];
    int ady[MAX_ADY][MAX_ADY];
    int nuNodes;
    int nuEdges;
};

Graph * graph_ini(){

    
    Graph *aux = NULL;
    int i,j;
    
    aux = (Graph*) malloc (sizeof(Graph));
    
    if(!aux)
        return NULL;

    for(i=0;i<MAX_NODES;i++){
        aux->pnode[i] = node_ini();
    }

    for(i=0;i<MAX_NODES;i++)
    {
        for(j=0;j<MAX_NODES;j++)
        {
          aux->ady[i][j] = 0;
        }
    }
    
    aux->nuNodes=0;
    
    aux->nuEdges=0;
    
    return aux;
}

void graph_destroy(Graph * g){
    
    int i;
    
    if(!g)
        return;
    
    for(i=0;i<MAX_NODES;i++)
    {
        node_destroy(g->pnode[i]);
    }
    
    free(g);
    
    return;
}

int graph_getNnodes(const Graph * g){
    
    if(!g)
        return -1;
         
    return g->nuNodes;
    
}


int* graph_getNodeIds(const Graph * g){
    
    int *ids;
    int i;
    
    if(!g)
        return NULL;
        
    ids=(int*)malloc(MAX_NODES*sizeof(int)); 
    
    if(!ids)
    {
        return NULL;
    }
        
    for(i=0;i<g->nuNodes;i++)
    {
        ids[i]=node_getId(g->pnode[i]);
        
    }
    
    return ids;
}


int graph_getNedges(const Graph * g){
    
    if(!g)
        return -1;
    
    return g->nuEdges;
    
}

Graph * graph_addNode(Graph * g, const Node* n){
    
    Node * aux;
    int numNodes;
    
    if(!g || !n)
        return NULL;
          
    numNodes = graph_getNnodes(g);

    aux = node_copy(n);
     if(!aux)
        return NULL;
    
    node_destroy(g->pnode[numNodes]);

    g->pnode[numNodes] = aux;
    
    g->nuNodes++;
    
    return g;
}

Graph * graph_addEdge(Graph * g, const int nId1, const int nId2){
    
    if(!g)
        return NULL;
        
    g->ady[find_node_index(g,nId1)][find_node_index(g,nId2)] = 1;
    
    g->nuEdges++;
    
    return g;
}

int find_node_index(const Graph * g, int nId1){
    
    int i,aux;
    
    if(!g)
        return -1;
        
    for(i=0;i<g->nuNodes;i++){
        aux = node_getId(g->pnode[i]);
        if(aux == nId1)
            return i;
    }

    return -1;
}

Node * graph_getNode(const Graph * g, int nId){
    
    Node *p1=NULL;
    
    if(!g)
        return NULL;
        
    p1 = g->pnode[find_node_index(g,nId)];
    
    return p1;
}

Bool graph_areConnected(const Graph * g, const int nId1, const int nId2){
    
    if(!g)
        return FALSE;
    
    if(g->ady[find_node_index(g,nId1)][find_node_index(g,nId2)] == 1){
        return TRUE;
    }
    
        
    return FALSE;
}

int graph_getNumberOfConnectionsFrom(const Graph * g, const int fromId){
    
    int i,cont=0;
    
    if(!g)
        return -1;
    
    for(i=0;i<MAX_NODES;i++){
       
        if(g->ady[fromId][i] == 1)
            cont++;
            
    }  
    
    return cont;
}

int* graph_getConnectionsFrom(const Graph * g, const int fromId){
    
    int *ids=NULL, i, j;
    
    if(!g)
        return NULL;
        
    ids=(int*)malloc(MAX_NODES*sizeof(int));
    
    if(!ids)
        return NULL;
        
    for(i=0,j=0;i<graph_getNnodes(g);i++)
    {
        if(g->ady[fromId][i]==1){
            ids[j]=node_getId(g->pnode[fromId]);
            j++;
        }
    }
    
    return ids;
    
}

int graph_getNumberOfConnectionsTo(const Graph * g, const int toId){
    
    int i,cont=0;
    
    if(!g)
        return -1;
    
    for(i=0;i<MAX_NODES;i++){
       
        if(g->ady[i][toId] == 1)
            cont++;
            
    }  
    
    return cont;
}

int* graph_getConnectionsTo(const Graph * g, const int toId){
    
    int *ids, i, j;
    
    if(!g)
        return NULL;
        
    ids=(int*)malloc(MAX_NODES*sizeof(int));
    
    if(!ids)
        return NULL;
        
    for(i=0,j=0;i<graph_getNnodes(g);i++)
    {
        if(g->ady[i][toId]==1){
            ids[j]=node_getId(g->pnode[i]);
            j++;
        }
    }
    
    return ids;
    
}

int graph_print(FILE *pf, const Graph * g){
    
    int i,j,num;
    
    if(!g || !pf)
        return -1;
        
    num=fprintf(pf, "N=%d E=%d\n", graph_getNnodes(g), graph_getNedges(g));
    
    for(i=0;i<graph_getNnodes(g);i++)
    {
        num+=fprintf(pf, "[ %d, %s]->", node_getId(g->pnode[i]), node_getName(g->pnode[i]));
            for(j=0;j < g->nuNodes;j++){
                num+=fprintf(pf," %d ", g->ady[i][j]);
            }  
        printf("\n");      
    }
    
    return num;

}

