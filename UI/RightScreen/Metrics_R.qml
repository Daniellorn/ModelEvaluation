import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Basic

Item {
    width: rightScroll.width
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
            text: modelAnalysis ? modelAnalysis.accuracy2.toFixed(2) + "%" : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.accuracy2>= modelAnalysis.accuracy) ? "green" : "red"
            }
        }

        Text {
            text: "Czułość: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.recall2.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.recall2>= modelAnalysis.recall) ? "green" : "red"
            }
        }

        Text {
            text: "Swoistość: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.specifity2.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.specifity2>= modelAnalysis.specifity) ? "green" : "red"
            }
        }

        Text {
            text: "Precyzja: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.precision2.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.precision2>= modelAnalysis.precision) ? "green" : "red"
            }
        }

        Text {
            text: "Wskaźnik f1: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.f12.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.f12>= modelAnalysis.f1) ? "green" : "red"
            }
        }

        Text {
            text: "AUC: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.auc2.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.auc2 >= modelAnalysis.auc) ? "green" : "red"
            }
        }
    }
}
