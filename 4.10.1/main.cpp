#include <iostream>
using namespace std ;

int Fib(int m)
{
   int value = 0;
   if (m<1) return 0;
   if (m==1) return 1;
   return Fib(m-1) + Fib(m - 2);
}

int main ()
{
  int m ;
   cout <<"Enter m=";
   cin >> m;	
  if (m<0) cout << "End.";
  else
  while (m!=0)
  { 
   cout << Fib(m) << endl;
   cout <<"Enter new m=";
   cin >> m;
  }
return 0;
}

