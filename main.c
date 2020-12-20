#include <stdio.h>
//makes a copy of the array 
void makeArrayCopy (int fromArray[], int toArray[], int size) {
    //loop thru the size and allocate data into to from from
    for(int i = 0; i < size; i++) {
        toArray[i]=fromArray[i];
    }
}
//------------------------------------------------------------------------------
//sort the array function
void myFavoriteSort (int arr[], int size) {
    int temp;
    //get the first number loop next number until next number
    //greater if yes then swtich places with them 
    for(int i = 0;i < size; i++){
        for(int j = i + 1; j < size; j++) {
            //if the number is greater change
            if(arr[i] >= arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//------------------------------------------------------------------------------
//compares the index of each element
void indexComparison(int unsortedArray[],int sortedArray[],int size, int *counter){
    //loop thru both arrays and if check if they match
    //if yes then counter is added
    for(int i=0;i<size;i++){
        if(unsortedArray[i]==sortedArray[i]){
            *counter+=1;
        }
    }
}
//------------------------------------------------------------------------------
//targets the sum and checks if its possible to add themm 
int targetSum(int arr[], int size, int target, int*index1, int* index2){
    int tmp = 0;
    //simialr loop as the search function 
    //get first number and loop until ends 
    //repeat process
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++){
            //tmp is the holder for values
            tmp = arr[i] + arr[j];
           //if values match then
            if(tmp == target){
                //if theres another digit same with do this
                if(target == arr[i] + arr[j+1]) {
                *index1 = i;
                *index2 = j+1;
                return tmp;
                }
                //else do this 
            else {
                *index1 = i;
                *index2 = j;
                }
                return tmp;
            }
        }
    }
    return -1;
}
int main (int argc, char** argv)
{
 int val; 
 int userInput; 
 int *arr;  //Declare the pointer 
 int size = 5; // Declare a variable for size
 int count = 0;
 
 /*allocating an array of 5 integers */
 arr = (int*)malloc(sizeof(int)*size);
 
 /* prompt the user for input */
 printf ("Enter in a list of numbers to be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 /* loop until the user enters -999 */
 scanf ("%d", &val);
 while (val != -999)
   {
    /* store the value into an array */
    if(count>=size){
            /* set tmp to refer to the location of old array*/
    		int *tmp ; 
    		tmp = arr; 
            
            /*allocate new space for the larger array*/
    		arr = (int*)malloc(sizeof(int)*size*2); 

            /*copy the existing values from the original array to the larger array*/
    		for(int k = 0 ; k <size ; k++){
    			arr[k] = tmp[k];
    		}
            
            /* return the allocated memory from the original array back to the OS*/
    		free(tmp);

            /* update the size1 variable to properly reflect the current size of the array*/
    		size = size *2; 
    }
    arr[count] = val ; 
    count++;
    /* get next value */
    scanf("%d", &val);
   }

int *ar1;
ar1=(int*)malloc(sizeof(int)*count);
/* call function to make a copy of the array of values */
makeArrayCopy(arr,ar1,count);

/* call function to sort one of the arrays */ 
myFavoriteSort(ar1,count);

/* Prompt user to enter a value to pick a task */
printf("Enter 1 to perform index comparison, enter 2 to perform target sum.\n"); 
scanf ("%d", &userInput);

//if user input is anything else then loop until 1 or 2
while(userInput!=1 && userInput!=2){
    printf("Invalid input.Enter 1 or 2.\n");
    scanf ("%d", &userInput);
}

/* If user input is 1, perform index comparison */
if(userInput==1) {
    int counter=0;
    indexComparison(arr,ar1,count,&counter);
    if(0==counter){
        printf("All elements change location in the sorted array. \n");
        }
    else{
        printf("%d values are in the same location in both arrays. \n",counter);
        }
    }
    int index1=0;
    int index2=0;
    
/* If user input is 2, perform target sum */
 /* loop until the user enters -999 */
 if(userInput==2){
 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);
 while (val != -999)
   {
    /* call function to perform target sum operation */
    int ret=targetSum(ar1,count,val,&index1,&index2);
    /* print out info about the target sum results  */
    if(ret!=-1) {
    printf("Success! Elements at indices %d and %d add up to %d\n",index1,index2,ret);
    }
    else if(ret==-1){
        printf("Target sum failed!\n");
    }

    /* get next value */
    scanf("%d", &val);
   }
}

 printf ("Good bye\n");
 return 0;
} 
