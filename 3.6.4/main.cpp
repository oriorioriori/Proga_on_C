#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main ( )
{
     float a, h, x, y;
     cout << "Enter the border |a|="; 
	 cin >> a;
     cout << "Enter the increment value h="; 
     cin >> h;
     x=-a;
     if (abs(a)>1)
     	cout <<"Error. Type |a| <= 1." << endl;
    else
     while (x<a+h && x>=-a)
     {
     	y=2*sin (x);
     	cout << "X=" << x << "\t Y=" << y <<endl; 
     	x=x+h;
	 }
     return 0 ;
}
