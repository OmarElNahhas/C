/*
Q:
This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

note: if a class lecture starts on the same time another lecture ends, it is counted as 2 classrooms.
*/

#include <stdlib.h>
#include <stdio.h>


int countRooms(int timeClass[][2], int);

int main()
{
    int timeClass[][2] =   {    {30, 75}, // [row][column]
                                {0, 50},
                                {25, 80},
                                {60, 150},
                                {200, 300}
                            };
    int timestampAmount = sizeof(timeClass) / sizeof(timeClass[0]);
    //int columnSize = sizeof(timeClass[0])/sizeof(timeClass[0][0]);
    int requiredRooms = countRooms(timeClass, timestampAmount);
    printf("Rooms required: %i", requiredRooms);
    return 0;
}

int countRooms(int timeClass[][2], int rowSize)
{
    int satisfies = 0;
    int roomsRequired = 0;
    int prevMax = 0;
    int timeStart[rowSize];
    int timeEnd[rowSize];

    for(int i = 0; i < rowSize; i++) //put the start and end times in different arrays
    {
            timeStart[i] = timeClass[i][0];
            timeEnd[i] = timeClass[i][1];
    }

    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < rowSize; j++) //j = 0 to always compare the i-th iteration to the array starting from 0. This way the order of the inserted times are irrelevant
        {
            //printf("timeStart[%i] = %i\n", i, timeStart[i]);
            //printf("timeEnd[%i] = %i\n", i, timeEnd[i]);
            if(
               (timeStart[i] > timeStart[j] && timeStart[i] < timeEnd[j])
               ||
               (timeEnd[i] > timeStart[j] && timeEnd[i] < timeEnd[j])
               ||
               (timeStart[i] < timeStart[j] && timeEnd[i] > timeEnd[j])
               ||
               ( (timeStart[i] == timeStart[j] || (timeEnd[i] == timeEnd[j])) && (i != j) )
               )
            {
                roomsRequired++;
                if(roomsRequired > prevMax)
                    {
                        prevMax = roomsRequired;
                    }
                satisfies++; //how many times does the time satisfies the if-statement?
            }
        }
        roomsRequired = 0;
    }
    if((prevMax == 1 && satisfies > 1) || rowSize <= 2) //if there are 2 lectures, the maximum of other lectures the i-th iteration will see == 1
    {
        prevMax++;
    }
    return prevMax;
}
