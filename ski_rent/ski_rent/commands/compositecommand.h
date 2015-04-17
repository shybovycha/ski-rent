#ifndef COMPOSITECOMMAND_H
#define COMPOSITECOMMAND_H

#include <QList>

#include "commands/basecommand.h"

class CompositeCommand : public BaseCommand
{
public:
    CompositeCommand();
    ~CompositeCommand();

    static CompositeCommand* first(BaseCommand* cmd);
    CompositeCommand* then(BaseCommand* cmd);

protected:
    void routine();

    QList<BaseCommand*> nextCmd;
};

#endif // COMPOSITECOMMAND_H
