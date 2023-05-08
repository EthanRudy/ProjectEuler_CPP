#include <chrono>

enum unitOfTime {
	nanosecond,
	microsecond,
	millisecond,
	second
};

struct timer {
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;

	void start() {
		startTime = std::chrono::high_resolution_clock::now();
	}

	void end() {
		endTime = std::chrono::high_resolution_clock::now();
	}

	int duration(const unitOfTime& unit) {
		if (unit == 0) {
			return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		}
		else if (unit == 1) {
			return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
		}
		else if (unit == 2) {
			return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
		}
		return std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
	}
};
