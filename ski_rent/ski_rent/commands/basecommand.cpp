#include "basecommand.h"

BaseCommand::BaseCommand()
{
}

BaseCommand::~BaseCommand()
{
}

void BaseCommand::execute() {
    this->routine();
}
