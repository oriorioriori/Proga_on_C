#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main ( )
{
     int N, S, i;
     cout << "Enter N="; 
	 cin >> N;
     S=0;
     i=2;
     while (i<=N)
     {
     	S=S+i*i;
     	i=i+2;
	 }
	 cout << "Sum=" << S << endl;
     return 0 ;
}
