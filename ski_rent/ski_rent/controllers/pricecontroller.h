#ifndef PRICECONTROLLER_H
#define PRICECONTROLLER_H

#include <QObject>

#include "util/singleton.h"
#include "entities/price.h"
#include "dao/pricedao.h"

class PriceController : public QObject
{
    Q_OBJECT

public:
    PriceController();
    ~PriceController();

public slots:
    void createPrice(Price* newEntity);
    void updatePrice(QString type, char condition, int time, Price* newEntity);
    void deletePrice(QString type, char condition, int time);
};

typedef Singleton<PriceController> PriceControllerSingleton;

#endif // PRICECONTROLLER_H
