#include<iostream>


using namespace std;

int main()
{
    try
    {
        int a, b, c; // переменные для зранение данных
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;

        //проверка 
        if(b == 0)
        {
            throw runtime_error("You can't divide by zero!");
        }
        c = a / b;
        cout << "the result of division is: " << c;
    }
    catch(const range_error& err)
    {
        //обработка исключения
        cerr << "Exc.: " << err.what() << endl;
    }

    return 0;
}