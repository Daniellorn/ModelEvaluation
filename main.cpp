#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Backend/Csvreader.h"
#include "Backend/modelanalysis.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    CSVReader reader;

    qmlRegisterType<CSVReader>("CSVReader", 1, 0, "CSVReader");

    qmlRegisterType<ModelAnalysis>("ModelAnalysis", 1, 0, "ModelAnalysis");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("csvReader", &reader);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    ModelAnalysis analysis(nullptr, {});

    engine.rootContext()->setContextProperty("modelAnalysis", &analysis);


    engine.loadFromModule("ZadanieProgramistyczneED", "Main");

    QObject::connect(&reader, &CSVReader::fileLoaded,
                     [&analysis](std::vector<DataRow>& data)
                     {
                         analysis.SetData(data);
    });




    return app.exec();
}
