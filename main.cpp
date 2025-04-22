#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("ZadanieProgramistyczneED", "Main");

    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
