/*
@Author: Ramaguru Radhakrishnan
@Date: 21 - Dec - 2022
@Description: Creation and Execution of a simple thread
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>

// printWelcomeMessage will be called when the Thread is created in the main function 
// which takes string as an argument

struct varadd
{
	int a;
	int b;
}add;

void *addnumbers(struct *bro)
{
	int ans = 0;
	ans += bro->a;
	ans += bro -> b;
	printf("The sum is %d\n",ans);
	pthread_exit(NULL);
}

void *printWelcomeMessage(void *names) {
    
   sleep(2);    
   char *name = (char *)names;    
   printf("\n[THREAD] Hello, Welcome %s.", name);
   pthread_exit(NULL);
   
}

int main () {

   // thread defintion
   pthread_t threads[6];
   add add;
   
   // parameter to be passed to the called function - printWelcomeMessage
   char names[10][15] = {"Amritha","Praveen","Saurabh","Sangeetha","Lakshmy","Srinivasan","Ramaguru"};
   
   int result;
   
   for(int i = 0; i < 7; i++ ) {
   
      printf("\n[MAIN] Creating thread, %d", i);
      
      // Creating the threading and thus calling the function with parameter passed to it
      result = pthread_create(&threads[i], NULL, printWelcomeMessage, (void *)names[i]);
      
      if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
      }
      
   }
   add.a = 3;
   add.b = 5;
   
   printf("USING THREAD\n");
   result = pthread_create(&threads[0],NULL,addnumbers,(struct *)add);
   
   // Exit the thread
   pthread_exit(NULL);
}
