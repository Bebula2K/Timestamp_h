/*

[+]======INFO======[+]
Timestamp.h
Created Aug 2, 2023
Copyright Bebula Games
[+]================[+]

[+]=====PURPOSE=====[+]

Creates a timestamp at the start of a newline.
File built for linux. Windows cannot understand this file (wtf).

[+]=================+]

[+]===IMPLEMENTATION=====[+]

In Main.cpp

    Timestamp timestamp;
    while(true){
        std::string currentTime = timestamp.getCurrentTime();
        std::cout << "[" << currentTime << "] > ";
    }

[+]======================[+]

*/

#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <thread>
#include <chrono>
#include <ctime>
#include <string>

class Timestamp{
    public:
    std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    struct std::tm timeInfo;
    localtime_r(&time, &timeInfo);
    char buffer[9];
    strftime(buffer, sizeof(buffer), "%T", &timeInfo);
    return std::string(buffer);
}
};

#endif