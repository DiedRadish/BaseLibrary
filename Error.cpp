#include "Error.h"

#include<cstdio>

Error::Error(const char* tMsg): Msg(tMsg) {
}

const char* Error::GetMsg() const {
	return Msg;
}

void Report(const char* Msg, ReportType tType) {
	switch(tType) {
	case ReportType::Message:
		printf("%s\n", Msg);
		break;
	case ReportType::Warning:
		printf("Warning: %s\n", Msg);
		break;
	case ReportType::Error:
		throw Error(Msg);
		break;
	}
}