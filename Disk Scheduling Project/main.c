//Brien Hewan-Lowe
//CISC 3320
//Disk Scheduling Project

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CYLINDERS 5000 //Number of cylinders
#define NUMBEROFREQUESTS 50 //The number of requests that will be serviced

void randomize(int array[]);
void sort(int array[]);
int FCFS(int requests[]);
int SSTF(int requests[]);
int Look(int requests[], int start, int index);

int main(int argc, const char * argv[])
{
    srand(time(NULL));
    int start = atoi(argv[1]);//This stores the value of the initial position
                              //that gets inputted in on the command line
    if ((atoi(argv[1]) >= CYLINDERS) || (atoi(argv[1]) < 0) || (argc != 2))
    {
        printf("Please enter a number between 0 and 5000.\n");
        return 0;
    }
    
    int requests[NUMBEROFREQUESTS]; //This is an array where the
                                    //50 requests will be stored
    
    
     //The first value in the array of requests
                         //will be a random start index from 0-4999
    //This for loop give the 50 requests a random number
    //from 0-4999
    
    randomize(requests);
    requests[0] = start;
    //Prints the disk queue
    printf("\nThe disk queue is: ");
    for(int i = 0; i < NUMBEROFREQUESTS; i++)
    {
        printf("%i ", requests[i]);
    }
    printf("\nThe number of head movements for FCFS is %i. \n", FCFS(requests));
    
    //Sorts the disk queue in ascending order
    sort(requests);
    //Prints the disk queue
    printf("\nThe disk queue is: ");
    for(int i = 0; i < NUMBEROFREQUESTS; i++)
    {
        printf("%i ", requests[i]);
    }
    printf("\nThe number of head movements for SSTF is %i. \n", SSTF(requests));
  
    randomize(requests);
    int index = rand()%NUMBEROFREQUESTS;
    requests[index] = start;
    printf("\nThe disk queue is: ");
    for(int i = 0; i < NUMBEROFREQUESTS; i++)
    {
        printf("%i ", requests[i]);
    }
    printf("\nThe number of head movements for Look is %i. \n", Look(requests, start, index));

    
}

//Gives requests a random cylinder number
void randomize(int array[])
{
    for(int i = 0; i < NUMBEROFREQUESTS; i++)
    {
        array[i] = rand() % CYLINDERS;
    }
}

//This function will sort the array in ascending order.
void sort(int array[])
{
    int temp = 0;
    for(int i = 0; i < NUMBEROFREQUESTS; i++)
    {
        for(int j = i + 1; j < NUMBEROFREQUESTS; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

//This is the FCFS algorithm that services the requests by the
//order in which they arrive
int FCFS(int requests[])
{
    int head_movement = 0;
   
    //This for loop will run the main FCFS algorithm
    for(int i = 0; i < NUMBEROFREQUESTS - 1; i++)
    {
        head_movement += abs(requests[i] - requests[i+1]);
    }
    
    return head_movement; //Returns the number of head movements from FCFS
}

//This is the SSTF algorithm that executes the requests with the
//shortest seek times first
int SSTF(int requests[])
{
    int head_movement = 0;
    
    //This for loop will run the main SSTF algorithm
    for(int i = 0; i < NUMBEROFREQUESTS - 1; i++)
    {
        head_movement += abs(requests[i] - requests[i+1]);
    }
    
    return head_movement;
}

//This function will run the Look algorithm
//which takes requests from the front of the starting
//position and then at the back of the starting position
int Look(int requests[], int start, int index)
{
    int head_movement = 0;
    int current_value = requests[index];
    int next_value = 0;
    //This for loop services the front portion
    //of the queue
    for(int i = index + 1; i < NUMBEROFREQUESTS; i++)
    {
        next_value = requests[i];
        head_movement += abs(next_value - current_value);
        current_value = next_value;
    }
    
    //This for loop will service the back portion
    //of the queue
    for(int i = index - 1; i >= 0; i--)
    {
        next_value = requests[i];
        head_movement += abs(next_value - current_value);
        current_value = next_value;
    }

    
    return head_movement;
}
