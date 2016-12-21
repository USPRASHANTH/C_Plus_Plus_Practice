#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<queue>

using namespace std;

class HeapSortUtils
{
private:
    vector<int> heapArray;

    int Parent(int arrayIndex)
    {
        return arrayIndex - (arrayIndex / 2) - 1;
    }

    int Left(int arrayIndex)
    {
        return (arrayIndex * 2) + 1;
    }

    int Right(int arrayIndex)
    {
        return (arrayIndex * 2) + 2;
    }

    void Swap(int index1, int index2)
    {
        if (index1 < 0 || index2 < 0)
        {
            return;
        }

        int temp = heapArray[index1];
        heapArray[index1] = heapArray[index2];
        heapArray[index2] = temp;
    }

    // Assumes that left and right sub tree of index is already heapified.
    void MinHeapify(int index)
    {
        int size = heapArray.size();
        int leftIndex = Left(index);
        int rightIndex = Right(index);
        if (leftIndex >= size && rightIndex >= size)
        {
            return;
        }

        int root = heapArray[index];
        int left = heapArray[leftIndex];
        int right = root + 1;

        if (rightIndex < size)
        {
            right = heapArray[rightIndex];
        }

        if (left < root && left < right)
        {
            Swap(index, leftIndex);
            MinHeapify(leftIndex);
        }
        else if (right < root && right < left)
        {
            Swap(index, rightIndex);
            MinHeapify(rightIndex);
        }
    }

    void Insert(int key)
    {
        heapArray.push_back(key);
        int index = heapArray.size() - 1;
        while (index != -1)
        {
            int parentIndex = Parent(index);
            if ((parentIndex < 0) || (heapArray[parentIndex] < heapArray[index]))
            {
                break;
            }

            Swap(index, parentIndex);
            index = parentIndex;
        }
    }

    void Delete(int key)
    {
        int index = find(heapArray.begin(), heapArray.end(), key) - heapArray.begin();
        int size = heapArray.size();
        if (index >= size)
        {
            return;
        }

        heapArray[index] = -1;

        while (index != -1)
        {
            int parentIndex = Parent(index);
            if ((parentIndex < 0) || (heapArray[parentIndex] < heapArray[index]))
            {
                break;
            }

            Swap(index, parentIndex);
            index = parentIndex;
        }

        ExtractMin();
    }

    int ExtractMin()
    {
        if (heapArray.empty())
        {
            return -1;
        }

        int root = heapArray[0];
        int size = heapArray.size();
        heapArray[0] = heapArray[size - 1];
        heapArray.pop_back();
        MinHeapify(0);
        return root;
    }

public:
    void HeapSort(vector<int> inputArray)
    {
        heapArray = inputArray;
        cout << "Before sorting" << endl;
        PrintHeapContents();

        // Heapify the input array
        int size = heapArray.size();
        for (int i = size / 2; i >= 0; i--)
        {
            MinHeapify(i);
        }

        cout << "After heapify" << endl;
        PrintHeapContents();

        cout << "Sorted elements" << endl;
        size = heapArray.size();
        for (int i = 0; i < size; i++)
        {
            cout << ExtractMin() << endl;
        }

        cout << "After sorting" << endl;
        PrintHeapContents();
    }

    void PrintHeapContents()
    {
        cout << "Heap array contents" << endl;
        int size = heapArray.size();
        for (int i = 0; i < size; i++)
        {
            cout << heapArray[i] << endl;
        }
    }
};
