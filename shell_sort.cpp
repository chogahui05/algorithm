#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define sz 1000001
using namespace std;
int arr[sz];
vector <int> si;
void sort(int n);
void subsort(int lo,int gap,int n);
void change(int *a,int *b);
void init();
int main(void)
{
    int n; scanf("%d",&n); init(); //srand(time(NULL)); n = sz; init();
    for(int i=0;i<n;i++)
        scanf("%d",&(arr[i]));//arr[i] = n-i;
    sort(n);
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
}
void sort(int n)
{
    for(int i=(int)si.size()-1;i>=0;i--)
    {
        if(si[i]*2>n)
            continue;
        for(int j=0;j<si[i];j++)
            subsort(j,si[i],n);
    }
}
void subsort(int lo,int gap,int n)
{
    for(int i=lo+gap;i<n;i=i+gap)
    {
        for(int j=i;j>=0;j=j-gap)
        {
            int prev_lo = j-gap;
            if(prev_lo<0 || (arr[prev_lo]<=arr[j])) break;
            change(&arr[prev_lo],&arr[j]);
        }
    }
}
void change(int *a,int *b)
{
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}
void init()
{
    si.push_back(1);
    for(;;)
    {
        int t = si[(int)si.size()-1];
        si.push_back(3*t+1);
        if(3*t+1>sz)
            break;
    }
}
