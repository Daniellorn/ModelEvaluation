import QtQuick 2.15

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

            color: "white"
        }

        Rectangle {
            id: firstRowSecondCol
            width: 100
            height: 100

            color: "#3288EA"
        }

        Rectangle {
            id: firstRowThirdCol
            width: 100
            height: 100

            color: "#3288EA"
        }

        Rectangle {
            id: secondRowCol
            width: 100
            height: 100

            color: "#3288EA"
        }

        Rectangle {
            id: secondRowSecondCol
            width: 100
            height: 100

            color: "#3288EA"
        }

        Rectangle {
            id: secondRowThirdCol
            width: 100
            height: 100

            color: "#3288EA"
        }

        Rectangle {
            id: thirdRowCol
            width: 100
            height: 100

            color: "#3288EA"
        }

        Rectangle {
            id: thirdRowSecondCol
            width: 100
            height: 100

            color: "#3288EA"
        }

        Rectangle {
            id: thirdRowThirdCol
            width: 100
            height: 100

            color: "#3288EA"
        }

    }
}
