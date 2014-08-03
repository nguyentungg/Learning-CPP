#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

typedef int(*Comparer)(int left, int right);

/** Returns a random integer in range [from, to) */
int Random(int from, int to);

/** Returns two random dies */
void ThrowDice(int& die1, int& die2);

/** Returns two random dies */
void ThrowDice(int* die1, int* die2);

void RandomArrayFill(int* arr, int size);

void RandomArrayFill(vector<int>& vec, int size);

void Sort(int* arr, int length, Comparer comparer);

/** Returns:
 * < 0 -> if left < right
 * 0   -> if left == right
 * > 0 -> if left > right
 */
int LessCompare(int left, int right);

/** Returns:
* < 0 -> if left > right
* 0   -> if left == right
* < 0 -> if left < right
*/
int GreatCompare(int left, int right);

void PrintArray(int* arr, int size);

void PrintVector(vector<int> vec);

int main()
{
	srand(time(0));

	// -- Exercise 1 (Random Dice) --
	cout << "-- Exercise 1 (Random Dice)--" << endl;
	int die1 = 0;
	int die2 = 0;

	ThrowDice(die1, die2);
	cout << die1 << " & " << die2 << endl;

	ThrowDice(&die1, &die2);
	cout << die1 << " & " << die2 << endl << endl;

	// -- Exercise 2 (Random Array Fill) --
	cout << "-- Exercise 2 (Random Array Fill) --" << endl;

	int arrSize = 10;
	int* arr = new int[arrSize];
	RandomArrayFill(arr, arrSize);

	PrintArray(arr, arrSize);

	vector<int> vec;
	int vecSize = 10;
	RandomArrayFill(vec, vecSize);

	PrintVector(vec);
	cout << endl;

	// -- Exercise 3 (Pointer to function) --
	cout << "-- Exercise 3 (Pointer to function) --" << endl;

	cout << "Sorted Ascending" << endl;
	Sort(arr, arrSize, &LessCompare);
	PrintArray(arr, arrSize);

	cout << "Sorted Descending" << endl;
	Sort(arr, arrSize, &GreatCompare);
	PrintArray(arr, arrSize);

	delete [] arr;
}

int Random(int from, int to)
{
	return from + rand() % (to - from);
}

void ThrowDice(int& die1, int& die2)
{
	die1 = Random(1, 7);
	die2 = Random(1, 7);
}

void ThrowDice(int* die1, int* die2)
{
	*die1 = Random(1, 7);
	*die2 = Random(1, 7);
}

void RandomArrayFill(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = Random(0, 101);
	}
}

void RandomArrayFill(vector<int>& vec, int size)
{
	for (int i = 0; i < size; i++)
	{
		vec.push_back(Random(0, 101));
	}
}

void Sort(int* arr, int length, Comparer comparer)
{
	for (int i = 0; i < length - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if ((*comparer)(arr[j], arr[minIndex]) < 0)
			{
				minIndex = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

int LessCompare(int left, int right)
{
	return left - right;
}

int GreatCompare(int left, int right)
{
	return right - left;
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void PrintVector(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	cout << endl;
}