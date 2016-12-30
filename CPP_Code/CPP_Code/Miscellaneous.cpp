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

    // https://leetcode.com/problems/top-k-frequent-elements/
    vector<int> TopKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        map<int, int> countMap;

        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int current = nums[i];
            map<int, int>::iterator it = countMap.find(current);

            if (it == countMap.end()) // entry for key=current not found
            {
                countMap.insert(pair<int, int>(current, 1));
            }
            else
            {
                int frequency = (it->second) + 1;
                countMap[current] = frequency;
            }
        }

        map<int, vector<int>> frequencyList;
        map<int, int>::iterator countMap_iterator;
        for (countMap_iterator = countMap.begin(); countMap_iterator != countMap.end(); countMap_iterator++)
        {
            int current = (countMap_iterator->first);
            int frequency = (countMap_iterator->second);

            map<int, vector<int>>::iterator it = frequencyList.find(frequency);
            if (it == frequencyList.end()) // entry for key=frequency not found
            {
                vector<int> temp;
                temp.push_back(current);
                frequencyList.insert(pair<int, vector<int>>(frequency, temp));
            }
            else
            {
                (it->second).push_back(current);
            }
        }

        int count = k;
        for (int i = size; i >= 0; i--)
        {
            map<int, vector<int>>::iterator it = frequencyList.find(i);
            if (it != frequencyList.end())
            {
                vector<int> temp = (it->second);
                int tempSize = temp.size();

                for (int j = 0; (j < tempSize && count != 0); j++)
                {
                    result.push_back(temp[j]);
                    count--;
                }
            }
        }

        return result;
    }

    // https://leetcode.com/problems/sort-characters-by-frequency/
    string FrequencySort(string s)
    {
        string result;
        map<char, int> countMap;

        int size = s.length();
        for (int i = 0; i < size; i++)
        {
            char current = s[i];
            map<char, int>::iterator it = countMap.find(current);

            if (it == countMap.end()) // entry for key=current not found
            {
                countMap.insert(pair<char, int>(current, 1));
            }
            else
            {
                int frequency = (it->second) + 1;
                countMap[current] = frequency;
            }
        }

        map<int, vector<char>> frequencyList;
        map<char, int>::iterator countMap_iterator;
        for (countMap_iterator = countMap.begin(); countMap_iterator != countMap.end(); countMap_iterator++)
        {
            char current = (countMap_iterator->first);
            int frequency = (countMap_iterator->second);

            map<int, vector<char>>::iterator it = frequencyList.find(frequency);
            if (it == frequencyList.end()) // entry for key=frequency not found
            {
                vector<char> temp;
                temp.push_back(current);
                frequencyList.insert(pair<int, vector<char>>(frequency, temp));
            }
            else
            {
                (it->second).push_back(current);
            }
        }

        for (int i = size; i >= 0; i--)
        {
            map<int, vector<char>>::iterator it = frequencyList.find(i);

            if (it != frequencyList.end())
            {
                // For frequency=i, there are as many characters as in the temp vector.
                vector<char> temp = (it->second);
                int tempSize = temp.size();

                // for each character in the temp vector, insert that character to result i times.
                for (int j = 0; j < tempSize; j++)
                {
                    for (int k = 0; k < i; k++)
                    {
                        result.push_back(temp[j]);
                    }
                }
            }
        }

        return result;
    }

    // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    vector<int> TwoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        int size = numbers.size();
        int left = 0;
        int right = size - 1;

        while (left < right)
        {
            int currentSum = numbers[left] + numbers[right];
            if (currentSum == target)
            {
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }
            else if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return result;
    }

    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    int MaxProfit(vector<int>& prices)
    {
        int size = prices.size();
        bool doWeHaveStock = false;
        int profit = 0;
        int buyingPrice;

        for (int i = 1; i <= size; i++)
        {
            // If i-1 is the last day, and we have stock to sell, and stock price is greater than buying price, sell it now.
            if (i == size)
            {
                if (doWeHaveStock && (buyingPrice < prices[i - 1]))
                {
                    profit = profit + (prices[i - 1] - buyingPrice);
                    doWeHaveStock = false;
                }
            }

            // price increased from i-1 to i.
            else if (prices[i - 1] < prices[i])
            {
                // As of i-1, if we don't have stock, buy stock at i-1.
                if (!doWeHaveStock)
                {
                    buyingPrice = prices[i - 1];
                    doWeHaveStock = true;
                }

                // If we have stock already and i is not the last day, we should wait for stock value to increase. Do nothing now.
            }
            // price decreased from i-1 to i. As of i-1, if we have stock, sell stock at i-1. Otherwise do nothing.
            else if (prices[i - 1] > prices[i])
            {
                if (doWeHaveStock)
                {
                    profit = profit + (prices[i - 1] - buyingPrice);
                    doWeHaveStock = false;
                }
            }
        }

        return profit;
    }

    // https://leetcode.com/problems/count-numbers-with-unique-digits/
    int CountNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
        {
            // 10 to the power of 0 is 1. So, there are two numbers 0 and 1 with unique digits. But the condition is 0 <= x < 1. So only 0 satisfies the condition.
            return 1;
        }

        int result = 10;
        int iDigitNumbers = 9;
        int uniqueDigitsPossible = 9;

        for (int i = 2; (i <= n && uniqueDigitsPossible > 0); i++)
        {
            iDigitNumbers = iDigitNumbers * uniqueDigitsPossible;
            result = result + iDigitNumbers;
            uniqueDigitsPossible--;
        }

        return result;
    }

    // https://leetcode.com/problems/missing-number/
    int MissingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int sumFromOntToN = (n * (n + 1)) / 2;
        int actualSum = 0;

        for (int i = 0; i < n; i++)
        {
            actualSum += nums[i];
        }

        return sumFromOntToN - actualSum;
    }

    int MissingNumber_SortedArray(vector<int>& nums)
    {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int missingNumber = -1;

        while (left <= right)
        {
            int mid = left + ((right - left) / 2);

            // If entire elements from left to right is correct, then missing element is right + 1
            if (nums[left] == left && nums[right] == right)
            {
                missingNumber = nums[right] + 1;
                break;
            }
            // If entire elements from left to right is wrong, then missing element is left - 1
            else if (nums[left] != left && nums[right] != right)
            {
                missingNumber = nums[left] - 1;
                break;
            }
            // If left half is correct, check right half
            else if (nums[left] == left && nums[mid] == mid)
            {
                left = mid + 1;
            }
            // If right half is correct, check left half
            else if (nums[right] != right && nums[mid] != mid)
            {
                right = mid - 1;
            }
        }

        return missingNumber;
    }

    void KthSmallest_InSortedMatrix(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<int>& sortedLinearArray, int rows, int columns, int i, int j)
    {
        if (visited[i][j])
        {
            return;
        }

        visited[i][j] = true;
        sortedLinearArray.push_back(matrix[i][j]);

        int next_i = i + 1;
        int next_j = j + 1;

        if (next_i < rows && next_j < columns)
        {
            if (matrix[next_i][j] < matrix[i][next_j])
            {
                KthSmallest_InSortedMatrix(matrix, visited, sortedLinearArray, rows, columns, next_i, j);
                KthSmallest_InSortedMatrix(matrix, visited, sortedLinearArray, rows, columns, i, next_j);
            }
            else
            {
                KthSmallest_InSortedMatrix(matrix, visited, sortedLinearArray, rows, columns, i, next_j);
                KthSmallest_InSortedMatrix(matrix, visited, sortedLinearArray, rows, columns, next_i, j);
            }
        }
        else if (next_i < rows)
        {

        }
        else if (next_j < columns)
        {

        }
    }

    // https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
    int KthSmallest(vector<vector<int>>& matrix, int k)
    {

    }
};
