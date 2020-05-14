#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class MyException : public runtime_error {
private:
	const char* message;
public:
	MyException(const char* msg) : runtime_error(msg), message(msg) {
	}

	const char* what() {
		return message;
	}
};