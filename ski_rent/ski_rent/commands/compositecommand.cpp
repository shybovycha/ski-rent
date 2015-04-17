#include "compositecommand.h"

CompositeCommand::CompositeCommand() : BaseCommand()
{

}

CompositeCommand::~CompositeCommand()
{

}

CompositeCommand* CompositeCommand::first(BaseCommand *cmd) {
    CompositeCommand* res = new CompositeCommand();

    res->nextCmd.append(cmd);

    return res;
}

CompositeCommand* CompositeCommand::then(BaseCommand *cmd) {
    this->nextCmd.append(cmd);
    return this;
}

void CompositeCommand::routine() {
    for (int i = 0; i < this->nextCmd.size(); i++) {
        this->nextCmd.at(i)->routine();
    }
}

