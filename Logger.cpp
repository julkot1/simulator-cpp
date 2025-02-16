//
// Created by julian on 4/18/24.
//

#include "Logger.h"

Logger& Logger::operator<<(const std::string& log) {
    current_log.append(log);
    return *this;
}

std::string Logger::eol() {
    current_log.append("\n");
    logs.push_back(current_log);
    current_log = "";
    return "";
}

Logger &Logger::operator<<(const int val) {
    current_log.append(std::to_string(val));
    return *this;
}

std::vector<std::string> Logger::getLogs() const {
    return logs;
}

void Logger::clearLogs() {
    logs.clear();
}

void Logger::printLogs(std::ostream &os) {
    for(const auto& log : logs){
        os << log;
    }
}

void Logger::printLogs(std::ostream &os, int n) {
    for(int i = 0; i < n; i++){
        os << logs[i];
    }

}

void Logger::printCurrentLog(std::ostream &os) {
    if(!logs.empty()){
        os << logs.back();
    }
}

Logger &Logger::newLog(int turn) {
    current_log = "[Turn: " + std::to_string(turn) + "]: ";
    return *this;
}




