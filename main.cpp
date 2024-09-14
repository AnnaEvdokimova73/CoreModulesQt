#include <QCoreApplication>

#include <QSqlDatabase>
#include <QUdpSocket>

void workDataBase()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "MyDataBase");
   db.setHostName("localhost");
   db.setDatabaseName("name");
   db.setUserName("user");
   db.setPassword("123hgfasd");
   bool ok = db.open();
   qDebug() << (ok ? "База данных была открыта" : "База данных не была открыта") ;
}

void workNetwork()
{
    QUdpSocket* udpSocket = new QUdpSocket();
    udpSocket->bind(QHostAddress::Any, 7755);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    workDataBase();
    workNetwork();

    return a.exec();
}
