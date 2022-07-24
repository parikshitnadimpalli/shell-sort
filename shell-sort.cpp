#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
void shellSort(int[], int);
void displayArray(int[], int);

int main()
{
	int size, * arr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter " << size << " numbers: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
	}

	shellSort(arr, size);
	displayArray(arr, size);

	return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

void shellSort(int arr[], int size)
{
	for (int gap = (size - 1) / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i += 1)
		{
			int temp = arr[i];
			int j = 0;

			for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap) // Here at the first iteration, j is set equal to the gap. The condition arr[j-gap]>temp checks whether the value separated by the "gap" before element at gap is greater or not. The decrement is done to keep checking the list in "gap" intervals till the first element is reached
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;	// Completing the swapping of values
		}
	}
}

void displayArray(int arr[], int size)
{
	cout << endl << "The sorted array is: ";

	for (int i = 0; i < size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}