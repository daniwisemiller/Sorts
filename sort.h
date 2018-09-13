#ifndef SORT_H
#define SORT_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sort
{
	public: 
		Sort()
		{
			comparisons = 0;
		}
		void insertion_sort(std::vector<int> &data);
		void shell_sort(std::vector<int> &data);
		void quick_sort_f(std::vector<int> &data, int low, int high);
		void quick_sort_l(std::vector<int> &data, int low, int high);
		void quick_sort_m(std::vector<int> &data, int low, int high);
		int comparisons;
		
	private:
		int partition(std::vector<int> &data, int low, int high);
		void swap(std::vector<int> &data, int a, int b);
};
#endif