#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<queue>

using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList* next;
};

class LinkedListUtils
{
private:
    LinkedList* SortedMergeInternal(LinkedList* head1, LinkedList* head2)
    {
        if (head1 == NULL)
        {
            return head2;
        }

        if (head2 == NULL)
        {
            return head1;
        }

        if (head1->data < head2->data)
        {
            head1->next = SortedMergeInternal(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = SortedMergeInternal(head1, head2->next);
            return head2;
        }

        /*
        LinkedList result;
        LinkedList* resultPointer = &result;

        if (head1->data < head2->data)
        {
            resultPointer->data = head1->data;
            resultPointer->next = SortedMergeInternal(head1->next, head2);
        }
        else
        {
            resultPointer->data = head2->data;
            resultPointer->next = SortedMergeInternal(head1, head2->next);
        }

        return resultPointer;
        //*/
    }

    LinkedList GetLinkedListNode(int data, LinkedList* next)
    {
        LinkedList node;
        node.data = data;
        node.next = next;

        return node;
    }

    int AddNumbersInternal(LinkedList* n1, LinkedList* n2, LinkedList** result, int& sum, int& carry)
    {
        if (n1 == NULL)
        {
            return 0;
        }

        AddNumbersInternal(n1->next, n2->next, result, sum, carry);

        sum = n1->data + n2->data + carry;
        carry = sum / 10;
        sum = sum % 10;

        LinkedList* node = new LinkedList();
        node->data = sum;
        node->next = (*result);
        (*result) = node;

        return carry;
    }
public:
    void ReverseLinkedList(LinkedList** head)
    {
        LinkedList* headPointer = *head;
        LinkedList* current = headPointer;
        LinkedList* next = current->next;

        while (current != NULL && next != NULL)
        {
            current->next = next->next;
            next->next = headPointer;
            headPointer = next;

            next = current->next;
        }

        *head = headPointer;
    }

    LinkedList* ReverseKItemsRecursive(LinkedList* head, int k)
    {
        LinkedList* headPointer = head;
        LinkedList* current = headPointer;
        LinkedList* next = current->next;

        int i = k;
        while (i != 1 && next != NULL)
        {
            current->next = next->next;
            next->next = headPointer;
            headPointer = next;
            next = current->next;

            i--;
        }

        if (next != NULL)
        {
            current->next = ReverseKItemsRecursive(next, k);
        }

        return headPointer;
    }

    int GetLength(LinkedList* head)
    {
        int i = 0;
        LinkedList* ptr = head;

        while (ptr != NULL)
        {
            i++;
            ptr = ptr->next;
        }

        return i;
    }

    LinkedList* GetIntersection(LinkedList* h1, LinkedList* h2)
    {
        int l1, l2, diff;
        l1 = GetLength(h1);
        l2 = GetLength(h2);
        diff = l1 - l2;

        LinkedList* ptr1 = h1;
        LinkedList* ptr2 = h2;

        if (diff >= 0)
        {
            for (int i = 0; i < diff; i++)
            {
                ptr1 = ptr1->next;
            }
        }
        else
        {
            diff = -diff;
            for (int i = 0; i < diff; i++)
            {
                ptr2 = ptr2->next;
            }
        }

        while (ptr1 != NULL && ptr2 != NULL && ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }

    LinkedList* SortedMerge(LinkedList* head1, LinkedList* head2)
    {
        LinkedList* result = SortedMergeInternal(head1, head2);
        return result;
    }

    bool IsLoopPresent(LinkedList* head)
    {
        LinkedList* slow = head;
        LinkedList* fast = slow->next;

        while (slow != NULL && fast != NULL && fast->next != NULL && slow != fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow == fast;
    }

    // https://leetcode.com/problems/add-two-numbers-ii/
    LinkedList* AddNumbers(LinkedList* n1, LinkedList* n2)
    {
        int len1 = GetLength(n1);
        int len2 = GetLength(n2);

        if (len1 > len2)
        {
            int diff = len1 - len2;
            for (int i = 0; i < diff; i++)
            {
                LinkedList* node = new LinkedList();
                node->data = 0;
                node->next = n2;
                n2 = node;
            }
        }
        else if (len2 > len1)
        {
            int diff = len2 - len1;
            for (int i = 0; i < diff; i++)
            {
                LinkedList* node = new LinkedList();
                node->data = 0;
                node->next = n1;
                n1 = node;
            }
        }

        int sum = 0;
        int carry = 0;
        LinkedList* result = NULL;
        carry = AddNumbersInternal(n1, n2, &result, sum, carry);

        if (carry > 0)
        {
            LinkedList* node = new LinkedList();
            node->data = carry;
            node->next = result;
            result = node;
        }

        return result;
    }

    LinkedList* GetLinkedList(int number)
    {
        LinkedList* head = NULL;

        while (number != 0)
        {
            LinkedList* node = new LinkedList();
            node->data = number % 10;
            node->next = head;
            head = node;

            number = number / 10;
        }

        return head;
    }

    void PrintLinkedListNumber(LinkedList* head)
    {
        LinkedList* current = head;
        cout << "LinkedList number = ";
        while (current != NULL)
        {
            cout << current->data;
            current = current->next;
        }

        cout << endl;
    }

    void PrintLinkedListContents(LinkedList* head)
    {
        LinkedList* current = head;
        cout << "LinkedList contents" << endl;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};
