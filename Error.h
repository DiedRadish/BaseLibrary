#pragma once

#include<exception>

class Error {
private:
	const char* Msg;

public:
	Error(const char* tMsg);
	const char* GetMsg() const;
};

enum class ReportType {
	Message,
	Warning,
	Error
};

void Report(const char* Msg, ReportType tType = ReportType::Message);