import QtQuick 2.15
import CSVReader
import ModelAnalysis

import QtQuick.Layouts
import QtQuick.Controls


Rectangle {
    id: topBar

    anchors {
        top: parent.top
        right: parent.right
        left: parent.left
    }

    color: "#1a2226"
    height: parent.height * 1/6

    signal comboBox1CurrentTextChanged(string selectedModel)

    RowLayout {

        anchors.fill: parent
        spacing: 20

        anchors.topMargin: 10
        anchors.bottomMargin: 10
        anchors.leftMargin: 100
        anchors.rightMargin: 100

        Text {
            text: "Ocena\nmodelu"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 32
            color: "white"
        }

        Column {

            spacing: 5

            topPadding: 15

            Text {
                text: "Nazwa pliku"
                font.pixelSize: 18
                color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
            }

            TextField {

                id: fileNameField
                width: 200
                height: 25
                anchors.horizontalCenter: parent.horizontalCenter

                leftPadding: 5
                topPadding: 5
                bottomPadding: 5

                placeholderText: qsTr("Podaj nazwę pliku")
            }

            Button {
                text: "Wczytaj"
                anchors.horizontalCenter: parent.horizontalCenter

                height: 25
                width: 100

                onClicked: {
                    csvReader.loadFileSlot("Data/" + fileNameField.text + ".csv")
                }
            }
        }

        Column {

            spacing: 5

            bottomPadding: 15

            Text {
                text: "Wybór modelu"
                font.pixelSize: 18
                color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
            }

            ComboBox {
                id: comboBox1
                width: 200
                height: 25
                anchors.horizontalCenter: parent.horizontalCenter


                leftPadding: 5
                topPadding: 5
                bottomPadding: 5

                model:  ListModel {
                    ListElement { value: "Klasyfikacyjny" }
                    ListElement { value: "Regresyjny" }
                    }

                textRole: "value"
                Component.onCompleted: {
                    comboBox1.currentIndex = 0
                }

                onCurrentTextChanged: {
                    topBar.comboBox1CurrentTextChanged(comboBox1.currentText)
                }

            }
        }


        Button {
            id: button1
            text: "Oceń model"

            Layout.preferredHeight: 25
            Layout.preferredWidth: 100
            Layout.topMargin: 15

            onClicked: {
                modelAnalysis.calculate()
            }
        }

    }

}
