#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Backend/Csvreader.h"
#include "Backend/modelanalysis.h"
#include "Backend/modelanalysisv2.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    CSVReader reader;

    qmlRegisterType<CSVReader>("CSVReader", 1, 0, "CSVReader");

    qmlRegisterType<ModelAnalysis>("ModelAnalysis", 1, 0, "ModelAnalysis");
    qmlRegisterType<ModelAnalysisV2>("ModelAnalysis2", 1, 0, "ModelAnalysis2");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("csvReader", &reader);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    ModelAnalysis analysis(nullptr, {});
    ModelAnalysisV2 analysisV2(nullptr, {});

    engine.rootContext()->setContextProperty("modelAnalysis", &analysis);
    engine.rootContext()->setContextProperty("modelAnalysis2", &analysisV2);

    engine.loadFromModule("ZadanieProgramistyczneED", "Main");

    QObject::connect(&reader, &CSVReader::fileLoaded,
                     [&analysis](std::vector<DataRow>& data)
                     {
                         analysis.SetData(data);
    });


    QObject::connect(&reader, &CSVReader::fileLoaded2,
                     [&analysisV2](std::vector<DataRow2>& data)
                     {
                         analysisV2.SetData(data);
                     });



    return app.exec();
}
