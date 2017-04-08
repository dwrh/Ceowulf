/* 

Chapter 2 Example Code: Program "Compute Average"
Author:  Claudia Falcon
Email: cfalcon@math.ucla.edu
Course: PIC 10A Section 5 Fall 2016
Collaborators: PIC10A Section5 Students present on 09/30/2016.


Honesty Pledge: 
I, Claudia Falcon, pledge that this is my independent work and abide by the guidelines of honesty 
outlined in the syllabus. 

User inputs: 3 temperatures temp1, temp2, temp3
Output: average temperature from 3 days. 

List of known bugs: none
*/ 

#include <iostream>

using namespace std; 

int main () {
double temp1,temp2,temp3; //temperature values from three different days in °F . 
const int DAYS = 3;  //number of days.  
double temperature_average; //average temperature from three days in °F

cout<< endl;
cout<< "Write the temperature of the first day in °F = ";
cin >> temp1;
cout<< endl;


cout<< "Write the temperature of the second day in °F = ";
cin >> temp2;
cout<< endl;


cout<< "Write the temperature of the third day in °F = ";
cin >> temp3;
cout<< endl;

temperature_average = (temp1+temp2 +temp3)/DAYS;
cout << "The average temperature is = " << temperature_average << " °F "<<endl;
cout<< endl;

return 0;
}