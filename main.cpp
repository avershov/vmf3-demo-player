#include <QApplication>
#include <QQmlApplicationEngine>

#include <QmlVlc.h>
#include <QmlVlc/QmlVlcConfig.h>

#include <QtWebEngine/qtwebengineglobal.h>

int main(int argc, char *argv[])
{
    RegisterQmlVlc();
    QmlVlcConfig& config = QmlVlcConfig::instance();
    //config.enableDebug( true );

    QApplication app(argc, argv);

    QtWebEngine::initialize();

    QQmlApplicationEngine engine;

    //this code has no visible effect
//    engine.addImportPath(QStringLiteral(":/imports"));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //everything works fine w/o that code
//    QObject::connect(&engine, SIGNAL(quit()), qApp, SLOT(quit()));

    //this code was used to call init function from QML file
    //obviously it should be changed
    //"parameters" were taken from comand line, can be empty
//    QObject *item = engine.rootObjects().first();
//    Q_ASSERT(item);
//    QMetaObject::invokeMethod(item, "initializeProviders",
//                              Q_ARG(QVariant, QVariant::fromValue(parameters)));

    return app.exec();
}

