#include <stdio.h>
#include <stdlib.h>

int main() {
    int h = 4;
    
    void *p = &h;
    
    printf("%d\n", *(int *)p);
    
    
    
    void *a = malloc (sizeof(char *) * 20);
    {
        *(char*)(a + i) = '1' + i;
        printf("%c\n", *(char*)(a + i));
    }
    

    int x = 4;
    int d = 7;
        printf("%i\n", x);
        printf("%i\n", &x + 1);



    return 0;
}