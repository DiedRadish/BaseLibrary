#pragma once

#include"Macro.h"

#define SPACE_SINGLETON_CLASS(CLASS) \
public: \
	static CLASS* Get() { \
		static CLASS t; \
		return &t; \
	} \
private: \
	CLASS() = default; \
	~CLASS() = default; \
	CLASS(const CLASS&) = delete; \
	CLASS& operator=(const CLASS&) = delete;

#define SPACE_SINGLETON_GET(CLASS) Space::CLASS::Get()->