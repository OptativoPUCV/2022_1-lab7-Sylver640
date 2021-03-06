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
      pq->heapArray = realloc(pq->heapArray, pq->capac*sizeof(heapElem));
   }

   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;

   int auxSize = pq->size;
   int auxFatherSize = ((pq->size-1)/2);
   heapElem* aux = (heapElem*) malloc (sizeof(heapElem));

   while (auxSize > 0)
   {
      if (pq->heapArray[auxSize].priority > pq->heapArray[auxFatherSize].priority)
      {
         *aux = pq->heapArray[auxFatherSize];
         pq->heapArray[auxFatherSize] = pq->heapArray[auxSize];
         pq->heapArray[auxSize] = *aux;
      }
      auxSize = auxFatherSize;
      auxFatherSize = (auxSize-1)/2;
   }
   pq->size++;
}

void heap_pop(Heap* pq){
   heapElem* aux = (heapElem*) malloc (sizeof(heapElem));
   
   pq->heapArray[0] = pq->heapArray[pq->size];
   pq->size--;

   int auxSize = 0;
   int youngerAux = (2*auxSize) + 1;
   int olderAux = (2*auxSize) + 2; 
   while (auxSize < pq->size)
   {
      if (pq->heapArray[auxSize].priority < pq->heapArray[youngerAux].priority && pq->heapArray[youngerAux].priority > pq->heapArray[olderAux].priority)
      {
         *aux = pq->heapArray[auxSize];
         pq->heapArray[auxSize] = pq->heapArray[youngerAux];
         pq->heapArray[youngerAux] = *aux;

         auxSize = youngerAux;
         youngerAux = (2*auxSize) + 1;
         olderAux = (2*auxSize) + 2;
      }
      else if (pq->heapArray[auxSize].priority < pq->heapArray[olderAux].priority && pq->heapArray[olderAux].priority > pq->heapArray[youngerAux].priority)
      {
         *aux = pq->heapArray[auxSize];
         pq->heapArray[auxSize] = pq->heapArray[olderAux];
         pq->heapArray[olderAux] = *aux;

         auxSize = olderAux;
         youngerAux = (2*auxSize) + 1;
         olderAux = (2*auxSize) + 2;
      }
      else
         break;
   }
}

Heap* createHeap(){
   Heap* new = (Heap*) malloc (sizeof(Heap));
   new->size = 0;
   new->capac = 3;

   new->heapArray = (heapElem*) malloc (3*sizeof(heapElem));

   return new;
}
