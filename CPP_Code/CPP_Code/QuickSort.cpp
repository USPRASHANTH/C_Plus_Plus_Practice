#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<queue>

using namespace std;

class QuickSort
{
private:
    void Swap(vector<int>& inputArray, int i, int j)
    {
        int temp = inputArray[i];
        inputArray[i] = inputArray[j];
        inputArray[j] = temp;
    }

    int Partition(vector<int>& inputArray, int start, int end)
    {
        int pivotIndex = end;
        end--;
        int pivot = inputArray[pivotIndex];

        do
        {
            while (start <= pivotIndex && inputArray[start] < pivot)
            {
                start++;
            }

            while (end >= 0 && inputArray[end] > pivot)
            {
                end--;
            }

            if (start < end) 
            {
                Swap(inputArray, start, end);
            }
        } while (start < end);

        Swap(inputArray, pivotIndex, end + 1);
        return (end + 1);
    }

    void SortInternal(vector<int>& inputArray, int start, int end)
    {
        if (start == end)
        {
            return;
        }

        int pivotPos = Partition(inputArray, start, end);

        if (pivotPos - start > 1)
        {
            SortInternal(inputArray, start, pivotPos - 1);
        }

        if (end - pivotPos > 1)
        {
            SortInternal(inputArray, pivotPos + 1, end);
        }
    }

    void PrintArrayElements(vector<int> inputArray)
    {
        int size = inputArray.size();
        cout << "Array contents" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << inputArray[i] << " ";
        }

        cout << endl;
    }
public:
    void Sort(vector<int>& inputArray)
    {
        PrintArrayElements(inputArray);
        SortInternal(inputArray, 0, inputArray.size() - 1);
        PrintArrayElements(inputArray);
    }
};
