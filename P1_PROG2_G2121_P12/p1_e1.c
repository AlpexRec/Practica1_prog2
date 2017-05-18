/****************************************************
Nombre del módulo:p1_e1.c
Autor: Alexis Calderon, Mario Baena
Fecha:21/02/2017
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "types.h"

int main(){
    
    Node *p1=NULL, *p2=NULL;
    int num=0;
    
    p1 = node_ini();
    
    if(!p1)
    {
        node_destroy(p1); 
        printf("Error al reservar memoria\n");
        return -1;
    }
         
    p2 = node_ini();
    
    if(!p2)
    {
        printf("Error al reservar memoria\n");
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
    
    num=node_print(stdout, p1);
    
    if(num==-1)
    {
        printf("ERROR al imprimir nodo1");
  
        return -1;
    }
    num=node_print(stdout, p2);
    
    if(num==-1)
    {
        printf("ERROR al imprimir nodo2");

        return -1;
    }
    
    printf("\n");
    
    printf("Son Iguales?: ");
    
    if(node_equals(p1,p2) == TRUE){
        printf("Sí\n");
    }
    else
        printf("No\n");
       
    printf("El id del primer nodo es: %d\n", node_getId(p1));
    
    printf("El nombre del segundo nodo es: %s\n", node_getName(p2));
    
    node_destroy(p2);
    
    p2 = node_copy(p1);
    
    if(!p2)
    {
        printf("ERROR al copiar el nodo2");
    
        return -1;
    }
    
    node_print(stdout, p1);
    
    if(num==-1)
    {
        printf("ERROR al imprimir nodo1");
    
        return -1;
    }
    
    node_print(stdout, p2);
    
    if(num==-1)
    {
        printf("ERROR al imprimir nodo2");
    
        return -1;
    }
    
    printf("\n");
    
    printf("Son Iguales?: ");
    
    if(node_equals(p1,p2) == TRUE){
        printf("Sí\n");
    }
    else
        printf("No\n");
        
    node_destroy(p1);
    node_destroy(p2);
    
    return 0;
}