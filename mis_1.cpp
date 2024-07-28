#include<iostream>


using namespace std;

class ZeroExept
{
public:
    ZeroExept(string mesege): itsMesege(mesege){}
    ~ZeroExept(){}

    string GetMaseges() const { return itsMesege; }
private:
    string itsMesege;
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
            throw ZeroExept("You can't divide by zero!");
        }
        c = a / b;
        cout << "the result of division is: " << c;
    }
    catch(const ZeroExept& err)
    {
        //обработка исключения
        cerr << "Exc.: " << err.GetMaseges() << endl;
    }

    return 0;
}