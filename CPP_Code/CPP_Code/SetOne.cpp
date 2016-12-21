#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<queue>

using namespace std;

class DP_SetOne
{
private:
    int Max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }

        return b;
    }

    void PrintArray(vector<int> array)
    {
        int size = array.size();

        for (int i = 0; i < size; i++)
        {
            cout << array[i] << "\t";
        }

        cout << endl;
    }

    void PrintTwoDimensionalArray(vector<vector<int>> array)
    {
        int rows = array.size();

        for (int i = 0; i < rows; i++)
        {
            int columns = array[i].size();

            for (int j = 0; j < columns; j++)
            {
                cout << array[i][j] << "\t";
            }

            cout << endl;
        }
    }
public:
    void LCS(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> LCS_Array(len1 + 1, vector<int>(len2 + 1));

        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
                if (i == 0 || j == 0)
                {
                    LCS_Array[i][j] = 0;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    LCS_Array[i][j] = LCS_Array[i - 1][j - 1] + 1;
                }
                else
                {
                    LCS_Array[i][j] = Max(LCS_Array[i - 1][j], LCS_Array[i][j - 1]);
                }
            }
        }

        PrintTwoDimensionalArray(LCS_Array);
    }

    void LIS(vector<int> inputArray)
    {
        int size = inputArray.size();
        vector<int> LIS_Array(size, 1);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((inputArray[i] > inputArray[j]) && (LIS_Array[i] < LIS_Array[j] + 1))
                {
                    LIS_Array[i] = LIS_Array[j] + 1;
                }
            }
        }

        PrintArray(LIS_Array);
    }
};
