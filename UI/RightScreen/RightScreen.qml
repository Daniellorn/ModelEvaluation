import QtQuick 2.15

import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: rightScreen

    color: "#1a2226"

    property string model: ""

    anchors {
        top: topBar.bottom
        left: separator.right
        right: parent.right
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
                id: rightScroll

                Layout.fillWidth: true
                Layout.fillHeight: true

                anchors.fill: parent

                ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                ColumnLayout {
                    id: column1

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    spacing: 10

                    Layout.margins: 20

                    ConfusionMatrix_R {
                        id: confusionMatrix
                    }

                    Metrics_R {
                        id: metrics
                    }

                    ROCGraph_R {
                        id: roc
                    }

                }
            }
        }


        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ScrollView {
                id: rightScroll2

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

                    MetricsRegresion_R {
                        id: metricsRegresion
                    }

                }
            }
        }
    }

}
