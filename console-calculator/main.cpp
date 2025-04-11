#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    //Identifying a variable
    int T;

    cout << "==============================" << endl;
    cout << "Choose the type of the Operation:" << endl << "1.Basic two-operands Function" << endl << "2.Roots of a Quadratic Function" << endl;
    cout << ">> ";

    //Taking the input for the variable "T"
    cin >> T;

    cout << "==============================" << endl;

    //Checks the case of the chosen operation
    switch (T)
    {
    case 1:

        //Identifying variables
        int x; char o; int y;

        //Taking inputs of "x", "o", "y"
        cout << "Input Your Function (X, operand, Y)" << endl;
        cout << ">> ";

        cin >> x >> o >> y;

        cout << "==============================" << endl;
    
        //Checking the type of the operation
        if(o == '+')
        {
            cout << x << " + " << y << " = " << x + y << endl;
            cout << "==============================" << endl;
        }
        else if(o == '-'){
            cout << x << " - " << y << " = " << x - y << endl;
            cout << "==============================" << endl;
        }
        else if(o == '*'){
            cout << x << " × " << y << " = " << x * y << endl;
            cout << "==============================" << endl;
        }
        else if(o == '/')
        {
            //Expects a devision by zero error
            if (y == 0)
            {
                cout << "Error: Division by Zero!";
            }
            else
            {
            cout << x << " ÷ " << y << " = " << x / y << endl;
            cout << "==============================" << endl;
            }
        }

        //Not a supported operation
        else
        {
            cout << "Not a Supported Operation!" << endl;
            cout << "==============================" << endl;
        }
        break;
    
    case 2:

        //Identifying variables
        double a, b, c;

        //Taking inputs of "a", "b", "c"
        cout << "Input the Co-effecients: a, b, c (ax^2 + bx + c)" << endl;
        cout << ">> ";

        cin >> a >> b >> c;

        cout << "==============================" << endl;

        //Checking if the value the root is negative
        if (((b * b) - 4 * a * c) < 0)
        {
            cout << "No Real Roots!" << endl;
            cout << "==============================" << endl;
        }

        //If the roots exist
        else
        {
            //Calculating the roots
            double answer_1 = (-b + pow((b * b - 4 * a * c), 0.5)) / (2 * a);
            double answer_2 = (-b - pow((b * b - 4 * a * c), 0.5)) / (2 * a);

            //Outputing the results
            cout << fixed << setprecision(3);
            cout << "Answer 1: " << answer_1 << endl;
            cout << "Answer 2: " << answer_2 << endl;
            cout << "==============================" << endl;
        }
        break;

    default:
        
        cout << "Not a Valid Input!" << endl;
        cout << "==============================" << endl;
        break;
    }

    return 0;
}