// Program Name: Project 4.cpp
// Course: CSE1311/Section 001 
// Student Name: Christopher Dennis
// Assignment Number: Project #4
// Due Date: 11/28/2017
//Description: Run a program to read the name and weight of individuals, then arrange the people to fit on an elevator with a max weight capacity. Re-order the people by ascending weight, then by descending names. Print the method that allows for the most people to fit on the elevator.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Sorts the arrays in ascending sequence by weight
void selectionSort(string name[], int wt[], int size)
{
for (int i = 0; i < (size - 1); i++)
{
int max = i;
for (int j = i + 1; j < size; j++)
{
if (wt[j] < wt[max])
max = j;
}
  
if (max != i)
{
// Swap
int temp = wt[i];
wt[i] = wt[max];
wt[max] = temp;
  
string tempStr = name[i];
name[i] = name[max];
name[max] = tempStr;
}
}
}

// Sorts the arrays in descending sequence by name
void insertionSort(string name[], int wt[], int size)
{
for (int i = 1; i < size; i++)
{
string tempStr = name[i];
int temp = wt[i];
// Find an index for temp such that temp is alphabetically lower than the ones before it
int j;
for (j = i - 1; ((j >= 0) && (tempStr.compare(name[j]) > 0)); j--)
{
name[j + 1].swap(name[j]);
wt[j + 1] = wt[j];
}
  
// Swap
name[j + 1].swap(tempStr);
wt[j + 1] = temp;
}
}

// Determines how many people gets on the elevator
int getOnElevator(int wt[], int size, int &ttlWt)
{
int i = 0;
for (i = 0; i < size; i++)
{
if ((ttlWt + wt[i]) <= 1100)
ttlWt += wt[i];
else
break;
}
  
return i;
}

// Prints both the arrays
void print(string name[], int wt[], int size)
{
for (int i = 0; i < size; i++)
{
cout << setw(10) << left << name[i] << " " << wt[i] << endl;
}
}

int main()
{
string name[] = {"Anne", "Bob", "Ralph", "Tim", "Barbara", "Jane", "Steve", "Tom", "Mike", "Shirley", "Pam", "Frank"};
int wt[] = {150, 250, 305, 250, 85, 160, 180, 210, 165, 155, 125, 130};
int size = sizeof(name) / sizeof(name[0]);
  
// Print arrays
cout << "Original Order"<<endl;
print(name, wt, size);
cout << endl;
  
// Determine number of people who gets of the elevator
int ttlWt = 0;
int noOrderCnt = getOnElevator(wt, size, ttlWt);
  
// Print people who got on the elevator
cout << "People who got on the elevator" << endl;
print(name, wt, noOrderCnt);
cout << "\nTOTAL WEIGHT: " << ttlWt << endl;
cout << "The number of people who got on the elevator is " << noOrderCnt << endl;
cout << endl;
  
// Sort in ascending sequence by weight
selectionSort(name, wt, size);
  
// Print arrays
cout << "--------------------------------------------" << endl;
cout << "Arrays sorted in ascending sequence by weight" << endl;
print(name, wt, size);
cout << endl;
  
// Determine number of people who gets of the elevator
ttlWt = 0;
int descOrderCnt = getOnElevator(wt, size, ttlWt);
  
// Print people who got on the elevator
cout << "People who got on the elevator" << endl;
print(name, wt, descOrderCnt);
cout << "\nTOTAL WEIGHT: " << ttlWt << endl;
cout << "The number of people who got on the elevator is " << descOrderCnt << endl;
cout << endl;
  
// Sort in descending sequence by name
insertionSort(name, wt, size);
  
// Print arrays
cout << "--------------------------------------------" << endl;
cout << "Arrays sorted in descending sequence by name" << endl;
print(name, wt, size);
cout << endl;
  
// Determine number of people who gets on the elevator
ttlWt = 0;
int ascOrderCnt = getOnElevator(wt, size, ttlWt);
  
// Print people who got on the elevator
cout << "People who got on the elevator" << endl;
print(name, wt, ascOrderCnt);
cout << "\nTOTAL WEIGHT: " << ttlWt << endl;
cout << "The number of people who got on the elevator is " << ascOrderCnt << endl;
cout << endl;
  
// Determine which method allowed the most people to get on the elevator
int max = noOrderCnt;
if (descOrderCnt > max)
{
max = descOrderCnt;
}
if (ascOrderCnt > max)
{
max = ascOrderCnt;
}
 
cout << "--------------------------------------------" << endl;  
cout << "The method allowing the most people on the elevator is: " << endl;
if (max == noOrderCnt)
{
cout << "Original order" << endl;
}
if (max == descOrderCnt)
{
cout << "Ascending order by weight" << endl;
}
if (max == ascOrderCnt)
{
cout << "Descending order by name" << endl;
}
cout<< "\n\nCoded by Christopher Dennis" <<endl;
	system("PAUSE");
	return 0;
}

