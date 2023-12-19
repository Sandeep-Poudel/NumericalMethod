#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//?====================================================================================
//* Fucntion value
float function(float value)
{
    float result = pow(value, 3) + 2 * value - 5;
    return result;
}
//?====================================================================================
//* Clear the screen!
void clear()
{
    system("clear");
}

//?============================================================================================

void Bisection()
{
    int format = 12;
    float tolerance = 0.001;
    float a, b, c;
    float root;
    int count = 1;
    while (true)
    {
        clear();
        cout << "Give two initial guesses that may enclose the root: " << endl;
        cin >> a >> b;
        if ((function(a) * function(b)) > 0)
        {
            cout << "The given values do not enclose the root.\nPlease try again!!" << endl;
            getchar();
            continue;
        }
        else
            break;
    }
    clear();
    cout << left << setw(format) << "Iteration"
         << " | " << setw(format) << "a"
         << " | " << setw(format) << "b"
         << " | " << setw(format) << "c=(a+b)/2"
         << " | " << setw(format) << "f(a)"
         << " | " << setw(format) << "f(b)"
         << " | " << setw(format) << "f(c)"
         << " | ";
    cout << "\n______________________________________________________________________________________________________\n";

    while (true)
    {
        c = (a + b) / 2;
        float funcA = function(a), funcB = function(b), funcC = function(c);
        cout << left << setw(format) << count << " | " << fixed << setprecision(5) << setw(format) << setw(format) << a << " | " << setw(format) << b << " | " << setw(format) << c << " | " << setw(format) << funcA << " | " << setw(format) << funcB << " | " << setw(format) << funcC << " | " << endl;

        if (abs(c - b) <= tolerance)
        {
            root = a;
            break;
        }
        else if (abs(c - b) <= tolerance)
        {
            root = b;
            break;
        }
        count++;

        if (funcC > 0)
            b = c;
        else
            a = c;
    }
    cout << "______________________________________________________________________________________________________\n";

    cout << "The root is " << setprecision(3) << root << endl;
    getchar();
}
//?======================================================================================
void Secant(){
    
}
//?======================================================================================

//* Displays the menu!
int menu()
{
    int choice;
    clear();
    cout << "Enter your choice:" << endl;
    cout << "\tBracketing Method -------   1" << endl;
    cout << "\tSecant Method     -------   2" << endl;
    cout << "Choose:  ";
    cin >> choice;

    // Flush the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
        /* code */
        clear();
        Bisection();
        getchar();
        break;
    case 2:
        clear();
        cout << "Secant Method" << endl;
        getchar();
        break;

    default:
        cout << "Invalid choice! Try again" << endl;
        getchar();
    }
    return 0;
};

//?============================================================================================

int main()
{
    while (true)
    {
        menu();
    }

    return 0;
};
//?=================================================================================================