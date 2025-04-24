import QtQuick 2.15

import QtQuick.Layouts
import QtCharts

Item {
    width: leftScroll.width
    height: 600

    Layout.topMargin: 10
    Layout.leftMargin: 10
    Layout.rightMargin: 10

    ChartView {
            id: chartView
            width: parent.width
            height: parent.height

            // Ustawienia wykresu
            title: "Krzywa ROC"
            legend.visible: true
            antialiasing: true

            axes: [
                ValuesAxis {
                    id: axisX
                    min: 0
                    max: 1
                    titleText: "1 - specyficznosc"
                },
                ValuesAxis {
                    id: axisY
                    min: 0
                    max: 1
                    titleText: "czułość"
                }

            ]

            LineSeries {

                    id: rocSeries
                    name: "ROC Curve"
                    color: "blue"

                    axisX: axisX
                    axisY: axisY

                    Connections {

                        target: modelAnalysis

                        onRocPointsReady: {
                            var points = modelAnalysis.getROCPoints();

                            for (var i = 0; i < points.length; i++)
                            {
                                var point = points[i];
                                rocSeries.append(point.x, point.y);
                            }
                        }
                    }

                }

            LineSeries {
                id: refLine
                name: "refLine"
                color: "green"
                axisX: axisX
                axisY: axisY

                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1; y: 1 }
            }
        }




}
