#include <iostream>
#include "configParser/headers/func.h"

using namespace configParse;
using namespace std;

int main(int argc, char* argv[])
{
    QList<config>* confs = ConfigsParser::getConfig(argv[1]);

    delete confs;
    return 0;
}
