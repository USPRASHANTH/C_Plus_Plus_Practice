#include "stdafx.h"
#include "MinHeap.cpp"
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<queue>

using namespace std;

class KthLargest
{
public:
    void FindKthLargest(int k, vector<int> inputArray)
    {
        //*
        MinHeap minHeap;
        int size = inputArray.size();
        for (int i = 0; i < size; i++)
        {
            if (i < k)
            {
                minHeap.Insert(inputArray[i]);
            }
            else
            {
                if (inputArray[i] < minHeap.FindMin())
                {
                    continue;
                }

                minHeap.ExtractMin();
                minHeap.Insert(inputArray[i]);
            }
        }

        minHeap.PrintHeapContents();
        cout << "(" << k << ") th largest element is " << minHeap.FindMin() << endl;

        // Clean up the min heap that we constructed.
        for (int i = 0; i < k; i++)
        {
            minHeap.ExtractMin();
        }
        //*/
    }
};
