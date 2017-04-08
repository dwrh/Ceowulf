#include <iostream>
#include <string>

using namespace std;

int main()
{
    string marital_status;
    
    double income, tax;

// single categories 
    const double SINGLE_LEVEL1= 21450;
    const double SINGLE_LEVEL2 = 51900;

    const double SINGLE_TAX1 = 3217.50;
    const double SINGLE_TAX2 = 11743.50;

// married categories 
    const double MARRIED_LEVEL1= 35800;
    const double MARRIED_LEVEL2 = 86500;

    const double MARRIED_TAX1 = 5370;
    const double MARRIED_TAX2 = 19566;

//tax rates
    const double RATE1=0.15;
    const double RATE2= 0.28;
    const double RATE3 = 0.31;

    cout<< "Please enter income: "; 
    cin >>income;

    cout << "Please enter s for single, m for married: ";
    cin >>marital_status;

    if (marital_status == "s") // if status is single 
    {
        if (income <= SINGLE_LEVEL1)
        tax = RATE1*income;
        else if (income <= SINGLE_LEVEL2)
        tax = SINGLE_TAX1 + RATE2*(income - SINGLE_LEVEL1);
        else 
        tax = SINGLE_TAX2 + RATE3*(income-SINGLE_LEVEL2);
    }
    else //if status is married 
    {
        if (income <=MARRIED_LEVEL1)
        tax = RATE1*income; 
        else if (income <=MARRIED_LEVEL2)
        tax = MARRIED_TAX1 +RATE2*(income - MARRIED_LEVEL1);
        else
        tax = MARRIED_TAX2+ RATE3*(income - MARRIED_LEVEL2);
    }
    //outputs the total tax to pay
    cout <<"The tax is $" <<tax <<endl;
    return 0;
}