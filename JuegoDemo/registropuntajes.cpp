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

int RegistroPuntajes::cantidad() const
{
    return partidas.size();
}

void RegistroPuntajes::agregarPartida(
    const QString &nombre,
    const QString &alias,
    int edad,
    const QString &dificultad,
    int puntos
    )
{
    if (nombre.trimmed().size() < 2 ||
        alias.trimmed().size() < 2 ||
        edad < 5 ||
        edad > 100 ||
        puntos < 0)
        return;

    Partida partida;

    partida.nombre = nombre.trimmed();
    partida.alias = alias.trimmed();
    partida.edad = edad;
    partida.dificultad = dificultad;
    partida.puntos = puntos;
    partida.fecha = QDateTime::currentDateTime().toString(
        "dd/MM/yyyy hh:mm"
        );

    beginInsertRows(QModelIndex(), 0, 0);
    partidas.prepend(partida);
    endInsertRows();

    emit cantidadChanged();

    guardarPartidas();
}

void RegistroPuntajes::eliminarHistorial()
{
    if (partidas.isEmpty())
        return;

    beginResetModel();
    partidas.clear();
    endResetModel();

    emit cantidadChanged();

    guardarPartidas();
}
