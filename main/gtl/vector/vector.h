#ifndef _vector_
#define _vector


typedef void (*VectorFreeFunction)(void *elem);
typedef int (*VectorCompareFunction)(const void *elem1, const void *elem2);

typedef struct {
    void* base;
    int logLen;
    int allocLen;
    int elem_size;
    VectorFreeFunction freeFn;
} Vector;


void VectorNew(Vector* vec, int elem_size, VectorFreeFunction freeFn);

int VectorIsEmpty(Vector* vec);

int VectorSize(Vector* vec);

int VectorCapacity(Vector* vec);

void* VectorGet(Vector* vec, int index);

void VectorInsert(Vector* vec, void* elem, int index);

void VectorRemove(Vector* vec, int index);

void VectorPush(Vector* vec, void* elem);

void VectorPop(Vector* vec);

void VectorShift(Vector* vec);

void VectorUnshift(Vector* vec, void* elem);

#endif