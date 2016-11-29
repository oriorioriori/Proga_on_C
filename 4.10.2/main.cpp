#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

unsigned long long int DecNC(unsigned long long int N, unsigned int b )
{
   unsigned long long int S, P ;
   for (S=0, P=1; N!= 0; S+=N%10*P, P*=b, N/=10) ;
   return S ;
}

unsigned long long int NC(unsigned long long int N, unsigned int b )
{
   unsigned long long int S, P ;
   for (S=0, P=1; N!= 0; S+=N%b*P, P*=10, N/=b) ;
   return S ;
}

int main ( )
{
     unsigned long long int A, B, C; 
     cout << "Enter A = "; 
	 cin >> A;  
     cout << "Enter B = "; 
	 cin >> B; 
	 A=DecNC(A, 4);
	 B=DecNC(B, 7);
	 cout << "A(4)=" << A << "(10)" << endl ;
     cout << "B(7)=" << B << "(10)" << endl ;
     C=(B*B*B-B*B+2*A);
	 cout << "C(10)=" << C << endl;
   	 cout << "C(10)= "<< NC(C, 2) << "(2)" << endl;
     return 0 ;
}
