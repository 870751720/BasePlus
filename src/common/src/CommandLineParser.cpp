#include "CommandLineParser.h"

CommandLineParser::CommandLineParser() : desc("Allowed options") {}

CommandLineParser& CommandLineParser::getInstance() {
    static CommandLineParser instance;
    return instance;
}

void CommandLineParser::addOption(const std::string& name, const std::string& description) {
    desc.add_options()(name.c_str(), description.c_str());
}

bool CommandLineParser::parse(int argc, char* argv[]) {
    try {
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);
        return true;
    } catch (std::exception& e) {
        return false;
    }
}

bool CommandLineParser::hasOption(const std::string& name) const {
    return vm.count(name) > 0;
}
