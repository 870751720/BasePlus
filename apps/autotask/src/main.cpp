#include <QApplication>
#include <QPushButton>
#include "CommandLineParser.h"
#include "QtUtils.h"


int main(int argc, char *argv[]) {
    CommandLineParser& parser = CommandLineParser::getInstance();
    parser.addOption("runCode", "coding");
    if (!parser.parse(argc, argv)) {
        return 1;
    }

    QApplication* app = createQApplication(argc, argv);
    
    QPushButton button("开始");

    button.show();
    return app->exec();
}