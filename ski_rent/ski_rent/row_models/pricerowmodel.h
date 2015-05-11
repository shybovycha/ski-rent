#ifndef PRICEROWMODEL_H
#define PRICEROWMODEL_H

#include "entities/price.h"
#include "row_models/abstractrowmodel.h"

template<>
void AbstractRowModel<Price>::setColumns() {
    columns.clear();
    columns["type"] = tr("Equipment");
    columns["condition"] = tr("Condition");
    columns["time"] = tr("Rent time");
    columns["price"] = tr("Price");
}

#endif // PRICEROWMODEL_H

