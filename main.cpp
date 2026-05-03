#include <iostream>
#include <cmath>
using namespace std;


class CalculatorBase
{
    public:
    virtual double add(double num1, double num2){}
    virtual double sub(double num1, double num2){}
    virtual double mul(double num1, double num2){}
    virtual double div(double num1, double num2){}

    void ShowDisplay(string o, double r)
    {
        cout << "====== scientific calculator ======" << endl;
        cout << "Operation : " << o << endl;
        cout << "Result    : " << r << endl;
        cout << "======================" << endl;
    }
};

// Scientific Calculator
class ScientificCalculator : public CalculatorBase
{
    public:
    double add(double arr[], int n)
    {
        double sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }

        return sum;
    }
    double sub(double arr[], int n)
    {
        double result = arr[0];

        for(int i = 1; i < n; i++)
        {
            result = result - arr[i];
        }

        return result;
    }
    double mul(double arr[], int n)
    {
        double result = 1;

        for(int i = 0; i < n; i++)
        {
            result = result * arr[i];
        }

        return result;
    }
    double div(double arr[], int n)
    {
        double result = arr[0];

        for(int i = 1; i < n; i++)
        {
            result = result / arr[i];
        }

        return result;
    }

    double square(double num1)
    {
        return num1 * num1;
    }
    double cube(double num1)
    {
        return num1 * num1 * num1;
    }
    double Sqrt(double num1)
    {
        return sqrt(num1);
    }

    double power(double base, double exponent)
    {
        return pow(base, exponent);
    }
};

// Legacy Calculator
class LegacyCalculator : public ScientificCalculator
{
    public:
    double add(double num1, double num2)
    {
        return num1 + num2;
    }
    double sub(double num1, double num2)
    {
        return num1 - num2;
    }
    double mul(double num1, double num2)
    {
        return num1 * num2;
    }
    double div(double num1, double num2)
    {
        return num1 / num2;
    }
};

template <typename T> class Number
{
    public:
        T value;

        void operator += (Number obj)
        {
            return this->value += obj.value;
        }

        T operator ^ (Number obj)
        {
            return this->value ^ obj.value;
        }
};


int main()
{
    int calMode, choiceMethod;
    double num1, num2;

    cout << "Choose your Calculator:" << endl;
    cout << "type 1 for Scientific Calculator" << endl;
    cout << "type 2 for Legacy Calculator" << endl;
    cin >> calMode;

    try
    {
        ScientificCalculator calculator;
        if (calMode == 1)
        {
            cout << "Choose your option" << endl;
            cout << "Type 1. Addition Series" << endl;
            cout << "Type 2. Subtract Series" << endl;
            cout << "Type 3. Multiply Series" << endl;
            cout << "Type 4. Divide Series" << endl;
            cout << "Type 5. Square" << endl;
            cout << "Type 6. Cube" << endl;
            cout << "Type 7. Square Root" << endl;
            cout << "Type 8. Power" << endl;

            try
            {
                int n;
                cin >> choiceMethod;

                if (choiceMethod == 1)
                {
                    cout << "How many numbers do you want to enter? : ";
                    cin >> n;
                    double arr[n];
                    cout << "\nEnter " << n << " interger numbers one by one:" << endl;
                    for(int i = 0; i < n; i++)
                    {
                        cout << "Enter number " << i + 1 << " : ";
                        cin >> arr[i];
                    }
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.add(arr,  n);
                    calculator.ShowDisplay("Addition Series = ", result);
                }
                else if (choiceMethod == 2)
                {
                    cout << "How many numbers do you want to enter? : ";
                    cin >> n;
                    double arr[n];
                    cout << "\nEnter " << n << " integer numbers one by one:" << endl;
                    for(int i = 0; i < n; i++)
                    {
                        cout << "Enter number " << i + 1 << " : ";
                        cin >> arr[i];
                    }
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.sub(arr, n);
                    calculator.ShowDisplay("Substraction", result);
                }
                else if (choiceMethod == 3)
                {
                    cout << "How many numbers do you want to enter? : ";
                    cin >> n;
                    double arr[n];
                    cout << "\nEnter " << n << " integer numbers one by one:" << endl;
                    for(int i = 0; i < n; i++)
                    {
                        cout << "Enter number " << i + 1 << " : ";
                        cin >> arr[i];
                    }
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.mul(arr, n);
                    calculator.ShowDisplay("Multiplication", result);
                }

                else if (choiceMethod == 4)
                {
                    cout << "How many numbers do you want to enter? : ";
                    cin >> n;
                    double arr[n];
                    cout << "\nEnter " << n << " integer numbers one by one:" << endl;
                    for(int i = 0; i < n; i++)
                    {
                        cout << "Enter number " << i + 1 << " : ";
                        cin >> arr[i];
                    }
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    if(n <= 0)
                    {
                        throw "invalidSize";
                    }
                    // ScientificCalculator calculator;
                    double result = calculator.div(arr, n);
                    calculator.ShowDisplay("Division", result);
                }

                else if (choiceMethod == 5)
                {
                    cout << "Enter a value : " ;
                    cin >> num1;
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.square(num1);
                    calculator.ShowDisplay("Square", result);
                }
                else if (choiceMethod == 6)
                {
                    cout << "Enter a value : " ;
                    cin >> num1;
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.cube(num1);
                    calculator.ShowDisplay("Cude", result);
                }
                else if (choiceMethod == 7)
                {
                    cout << "Enter a value : " ;
                    cin >> num1;
                    if (cin.fail())
                    {
                        throw "onlyPositiveNumber";
                    }
                    if (num1 <= 0)
                    {
                        throw "errorRoot";
                    }
                    double result = calculator.Sqrt(num1);
                    calculator.ShowDisplay("Square Root", result);
                }
                else if (choiceMethod == 8)
                {
                    cout << "Enter base and power value : " ;
                    cin >> num1 >> num2;
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.power(num1, num2);
                    calculator.ShowDisplay("Power", result);
                }
                else
                {
                    throw "invalidMethod";
                }
            }
            catch (const char* msg)
            {
                if (msg == "inValidMethod")
                {
                    cout << "Error : Invalid choice! Please select a valid menu option." << endl;
                }

                if (msg == "onlyNumber")
                {
                    cout << "Error : Invalid input! Please enter numbers only." << endl;
                }

                if (msg == "wrongInput")
                {
                    cout << "Error : Wrong input! Division by zero is not allowed." << endl;
                }

                if (msg == "invalidSize")
                {
                    cout << "Error : Invalid input size! Number of elements must be greater than 0." << endl;
                }

                if (msg == "divideByZero")
                {
                    cout << "Error : Error! You cannot divide by zero in a series." << endl;
                }

                if (msg == "errorRoot")
                {
                    cout << "Error: Invalid input! Square root requires a positive number." << endl;
                }

                if (msg == "onlyPositiveNumber")
                {
                    cout << "Error : Invalid input! Please enter a positive number only." << endl;
                }
            }
        }
        else if (calMode == 2)
        {
            LegacyCalculator calculator;
            cout << "Choose your option" << endl;
            cout << "Type 1. Add" << endl;
            cout << "Type 2. Subtract" << endl;
            cout << "Type 3. Multiply" << endl;
            cout << "Type 4. Divide" << endl;

            try
            {
                cin >> choiceMethod;

                if (choiceMethod == 1)
                {
                    cout << "Enter two value : " ;
                    cin >> num1 >> num2;
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.add(num1, num2);
                    calculator.ShowDisplay("Addition", result);
                }
                else if (choiceMethod == 2)
                {
                    cout << "Enter two value : " ;
                    cin >> num1 >> num2;
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.sub(num1, num2);
                    calculator.ShowDisplay("Substraction", result);
                }
                else if (choiceMethod == 3)
                {
                    cout << "Enter two value : " ;
                    cin >> num1 >> num2;
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    double result = calculator.mul(num1, num2);
                    calculator.ShowDisplay("Multiplication", result);
                }

                else if (choiceMethod == 4)
                {
                    cout << "Enter two value : " ;
                    cin >> num1 >> num2;
                    if (cin.fail())
                    {
                        throw "onlyNumber";
                    }
                    if (num2 == 0)
                    {
                        throw "wrongInput";
                    }
                    // ScientificCalculator calculator;
                    double result = calculator.div(num1, num2);
                    calculator.ShowDisplay("Division", result);
                }

            }
            catch (const char* msg)
            {
                if (msg == "onlyNumber")
                {
                    cout << "Error : Only accept Number " << endl;
                }
                if ( msg == "wrongInput")
                {
                    cout  << "Error : Wrong input" << endl;
                }
            }
        }
        else
        {
            throw "inValidCalculator";
        }
    }
    catch (const char* msg)
    {
        if (msg == "inValidCalculator")
        {
            cout << "Error : Invalid Calculator" << endl;
        }
    }

    return 0;

}