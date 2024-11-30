#include "QtUtils.h"
#include <QDir>
#include "CommandLineParser.h"


QApplication* createQApplication(int argc, char *argv[]) {
    CommandLineParser& parser = CommandLineParser::getInstance();
    bool runCode = parser.hasOption("runCode");

    QString pluginPath;
    if (runCode) {
        const char* vkpkgPath = std::getenv("VCPKG_HOME");
        if (vkpkgPath) {
#ifdef NDEBUG
            pluginPath = QDir(QString(vkpkgPath)).filePath("installed/x64-windows/Qt6/plugins/platforms");
#else
            pluginPath = QDir(QString(vkpkgPath)).filePath("installed/x64-windows/debug/Qt6/plugins/platforms");
#endif
        } else {
            return nullptr;
        }
    } else {
        QString executableDir = QCoreApplication::applicationDirPath();
        pluginPath = QDir(executableDir).absoluteFilePath("");
    }

    qputenv("QT_QPA_PLATFORM_PLUGIN_PATH", pluginPath.toUtf8());
    return new QApplication(argc, argv);
}