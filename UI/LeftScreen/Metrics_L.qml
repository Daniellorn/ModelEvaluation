import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Basic

import ModelAnalysis

Item {
    width: leftScroll.width
    height: grid2.height

    Layout.topMargin: 10
    Layout.leftMargin: 80

    GridLayout {
        id: grid2

        rows: 2
        columns: 4

        rowSpacing: 5
        columnSpacing: 10

        Text {
            text: "Trafność: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.accuracy.toFixed(2) + "%" : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            width: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: "transparent"
            }
        }

        Text {
            text: "Czułość: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.recall.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            width: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: "transparent"
            }
        }

        Text {
            text: "Swoistość: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.specifity.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            width: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: "transparent"
            }
        }

        Text {
            text: "Precyzja: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.precision.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            width: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: "transparent"
            }
        }

        Text {
            text: "Wskaźnik f1: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.f1.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            width: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: "transparent"
            }
        }
    }
}
