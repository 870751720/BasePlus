#ifndef COMMAND_LINE_PARSER_H
#define COMMAND_LINE_PARSER_H

#include <boost/program_options.hpp>
#include <string>
#include <vector>


class CommandLineParser {
public:
    static CommandLineParser& getInstance();
    void addOption(const std::string& name, const std::string& description);
    bool parse(int argc, char* argv[]);
    bool hasOption(const std::string& name) const;

private:
    CommandLineParser();
    CommandLineParser(const CommandLineParser&) = delete;
    CommandLineParser& operator=(const CommandLineParser&) = delete;

    boost::program_options::options_description desc;
    boost::program_options::variables_map vm;
};

#endif // COMMAND_LINE_PARSER_H