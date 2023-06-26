#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Timer.hpp"

// May create a template with a sorting algorithm file
void swap(std::string* a, std::string* b);

int partition(std::string arr[], int low, int high);

void quickSort(std::string arr[], int low, int high);

int wordValue(std::string str, int n);

int main() {
	timer timer;
	timer.start();

	std::ifstream file("p022.txt");
	std::string word, name, temp;
	while (file >> word) {
		name = word;
	}

	std::string arr[5163];
	std::stringstream ss(name);
	
	int count = 0;
	while (std::getline(ss, temp, ',')) {
		arr[count] = temp.substr(1, temp.size() - 2);
		++count;
	}

	quickSort(arr, 0, 5162);
	int sum = 0;
	for (int i = 0; i < 5163; ++i) {
		sum += wordValue(arr[i], i + 1);
	}

	timer.end();

	std::cout << "Answer: " << sum << "\n";
	std::cout << "Found in: " << timer.duration(millisecond) << " milliseconds\n";

	// ~34 milliseconds
}

void swap(std::string* a, std::string* b) {
	std::string t = *a;
	*a = *b;
	*b = t;
}

int partition(std::string arr[], int low, int high) {
	std::string piv = arr[high];
	int i = low - 1;
	for (int j = low; j < high; ++j) {
		if (arr[j] <= piv) {
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(std::string arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int wordValue(std::string str, int n) {
	int val = 0;

	for (int i = 0; i < str.size(); ++i) {
		char temp = str.at(i);
		val += (int)temp - 64;
	}
	val *= n;

	return val;
}
