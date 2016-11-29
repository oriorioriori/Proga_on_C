#include <iostream>
using namespace std;

int main ( )
{
     float X, Y;
     cout << "Enter value X="; 
	 cin >> X ;
     cout << "Enter value Y="; 
     cin >> Y ;
     if ((Y>=3-X && Y<=5-X && Y>=X-1 && Y<=1+X) || (Y<=-3-X && Y>=-5-X && Y>=X-1 && Y<=1+X))
	   cout <<"Belongs." << endl;
     else cout <<"Do not belong." << endl;
     return 0 ;
}

