#include <iostream>
using namespace std;

int main ( )
{
     float X, Y;
     cout << "Enter value X= "; 
	 cin >> X;
     if (X<-3) Y=3;
     else if (X>=-3) Y=4;
     cout <<"The value of the function Y= " << Y << endl;
     return 0 ;
}

