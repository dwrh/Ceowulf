#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std; 

int main() 
{
 
double r = sqrt(2); 
if (r*r - 2 < 10e-14) 
//if (r*r == 2)
{ 
    cout <<"I knew it! r^2 = 2 \n"; 
}
else 
{
    //cout<<"Nope, r^2 =" << r*r <<endl;
    cout<<fixed<<setprecision(16)<<"Nope, r^2 = " <<r*r<<endl;
}
   return 0;
}