#include <iostream>
using namespace std;

int main ( )
{
     float a, b, x;
     cout << "Enter value a="; 
	 cin >> a;
     cout << "Enter value b="; 
     cin >> b;
     if (a==0 && b==0)
	   cout <<"It coincides with the X axis." << endl;
	 else if (a==0)
	        cout <<"It does not cross the X axis." << endl;
	      else if (b==0)
	             cout <<"Intersects the X axis at Y=0 \t X=0." << endl;
	           else cout <<"Intersects the X axis at Y=0 \t X=" << -b/a << endl;
     return 0 ;
}
