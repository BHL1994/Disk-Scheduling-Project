# Disk Scheduling Project
CISC 3320

Author:
Brien Hewan-Lowe
Coding, documentation and output was all completed by me.

Problem: Write a program that implements 3 of the 6 disk-scheduling algorithms. The program will have a disk that contains 5000 cylinders numbered 0-4999. The program will generate a 50 requests and each must be serviced based on the 3 algorithms that were chosen. An initial position must be passed through a command line argument and the number of head movements for each algorithm must be shown.

int main(int argc, const char * argv[])
In main the program will first ask for a value between 0-4999 to be stored in the start variable. This variable will give a starting position for the algorithms to run. A constant named CYLINDERS is declared with a value of 5000, a constant named NUMBEROFCYLINDERS is declared with a value of 50 and an array of integers named request is made with 50 elements. Before each algorithm is ran the program will either randomize or sort the array of requests and then print the current values in them.

void randomize(int array[])
The randomize function will take in an array and add a random value between 0-4999 to each element.

void sort(int array[])
The sort function will take in an array as an parameter and sort it in ascending order.

int FCFS(int requests[])
The FCFS function will run the FCFS algorithm. This algorithm will service the requests by the order in which they arrive. The main for loop will iterate through the array and subtract the current value from the next value and add that absolute value of that value to the head movement variable and then return it.

int SSTF(int requests[])
The SSTF function runs the SSTF algorithm, which executes the requests with the shortest seek times first. First the array of requests is sorted in ascending order and then similar to the FCFS algorithm, the for loop will iterate through the array and subtract the current value from the next value and then add the absolute value of that value to the head movement value and return it.

int Look(int requests[], int start, int index)
This function will run the Look algorithm which services the requests after the starting position first and then services the requests before the starting position. This function takes in 3 parameters. First a current value variable is declared and is set to the value of the staring position. The first loop iterates from the first position after the starting position to the end of the array. On each iteration the next value is set to the value after the current value, the head movement variable is given the value of the next value subtracted from the current value, and then the current value is set to the value of the next value. The next loop does the same thing however this time it iterates from the position before the starting value until the first element in the array.

