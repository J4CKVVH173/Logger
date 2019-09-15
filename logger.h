#ifndef APIDB_H
#define APIDB_H

#include "libs/sqlite3.h"
#include <fstream>


/*!
 * \brief The Logger class - класс для логирования информации. Производит подключение к бд, и пишет данные в нее через спец методы.
 */
class Logger
{
public:
    /*!
     * \brief ApiDb - конструктор который вроизводит подключение в дб и создает все таблицы файла tables.txt которых еще нет в бд.
     * Если бд создается с нуля, то создаются все таблицы из файла.
     * \param pathToSql - путь до дирректории где лежат все файлы с sql командами
     * \param dbName - название бд которая будет создана или к которой будет произведено подключение
     */
    Logger(std::string pathToSql, std::string dbName = "db");
    ~Logger();

    /*!
     МЕТОД ИСПОЛЬЗУЕТСЯ КАК ТЕСТОВЫЙ ПРИМЕР НА БУДУЩЕЕ. СДЕЛАТЬ ПО АНАЛОГИИ ВСЕ ЛОГЕРЫЮ.
     */
    bool addUser(std::string username, std::string firstName = "1",std::string firstEnter = "1", std::string userId = "1");

    // https://stackoverflow.com/questions/11945980/sqlite-insert-statement-with-c  -- пример как производить вставку
private:
    /*!
     * \brief dbConnection глобальная переменная содержащая объект класса sqlite3
     */
    sqlite3 *dbConnection;
    /*!
     * \brief dbName глобальная переменная имени файла БД с которым производится работа
     */
    std::string dbName;
    /*!
     * \brief pathToSqlDir строка содержащая полный путь до директории с файлами sql команд для работы с бд
     */
    std::string pathToSqlDir;

    /*!
     * \brief getSqlCommandFromFile - метод достатет из указанного файла все sql команды и возращает их ввиде std::string
     * \param fileName - название файла из которого будут доставаться переменные
     * \return возвращает std::string содержащую все команды из указанного файла
     */
    std::string getSqlCommandFromFile(std::string fileName);
    /*!
     * \brief createTables - каждый раз при создании объекта ApiDb производит создание всех таблиц если
     * sql файл с командами для инициализации таблиц лежит по указанному пути pathToSqlDir
     */
    void createTables();

    /*!
     * \brief quotesql - строчные значениея записываемые в бд должны быть обернуты в ', функция
     * автоматизирует этот процесс
     * \param s - строковое значение которое оборачивается в '
     * \return - строка обернутая в одинарные ковычки
     */
    std::string quotesql( const std::string& s );
};

#endif // APIDB_H
