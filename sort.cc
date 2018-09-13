#include "iostream"
#include "sort.h"
using namespace std;

//implements insertion sort
void Sort::insertion_sort(vector<int> &data)
{
	for (unsigned int i = 1; i < data.size(); i++) 
	{
		int j = i;
		//makes the swaps to order the data in array
		while (j > 0 && data[j-1] > data[j]) 
		{
			comparisons++;
			swap(data,j,j-1);
			j--;
		}
		comparisons++;//one comparison is made w/o entering the loop
	}
}
//implements shell sort
void Sort::shell_sort(std::vector<int> &data) 
{
	//get n/2 gap sequence
	int gap = data.size() / 2;
	
	while (gap > 0) 
	{
		//sort data points in array
		for (unsigned int i = 1; i < (data.size() - gap); i++) 
		{
			int j = i + gap;
			while (j >= gap && data[j] < data[j-gap]) 
			{
				comparisons++;
				swap(data,j,j-1);
				j -= gap;
			}
			comparisons++;//one comparison is made w/o entering the loop
		}
		if (gap == 2) 
		{
			gap = 1;
		} 
		else
		{
			gap /= 2;
		}
	}
}
//implements quick sort with first as pivot
void Sort::quick_sort_f(std::vector<int> &data, int low, int high) 
{
	if (low >= high) 
		return;
	
	int	pivotIndex = low; //use first element as pivot
	
	//swap pivot w/ first element in vector
	swap(data,low,pivotIndex);
	//recursive quicksort 
	int p = partition(data, low, high);
	quick_sort_f(data, low, p-1);
	quick_sort_f(data, p+1, high);
	
}
//implements quicksort with last number as pivot
void Sort::quick_sort_l(std::vector<int> &data, int low, int high) 
{
	if (low >= high) 
		return;
	
	int	pivotIndex = high - 1; //use last element as pivot
	
	//swap pivot w/ first element in vector
	swap(data,low,pivotIndex);
	//recursive quicksort
	int p = partition(data, low, high);
	quick_sort_l(data, low, p-1);
	quick_sort_l(data, p+1, high);
	
}
//implements quicksort with median of first last and middle numbers as pivot
void Sort::quick_sort_m(std::vector<int> &data, int low, int high) 
{
	if (low >= high) 
		return;
	
	// Choose pivot point between all three
	int a = data[low];
	int b = data[high / 2];
	int c = data[high - 1];
	int pivot = max(min(a,b), min(max(a,b),c));
	int pivotIndex;
	if (pivot == data[low]) 
	{
		pivotIndex = low;
	} 
	else if (pivot == data[high / 2]) 
	{
		pivotIndex = (high / 2);
	} 
	else 
	{
		pivotIndex = (high - 1);
	}
	
	//swap pivot w/ first element in vector
	swap(data,low,pivotIndex);
	//recursive quicksort
	int p = partition(data, low, high);
	quick_sort_m(data, low, p-1);
	quick_sort_m(data, p+1, high);
	
}

//****************************************private functions**********************************************//
// size_t index_of_median(vector<int>& data, size_t l, size_t r) {
//
//   // I copy data into a scratch vector because nth_element
//   // modifies the provided list.
//   vector<int> scratch(data.begin() + l, data.begin() + r + 1);
//
//   size_t median = (scratch.size() - 1) / 2;
//   nth_element(scratch.begin(), scratch.begin() + median, scratch.end());
//
//   return find(data.begin() + l, data.begin() + r + 1, scratch[median]) - data.begin();
// }
int Sort::partition(std::vector<int> &data, int low, int high) 
{
   
	// start = first element, index >low & <=small are smaller, index >small <=mainIndex are larger
	int pivot = data[low];
	int small = low;
	int mainIndex = low+1;
	while(mainIndex <= high) {
		if (data[mainIndex] < pivot) 
		{
			small++;
			swap(data, small, mainIndex);
			mainIndex++;
		} 
		else 
		{
			mainIndex++;
		}
		comparisons++;
	}
	
	swap(data, small, low);
	
	return small;
}
//swaps values
void Sort::swap(vector<int> &data, int a, int b)
{
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}
