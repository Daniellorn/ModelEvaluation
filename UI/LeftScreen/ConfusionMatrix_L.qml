import QtQuick 2.15

import ModelAnalysis

import QtQuick.Layouts

Item {

    width: leftScroll.width
    height: grid.height
    Layout.alignment: Qt.AlignHCenter

    Layout.topMargin: 20
    Layout.rightMargin: 80

    GridLayout {
        id: grid

        width: 3 * 100 + 2 * 5

        anchors.horizontalCenter: parent.horizontalCenter

        rows: 3
        columns: 3

        rowSpacing: 5
        columnSpacing: 5

        Rectangle {
            id: firstRowCol
            width: 100
            height: 100

            color: "#1a2226"
        }

        Rectangle {
            id: firstRowSecondCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: "Przewidywane\n0"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: firstRowThirdCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: "Przewidywane\n1"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: secondRowCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: "Faktyczne\n0"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: secondRowSecondCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.tn : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: secondRowThirdCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.fp : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: thirdRowCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: "Faktyczne\n1"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: thirdRowSecondCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.fn : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: thirdRowThirdCol
            width: 100
            height: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.tp : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

    }
}
