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
            cout << "Type 1. Add" << endl;
            cout << "Type 2. Subtract" << endl;
            cout << "Type 3. Multiply" << endl;
            cout << "Type 4. Divide" << endl;
            cout << "Type 5. Square" << endl;
            cout << "Type 6. Cube" << endl;
            cout << "Type 7. Square Root" << endl;
            cout << "Type 8. Power" << endl;

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
                    cout << "Invalid choice your method! please try again" << endl;
                }
                if (msg == "onlyNumber")
                {
                    cout << "Only accept Number " << endl;
                }
                if ( msg == "wrongInput")
                {
                    cout  << "Wrong input" << endl;
                }
                if (msg == "errorRoot")
                {
                    cout << "Error " << endl;
                }
                if (msg == "onlyPositiveNumber")
                {
                    cout << "Only positive number " << endl;
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
                    cout << "Only accept Number " << endl;
                }
                if ( msg == "wrongInput")
                {
                    cout  << "Wrong input" << endl;
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
            cout << "Invalid Calculator" << endl;
        }
    }

    return 0;

}