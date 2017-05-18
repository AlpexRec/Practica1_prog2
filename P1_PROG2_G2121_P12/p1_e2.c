/****************************************************
Nombre del módulo:p1_e2.c
Autor: Alexis Calderon, Mario Baena
Fecha:21/02/2017
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "types.h"
#include "graph.h"

int main(){
    
    Node *p1,*p2;
    Graph *g;
    int num=0;
    
    g=graph_ini();
    
    if(!g)
    {
        printf("ERROR al crear el grafo");
        return -1;
    }
    
    p1=node_ini();
    
    if(!p1)
    {
        printf("ERROR al crear el nodo1");
        return -1;
    }
    
    p2=node_ini();
    
    if(!p2)
    {
        printf("ERROR al crear nodo2");
        return -1;
    }
    
    p1 = node_setName(p1,"first");
    
    if(!p1)
    {
        printf("ERROR al añadir el nombre al nodo1");
        return -1;
    }
    
    p1 = node_setId(p1,111);
    
     if(!p1)
    {
        printf("ERROR al añadir el id al nodo1");
        return -1;
    }
    
    p2 = node_setName(p2,"second");
    
     if(!p2)
    {
        printf("ERROR al añadir el nombre al nodo2");
        return -1;
    }
    
    p2 = node_setId(p2,222);
    
     if(!p2)
    {
        printf("ERROR al añadir el id al nodo2");
        return -1;
    }

    printf("N=%d, E=%d", graph_getNnodes(g), graph_getNedges(g));
    
    printf("\ninsertando nodo1...\n");
    
    g=graph_addNode(g,p1);
    
    if(!g)
    {
        printf("ERROR al insertar el nodo1");
        return 1;
    }
    
    num=graph_print(stdout,g);
    
    if(num==-1)
    {
        printf("ERROR al imprimir el grafo");
        return -1;
    }
    
    printf("insertando nodo2...\n");
    
    g=graph_addNode(g,p2);
    
    if(!g)
    {
        printf("ERROR al insertar el nodo1\n");
        return 1;
    }

    num=graph_print(stdout,g);
    
    if(num==-1)
    {
        printf("ERROR al imprimir el grafo");
        return -1;
    }
    
    printf("Conectados nodo1 y nodo2? : ");

    if(graph_areConnected(g,node_getId(p1),node_getId(p2)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");

    printf("Conectados nodo2 y nodo1? : ");
    
    if(graph_areConnected(g,node_getId(p2),node_getId(p1)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");

    printf("Insertando Nodo 2 -> Nodo 1: \n");

    g=graph_addEdge(g,node_getId(p2),node_getId(p1));
    
    if(!g)
        return -1;
    
    num=graph_print(stdout,g);
    
    if(num==-1)
    {
        printf("ERROR al imprimir el grafo");
        return -1;
    }
    
    printf("Conectados nodo1 y nodo2? : ");

    if(graph_areConnected(g,node_getId(p1),node_getId(p2)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");

    printf("Conectados nodo2 y nodo1? : ");
    
    if(graph_areConnected(g,node_getId(p2),node_getId(p1)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");

    printf("Insertando Nodo 1 -> Nodo 2: \n");

    g=graph_addEdge(g,node_getId(p1),node_getId(p2));
    
    if(!g)
        return -1;

    num=graph_print(stdout,g);
    
    if(num==-1)
    {
        printf("ERROR al imprimir el grafo");
        return -1;
    }
    
    printf("Conectados nodo1 y nodo2? : ");

    if(graph_areConnected(g,node_getId(p1),node_getId(p2)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");

    printf("Conectados nodo2 y nodo1? : ");
    
    if(graph_areConnected(g,node_getId(p2),node_getId(p1)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");

    printf("Insertando Nodo 2 -> Nodo 1: \n");
    
    num=graph_print(stdout,g);
    
    if(num==-1)
    {
        printf("ERROR al imprimir el grafo");
        return -1;
    }
    
        printf("Conectados nodo1 y nodo2? : ");

    if(graph_areConnected(g,node_getId(p1),node_getId(p2)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");

    printf("Conectados nodo2 y nodo1? : ");
    
    if(graph_areConnected(g,node_getId(p2),node_getId(p1)) == TRUE)
        printf("Sí \n");
    else 
        printf("No \n");
    
    /*destruir nodos*/
    graph_destroy(g);  
    node_destroy(p1);
    node_destroy(p2);
    
    return 0;
}
    
