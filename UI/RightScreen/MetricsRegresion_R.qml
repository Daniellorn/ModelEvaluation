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
            text: "MAE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.mae2.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color: (modelAnalysis2 && modelAnalysis2.mae2 <= modelAnalysis2.mae) ? "green" : "red"
            }
        }

        Text {
            text: "MAPE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.mape2.toFixed(2) + "%" : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:  (modelAnalysis2 && modelAnalysis2.mape2 <= modelAnalysis2.mape) ? "green" : "red"
            }
        }

        Text {
            text: "MSE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.mse2.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:  (modelAnalysis2 && modelAnalysis2.mse2 <= modelAnalysis2.mse) ? "green" : "red"
            }
        }

        Text {
            text: "RMSE: "
            font.pixelSize: 18
            color: "white"

        }

        TextField {
            text: modelAnalysis2 ? modelAnalysis2.rmse2.toFixed(2) : 0
            font.pixelSize: 18
            color: "white"
            readOnly: true
            Layout.preferredWidth: 100

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: "#1a2226"
                border.color:  (modelAnalysis2 && modelAnalysis2.rmse2 <= modelAnalysis2.rmse) ? "green" : "red"
            }
        }

    }
}
