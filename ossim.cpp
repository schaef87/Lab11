//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                    ossim.cpp
//
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#include "Heap.cpp"

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//
struct TaskData
{
    int getPriority () const
        { return priority; }     // Returns the priority. Needed by the heap.

    int priority,                // Task's priority
        arrived;                 // Time when task was enqueued

};


//--------------------------------------------------------------------

int main ()
{
    Heap<TaskData, int, Less<int> > taskPQ;   // Priority queue of tasks
    TaskData task;               // Task
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        numPtyLevels,            // Number of priority levels
        numArrivals,             // Number of new tasks arriving
        j;                       // Loop counter


    // Seed the random number generator
    srand( (unsigned int) time( NULL ) );

    // Get the required input from the user
	cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;
    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    // Run the simulation
	for ( minute = 0 ; minute < simLength ; minute++ )
    {
		cout << endl;
        cout << "minute " << minute << endl;
        cout << "-------------" << endl;


        // Remove the highest priority task in the queue (if any).
		if ( ! taskPQ.isEmpty() )
        {
               task = taskPQ.remove();                        // <--------------------------- add one line of code here
           cout << "dequeued task with priority "
                << task.priority << " that \n    arrived at minute " << task.arrived << " (waited "
                << (minute-task.arrived) << " minutes in queue)" << endl;
        }


        // Determine the number of new tasks and add them to the queue.
        switch ( rand() % 4 )
        {
          case 0 :
          case 3 : numArrivals = 0; break;
          case 1 : numArrivals = 1; break;
          case 2 : numArrivals = 2;
        }
	    task.arrived = minute;
        for ( j = 0 ; j < numArrivals ; j++ )
        {
            task.priority = rand() % numPtyLevels;
            taskPQ.insert(task);                              // <--------------------------- add one line of code here
            cout << "inserted task with priority " << task.priority << " at time " << minute << endl;
        }
    }

    return 0;
}

