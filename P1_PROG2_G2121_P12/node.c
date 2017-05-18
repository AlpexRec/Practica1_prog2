/****************************************************
Nombre del módulo:node.c
Autor: Alexis Calderon, Mario Baena
Fecha:21/02/2017
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "types.h"

/*estructura de node*/
struct _Node {
 char name[100];
 int id;
};

Node * node_ini()
{
    Node *n=NULL;
 
    n=(Node *)malloc(sizeof(Node));
    
    if(!n)
        return NULL;

    n->name[0] = '\0';    
     
    n->id = 0;
    
    return n;
}

void node_destroy(Node * n){
    
    if(!n)
        return;
    
    free(n);

    return;
}

int node_getId(const Node * n){
    
    if(!n)
        return -1;
        
    return n->id;
    
}

char* node_getName(const Node * n){
    
    if(!n)
        return NULL;
        
    return (char*)n->name;
}

Node * node_setId(Node * n, const int id){
    
    if(!n)
        return NULL;
    
    n->id = id;
    
    return n;
}

Node * node_setName(Node * n, const char* name){
    
    if(!n)
        return NULL;
    
    strcpy (n->name, name);
    
    return n;
}

Bool node_equals(const Node * n1, const Node * n2){
    
    if(!n1 || !n2)
        return FALSE;
        
    if(n1->id == n2->id && strcmp(n1->name,n2->name) == 0){
        return TRUE;
    }
    
    return FALSE;
}

Node * node_copy(const Node * src){
    
    Node *aux = NULL;

    if(!src)
        return NULL;
        
    aux = node_ini();
    
    if(!aux)
    {
        return NULL;
    }

    strcpy(aux->name,src->name);  

    aux->id = src->id;
    
    return aux;
    
}

int node_print(FILE *pf, const Node * n){
    
    int num;
    
    if(!pf || !n)
        return -1;
        
    num=fprintf(pf,"[%d, %s]",n->id, n->name);
    
    if(num==0)
        return -1;
        
    return num;
}
