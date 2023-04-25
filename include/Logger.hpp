#pragma once
// Standard Library Includes
#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <typeinfo>

#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

namespace Logger {
    template <typename T>
    static void Notify(T t) { std::clog << ANSI_BLUE << t << ANSI_RESET << std::endl; }
    template <typename T, typename... Args>
    static void Notify(T t, Args... args) { std::clog << ANSI_BLUE << t << ANSI_RESET << " "; Notify(args...); }

    template <typename T>
    static void Inform(T t) { std::clog << ANSI_CYAN << t << ANSI_RESET << std::endl; }
    template <typename T, typename... Args>
    static void Inform(T t, Args... args) { std::clog << ANSI_CYAN << t << ANSI_RESET << " "; Inform(args...); }

    template <typename T>
    static void Warn(T t) { std::clog << ANSI_YELLOW << t << ANSI_RESET << std::endl; }
    template <typename T, typename... Args>
    static void Warn(T t, Args... args) { std::clog << ANSI_YELLOW << t << ANSI_RESET << " "; Warn(args...); }

    template <typename T>
    static void Error(T t) { std::clog << ANSI_RED << t << ANSI_RESET << std::endl; exit(1); }
    template <typename T, typename... Args>
    static void Error(T t, Args... args) { std::clog << ANSI_RED << t << ANSI_RESET << " "; Error(args...);}
};