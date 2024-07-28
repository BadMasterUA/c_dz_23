#include <iostream>
#include <cstring> // пропущена буква "c" в названии библеотеки
using namespace std;

class xOutOfMemory
{
public:
    xOutOfMemory()
    {
        theMsg = new char[20];
        strcpy(theMsg, "error in memory");
    }
    ~xOutOfMemory()
    {
        delete[] theMsg;
        cout << "Memory restored. " << endl;
    }
    char *Message() { return theMsg; }

private:
    char *theMsg;
};

int main()
{
    try
    {
        
        char *var = new char;
        /* лишняя проверка 
        if (var == nullptr)
        {
            xOutOfMemory *px = new xOutOfMemory;
            throw px;
        }*/
    }
    catch (xOutOfMemory *theException)
    {
        cout << theException->Message() << endl;
        delete theException;
    }
    return 0;
}

/*Если исключение сработает до удаления объекта xOutOfMemory, это приведет к утечке памяти*/