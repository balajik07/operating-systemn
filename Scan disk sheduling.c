// C# program to demonstrate
// SCAN Disk Scheduling algorithm
using System;
using System.Collections.Generic;
 
class GFG
{
 
static int size = 8;
static int disk_size = 200;
 
static void SCAN(int []arr, int head, String direction)
{
    int seek_count = 0;
    int distance, cur_track;
    List<int> left = new List<int>(),
                    right = new List<int>();
    List<int> seek_sequence = new List<int>();
 
    // appending end values
    // which has to be visited
    // before reversing the direction
    if (direction == "left")
        left.Add(0);
    else if (direction == "right")
        right.Add(disk_size - 1);
 
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left.Add(arr[i]);
        if (arr[i] > head)
            right.Add(arr[i]);
    }
 
    // sorting left and right vectors
    left.Sort();
    right.Sort();
 
    // run the while loop two times.
    // one by one scanning right
    // and left of the head
    int run = 2;
    while (run-- >0)
    {
        if (direction == "left")
        {
            for (int i = left.Count - 1; i >= 0; i--)
            {
                cur_track = left[i];
 
                // appending current track to seek sequence
                seek_sequence.Add(cur_track);
 
                // calculate absolute distance
                distance = Math.Abs(cur_track - head);
 
                // increase the total count
                seek_count += distance;
 
                // accessed track is now the new head
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right")
        {
            for (int i = 0; i < right.Count; i++)
            {
                cur_track = right[i];
                 
                // appending current track to seek sequence
                seek_sequence.Add(cur_track);
 
                // calculate absolute distance
                distance = Math.Abs(cur_track - head);
 
                // increase the total count
                seek_count += distance;
 
                // accessed track is now new head
                head = cur_track;
            }
            direction = "left";
        }
    }
 
    Console.Write("Total number of seek operations = "
                        + seek_count + "\n");
    Console.Write("Seek Sequence is" + "\n");
    for (int i = 0; i < seek_sequence.Count; i++)
    {
        Console.Write(seek_sequence[i] + "\n");
    }
}
 
// Driver code
public static void Main(String[] args)
{
 
    // request array
    int []arr = { 176, 79, 34, 60,
                    92, 11, 41, 114 };
    int head = 50;
    String direction = "left";
 
    SCAN(arr, head, direction);
}
}
