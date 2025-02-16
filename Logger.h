//
// Created by julian on 4/18/24.
//

#ifndef SIM_CPP_LOGGER_H
#define SIM_CPP_LOGGER_H
#include <vector>
#include <string>

class Logger {
public:
    Logger& operator << (const std::string& log);
    Logger& operator << (int val);
    std::string eol();
    std::vector<std::string> getLogs() const;
    Logger &newLog(int turn);
    void clearLogs();
    void printLogs(std::ostream &os);
    void printLogs(std::ostream &os, int n);
    void printCurrentLog(std::ostream &os);

private:
    std::vector<std::string> logs;
    std::string current_log;
};


#endif //SIM_CPP_LOGGER_H
