#include <iostream>
using namespace std;

int main() 
{ 
    int A, S;
    cout <<"Enter the three-digit number:" << endl;
    cin >> A;
    S= A/100 + A/10%10 + A%10;
    cout <<"The sum of digits=" << S << endl;
    return (0);
}
