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
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.accuracy>= modelAnalysis.accuracy2) ? "green" : "red"
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
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis && modelAnalysis.recall>= modelAnalysis.recall2) ? "green" : "red"
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
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:  (modelAnalysis && modelAnalysis.specifity>= modelAnalysis.specifity2) ? "green" : "red"
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
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:  (modelAnalysis && modelAnalysis.precision>= modelAnalysis.precision2) ? "green" : "red"
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
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:  (modelAnalysis && modelAnalysis.f1>= modelAnalysis.f12) ? "green" : "red"
            }
        }

        Text {
            text: "Całkowity\nwspółczynnik błędu: "
            font.pixelSize: 18
            color: "white"
            horizontalAlignment: Text.AlignHCenter

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.errorRate.toFixed(2) + "%"  : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:  (modelAnalysis && modelAnalysis.errorRate <= modelAnalysis.errorRate2) ? "green" : "red"
            }
        }

        Text {
            text: "AUC: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis ? modelAnalysis.auc.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:(modelAnalysis && modelAnalysis.auc >= modelAnalysis.auc2) ? "green" : "red"
            }
        }
    }
}
