#include <stdlib.h>

typedef struct {
    int price;
    int span;
} Pair;

typedef struct {
    Pair stack[10000];
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = malloc(sizeof(StockSpanner));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;

    while (obj->top >= 0 &&
           obj->stack[obj->top].price <= price) {
        span += obj->stack[obj->top].span;
        obj->top--;
    }

    obj->stack[++obj->top].price = price;
    obj->stack[obj->top].span = span;

    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}