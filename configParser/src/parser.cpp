#include "../headers/func.h"

using namespace std;

namespace configParse {
    struct QList<config>* ConfigsParser::getConfig(char* path){
        QList<config>* configs = new QList<config>();


        qDebug() << path;
        QString str = QString::fromUtf8(path);
        QFile* cfgFile = new QFile(str);

        if (!cfgFile->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return configs;
        }
        QXmlStreamReader xml(cfgFile);

        while (!xml.atEnd() && !xml.hasError())
        {
            QXmlStreamReader::TokenType token = xml.readNext();
            if (token == QXmlStreamReader::StartDocument)
                continue;

            if (token == QXmlStreamReader::StartElement)
            {
                if (xml.name() == "config")
                    while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "config"))
                    {
                        if (xml.tokenType() == QXmlStreamReader::StartElement)
                        {
                            if(xml.name() == "data"){
                              config* conf = new config;
                              QXmlStreamAttributes attributes = xml.attributes();
                              if (attributes.hasAttribute("offset")){
                                  QString of = attributes.value("offset").toString();
                                  conf->offset = of.toUInt();
                              }
                              if (attributes.hasAttribute("block_length")) {
                                  QString b = attributes.value("block_length").toString();
                                  conf->block_length = b.toUInt();
                              }
                              if (attributes.hasAttribute("type_crc")) {
                                  QString t = attributes.value("type_crc").toString();
                                  conf->type_crc = t.toUInt();
                              }
                              if (attributes.hasAttribute("payload")) {
                                  QString p = attributes.value("payload").toString();
                                  QByteArray latin1BAString1 = p.toLocal8Bit();
                                  char* latin1_c_str1 = latin1BAString1.data();
                                  conf->payload = p.toStdString();
                              }

                              configs->insert(configs->end(), *conf);

                              delete conf;

                              xml.readNext();
                            }

                            xml.readNext();
                            continue;
                         }
                        xml.readNext();
                        continue;
                     }
                xml.readNext();
                continue;
            }
        }

        delete file;

        return configs;
    }
}
