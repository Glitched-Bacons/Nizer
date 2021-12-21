#include "QTestCase.h"

QTestCase::QTestCase()
{
    suite().push_back(this);
}


std::vector<QObject*> & QTestCase::suite()
{
    static std::vector<QObject*> objects;
    return objects;
}
