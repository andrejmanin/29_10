#include <cstring>
#include <iostream>
#include "loger/logs.h"
using namespace std;

FileSystem Logger::log_file("log.txt");

int main() {
    Logger::debug("debug");
    Logger::info("info");
    Logger::warn("warn");
    Logger::error("error");
    return 0;
}