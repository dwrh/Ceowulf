/* 

Chapter 2 Example Code: Program "Compute Average"
Author:  Claudia Falcon
Email: cfalcon@math.ucla.edu
Course: PIC 10A Section 5 Fall 2016
Collaborators: PIC10A Section5 Students present on 10/14/2016.


Honesty Pledge: 
I, Claudia Falcon, pledge that this is my independent work and abide by the guidelines of honesty 
outlined in the syllabus. 

User inputs: temperatures inputs and Q for quit 
Output: Average of temperatures

List of known bugs: none
*/ 

#include <iostream>

using namespace std; 


int main () {
double tempsum = 0; 
double inputtemp; 
int days = 0; 
bool condition = true; 


while (condition )
{
    cout << "Enter temp value, and Q to finish: ";
    cin>> inputtemp; 

    if (cin.fail())
    condition = false;
    else 
    {tempsum = tempsum + inputtemp; 
    days++;
    }

}
if (days > 0 )
cout << " Average: " << tempsum/days <<endl;
cout<< endl;

return 0;
}