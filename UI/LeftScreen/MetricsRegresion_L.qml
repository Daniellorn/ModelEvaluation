import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Basic

import QtCharts

import ModelAnalysis2

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
            text: "MAE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.mae.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis2 && modelAnalysis2.mae>= modelAnalysis2.mae2) ? "green" : "red"
            }
        }

        Text {
            text: "MAPE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.mape.toFixed(2) + "%" : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis2 && modelAnalysis2.mape>= modelAnalysis2.mape2) ? "green" : "red"
            }
        }

        Text {
            text: "MSE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.mse.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis2 && modelAnalysis2.mse>= modelAnalysis2.mse2) ? "green" : "red"
            }
        }

        Text {
            text: "RMSE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.rmse.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis2 && modelAnalysis2.rmse>= modelAnalysis2.rmse2) ? "green" : "red"
            }
        }
    }
}
