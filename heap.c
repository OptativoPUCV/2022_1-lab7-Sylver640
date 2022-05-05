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
