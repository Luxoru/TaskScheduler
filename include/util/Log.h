#pragma once
#include <format>
#include <iostream>


// C++20 LOG macro with std::format
#define LOG(fmt, ...) std::cout << std::format(fmt __VA_OPT__(,) __VA_ARGS__) << std::endl;
