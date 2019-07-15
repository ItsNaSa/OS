#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
void bubbleSort(int array[],int);

int main(){
	int integerArray[15];
	int noOfElements;
	int pid;
	char *s[15],*str; //array of strings
	printf("Enter the no. of elements in the array :: ");
	scanf("%d",&noOfElements);
	printf("\n");
	
	printf("Enter the elements of array :: \n");
	for(int i = 0; i< noOfElements; i++){
		scanf("%d",&integerArray[i]);
	}
	
	printf("Accepted the array of numbers\n\n");
	printf("Now invoking fork\n\n");
	
//	pid = fork();
	
//	if(pid == 0){		//if the child process is invoked.....
//		printf("Into the child process\n\n");
//		printf("Sorting the array\nCalling the bubble sort\n\n");
		bubbleSort(integerArray,noOfElements);
		printf("Sorting complete\nConverting the array to the string\n");
		
		for(int j = 0 ; j<noOfElements; j++){
			printf("%d\n",integerArray[j]);
			sprintf(str,"%d",integerArray[j]);
			s[j] = malloc(sizeof(str));
			strcpy(s[j],str);
		}
		
		execve("./2b2",s,NULL);
		
		printf("The integer array is converted to the string\n%s\n",str);
		printf("Child process is exiting\n\n");
//	}
//	else{				//parent process is invoked
//		printf("Into the parent process\n\nParent in the waiting mode\n\n");
//		sleep(15);
//		printf("Parent done waiting\n");
//		printf("The parent is exiting\n");
//		
//	}
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int array[],int n){
	int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (array[j] > array[j+1]) 
              swap(&array[j], &array[j+1]); 
}
