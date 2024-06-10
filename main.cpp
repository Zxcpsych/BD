#include <QApplication>
#include <QFile>
#include "secondwindow.h"

#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager dbManager("localhost", 5432, "Kurs", "postgres", "1928");

    SecondWindow w(&dbManager);
    w.show();


    return a.exec();
}
