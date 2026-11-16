#include "registropuntajes.h"
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSaveFile>
#include <QStandardPaths>

RegistroPuntajes::RegistroPuntajes(QObject *padre)
    : QAbstractListModel(padre)
{
    cargarPartidas();
}

int RegistroPuntajes::rowCount(
    const QModelIndex &padre
    ) const
{
    if (padre.isValid())
        return 0;

    return partidas.size();
}

QVariant RegistroPuntajes::data(
    const QModelIndex &indice,
    int campo
    ) const
{
    if (!indice.isValid() ||
        indice.row() < 0 ||
        indice.row() >= partidas.size())
        return {};

    const Partida &partida = partidas.at(indice.row());

    switch (campo) {
    case Nombre:
        return partida.nombre;
    case Alias:
        return partida.alias;
    case Edad:
        return partida.edad;
    case Dificultad:
        return partida.dificultad;
    case Puntos:
        return partida.puntos;
    case Fecha:
        return partida.fecha;
    default:
        return {};
    }
}

QHash<int, QByteArray> RegistroPuntajes::roleNames()const
{
    return {
        {Nombre, "nombre"},
        {Alias, "alias"},
        {Edad, "edad"},
        {Dificultad, "dificultad"},
        {Puntos, "puntos"},
        {Fecha, "fecha"}
    };
}
