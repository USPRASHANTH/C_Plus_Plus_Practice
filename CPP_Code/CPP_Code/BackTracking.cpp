#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<deque>
#include<queue>

using namespace std;

class BackTracking
{
private:
    map<int, vector<char>> T9_map;
    void PrintString(string str)
    {
        int size = str.length();
        for (int i = 0; i < size; i++)
        {
            cout << str[i];
        }

        cout << endl;
    }

    void Swap(string& str, int i, int j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    void PrintPermutationsHelper(string str, int index, int length)
    {
        if (index == length - 1)
        {
            PrintString(str);
        }

        for (int j = index; j < length; j++)
        {
            Swap(str, index, j);
            PrintPermutationsHelper(str, index + 1, length);
            Swap(str, index, j);
        }
    }

    void PopulateT9Map()
    {
        vector<char> T9_2;
        T9_2.push_back('A');
        T9_2.push_back('B');
        T9_2.push_back('C');
        vector<char> T9_3;
        T9_3.push_back('D');
        T9_3.push_back('E');
        T9_3.push_back('F');
        vector<char> T9_4;
        T9_4.push_back('G');
        T9_4.push_back('H');
        T9_4.push_back('I');
        vector<char> T9_5;
        T9_5.push_back('J');
        T9_5.push_back('K');
        T9_5.push_back('L');
        vector<char> T9_6;
        T9_6.push_back('M');
        T9_6.push_back('N');
        T9_6.push_back('O');
        vector<char> T9_7;
        T9_7.push_back('P');
        T9_7.push_back('Q');
        T9_7.push_back('R');
        T9_7.push_back('S');
        vector<char> T9_8;
        T9_8.push_back('T');
        T9_8.push_back('U');
        T9_8.push_back('V');
        vector<char> T9_9;
        T9_9.push_back('W');
        T9_9.push_back('X');
        T9_9.push_back('Y');
        T9_9.push_back('Z');

        T9_map[2] = T9_2;
        T9_map[3] = T9_3;
        T9_map[4] = T9_4;
        T9_map[5] = T9_5;
        T9_map[6] = T9_6;
        T9_map[7] = T9_7;
        T9_map[8] = T9_8;
        T9_map[9] = T9_9;

        // T9_map.find(3)->second
    }

    void PrintT9CombinationsHelper(vector<int> inputArray, int index, int length, string& result)
    {
        if (index == length)
        {
            PrintString(result);
            return;
        }

        int input = inputArray[index];
        vector<char> possibleSubstitutes = T9_map.find(input)->second;
        int size = possibleSubstitutes.size();

        for (int i = 0; i < size; i++)
        {
            result[index] = possibleSubstitutes[i];
            PrintT9CombinationsHelper(inputArray, index + 1, length, result);
        }
    }

    void PrintCommaPermutationsHelper(string str, int index, int length, vector<char> result)
    {
        if (index == length - 1)
        {
            PrintCharArray(result);
            return;
        }

        // Set ',' at position '2i+1' and recur
        int offset = (2 * index) + 1;
        result[offset] = ',';
        PrintCommaPermutationsHelper(str, index + 1, length, result);

        // recur without comma
        result[offset] = ' ';
        PrintCommaPermutationsHelper(str, index + 1, length, result);
    }

    void PrintCharArray(vector<char> result)
    {
        int size = result.size();
        for (int i = 0; i < size; i++)
        {
            if (result[i] != ' ')
            {
                cout << result[i];
            }
        }

        cout << endl;
    }

    void PrintSetOfCharacters(set<char> result)
    {
        set<char>::iterator it;
        for (it = result.begin(); it != result.end(); ++it)
        {
            cout << *it;
        }

        cout << endl;
    }

    /*
     * input - array of characters input
     * n - number of elements in input array
     * r - number of items to select
     * index - current index
     * Repetitions allowed
    */
    void PrintCombinationHelper_WithRepetitions(vector<char> input, int n, int r, int start, int index, vector<char> result)
    {
        if (index == r)
        {
            PrintCharArray(result);
            return;
        }

        for (int i = start; i < n; i++)
        {
            result[index] = input[i];
            PrintCombinationHelper_WithRepetitions(input, n, r, i, index + 1, result);
        }
    }

    /*
    * input - array of characters input
    * n - number of elements in input array
    * r - number of items to select
    * start - pos from which we need to select elements from input
    * index - current index
    * Repetitions not allowed
    */
    void PrintCombinationHelper_WithoutRepetitions(vector<char> input, int n, int r, int start, int index, set<char> result)
    {
        if (index == r)
        {
            PrintSetOfCharacters(result);
            return;
        }

        for (int i = start; i < n; i++)
        {
            // if result set does not contain input[i], select input[i]
            if (result.find(input[i]) == result.end())
            {
                result.insert(input[i]);
                PrintCombinationHelper_WithoutRepetitions(input, n, r, i + 1, index + 1, result);

                set<char>::iterator pos = result.find(input[i]);
                result.erase(pos);
            }
        }
    }

    void FindSubsetSumHelper(vector<int> input, int n, int expectedSum, int sumTillNow, multiset<int> result)
    {
        if (sumTillNow == expectedSum)
        {
            PrintSetOfIntegers(result);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (input[i] + sumTillNow <= expectedSum)
            {
                result.insert(input[i]);
                FindSubsetSumHelper(input, n, expectedSum, sumTillNow + input[i], result);

                multiset<int>::iterator pos = result.find(input[i]);
                result.erase(pos);
            }
        }
    }

    void PrintSetOfIntegers(multiset<int> result)
    {
        set<int>::iterator it;
        for (it = result.begin(); it != result.end(); ++it)
        {
            cout << *it << " ";
        }

        cout << endl;
    }

public:
    void PrintPermutations(string str)
    {
        PrintPermutationsHelper(str, 0, str.length());
    }

    void PrintT9Combinations(vector<int> inputArray)
    {
        int size = inputArray.size();
        PopulateT9Map();
        string result(size, '.');
        PrintT9CombinationsHelper(inputArray, 0, size, result);
    }

    void PrintCommaPermutations(string str)
    {
        vector<char> result;
        int size = str.length();
        for (int i = 0; i < size; i++)
        {
            result.push_back(str[i]);
            result.push_back(' ');
        }

        PrintCommaPermutationsHelper(str, 0, size, result);
        cout << "---" << endl;
    }

    void PrintCombinations_WithRepetitions(vector<char> input, int r)
    {
        vector<char> result;
        int size = input.size();
        for (int i = 0; i < r; i++)
        {
            result.push_back('.');
        }

        PrintCombinationHelper_WithRepetitions(input, size, r, 0, 0, result);
    }

    void PrintCombinations_WithoutRepetitions(vector<char> input, int r)
    {
        set<char> result;
        int size = input.size();

        PrintCombinationHelper_WithoutRepetitions(input, size, r, 0, 0, result);
    }

    // http://www.practice.geeksforgeeks.org/problem-page.php?pid=1264
    void FindSubsetSum(vector<int> input, int sum)
    {
        int size = input.size();
        multiset<int> result;
        FindSubsetSumHelper(input, size, sum, 0, result);
    }
};
