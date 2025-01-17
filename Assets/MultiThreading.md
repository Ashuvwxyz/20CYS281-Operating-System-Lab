# 20CYS281 - Operating System Lab 
![](https://img.shields.io/badge/Batch-CYS-lightgreen) ![](https://img.shields.io/badge/UG-blue) ![](https://img.shields.io/badge/Subject-OS-blue)

## MultiThreading

**MultiThreading** is a form of Multitasking where concurrent execution of the program happens. _Process-based_ and _thread-based_ concurrent executions or multitasking are supported. In process-based, it is concurrent execution of the programs whereas in thread-based concurrent execution of parts of the same program. 

## MultiThreading in C 

C doesn't support Multithreading. Only through **POSIX Standards for threads (pthread)** implementations are available. 

### Header file
```
#include <pthread.h>
```

### Function 
```
pthread_create(&thread_id, attr, myFunc, parameters);
```

- &thread_id - pointer to thread_id 
- attr - thread attributes or NULL for default attributes
- myFunc - Function to be called once the thread is created
- parameters - parameters to the function (myFunc) called or NULL 

### Sample Example Program

```
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
void *printWelcomeMessage(void *names) {
    
   sleep(2);    
   char *name = (char *)names;    
   printf("\n[THREAD] Hello, Welcome %s.", name);
   pthread_exit(NULL);
   
}

int main () {

   // thread defintion
   pthread_t threads[5];
   
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
   
   // Exit the thread
   pthread_exit(NULL);
}
```
