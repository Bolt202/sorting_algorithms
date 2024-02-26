#include "sort.h"

void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("\n[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid, k = 0; i < mid || j < back; k++)
	{
		if (i < mid && j < back)
		{
			if (subarr[i] <= subarr[j])
				buff[k] = subarr[i++];
			else
				buff[k] = subarr[j++];
		}
		else if (i < mid)
		{
			buff[k] = subarr[i++];
		}
		else
		{
			buff[k] = subarr[j++];
		}
	}

	printf("[Done]: ");
	print_array(buff + front, back - front);
}

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}

int main(void)
{
	int array[] = {5, 3, 8, 4, 2};
	size_t size = sizeof(array) / sizeof(array[0]);

	merge_sort(array, size);

	printf("Sorted array: ");
	print_array(array, size);

	return (0);
}
