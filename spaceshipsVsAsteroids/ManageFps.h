#pragma once
#include <chrono>

class ManageFps
{
	std::chrono::system_clock::time_point tStart_;

public:
	ManageFps() :
		tStart_(std::chrono::high_resolution_clock::now())
	{}

	int inline getCurrentTime() const{
		std::chrono::system_clock::time_point tNow = std::chrono::high_resolution_clock::now();
		return std::chrono::duration_cast<std::chrono::milliseconds>(tNow - tStart_).count();
	}

	void inline resetChrono(){
		tStart_ = std::chrono::high_resolution_clock::now();
	}
};