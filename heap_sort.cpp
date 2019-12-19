#include <stdio.h>
#include <stdlib.h>
struct int_Heap
{
    int *heap,heap_sz;
    const int inf = 2147483647;
    void init(int n)
    {
        if(heap!=NULL)
            free(heap);
        heap = (int *)malloc(sizeof(int)*(2*n+10));
        for(int i=0;i<(2*n+10);i++)
            heap[i] = inf;
        heap_sz = 0;
    }
    void push(int x)
    {
        int cur = heap_sz;
        heap[heap_sz] = x;
        while(cur)
        {
            int parent = ((cur-1)>>1);
            if(heap[parent] <= heap[cur])
                break;
            swap(parent,cur);
            cur = parent;
        }
        heap_sz++;
    }
    int top()
    {
        return heap[0];
    }
    void pop()
    {
        int cur = 0;
        if(heap_sz == 0)
            return;
        heap_sz--; 
        heap[0] = heap[heap_sz]; heap[heap_sz] = inf;
        while(1)
        {
            int ch = ((heap[2*cur+1] <= heap[2*cur+2])?2*cur+1:2*cur+2);
            if(heap[cur] <= heap[ch])
                break;
            swap(cur,ch);
            cur = ch;
        }
    }
    void swap(int lo1,int lo2)
    {
        int temp = heap[lo1];
        heap[lo1] = heap[lo2];
        heap[lo2] = temp;
    }
};
typedef struct int_Heap int_Heap;
int_Heap h;
int main(void)
{
    int n,a; scanf("%d",&n); h.init(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a); h.push(a);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",h.top()); h.pop();
    }
}
