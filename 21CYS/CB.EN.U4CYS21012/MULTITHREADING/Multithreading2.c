#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>

struct number {
    int a;
    int b;
};

void *addition ( void *s){

    struct number *z = (struct number *)s;
    printf("Adding %d and %d gives %d	\n",z->a,z->b,z->a + z->b);
}

int main(){

    int result;
    pthread_t threads[5];
    struct number k[5];
    for ( int i = 0; i < 5; i++ ){
        scanf("%d", &k[i].a);
        scanf("%d", &k[i].b);
        result = pthread_create(&threads[i], NULL, addition, (void *)&k[i]);

        if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
      }
    }
}
