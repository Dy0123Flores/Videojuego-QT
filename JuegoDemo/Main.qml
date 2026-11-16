
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: ventana
    width: 390
    height: 740
    minimumWidth: 320
    minimumHeight: 550
    visible: true
    title: "Orbita Fugaz"
    color: "#101827"

    property int pantalla: 0
    property string nombreJugador: ""
    property string aliasJugador: ""
    property int edadJugador: 0
    property string dificultad: "Normal"
    property int puntos: 0
    property int tiempo: 30
    property int combo: 0
    property int mejorCombo: 0
    property bool jugando: false
    property bool pausado: false
    property bool partidaTerminada: false
    property int tipoObjetivo: 0
    property int tamañoObjetivo: 65
    property real posicionX: 0
    property real posicionY: 0

    function cambiarObjetivo() {
        tipoObjetivo = Math.random() < 0.25 ? 1 : 0

        posicionX = Math.random() *
                    Math.max(0, zonaJuego.width - tamañoObjetivo)

        posicionY = Math.random() *
                    Math.max(0, zonaJuego.height - tamañoObjetivo)
    }

    function iniciarJuego() {
        puntos = 0
        tiempo = 30
        combo = 0
        mejorCombo = 0
        pausado = false
        partidaTerminada = false

        if (dificultad === "Fácil")
            tamañoObjetivo = 85
        else if (dificultad === "Normal")
            tamañoObjetivo = 65
        else
            tamañoObjetivo = 48

        pantalla = 1
        jugando = true

        Qt.callLater(cambiarObjetivo)
    }
}