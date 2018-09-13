#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <vector>
#include "sort.h"

using namespace std;

//menu
void usage() 
{
  cout << "Usage: project2 [option]" << endl;
  cout << endl;
  cout << "  Options: " << endl;
  cout << "  1.  -s  performs shell sort on input array then displays results"     << endl;
  cout << "  2.  -i  performs insertion sort on input array then displays results" << endl;
  cout << "  3.  -l  performs quick sort on input array, using the last element"   << endl;
  cout << "          as the pivot, then displays result"                         << endl;
  cout << "  4.  -m  performs quick sort on input array, using the median of"      << endl;
  cout << "          the first, middle and last elements as the pivot, then"     << endl; 
  cout << "          displays results"                                           << endl;

exit(EXIT_FAILURE);
}

int main(int argc, char** argv) 
{
	vector<int> data;
	

for (int temp = 1000; temp <= 10000; temp += 100) 
{
        vector<int> data;
        
		//same number array for testing
		for(int i=0; i<temp; i++)
		{
			int j = 100;
			data.push_back(j);
		}
		
		
        /*random number array for testing
         int input = rand()%(temp+1);
         for (int i = 0; i < temp; i++) 
		 {
           	 data.push_back(rand()%(temp+1));
         }*/
        
        /*reverse sorted number array for testing
       	for (int i = temp; i > 0; i--) 
		{
			 data.push_back(temp);
		}*/
        
        /*sorted number array for testing
        for (int i = 0; i < temp; i++) 
		{
 	     	data.push_back(temp);
 	    }*/
		
	Sort s;
	//controls input trigger for function/sort type
	if (argc == 2) 
	{
		string option = argv[1];
		if (option == "-s") 
		{
			s.shell_sort(data);
		} 
		else if (option == "-i") 
		{	
			s.insertion_sort(data);
		} 
		else if (option == "-l") 
		{	
			s.quick_sort_l(data, 0, data.size()-1);
		} 
		else if (option == "-m") 
		{	
			s.quick_sort_m(data, 0, data.size()-1);
		}
	}
	else 
	{	
		s.quick_sort_f(data, 0, data.size()-1);
	}
	//outputs to file or screen
	cout<<temp<<"  "<<s.comparisons<<endl;
}
 return EXIT_SUCCESS;
}