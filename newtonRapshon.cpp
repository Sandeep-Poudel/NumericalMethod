#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double f(double x)
{
    return x * x + sin(x) - 5.23;
}

double ff(double x)
{
    return 2 * x + cos(x);
}

void clearScreen(){
    system("clear");
}

int main()
{
    double x, x1;
    int count = 0;
    while (true)
    {
        cout << "Enter a guess: ";
        cin >> x;
        clearScreen();
        cout<<"Iteration\tx\t\tx1\t\tf(x)\t\tf'(x)"<<endl;
        do
        {
            x1 = x - (f(x) / ff(x));
            cout<<count<<"\t\t"<<x<<"\t\t"<<x1<<"\t\t"<<f(x)<<"\t\t"<<ff(x)<<endl;
            x = x1;
            count++;
        } while (abs(f(x)) >= 0.001);
        cout << "Root is : " << x1 << endl;
        getchar();
        count = 0;
    }
    return 0;
}