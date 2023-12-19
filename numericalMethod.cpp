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
    string line = "  ________________________________________________________________________________________________________\n";
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
    cout << line;
    cout << left
         << " | " << setw(format) << "Iteration"
         << " | " << setw(format) << "a"
         << " | " << setw(format) << "b"
         << " | " << setw(format) << "c=(a+b)/2"
         << " | " << setw(format) << "f(a)"
         << " | " << setw(format) << "f(b)"
         << " | " << setw(format) << "f(c)"
         << " | ";
    cout << "\n"
         << line;

    while (true)
    {
        c = (a + b) / 2;
        float funcA = function(a), funcB = function(b), funcC = function(c);
        cout << " | " << left << setw(format) << count << " | " << fixed << setprecision(5) << setw(format) << setw(format) << a << " | " << setw(format) << b << " | " << setw(format) << c << " | " << setw(format) << funcA << " | " << setw(format) << funcB << " | " << setw(format) << funcC << " | " << endl;

        if (abs(c - a) <= tolerance)
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
    cout << line;

    cout << "The root is " << setprecision(3) << root << endl;
    getchar();
}
//?======================================================================================
void Secant()
{
    int format = 20;
    float tolerance = 0.001;
    float x0, x1, x2;
    float root;
    string line = "  _________________________________________________________________________________________________________________________________________________________________\n";
    int count = 1;
    while (true)
    {
        clear();
        cout << "Give two initial guesses that may enclose the root: " << endl;
        cin >> x0 >> x1;
        if ((function(x0) * function(x1)) > 0)
        {
            cout << "The given values do not enclose the root.\nPlease try again!!" << endl;
            getchar();
            continue;
        }
        else
            break;
    }
    clear();
    cout << line;
    cout << left
         << " | " << setw(format) << "Iteration"
         << " | " << setw(format) << "x0"
         << " | " << setw(format) << "x1"
         << " | " << setw(format) << "x2=x1-...."
         << " | " << setw(format) << "f(x0)"
         << " | " << setw(format) << "f(x1)"
         << " | " << setw(format) << "f(x2)"
         << " | ";
    cout << "\n " << line;
    while (true)
    {
        x2 = x1 - (function(x1) * (x0 - x1)) / (function(x0) - function(x1));
        float funcX0 = function(x0), funcX1 = function(x1), funcX2 = function(x2);
        cout << " | " << left << setw(format) << count << " | " << fixed << setprecision(5) << setw(format) << setw(format) << x0 << " | " << setw(format) << x1 << " | " << setw(format) << x2 << " | " << setw(format) << funcX0 << " | " << setw(format) << funcX1 << " | " << setw(format) << funcX2 << " | " << endl;
        if (abs(x2 - x0) <= tolerance || abs(x2 - x1) <= tolerance)
        {
            root = x2;
            break;
        }
        //----------------------------
        count++;
        //-------------------------
        if (funcX0 * funcX2 < 0)
            x1 = x2;
        else
            x0 = x2;
        //-------------------------
    }
    cout << line;
    cout << "The root is " << setprecision(3) << root << endl;
    getchar();
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
        Secant();
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