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

//расширеный класс ZeroExcept добовляет описание ошибки
class FullZeroExcept : public ZeroExcept
{
public:
    FullZeroExcept(const string& message, int errorCode, const string& additionalInfo): ZeroExcept(message, errorCode), additionalInfo(additionalInfo){}
    //метод получения кода ошибки
    string getadditionalInfo() const { return additionalInfo; }
private:
    string additionalInfo;
};

void f_lv1()
{
    int a, b, c; // переменные для зранение данных
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;

        //проверка 
        if(b == 0)
        {
            throw FullZeroExcept("You can't divide by zero!", 0101, "Divide by zero!"); // использую свой клсс с сообщ. и кодом ошибки
        }
        c = a / b;
        cout << "the result of division is: " << c;
}

void f_lv2()
{
    f_lv1();
}

void f_lv3()
{
    f_lv2;
}
int main()
{
    try
    {
        f_lv3();
    }
    catch(const ZeroExcept& err)
    {
        //обработка исключения
        cerr << "Exc.: " << err.what() << endl;
        cerr << "Error code: " << err.getErrorCode() << endl;
    }
    catch(const FullZeroExcept& err)
    {
        //обрабработка насл. искллючения
        cerr << "Exc.: " << err.what() << endl;
        cerr << "Error code: " << err.getErrorCode() << endl;
        cerr << " Error info: " << err.getadditionalInfo() << endl;
    }

    return 0;
}