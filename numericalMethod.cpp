#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;
static int ready;

//?====================================================================================
void flush()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}
//?======================================================================================
float useFunction(float data, bool configure = false)
{
    static int order;
    static float coefficient[100]; // Assuming a maximum of 100 coefficients
    float result = 0;

    while (true)
    {
        if (configure)
        {
            cout << "Enter the order of the polynomial (odd): " << endl;
            cin >> order;
            if (order % 2 == 0)
            {
                continue;
            }
            cout << "Enter the coefficients in order of decreasing term power:" << endl;
            for (int i = order; i >= 0; i--)
            {
                cin >> coefficient[i];
            }
            cout << "Polynomial Function configured! You can use all the useFunctions now!!" << endl;
            ready = 1;
            getchar();
            return 0;
        }
        else
        {
            for (int i = order; i >= 1; i--)
            {
                result += coefficient[i] * pow(data, i);
            }
            result += coefficient[0];
            return result;
        }
    }
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
    float tolerance = 0.0001;
    float a, b, c;
    float root;
    int count = 1;
    string line = "  ________________________________________________________________________________________________________\n";

    while (true)
    {
        clear();
        if (!ready)
        {
            cout << "You havent configured the function yet! please configure it before using this method!" << endl;
            flush();
            getchar();
            return;
        }
        cout << "Give two initial guesses that may enclose the root: " << endl;
        cin >> a >> b;
        cout << useFunction(a) << "\t" << useFunction(b) << endl;
        getchar();
        if ((useFunction(a) * useFunction(b)) > 0)
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
        float funcA = useFunction(a), funcB = useFunction(b), funcC = useFunction(c);
        cout << " | " << left << setw(format) << count << " | " << fixed << setprecision(6) << setw(format) << setw(format) << a << " | " << setw(format) << b << " | " << setw(format) << c << " | " << setw(format) << funcA << " | " << setw(format) << funcB << " | " << setw(format) << funcC << " | " << endl;

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
    float tolerance = 0.0001;
    float x0, x1, x2;
    float root;
    string line = "  _________________________________________________________________________________________________________________________________________________________________\n";
    int count = 1;
    while (true)
    {
        clear();
        if(! ready)
        {
            cout << "You havent configured the function yet! please configure it before using this method!" << endl;
            flush();
            getchar();
            return;
        }
        cout << "Give two initial guesses that may enclose the root: " << endl;
        cin >> x0 >> x1;
        flush();
        if ((useFunction(x0) * useFunction(x1)) > 0)

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
    cout << "\n"
         << line;
    while (true)
    {
        x2 = x1 - (useFunction(x1) * (x0 - x1)) / (useFunction(x0) - useFunction(x1));
        float funcX0 = useFunction(x0), funcX1 = useFunction(x1), funcX2 = useFunction(x2);
        cout << " | " << left << setw(format) << count << " | " << fixed << setprecision(6) << setw(format) << setw(format) << x0 << " | " << setw(format) << x1 << " | " << setw(format) << x2 << " | " << setw(format) << funcX0 << " | " << setw(format) << funcX1 << " | " << setw(format) << funcX2 << " | " << endl;

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
    cout << "\tBisection Method     -------   1" << endl;
    cout << "\tSecant Method         -------   2" << endl;
    cout << "\tConfigure useFunction    -------   3" << endl;
    cout << "Choose:  ";
    cin >> choice;

    // Flush the input buffer
    ;
    switch (choice)
    {
    case 1:
        /* code */
        clear();
        Bisection();
        break;
    case 2:
        clear();
        Secant();
        break;
    case 3:
        clear();
        useFunction(0, true);
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
