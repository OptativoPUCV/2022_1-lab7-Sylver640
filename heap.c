#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if (pq->size == 0) return NULL;
   return (void*) pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
   if (pq->size == pq->capac)
   {
      pq->capac = (pq->capac*2)+1;
      pq->heapArray = realloc(pq->heapArray, pq->capac);
   }

   pq->heapArray[pq->size+1].data = data;
   pq->heapArray[pq->size+1].priority = priority;
   pq->size++;

   int auxSize = pq->size;
   heapElem aux = pq->heapArray[auxSize];
   heapElem auxFather = pq->heapArray[(auxSize-1)/2];
   printf("prioridad antes de while: ");
   printf("[%i ", pq->heapArray[0].priority);
   for (int i = 1; i < pq->size; i++)
   {
      printf("%i ", pq->heapArray[i].priority);  
   }
   printf("]\n");

   while (aux.priority > auxFather.priority)
   {
      aux = pq->heapArray[auxSize];
      aux = auxFather;
      auxFather = aux;

      auxSize = auxSize/2;
   }
}

void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap* new = (Heap*) malloc (sizeof(Heap));
   new->size = 0;
   new->capac = 3;

   new->heapArray = (heapElem*) malloc (3*sizeof(heapElem));

   return new;
}
