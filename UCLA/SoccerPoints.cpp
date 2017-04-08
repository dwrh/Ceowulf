#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int points,red_goals,blue_goals, goal_diff;
    string win_team;

    cout<<endl;
    cout<< "Type number of goals for Blue team = ";
    cin>>blue_goals;

    cout<<"Type number of goals for Red team = ";
    cin>>red_goals;

    points =3;
    if (blue_goals > red_goals)
    {
	    win_team   = "Blue Team";
        goal_diff  = blue_goals - red_goals;
    }
    else if (blue_goals == red_goals)
    {
	    win_team   = "Red\\Blue Tie" ;
	    points = 1; 
    }   
    else 
    {
	    win_team   = "Red Team";
        goal_diff=red_goals-blue_goals;
    }

    cout<<endl<<endl<<endl;

    cout <<setw(25)<< "Winner : " << win_team <<endl;
    cout <<setw(25)<< "Points : " << "+"<< points << endl;
    cout <<setw(25)<< "Goal Difference : "<<"+" << goal_diff<< endl;

    cout<<endl<<endl<<endl;

    return 0; 

}