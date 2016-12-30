// CPP_Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HeapSort.cpp"
#include "KthLargestUsingMinHeap.cpp"
#include "BinaryTree.cpp"
#include "LinkedList.cpp"
#include "Miscellaneous.cpp"
#include "BackTracking.cpp"
#include "SetOne.cpp"
#include "BitMagic.cpp"
#include "QuickSort.cpp"
#include<iostream>
#include<map>
#include<deque>
#include<queue>

using namespace std;

int main()
{
    /*
    cout << "Hello";
    string str;
    std::map<int, int> my_map;
    //*/
    /*
    queue<int> q_int;
    map<int, int> my_map;
    cout << "Hello" << endl;
    my_map.insert(pair<int, int>(3, 9));
    my_map[7] = 49;
    cout << my_map.find(7)->second << endl;
    cout << my_map.find(3)->second << endl;
    //*/

    BackTracking utils;
    utils.GenerateParenthesis(3);
    cout << "---" << endl;
    utils.GenerateParenthesis(2);
    cout << "---" << endl;
    utils.GenerateParenthesis(1);
    cout << "---" << endl;
    utils.GenerateParenthesis(4);
    cout << "---" << endl;

    /*
    // https://leetcode.com/problems/add-two-numbers-ii/
    LinkedListUtils utils;
    LinkedList* num1;
    LinkedList* num2;
    LinkedList* result;

    num1 = utils.GetLinkedList(456);
    num2 = utils.GetLinkedList(15);
    result = utils.AddNumbers(num1, num2);
    utils.PrintLinkedListNumber(result);

    num1 = utils.GetLinkedList(7);
    num2 = utils.GetLinkedList(105);
    result = utils.AddNumbers(num1, num2);
    utils.PrintLinkedListNumber(result);

    num1 = utils.GetLinkedList(999);
    num2 = utils.GetLinkedList(1);
    result = utils.AddNumbers(num1, num2);
    utils.PrintLinkedListNumber(result);

    num1 = utils.GetLinkedList(456);
    num2 = utils.GetLinkedList(996);
    result = utils.AddNumbers(num1, num2);
    utils.PrintLinkedListNumber(result);

    num1 = utils.GetLinkedList(46);
    num2 = utils.GetLinkedList(195);
    result = utils.AddNumbers(num1, num2);
    utils.PrintLinkedListNumber(result);
    //*/

    /*
    AlgorithmUtils utils;
    vector<int> input;
    input.push_back(0);
    input.push_back(2);
    input.push_back(3);
    input.push_back(1);
    input.push_back(4);
    input.push_back(7);
    input.push_back(5);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(2);
    input.push_back(3);
    input.push_back(0);
    input.push_back(5);
    input.push_back(4);
    input.push_back(6);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(0);
    input.push_back(1);
    input.push_back(4);
    input.push_back(2);
    input.push_back(5);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(0);
    input.push_back(6);
    input.push_back(1);
    input.push_back(3);
    input.push_back(4);
    input.push_back(2);
    input.push_back(5);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(1);
    input.push_back(4);
    input.push_back(2);
    input.push_back(3);
    input.push_back(6);
    input.push_back(5);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(1);
    input.push_back(2);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(2);
    input.push_back(0);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(0);
    input.push_back(1);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(1);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();

    input.push_back(0);
    cout << "Missing element = " << utils.MissingNumber(input);
    cout << endl;
    input.clear();
    //*/

    /*
    AlgorithmUtils utils;
    cout << "n=0 -> " << utils.CountNumbersWithUniqueDigits(0) << endl;
    cout << "n=1 -> " << utils.CountNumbersWithUniqueDigits(1) << endl;
    cout << "n=2 -> " << utils.CountNumbersWithUniqueDigits(2) << endl;
    cout << "n=3 -> " << utils.CountNumbersWithUniqueDigits(3) << endl;
    cout << "n=4 -> " << utils.CountNumbersWithUniqueDigits(4) << endl;
    cout << "n=5 -> " << utils.CountNumbersWithUniqueDigits(5) << endl;
    cout << "n=6 -> " << utils.CountNumbersWithUniqueDigits(6) << endl;
    cout << "n=7 -> " << utils.CountNumbersWithUniqueDigits(7) << endl;
    cout << "n=8 -> " << utils.CountNumbersWithUniqueDigits(8) << endl;
    cout << "n=9 -> " << utils.CountNumbersWithUniqueDigits(9) << endl;
    cout << "n=10 -> " << utils.CountNumbersWithUniqueDigits(10) << endl;
    cout << "n=11 -> " << utils.CountNumbersWithUniqueDigits(11) << endl;
    cout << "n=12 -> " << utils.CountNumbersWithUniqueDigits(12) << endl;
    //*/

    /*
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    AlgorithmUtils utils;
    vector<int> prices;

    prices.push_back(7);
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(3);
    prices.push_back(7);
    cout << utils.MaxProfit(prices) << endl;

    prices.clear();
    prices.push_back(7);
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(3);
    cout << utils.MaxProfit(prices) << endl;

    prices.clear();
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(3);
    cout << utils.MaxProfit(prices) << endl;

    prices.clear();
    prices.push_back(10);
    prices.push_back(3);
    prices.push_back(4);
    prices.push_back(7);
    prices.push_back(8);
    prices.push_back(5);
    cout << utils.MaxProfit(prices) << endl;

    prices.clear();
    prices.push_back(7);
    prices.push_back(8);
    prices.push_back(3);
    prices.push_back(9);
    prices.push_back(4);
    cout << utils.MaxProfit(prices) << endl;

    prices.clear();
    prices.push_back(7);
    prices.push_back(9);
    cout << utils.MaxProfit(prices) << endl;

    prices.clear();
    prices.push_back(7);
    prices.push_back(3);
    cout << utils.MaxProfit(prices) << endl;

    prices.clear();
    prices.push_back(7);
    cout << utils.MaxProfit(prices) << endl;
    //*/

    /*
    // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(7);
    input.push_back(8);
    input.push_back(11);
    input.push_back(15);
    AlgorithmUtils utils;
    vector<int> result;

    result = utils.TwoSum(input, 8);
    int size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;

    result = utils.TwoSum(input, 9);
    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;

    result = utils.TwoSum(input, 10);
    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;

    result = utils.TwoSum(input, 19);
    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;

    result = utils.TwoSum(input, 14);
    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;

    result = utils.TwoSum(input, 26);
    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;

    result = utils.TwoSum(input, 36);
    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;

    result = utils.TwoSum(input, -6);
    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl << "---" << endl;
    //*/

    /*
    // https://leetcode.com/problems/sort-characters-by-frequency/
    AlgorithmUtils utils;
    cout << utils.FrequencySort("tree") << endl;
    cout << utils.FrequencySort("ccaaa") << endl;
    cout << utils.FrequencySort("Aabb") << endl;
    cout << utils.FrequencySort("cccaaa") << endl;
    //*/

    /*
    // https://leetcode.com/problems/top-k-frequent-elements/
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    input.push_back(2);
    input.push_back(1);
    input.push_back(3);
    input.push_back(4);
    input.push_back(3);

    vector<int> result;
    AlgorithmUtils utils;
    result = utils.TopKFrequent(input, 4);

    int size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }

    cout << endl << "---" << endl;
    result = utils.TopKFrequent(input, 5);

    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }

    cout << endl << "---" << endl;
    result = utils.TopKFrequent(input, 3);

    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }

    cout << endl << "---" << endl;
    result = utils.TopKFrequent(input, 2);

    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }

    cout << endl << "---" << endl;
    result = utils.TopKFrequent(input, 1);

    size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << "\t";
    }

    cout << endl << "---" << endl;
    //*/

    /*
    // https://leetcode.com/problems/counting-bits/
    BitMagic bitMagic;
    vector<int> result = bitMagic.CountBits(16);

    int size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << i << "\t" << result[i] << endl;
    }
    //*/

    /*
    // BST to sorted DLL
    BinaryTree BT_7;
    BinaryTree BT_5;
    BinaryTree BT_9;
    BinaryTree BT_3;
    BinaryTree BT_6;
    BinaryTree BT_8;
    BT_7.data = 7;
    BT_5.data = 5;
    BT_9.data = 9;
    BT_3.data = 3;
    BT_6.data = 6;
    BT_8.data = 8;

    BT_8.left = NULL; BT_8.right = NULL;
    BT_9.left = &BT_8; BT_9.right = NULL;
    BT_3.left = NULL; BT_3.right = NULL;
    BT_6.left = NULL; BT_6.right = NULL;
    BT_5.left = &BT_3; BT_5.right = &BT_6;
    BT_7.left = &BT_5; BT_7.right = &BT_9;

    BinaryTreeUtlis utils;
    BinaryTree* root = &BT_7;
    utils.ConvertBSTToSortedDLL(root);
    //*/

    // Backtracking Algorithms
    /*
    BackTracking utils;

    vector<int> input;
    input.push_back(2);
    input.push_back(5);
    input.push_back(3);
    utils.FindSubsetSum(input, 10);

    vector<char> input;
    input.push_back('A');
    input.push_back('B');
    input.push_back('C');
    input.push_back('D');
    input.push_back('E');
    utils.PrintCombinations_WithRepetitions(input, 2);
    // utils.PrintCombinations_WithoutRepetitions(input, 2);
    //*/

    /*
    string str = "ABCD";
    utils.PrintCommaPermutations(str);
    str = "ABC";
    utils.PrintCommaPermutations(str);

    string str = "ABCD";
    utils.PrintPermutations(str);

    vector<int> inputArray;
    inputArray.push_back(3);
    inputArray.push_back(9);
    utils.PrintT9Combinations(inputArray);
    //*/

    /*
    AlgorithmUtils utils;
    utils.PrintParenthesis(3);
    //*/

    /*
    // Is BST?
    BinaryTree BT_7;
    BinaryTree BT_5;
    BinaryTree BT_9;
    BinaryTree BT_3;
    BinaryTree BT_6;
    BinaryTree BT_8;
    BT_7.data = 7;
    BT_5.data = 5;
    BT_9.data = 9;
    BT_3.data = 3;
    BT_6.data = 6;
    BT_8.data = 8;

    BT_8.left = NULL; BT_8.right = NULL;
    BT_9.left = &BT_8; BT_9.right = NULL;
    BT_3.left = NULL; BT_3.right = NULL;
    BT_6.left = NULL; BT_6.right = NULL;
    BT_5.left = &BT_3; BT_5.right = &BT_6;
    BT_7.left = &BT_5; BT_7.right = &BT_9;

    BinaryTreeUtlis utils;
    BinaryTree* root = &BT_7;
    utils.PrintInOrder(root);
    cout << endl << "Is BST = " << utils.isBST(root) << endl;
    //*/

    /*
    // BitMagic
    BitMagic bitMagic;

    cout << bitMagic.AndProduct(2, 3) << "\t" << bitMagic.AndProduct_BruteForce(2, 3) << endl;
    cout << bitMagic.AndProduct(2, 5) << "\t" << bitMagic.AndProduct_BruteForce(2, 5) << endl;
    cout << bitMagic.AndProduct(12, 15) << "\t" << bitMagic.AndProduct_BruteForce(12, 15) << endl;
    cout << bitMagic.AndProduct(129, 253) << "\t" << bitMagic.AndProduct_BruteForce(129, 253) << endl;
    cout << bitMagic.AndProduct(127, 129) << "\t" << bitMagic.AndProduct_BruteForce(127, 129) << endl;
    cout << bitMagic.AndProduct(15, 17) << "\t" << bitMagic.AndProduct_BruteForce(15, 17) << endl;
    cout << bitMagic.AndProduct(13, 15) << "\t" << bitMagic.AndProduct_BruteForce(13, 15) << endl;
    cout << bitMagic.AndProduct(513, 1023) << "\t" << bitMagic.AndProduct_BruteForce(513, 1023) << endl;
    //*/

    /*
    bitMagic.CounterGame(0);
    bitMagic.CounterGame(1);
    bitMagic.CounterGame(2);
    bitMagic.CounterGame(7);
    bitMagic.CounterGame(14);
    bitMagic.CounterGame(30);
    bitMagic.CounterGame(99);
    bitMagic.CounterGame(224);
    bitMagic.CounterGame(333);
    bitMagic.CounterGame(1010);
    bitMagic.CounterGame(22000);
    //*/

    /*
    bitMagic.IsPowerOfTwo_BitSet(0);
    bitMagic.IsPowerOfTwo_BitSet(1);
    bitMagic.IsPowerOfTwo_BitSet(2);
    bitMagic.IsPowerOfTwo_BitSet(3);
    bitMagic.IsPowerOfTwo_BitSet(4);
    bitMagic.IsPowerOfTwo_BitSet(5);
    bitMagic.IsPowerOfTwo_BitSet(6);
    bitMagic.IsPowerOfTwo_BitSet(7);
    bitMagic.IsPowerOfTwo_BitSet(8);
    bitMagic.IsPowerOfTwo_BitSet(9);
    bitMagic.IsPowerOfTwo_BitSet(12);
    bitMagic.IsPowerOfTwo_BitSet(15);
    bitMagic.IsPowerOfTwo_BitSet(16);
    bitMagic.IsPowerOfTwo_BitSet(32);
    bitMagic.IsPowerOfTwo_BitSet(-1);
    bitMagic.IsPowerOfTwo_BitSet(-2);
    bitMagic.IsPowerOfTwo_BitSet(-3);
    bitMagic.IsPowerOfTwo_BitSet(-4);
    bitMagic.IsPowerOfTwo_BitSet(-7);
    bitMagic.IsPowerOfTwo_BitSet(-8);
    bitMagic.IsPowerOfTwo_BitSet(-16);
    bitMagic.IsPowerOfTwo_BitSet(-32);

    bitMagic.FlipBits(0);
    bitMagic.FlipBits(1);
    bitMagic.FlipBits(2);
    bitMagic.FlipBits(3);
    bitMagic.FlipBits(4);
    bitMagic.FlipBits(5);
    bitMagic.FlipBits(6);
    bitMagic.FlipBits(7);
    bitMagic.FlipBits(8);
    bitMagic.FlipBits(9);
    bitMagic.FlipBits(12);
    bitMagic.FlipBits(15);
    bitMagic.FlipBits(16);
    bitMagic.FlipBits(32);
    bitMagic.FlipBits(-1);
    bitMagic.FlipBits(-2);
    bitMagic.FlipBits(-3);
    bitMagic.FlipBits(-4);
    bitMagic.FlipBits(-7);
    bitMagic.FlipBits(-8);
    bitMagic.FlipBits(-16);
    bitMagic.FlipBits(-32);
    //*/

    /*
    // Dynamic Programming
    DP_SetOne utils;

    cout << "LIS" << endl;
    vector<int> LIS_input;
    LIS_input.push_back(10);
    LIS_input.push_back(9);
    LIS_input.push_back(22);
    LIS_input.push_back(21);
    LIS_input.push_back(33);
    LIS_input.push_back(25);
    LIS_input.push_back(40);
    utils.LIS(LIS_input);
    cout << endl;

    cout << "LCS" << endl;
    string s1 = "ABDMSD";
    string s2 = "ADMD";
    utils.LCS(s1, s2);
    //*/

    /*
    AlgorithmUtils utils;
    vector<int> array;
    array.push_back(3);
    array.push_back(5);
    array.push_back(2);
    array.push_back(7);
    cout << "Answer is " << utils.MaxArea(array) << endl;
    //*/

    /*
    // Search in rotated sorted array
    AlgorithmUtils utils;
    vector<int> array;
    array.push_back(6);
    array.push_back(7);
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    cout << "Index of 1 is " << utils.GetIndexOfElement(array, 1) << endl;
    cout << "Index of 2 is " << utils.GetIndexOfElement(array, 2) << endl;
    cout << "Index of 3 is " << utils.GetIndexOfElement(array, 3) << endl;
    cout << "Index of 4 is " << utils.GetIndexOfElement(array, 4) << endl;
    cout << "Index of 5 is " << utils.GetIndexOfElement(array, 5) << endl;
    cout << "Index of 6 is " << utils.GetIndexOfElement(array, 6) << endl;
    cout << "Index of 7 is " << utils.GetIndexOfElement(array, 7) << endl;
    //*/

    /*
    // Median of sorted arrays
    AlgorithmUtils utils;
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);

    vector<int> nums2;
    nums2.push_back(1);
    //nums2.push_back(1);
    nums2.push_back(2);

    vector<int> nums3;
    vector<int> nums4;
    double result = utils.FindMedianOfSortedArrays(nums1, nums2);
    cout << "Median is " << result << endl;
    //*/

    /*
    // Linked List - sorted merge
    LinkedListUtils utils;
    LinkedList LL_1;
    LinkedList LL_3;
    LinkedList LL_4;
    LL_1.data = 1;
    LL_3.data = 3;
    LL_4.data = 4;

    LL_1.next = &LL_3;
    LL_3.next = &LL_4;
    LL_4.next = NULL;

    LinkedList* head1 = &LL_1;
    utils.PrintLinkedListContents(head1);

    // Loop and intersections
    LinkedList LL_2;
    LinkedList LL_5;
    LL_2.data = 2;
    LL_5.data = 5;
    LL_2.next = &LL_5;
    LL_5.next = NULL;
    LinkedList* head2 = &LL_2;
    utils.PrintLinkedListContents(head2);

    LinkedList* result;
    result = utils.SortedMerge(head1, head2);

    utils.PrintLinkedListContents(result);
    //*/
    /*
    // Quick sort
    QuickSort qs;
    vector<int> inputArray;
    inputArray.push_back(2);
    inputArray.push_back(4);
    inputArray.push_back(5);
    inputArray.push_back(1);
    inputArray.push_back(3);

    qs.Sort(inputArray);

    vector<int> smallArray;
    smallArray.push_back(4);
    smallArray.push_back(2);

    qs.Sort(smallArray);

    vector<int> sortedArray;
    sortedArray.push_back(4);
    sortedArray.push_back(3);
    sortedArray.push_back(2);
    sortedArray.push_back(1);

    qs.Sort(sortedArray);
    //*/

    /*
    // Tree traversals
    BinaryTree BT_7;
    BinaryTree BT_5;
    BinaryTree BT_9;
    BinaryTree BT_3;
    BinaryTree BT_6;
    BinaryTree BT_8;
    BT_7.data = 7;
    BT_5.data = 5;
    BT_9.data = 9;
    BT_3.data = 3;
    BT_6.data = 6;
    BT_8.data = 8;

    BT_8.left = NULL; BT_8.right = NULL;
    BT_9.left = &BT_8; BT_9.right = NULL;
    BT_3.left = NULL; BT_3.right = NULL;
    BT_6.left = NULL; BT_6.right = NULL;
    BT_5.left = &BT_3; BT_5.right = &BT_6;
    BT_7.left = &BT_5; BT_7.right = &BT_9;

    BinaryTreeUtlis utils;
    BinaryTree* root = &BT_7;
    utils.PrintPreOrder(root);
    utils.PrintInOrder(root);
    utils.PrintPostOrder(root);
    //*/

    /*
    // NGE and Stock span problem
    vector<int> inputArray;
    inputArray.push_back(3);
    inputArray.push_back(7);
    inputArray.push_back(6);
    inputArray.push_back(4);
    inputArray.push_back(8);
    inputArray.push_back(3);
    inputArray.push_back(2);

    AlgorithmUtils utils;
    utils.NextGreaterElement(inputArray);
    utils.StockSpan(inputArray);
    //*/

    /*
    // Linked List operations
    LinkedList LL_1;
    LinkedList LL_2;
    LinkedList LL_3;
    LinkedList LL_4;
    LinkedList LL_5;
    LL_1.data = 1;
    LL_2.data = 2;
    LL_3.data = 3;
    LL_4.data = 4;
    LL_5.data = 5;

    LL_1.next = &LL_2;
    LL_2.next = &LL_3;
    LL_3.next = &LL_4;
    LL_4.next = &LL_5;
    LL_5.next = NULL;

    LinkedListUtils utils;
    LinkedList* head = &LL_1;

    // Loop and intersections
    LinkedList LL_1_dupe;
    LinkedList LL_2_dupe;
    LL_1_dupe.data = 100;
    LL_2_dupe.data = 101;
    LL_1_dupe.next = &LL_2_dupe;
    LL_2_dupe.next = &LL_1;
    LinkedList* head_dupe = &LL_1_dupe;
    LinkedList* intersection = utils.GetIntersection(head, head_dupe);
    cout << "Intersection at " << ((intersection != NULL) ? (intersection->data) : -1) << endl;
    intersection = utils.GetIntersection(head, head->next->next);
    cout << "Intersection at " << ((intersection != NULL) ? (intersection->data) : -1) << endl;
    //*/

    // Reverse linked list operations
    /*
    utils.PrintLinkedListContents(head);
    utils.ReverseLinkedList(&head);
    utils.PrintLinkedListContents(head);
    head = utils.ReverseKItemsRecursive(head, 2);
    utils.PrintLinkedListContents(head);
    head = utils.ReverseKItemsRecursive(head, 3);
    utils.PrintLinkedListContents(head);
    head = utils.ReverseKItemsRecursive(head, 4);
    utils.PrintLinkedListContents(head);
    head = utils.ReverseKItemsRecursive(head, 5);
    utils.PrintLinkedListContents(head);
    head = utils.ReverseKItemsRecursive(head, 6);
    utils.PrintLinkedListContents(head);
    //*/

    /*
    // Binary Tree - height, diameter, LCA
    BinaryTree BT_7;
    BinaryTree BT_5;
    BinaryTree BT_9;
    BinaryTree BT_3;
    BinaryTree BT_6;
    BinaryTree BT_8;
    BT_7.data = 7;
    BT_5.data = 5;
    BT_9.data = 9;
    BT_3.data = 3;
    BT_6.data = 6;
    BT_8.data = 8;

    BT_8.left = NULL; BT_8.right = NULL;
    BT_9.left = &BT_8; BT_9.right = NULL;
    BT_3.left = NULL; BT_3.right = NULL;
    BT_6.left = NULL; BT_6.right = NULL;
    BT_5.left = &BT_3; BT_5.right = &BT_6;
    BT_7.left = &BT_5; BT_7.right = &BT_9;

    BinaryTreeUtlis utils;
    cout << "Height of binary tree " << utils.Height(&BT_7) << endl;
    cout << "Diameter of binary tree " << utils.Diameter(&BT_7) << endl;

    BinaryTree* LCA = utils.LCA(&BT_7, 3, 6);
    LCA = utils.LCA(&BT_7, 3, 5);
    LCA = utils.LCA(&BT_7, 5, 6);
    LCA = utils.LCA(&BT_7, 7, 6);
    LCA = utils.LCA(&BT_7, 7, 8);
    LCA = utils.LCA(&BT_7, 7, 9);
    LCA = utils.LCA(&BT_7, 8, 9);
    LCA = utils.LCA(&BT_7, 6, 8);
    LCA = utils.LCA(&BT_7, 5, 8);
    LCA = utils.LCA(&BT_7, 6, 9);
    LCA = utils.LCA(&BT_7, 3, 9);
    //*/

    /*
    // Kth largest using Min heap
    vector<int> inputArray;
    inputArray.push_back(3);
    inputArray.push_back(5);
    inputArray.push_back(1);
    inputArray.push_back(4);
    inputArray.push_back(6);
    inputArray.push_back(7);
    inputArray.push_back(2);

    KthLargest kthLargest;
    kthLargest.FindKthLargest(1, inputArray);
    kthLargest.FindKthLargest(2, inputArray);
    kthLargest.FindKthLargest(3, inputArray);
    kthLargest.FindKthLargest(4, inputArray);
    kthLargest.FindKthLargest(5, inputArray);
    kthLargest.FindKthLargest(6, inputArray);
    kthLargest.FindKthLargest(7, inputArray);
    //*/

    /*
    // Heap Sort
    vector<int> inputArray;
    inputArray.push_back(3);
    inputArray.push_back(5);
    inputArray.push_back(1);
    inputArray.push_back(4);
    inputArray.push_back(6);
    inputArray.push_back(7);
    inputArray.push_back(2);

    HeapSortUtils utils;
    utils.HeapSort(inputArray);
    //*/

    /*
    // Min heap basic operations
    MinHeap MH;
    MH.Insert(3);
    MH.Insert(7);
    MH.Insert(2);
    MH.PrintHeapContents();
    MH.Insert(5);
    MH.Insert(8);
    MH.Insert(1);
    MH.PrintHeapContents();
    cout << "ExtractMin() returns " << MH.ExtractMin() << endl;
    cout << "ExtractMin() returns " << MH.ExtractMin() << endl;
    MH.Delete(5);
    MH.PrintHeapContents();
    //*/

    return 0;
}

