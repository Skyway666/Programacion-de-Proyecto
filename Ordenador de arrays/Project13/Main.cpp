#include <stdio.h>

 
void bubble_sort(int* arr, int array_size)
{
	int n = 0;
	int aux;
	do 
	{
		n = 0;
		for (int i = 0; i < array_size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i+1] = aux; 
				n++;
			}
		}
	} while (n != 0);
}


int main()
{

	int arr[10] = { 1,3,6,7,2,0,4,3,7,89 };
	bubble_sort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%i", arr[i]);
	}
	return 0;
}


