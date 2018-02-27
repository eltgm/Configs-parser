#include <QtWidgets>
#include <QtXml/QDomDocument>
#include "config.h"
#include <QList>

namespace configParse {
    class ConfigsParser{
    public:
        static struct QList<config>* getConfig(char* path);
    };
}
