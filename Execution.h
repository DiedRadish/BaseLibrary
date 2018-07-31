#pragma once

#include<functional>

#include"Macro.h"

SPACE_BEGIN
template<class Func>
class Execution {
public:
	Execution(std::function<Func> tFunc) {
		tFunc();
	}
	~Execution() = default;
private:
	Execution() = delete;
	Execution(const Execution&) = delete;
	Execution& operator=(const Execution&) = delete;
};
SPACE_END

#define SPACE_EXECUTION(FUNC, NAME) static Space::Execution<FUNC> SPACE_EXECUTION_FUNC_##NAME
