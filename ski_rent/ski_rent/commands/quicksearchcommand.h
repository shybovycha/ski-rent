#ifndef QUICKSEARCHCOMMAND_H
#define QUICKSEARCHCOMMAND_H

#include <QWidget>

#include "commands/basecommand.h"
#include "dao/userdao.h"
#include "dao/equipmentdao.h"
#include "dao/rentdao.h"
#include "dao/reservationdao.h"

class QuickSearchCommand : public BaseCommand
{
public:
    QuickSearchCommand(QString q, QWidget* w);
    ~QuickSearchCommand();

protected:
    void routine();

    QString query;
    QWidget* target;
};

#endif // QUICKSEARCHCOMMAND_H
