#include <stdio.h>
#include <iostream>
#include <cstdlib> 
#include <math.h> 
using namespace std;

int main() 
{ 
    float X, Y;
    printf ("Enter X \n");
    scanf ("%f", &X);
    printf ("X=%f \n", X);
    Y=pow(X, (4+3*M_PI)/4)-3*pow(X,3)-pow(pow(X+1,4)+(log10(X/(X+1))), 1/5);
    printf ("Y=%f \n", Y);
    system("pause"); 
    return 0; 
}
