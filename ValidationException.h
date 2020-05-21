#pragma once
#include <exception>
#include <string.h>
#include <string>

using namespace std;

class ValidationException : public exception {
private:
	string message;
public:
	ValidationException(string message)
	{
		this->message = message;
	}

	~ValidationException()
	{
	}

	virtual string what()
	{
		return this->message;
	}

	virtual void addMessage(string message) {
		this->message += message;
	}
};