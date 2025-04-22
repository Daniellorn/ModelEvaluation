import QtQuick 2.15

import QtQuick.Layouts
import QtCharts

Item {
    width: rightScroll.width
    height: 400

    Layout.topMargin: 10
    Layout.leftMargin: 10
    Layout.rightMargin: 10

    ChartView {
            id: chartView
            //anchors.fill: parent
            //anchors.bottom: aucText.top

            width: parent.width
            height: parent.height

            // Ustawienia wykresu
            title: "Krzywa ROC"
            legend.visible: false
            antialiasing: true

            // Dodanie serii danych (FPR, TPR)
            LineSeries {
                    name: "Line"
                    XYPoint { x: 0; y: 0 }
                    XYPoint { x: 1.1; y: 2.1 }
                    XYPoint { x: 1.9; y: 3.3 }
                    XYPoint { x: 2.1; y: 2.1 }
                    XYPoint { x: 2.9; y: 4.9 }
                    XYPoint { x: 3.4; y: 3.0 }
                    XYPoint { x: 4.1; y: 3.3 }
                }
        }

}
