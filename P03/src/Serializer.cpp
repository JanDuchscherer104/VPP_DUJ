//
// Created by Jan Duchscherer on 26.12.22.
//

#include "../include/Serializer.hpp"
#include <fstream>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include "../include/IKomponente.hpp"

Serializer::Serializer(IKomponente const& root) : ik{root} {}

void Serializer::writeToJson(const char* fname) {
    QFile jsonF(fname);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(ik.toJson());
    if (jsonF.open(QFile::WriteOnly)) {
        if (int bytesWritten = jsonF.write(jsonDoc.toJson()) == -1) {
            throw std::fstream::failure("Datei konnte nicht geoeffnet werden.");
        }
    } else {
        throw std::fstream::failure("Datei konnte nicht beschrieben werden.");
    }
    if (jsonF.isOpen()) {
        jsonF.close();
    }
}
