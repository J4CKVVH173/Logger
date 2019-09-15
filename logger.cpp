#include "logger.h"

// ToDo снести нахуй
#include <iostream>


Logger::Logger(std::string pathToSql, std::string dbName)
{
    // записываются основные конфигурационные параметры о бд в глобальные переменные
    Logger::pathToSqlDir = pathToSql;
    Logger::dbName = dbName + ".sqlite";

    // открывается соединение с бд
    sqlite3_open(Logger::dbName.c_str(), &dbConnection);

    // производится создание таблиц
    Logger::createTables();
}

Logger::~Logger()
{
    // закрываем соединение
    sqlite3_close(dbConnection);
}

bool Logger::addUser(std::string username, std::string firstName, std::string firstEnter, std::string userId)
{
    char *err = nullptr;
    // достается команда для аписи данныех в бд. команда оканчивается (, чтобы сразу можно было к ней приконкатенировать все динамические значения
    std::string user = Logger::getSqlCommandFromFile("add_user.sql");
    // конкатенируем динамические значения. строковые значения передаются в метод quotesql который оборачивает их в одинарные кавычки (так бд различает числа и строки)
    user += Logger::quotesql(username) + "," + Logger::quotesql(firstName) + "," +  firstEnter + "," + userId + ");";
    // пишем в бд, при удачной записи, возвращается true
    if (sqlite3_exec(dbConnection, user.c_str(), nullptr, nullptr,  &err)) return false;
    return true;
}

std::string Logger::getSqlCommandFromFile(std::string fileName)
{
    setlocale(LC_ALL, "ru");
    std::string sql;
    std::string line;
    // открыли файл для чтения
    std::ifstream fileWithSqlCommands(Logger::pathToSqlDir + fileName);
    // если файл не получилось открыть, вызывается исключение
    if (!fileWithSqlCommands.is_open()) throw "File did not open. Apidb class. createTable method.";
    // считываются все команды из файла
    while (!fileWithSqlCommands.eof()) {
        line = "";
        std::getline(fileWithSqlCommands, line);
        sql += " " + line;
    }
    fileWithSqlCommands.close();
    return sql;
}

void Logger::createTables()
{
    char *err = nullptr;
    std::string sqlCommands = Logger::getSqlCommandFromFile("tables.sql");
    sqlite3_exec(dbConnection, sqlCommands.c_str(), nullptr, nullptr, &err);
}

std::string Logger::quotesql(const std::string &s)
{
    return std::string("'") + s + std::string("'");
}
