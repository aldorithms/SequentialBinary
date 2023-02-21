/* SequentialBinarySearch.cpp
Date: 10-05-2018
Project 1 Part 2 (3.2 on page 91)
Q: Implement sequential search and binary search algorithms on your computer.
Run timings for each algorithm on arrays of size n = 10^i for i ranging from
1 to as large a value as your computer’s memory and compiler will allow.
For both algorithms, store the values 0 through n − 1 in order in the array,
and use a variety of random search values in the range 0 to n − 1 on each size n.
Graph the resulting times. When is sequential search faster than binary search for a sorted array?
*/

#include <iostream>
#include <ctime>		//Required for random
#include <time.h>		//Required for time, clock and clock tick
#include <windows.h>	//Required for sleep function

using namespace std;

void sequentialSearch(int dynamicArray[], int numberOfElements, int key)
{
	int i, start, end;
	start = clock();
	Sleep(100);
	for (i = 0; i < numberOfElements; i++)
	{
		//Try to match key with every element
		if (key == dynamicArray[i])
		{
			cout << "Found element key at index " << i << endl;
			break;
		}
	}
	//Either loop finds the key or it hits the break
	if (i == numberOfElements)
		cout << "The element key " << key << " is not present" << endl << endl;
	end = clock();
	cout << "\nSEQUENTIAL SEARCH algorithm took " << (float)(end - start) / (CLOCKS_PER_SEC) << " seconds to run\n\n";
}

void binarySearch(int dynamicArray[], int numberOfElements, int key)
{
	int i, start, end;
	start = clock();
	Sleep(100);
	int leftSide = -1;
	int rightSide = numberOfElements;			//Left side and right side are beyond the array bounds
	while (leftSide + 1 != rightSide)			//Stop when left and right meet
	{
		i = (leftSide + rightSide) / 2;
		if (key < dynamicArray[i])
			rightSide = i;											//In left half
		if (key == dynamicArray[i])
			cout << "Found element key at index " << i << endl;		//Found it
		if (key > dynamicArray[i])
			leftSide = i;											//In right half
	}
	if (key != dynamicArray[i])
		cout << "The element key " << key << " is not present" << endl << endl;
	end = clock();
	cout << "\nBINARY SEARCH algorithm took " << (float)(end - start) / (CLOCKS_PER_SEC) << " seconds to run\n\n";
}

void bubbleSort(int dynamicArray[], int numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		for (int j = i + 1; j < numberOfElements; j++)
		{
			int temp;
			if (dynamicArray[i] > dynamicArray[j])
			{
				temp = dynamicArray[i];
				dynamicArray[i] = dynamicArray[j];
				dynamicArray[j] = temp;
			}
		}
	}
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << "Index " << i << ": " << dynamicArray[i] << endl;
	}
}

int main()
{
	srand(time(NULL));
	//Setting array point to be used on heap instead of stack

	int capacity = 0;
	int numberOfElements = 0;
	int *dynamicArray = new int[capacity];

	//Initialize array just to be safe
	for (int i = 0; i < capacity; i++)
	{
		dynamicArray[i] = 0;
	}

	//Place random numbers in array
	while (numberOfElements < capacity)
	{
		dynamicArray[numberOfElements++] = 0;
	}

	for (int i = 0; i < numberOfElements; i++)
	{
		cout << i << ": " << dynamicArray[i] << endl;
	}

	//Expansion of array
	cout << "How many elements do you want to have in the array? ";
	cin >> capacity;
	int *tempDynamicArray = new int[capacity];		//Allocation
	for (int i = 0; i < numberOfElements; i++)
	{
		//Will copy all the data
		tempDynamicArray[i] = dynamicArray[i];
	}

	//Delete old data so there will not be a memory leak
	delete[] dynamicArray;							//Deallocation
	dynamicArray = tempDynamicArray;
	//Expansion end

	while (numberOfElements < capacity)
	{
		dynamicArray[numberOfElements++] = rand() % 10000;
	}

	cout << "\nPlease select the search algorithm" << endl;
	cout << "1. Sequential Search" << endl;
	cout << "2. Binary Search" << endl << endl;

	int choice;
	cin >> choice;
	cout << endl;

	if (choice == 1)
	{
		for (int i = 0; i < numberOfElements; i++)
		{
			cout << "Index " << i << ": " << dynamicArray[i] << endl;
		}
	}
	else
	{
		for (int i = 0; i < numberOfElements; i++)
		{
			cout << "Index " << i << ": " << dynamicArray[i] << endl;
		}
		cout << "\nSorting...\n" << endl;
		bubbleSort(dynamicArray, numberOfElements);
	}

	//Input the key to find
	int key;
	cout << "\nPlease enter the element key to find in the array: ";
	cin >> key;

	if (choice == 1)
	{
		//Call linear/sequential search - Search through entire array
		sequentialSearch(dynamicArray, numberOfElements, key);
	}
	else
		//Call binary search - Search through entire array after it has been sorted
		binarySearch(dynamicArray, numberOfElements, key);

	system("PAUSE");

	return 0;
}
