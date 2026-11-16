
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "registropuntajes.h"

int main(int argc, char *argv[])
{
    QGuiApplication aplicacion(argc, argv);

    RegistroPuntajes registro;

    QQmlApplicationEngine motor;

    motor.rootContext()->setContextProperty(
        "registroPuntajes", &registro
        );

    motor.loadFromModule("JuegoDemo", "Main");

    if (motor.rootObjects().isEmpty())
        return -1;

    return aplicacion.exec();
}
