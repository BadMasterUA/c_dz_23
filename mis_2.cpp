#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

//мой клас с доп. информацией
class ZeroExcept : public runtime_error
{
public:
    ZeroExcept(const string& message, int errorCode): runtime_error(message), errorCode(errorCode){}
    //метод получения кода ошибки
    int getErrorCode() const { return errorCode; }
private:
    int errorCode;
};

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
            throw ZeroExcept("You can't divide by zero!", 0101); // использую свой клсс с сообщ. и кодом ошибки
        }
        c = a / b;
        cout << "the result of division is: " << c;
    }
    catch(const ZeroExcept& err)
    {
        //обработка исключения
        cerr << "Exc.: " << err.what() << endl;
        cerr << "Error code: " << err.getErrorCode() << endl;
    }

    return 0;
}