
#include "BoolVector.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum Errors_and_Exceprions
{
    errorLenghtLessZero = 1,
    errorRangeIndexOutBooleanVector,
    errorShiftLenghtLessZero,
};

int main() {
    int n;
    cin >> n;
    BoolVector bv1 = BoolVector(n);
    cin >> bv1;
    cout << bv1;
    return 0;

    


}