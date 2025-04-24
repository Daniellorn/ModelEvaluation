import QtQuick 2.15

import QtQuick.Layouts

import ModelAnalysis

Item {

    width: rightScroll.width
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
            id: firstRowCol2
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

            color: "#1a2226"
        }

        Rectangle {
            id: firstRowSecondCol2
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
            id: firstRowThirdCol2
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
            id: secondRowCol2
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
            id: secondRowSecondCol2
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.tn2 : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: secondRowThirdCol2
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.fp2 : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: thirdRowCol2
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
            id: thirdRowSecondCol2
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.fn2 : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: thirdRowThirdCol2
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100

            color: "#3288EA"

            Text {
                text: modelAnalysis ? modelAnalysis.tp2 : 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

    }
}
