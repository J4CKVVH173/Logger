#include <iostream>
#include "logger.h"

using namespace std;

int main()
{
    // создается объект ворекр для бд, внутри происходит автоматическое подключение к бд, создание всех таблиц которых еще нет
    Logger* dbWorker = new Logger("C:\\Users\\andrey\\Documents\\dbAPi\\sql\\");
    // производится запись пользователя в бд при вызове метода.
    bool kek = dbWorker->addUser("My name");
    // при вызове деструктора происходит разрыв соединения с бд
    delete dbWorker;
    return 0;
}
