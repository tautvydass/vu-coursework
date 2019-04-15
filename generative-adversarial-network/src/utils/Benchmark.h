#pragma once

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
typedef void(*delegate)();

class Benchmark
{
public:
	static void run(delegate function, const size_t& iterationCount, const char* message)
	{
		auto begin = Clock::now();
		for (size_t i = 0; i < iterationCount; i++)
		{
			function();
		}
		auto end = Clock::now();
		auto miliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		std::cout << message << ": total time elapsed " << miliseconds << "ms" << std::endl;
		std::cout << message << ": average iteration length " << miliseconds / iterationCount << "ms" << std::endl;
	}
};