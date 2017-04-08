/* 
Chapter 2 (String) Example Code: Program "Greetings"
Author:  Claudia Falcon
Email: cfalcon@math.ucla.edu
Course: PIC 10A Section 5 Fall 2016
Collaborators: PIC10A Section5 Students present on 10/05/2016.


Honesty Pledge: 
I, Claudia Falcon, pledge that this is my independent work and abide by the guidelines of honesty 
outlined in the syllabus. 

*/ 

#include <iostream>
#include <iomanip> 
#include <string> 


using namespace std;

int main(){
    int string_length; 
    string welcome, greeting, shortgreeting, longgreeting, course;

    greeting = "Hello Class!!";
    welcome = "Welcome to PIC 10A"; 

    // Output a short greeting an a long greeting

    shortgreeting = greeting.substr(0,5)+ "."; 
    longgreeting = greeting +" " + welcome + "."; 

    cout <<endl<<endl;
    cout <<setw(35)<< "First day greeting : "<<longgreeting <<endl;
    cout <<setw(35)<<"Short way of greeting : " << shortgreeting<<endl;

    //Obtain the course title 

    string_length= welcome.length(); 
    course = welcome.substr( string_length - 7 );

    cout <<setw(35)<< "Course : " << course<<endl;
    cout <<endl<<endl;


    //Changing String Characters
    greeting[4] = greeting[8];
    cout <<setw(30)<< greeting<<endl<<endl; 

    return 0;
}