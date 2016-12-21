#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<bitset>

using namespace std;

class BitMagic
{
private:
    string GetPlayerName(int moves)
    {
        if (moves % 2 == 1)
        {
            return "Richard";
        }
        else
        {
            return "Louise";
        }
    }
public:
    bool IsPowerOfTwo_BitSet(unsigned int number)
    {
        bitset<8 * sizeof(number)> bits(number);
        cout << "Decimal - " << number << endl;
        cout << "Binary - " << bits << endl;
        cout << "Count - " << bits.count() << endl;
        cout << endl;

        return (bits.count() == 1);
    }

    bool IsPowerOfTwo(unsigned long number)
    {
        return !(number & (number - 1));
    }

    unsigned long FlipBits(unsigned long number)
    {
        bitset<8 * sizeof(number)> bits(number);
        // cout << "Decimal - " << number << endl;
        // cout << "Binary - " << bits << endl;
        bits.flip();
        // cout << "Binary - " << bits << endl;
        // cout << "Decimal - " << bits.to_ulong() << endl;
        return bits.to_ulong();
    }

    unsigned long LargestPowerOfTwoLesserThanNumber(unsigned long number)
    {
        unsigned long result = 1;

        while (result < number)
        {
            result = result << 1;
        }

        result = result >> 1;

        return result;
    }

    unsigned long SmallestPowerOfTwoGreaterThanNumber(unsigned long number)
    {
        unsigned long result = 1;

        while (result < number)
        {
            result = result << 1;
        }

        return result;
    }

    // https://www.hackerrank.com/challenges/counter-game
    void CounterGame(unsigned long number)
    {
        int moves = 0;
        cout << "Number = " << number << endl;

        while (number > 1)
        {
            cout << GetPlayerName(moves) << ": " << number;

            if (IsPowerOfTwo(number))
            {
                number = number >> 1;
            }
            else
            {
                number = number - LargestPowerOfTwoLesserThanNumber(number);
            }

            cout << " to " << number << endl;
            moves++;
        }

        cout << GetPlayerName(moves) << " lost the game" << endl;
        cout << "Total moves = " << moves << endl << endl;
    }

    // https://www.hackerrank.com/challenges/and-product
    unsigned long AndProduct(unsigned long a, unsigned long b)
    {
        unsigned long diff = SmallestPowerOfTwoGreaterThanNumber(b - a);
        diff = FlipBits(diff - 1);

        return (a & diff & b);
    }

    unsigned long AndProduct_BruteForce(unsigned long a, unsigned long b)
    {
        unsigned long result = a;
        for (unsigned long i = a + 1; i <= b; i++)
        {
            result = result & i;
        }

        return result;
    }
};
