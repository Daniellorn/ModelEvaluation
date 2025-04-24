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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

            color: "#1a2226"
        }

        Rectangle {
            id: firstRowSecondCol
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

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
