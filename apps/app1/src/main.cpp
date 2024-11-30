#include <QApplication>
#include <QDir>
#include <QPushButton>
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void performTask() {
    std::cout << "开始任务" << std::endl;
}

int main(int argc, char *argv[]) {
    bool runCode = false;
    po::options_description desc("");
    desc.add_options()
        ("runCode", "coding");
    try {
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
        if (vm.count("runCode")) {
            runCode = true;
        }
    } catch (std::exception& e) {
        return 1;
    }

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
            return 1;
        }
    } else {
        QString executableDir = QCoreApplication::applicationDirPath();
        pluginPath = QDir(executableDir).absoluteFilePath("");
    }

    qputenv("QT_QPA_PLATFORM_PLUGIN_PATH", pluginPath.toUtf8());
    QApplication app(argc, argv);
    
    QPushButton button("开始");
    QObject::connect(&button, &QPushButton::clicked, performTask);

    button.show();
    return app.exec();
}