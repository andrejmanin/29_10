#ifndef LOGS_H
#define LOGS_H

#include <iostream>
#include "../file_core/file_core.h"

enum Colors {
    Black = 30,
    Red = 31,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan
};

class Logger {
    static FileSystem log_file;

    static void setColor(int textColor) {
        cout << "\033[" << textColor << "m";
    }
    static void resetColor() { cout << "\033[0m"; }
public:
    static void info(string data) {
        string logMsg = "[INFO] " + data;
        log_file.writeFile(logMsg.c_str());
        setColor(Green);
        std::cout << "[INFO]: " << data << std::endl;
        resetColor();
    }
    static void error(string data) {
        string logMsg = "[ERROR]: ";
        logMsg.append(data);
        log_file.writeFile(logMsg.c_str());
        setColor(Red);
        std::cout << "[ERROR]: " << data << std::endl;
        resetColor();
    }
    static void warn(string data) {
        string logMsg = "[WARN]: ";
        logMsg.append(data);
        log_file.writeFile(logMsg.c_str());
        setColor(Yellow);
        std::cout << "[WARN]: " << data << std::endl;
        resetColor();
    }
    static void debug(string data) {
        string logMsg = "[DEBUG]: ";
        logMsg.append(data);
        log_file.writeFile(logMsg.c_str());
        setColor(Cyan);
        std::cout << "[DEBUG]: " << data << std::endl;
        resetColor();
    }
};

#endif //LOGS_H
