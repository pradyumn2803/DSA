#include <stdio.h>
#include <stdlib.h>

typedef struct Myarray
{
    int t_size;
    int u_size;
    int *ptr;
} M;

void set_val(M *a, int t, int u)
{
    // (*a).t_size=t;
    // (*a).u_size=u;
    // (*a).ptr= (int*) malloc(t*sizeof(int));
    int n;
    a->t_size = t;
    a->u_size = u;
    a->ptr = (int *)malloc(t * sizeof(int));
    for (int i = 0; i < u; i++)
    {
        // scanf("%d", &n);
        // (a->ptr)[i] = n;
        scanf("%d",&(a->ptr)[i]);
    }
}

void get_val(M *a)
{

    for (int i = 0; i < a->u_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    M marks;
    set_val(&marks, 10, 2);
    get_val(&marks);

    return 0;
}