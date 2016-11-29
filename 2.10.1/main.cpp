#include <stdio.h>
#include <iostream>
#include <cstdlib> 
using namespace std;

int main() 
{ 
    float A, B, C;
    printf ("Enter the value of the variable A and B. \n");
    scanf ("%f, %f", &A, &B);
   
    printf ("The values of the variables: A=%f \t  B=%f \n", A, B);
    C=A;
    A=B;
    B=C;
    printf ("The new values of the variables: A=%f \t  B=%f \n", A, B);
    system("pause"); 
    return 0; 
}
