#include <QApplication>

#include "controllers/maincontroller.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*UserDAO* userDao = new UserDAO();

    QList<User> users = userDao->all();

    for (int i = 0; i < users.size(); i++) {
        qDebug() << QString("%1) %2 %3 from %4").arg(users[i].getId()).arg(users[i].getName(), users[i].getSurname(), users[i].getCountry());
    }

    WelcomeWindow w;
    w.show();*/

    MainController::getInstancePtr()->index();

    return a.exec();
}

/*#include <QApplication>
#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow win;
    QTableView *cview = new QTableView();
    win.setCentralWidget(cview);

    QStandardItemModel model(0, 3);

    model.setHeaderData(0, Qt::Horizontal, "one" );
    model.setHeaderData(1, Qt::Horizontal, "two" );
    model.setHeaderData(2, Qt::Horizontal, "three");

    for (int groupnum = 0; groupnum < 3 ; ++groupnum)
    {
        model.appendRow(QList<QStandardItem*>() << new QStandardItem(QString("#%1").arg(groupnum)) << new QStandardItem("Hello") << new QStandardItem("World"));

        // model.appendRow(newRow);
        // model->appendRow(group);
    }

    cview->setModel(&model);

    win.show();
    return app.exec();
}
*/
