#include <iostream>
using namespace std;

void get_arrays(float* arr1, float* arr2, int n);
void print_arrays(float* arr1, float *arr2, int n);
void swap(float* arr1, float* arr2, int n);

int main()
{
	int n;
	cout << "Enter n: "; 
	cin >> n;

	srand((unsigned int)time(0));

	// memory for arrays
	float* arr1 = new float[n];
	float* arr2 = new float[n]; 

	// generate and print arrays
	get_arrays(arr1, arr2, n);
	print_arrays(arr1, arr2, n);

	// process arrays
	swap(arr1, arr2, n);
	// print result 
	print_arrays(arr1, arr2, n);

	// clean memory
	delete[] arr1;
	delete[] arr2;
	system("pause");
}

void get_arrays(float* arr1, float* arr2, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr1[i] = rand() % 1000 / (float)100 - 5;
		arr2[i] = rand() % 1000 / (float)100 - 5;
	}
}

void print_arrays(float* arr1, float *arr2, int n)
{
	cout << "arr = { ";
	for (int i = 0; i < n; i++)
			printf("%6.2f", arr1[i]);
	cout << "    }" << endl;

	cout << "arr = { ";
	for (int i = 0; i < n; i++)
		printf("%6.2f", arr2[i]);
	cout << "    }" << endl;
	
}

void swap(float *arr1, float* arr2, int n)
{
	float max = arr1[0];
	float min = arr2[0];
	int ptr1 = 0, ptr2 = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr1[i] > max)
		{
			max = arr1[i];
			ptr1 = i;
		}
		if (arr2[i] < min)
		{
			min = arr2[i];
			ptr2 = i;
		}
	}
	// swap on z
	arr1[ptr1] = (abs(max + min)) / 2;
	arr2[ptr2] = arr1[ptr1];

	printf("\nmax = %5.2f\nmin = %5.2f\nz = %7.2f\n\n", max, min, arr1[ptr1]);
}
