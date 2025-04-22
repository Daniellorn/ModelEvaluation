import QtQuick 2.15

import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: leftScreen

    color: "#1a2226"

    property string model: ""

    anchors {
        top: topBar.bottom
        left: parent.left
        right: separator.left
        bottom: parent.bottom
    }


    StackLayout {
        id: stack
        anchors.fill: parent
        currentIndex: model === "Klasyfikacyjny" ? 0 : 1


        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ScrollView {
                id: leftScroll

                Layout.fillWidth: true
                Layout.fillHeight: true

                anchors.fill: parent

                ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                ColumnLayout {
                    id: column1

                   // width: parent.width
                    spacing: 10

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Layout.margins: 20

                    ConfusionMatrix_L {
                        id: confusionMatrix
                    }

                    Metrics_L {
                        id: metrics
                    }

                    ROCGraph_L {
                        id: roc
                    }
                }
            }

        }


        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ScrollView {
                id: leftScroll2

                Layout.fillWidth: true
                Layout.fillHeight: true
                anchors.fill: parent

                ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                ColumnLayout {
                    id: column2

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 20

                    spacing: 10

                    MetricsRegresion_L {
                        id: metricsRegresion
                    }

                }
            }
        }



    }


}
