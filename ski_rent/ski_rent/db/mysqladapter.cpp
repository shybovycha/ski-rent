#include "db/mysqladapter.h"

#include <QDebug>

MySQLAdapter::MySQLAdapter(QString host, int port, QString user, QString password, QString database)
{
    this->db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName(host);
    db.setPort(port);
    db.setUserName(user);
    db.setPassword(password);
    db.setDatabaseName(database);

    bool isOk = db.open();

    if (!isOk) {
        QString msg = QString("Can not connect to database %1:%2/%3 with username %4 and password [HIDDEN] because of %5")
                .arg(host)
                .arg(port)
                .arg(database)
                .arg(user)
                .arg(this->db.lastError().text());

        qDebug() << msg;

        throw msg.toStdString().c_str();
    }
}

MySQLAdapter::~MySQLAdapter()
{
    this->db.close();
}

QList< DBRow > MySQLAdapter::select(QString query) {
    QList< DBRow > rows;

    QSqlQuery q;

    q.exec(query);

    while (q.next()) {
        int cols = q.record().count();
        DBRow row;
        QSqlRecord rec = q.record();

        for (int i = 0; i < cols; i++) {
            QString colName = rec.fieldName(i);
            QVariant colValue = rec.value(i);

            row[colName] = colValue;
        }

        rows.append(row);
    }

    return rows;
}

bool MySQLAdapter::update(QString query) {
    QSqlQuery q;

    bool res = q.exec(query);

    if (!res) {
        qDebug() << QString("Could not execute query:\n\n%1\n\nBecause of error: ").arg(query);
        qDebug() << this->db.lastError().databaseText();
        qDebug() << this->db.lastError().driverText();
        qDebug() << "==== Trace end ====";
    }

    return res;
}
