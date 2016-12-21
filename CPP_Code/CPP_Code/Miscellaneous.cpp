#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<queue>

using namespace std;

class AlgorithmUtils
{
private:
    double FindMedianOfSortedArray(vector<int>& array)
    {
        int length = array.size();
        double result = 0;
        if (length % 2 == 1)
        {
            result = array[length / 2];
        }
        else
        {
            int mid = length / 2;
            result = (array[mid - 1] + array[mid]) / 2.0;
        }

        return result;
    }

    int GetStartingPoint(vector<int>& array)
    {
        int size = array.size();
        for (int i = 1; i < size; i++)
        {
            if (array[i] < array[i - 1])
            {
                return i;
            }
        }

        return 0;
    }

    int ShiftIndex(int index, int startingPoint, int length)
    {
        return (index + startingPoint) % length;
    }

    int BinarySearch(vector<int>& array, int left, int right, int key, int startingPoint, int length)
    {
        int newLeft = ShiftIndex(left, startingPoint, length);
        int newRight = ShiftIndex(right, startingPoint, length);

        if (left == right)
        {
            if (array[newLeft] == key)
            {
                return newLeft;
            }

            return -1;
        }

        int mid = (left + right) / 2;
        int newMid = ShiftIndex(mid, startingPoint, length);

        if (key < array[newMid])
        {
            // Search for left sub tree
            return BinarySearch(array, left, mid - 1, key, startingPoint, length);
        }
        else if (key > array[newMid])
        {
            // Search for right sub tree
            return BinarySearch(array, mid + 1, right, key, startingPoint, length);
        }
        else
        {
            return newMid;
        }
    }

    int Minimum(int a, int b)
    {
        if (a < b)
        {
            return a;
        }

        return b;
    }

    void _printParenthesis(int pos, int n, int open, int close)
    {
        static char str[100];

        if (close == n)
        {
            printf("%s \n", str);
            return;
        }
        else
        {
            if (open > close) {
                str[pos] = '}';
                _printParenthesis(pos + 1, n, open, close + 1);
            }
            if (open < n) {
                str[pos] = '{';
                _printParenthesis(pos + 1, n, open + 1, close);
            }
        }
    }

public:

    /* Wrapper over _printParenthesis()*/
    void PrintParenthesis(int n)
    {
        if (n > 0)
            _printParenthesis(0, n, 0, 0);
        return;
    }

    // https://leetcode.com/problems/container-with-most-water/
    int MaxArea(vector<int>& height)
    {
        int size = height.size();
        int maxArea = 0;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int length = Minimum(height[i], height[j]);
                int width = j - i;
                int area = length * width;

                if (area > maxArea)
                {
                    maxArea = area;
                }
            }
        }

        return maxArea;
    }

    int GetIndexOfElement(vector<int>& array, int key)
    {
        int startingPoint = GetStartingPoint(array);
        int length = array.size();
        return BinarySearch(array, 0, length - 1, key, startingPoint, length);
    }

    double FindMedianOfSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int i = 0, j = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        int total = len1 + len2;
        int n = (total + 1) / 2;
        int nth = 0, nplusoneth = 0;

        if (len1 == 0)
        {
            return FindMedianOfSortedArray(nums2);
        }
        else if (len2 == 0)
        {
            return FindMedianOfSortedArray(nums1);
        }

        while (n >= 0)
        {
            if (i == len1)
            {
                if (n == 1)
                {
                    nth = nums2[j];
                }
                else if (n == 0)
                {
                    nplusoneth = nums2[j];
                }

                j++;
            }
            else if (j == len2)
            {
                if (n == 1)
                {
                    nth = nums1[i];
                }
                else if (n == 0)
                {
                    nplusoneth = nums1[i];
                }

                i++;
            }
            else if (nums1[i] < nums2[j])
            {
                if (n == 1)
                {
                    nth = nums1[i];
                }
                else if (n == 0)
                {
                    nplusoneth = nums1[i];
                }

                i++;
            }
            else // if (nums1[i] > nums2[j])
            {
                if (n == 1)
                {
                    nth = nums2[j];
                }
                else if (n == 0)
                {
                    nplusoneth = nums2[j];
                }

                j++;
            }

            n--;
        }

        double result;

        if (total % 2 == 1)
        {
            result = nth;
        }
        else
        {
            result = (nth + nplusoneth) / 2.0;
        }

        return result;
    }

    void NextGreaterElement(vector<int> array)
    {
        stack<int> S;
        int size = array.size();

        S.push(array[0]);

        for (int i = 1; i < size; i++)
        {
            if (S.empty())
            {
                S.push(array[i]);
            }
            else if (array[i] <= S.top())
            {
                S.push(array[i]);
            }
            else
            {
                while (!S.empty() && S.top() < array[i])
                {
                    cout << "NGE for " << S.top() << " is " << array[i] << endl;
                    S.pop();
                }
                S.push(array[i]);
            }
        }

        while (!S.empty())
        {
            cout << "NGE for " << S.top() << " is " << -1 << endl;
            S.pop();
        }
    }

    void StockSpan(vector<int> array)
    {
        stack<int> S;
        int size = array.size();

        S.push(0);
        cout << "Span of " << array[0] << " is 1" << endl;

        for (int i = 1; i < size; i++)
        {
            while (!S.empty() && array[S.top()] < array[i])
            {
                S.pop();
            }

            if (S.empty())
            {
                cout << "Span of " << array[i] << " is " << (i + 1) << endl;
            }
            else
            {
                cout << "Span of " << array[i] << " is " << (i - S.top()) << endl;
            }

            S.push(i);
        }
    }
};
