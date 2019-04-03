//Include libraries
#include "pch.h"
#include <string>
#include <cmath>
#include <iostream>
#include <memory>
#include <iomanip>
using namespace std;

//Prototypes
void bubblesort(string *, double *, int);
void swap_string(string &, string &);
void swap_double(double &, double &);
double average(double *, int);

//Main Function
int main() 
{
	//Get the amount of scores from the user
   int size, number = 5;
   cout << "How many test scores will you enter? ";
   cin >> size;

   //Declare and Inicialice pointers
   double *ptr = new double[size];
   string *stptr = new string[size];

   // Get values to the array LAST_NAME and SCORES.
   for (int index = 0; index < size; index++)
   {
	  cout << endl << "Enter the student " << (index + 1) << "'s last name: ";
	  cin >> stptr[index];
	  cout << "Enter the student's test score: ";
      cin >> ptr[index];

	  //Loop invalid input
	  while (ptr[index] < 0){
		  cout << endl << "*****You enter an invalid number*****\n" << endl << "Enter the student's test score: ";
		  cin >> ptr[index];
	  }
   }
   //Call bubblesort function and send the arrays and 
   bubblesort(stptr, ptr, size);

   // Display the values in the array.
   cout << endl <<  "The test scores in ascending order, and their average are:\n\n";
   cout << endl << "Name\t\tScore" << endl;
   cout << "************************************************" << endl;
   for (int index = 0; index < size; index++) {
	   cout << stptr[index] << "\t\t";
	   cout << fixed << showpoint << setprecision(2);
	   cout << ptr[index] << endl;
   }
	
   //Display average
   cout << " Average score : " << average(ptr, size);

   //Delete and free memory space
   delete[] ptr;
   delete[] stptr;
   //Assign pointer to null
   ptr = nullptr;
   stptr = nullptr;

   return 0;
}
// Sort arrays
void bubblesort(string *stptr, double *dbptr, int number)
{
	int maxElement;
	int index;

	for (maxElement = number - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (dbptr[index] > dbptr[index + 1])
			{
				swap_string(stptr[index], stptr[index + 1]);
				swap_double(dbptr[index], dbptr[index + 1]);
			}
		}
	}
}

void swap_double(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
}

void swap_string(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

// Calculate average
double average(double *scores, int sec_counter)
{
	int counter = 1;
	double total = 0;
	double average;
	while (counter < sec_counter)
	{
		total += scores[counter];
		counter++;
	}

	average = total / (sec_counter - 1);
	return average;


}