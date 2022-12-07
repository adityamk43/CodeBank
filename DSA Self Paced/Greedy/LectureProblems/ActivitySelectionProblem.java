/**
 * @file class ActivitySelectionProblem.java
 * @author ADITYA BHARDWAJ
 * @brief
 *
 * Problem: You are given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single machine, assuming that a machine can only work on a single activity/task at a time.
 *
 * Example 1: Consider the following 3 activities sorted by
finish time.
    start[]  =  {10, 12, 20};
    finish[] =  {20, 25, 30};
A person can perform at most two activities. The
maximum set of activities that can be executed
is {0, 2} [ These are indexes in start[] and
finish[] ]

Example 2: Consider the following 6 activities
sorted by finish time.
    start[]  =  {1, 3, 0, 5, 8, 5};
    finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The
maximum set of activities that can be executed
is {0, 1, 3, 4} [ These are indexes in start[] and
finish[] ]

The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

To do this:

1.) Sort the activities according to their finishing time.

2.) Select the first activity from the sorted array and print it.

3.) Do following for remaining activities in the sorted array.
->If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.
->Else if current activity overlaps with the last picked activity in the solution, ignore the current activity.
*
* @version 0.1
* @date 2022-12-07 09:51 PM
*
* @copyright Copyright (c) 2022
*
*/
import java.util.Arrays;

class Activity implements Comparable<Activity>
{
    int start;
    int finish;

    Activity(int s, int f)
    {
        this.start = s;
        this.finish = f;
    }

    @Override
    public int compareTo(Activity a)
    {
        return finish - a.finish;
    }
}


public class ActivitySelectionProblem {

    /**
     * TIME COMPLEXITY: O(nlogn)
     * AUX SPACE: O(1) as we are not creating array
     * @param arr
     * @return
     */
    public static int maxActivity(Activity arr[])
    {
        //O(nlogn)
        Arrays.sort(arr);

        int res=1;
        int prev=0;

        //⊝(n)
        for (int i=1; i<arr.length; i++)
        {
            if (arr[i].start >= arr[prev].finish)
            {
                res++;
                prev = i;
            }
        }

        return res;
    }

    public static void main(String args[])
    {   
        //EXAMPLE 1
        Activity arr[] = {
            new Activity(3, 8),
            new Activity(2, 4),
            new Activity(1, 3),
            new Activity(10, 11)
        };
        
        //EXAMPLE 2
        // Activity arr[] = {
            //     new Activity(12, 25),
            //     new Activity(10, 20),
            //     new Activity(20, 30)
            // };
        
        System.out.println(maxActivity(arr));

    }
}
