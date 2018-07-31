#pragma once

#include<map>
#include<string>
#include<functional>

#include"Macro.h"

SPACE_BEGIN
class Reflection {
public:
	Reflection() = default;
	~Reflection() = default;
public:
	using CreateFunc = std::function<void*()>;
protected:
	static std::map<std::string, CreateFunc> Classes;

public:
	static void AddClass(std::string tName, CreateFunc tCreateFunc) {
		Classes[tName] = tCreateFunc;
	}

	template<class T>
	static T* CreateClass() {
		std::string Name = T::GetName();
		return (T*)Classes[Name]();
	}
	template<class T>
	static T* CreateClass(std::string tClass) {
		return (T*)Classes[tClass]();
	}
};
std::map<std::string, Reflection::CreateFunc> Reflection::Classes;
SPACE_END

#define SPACE_CREATE(CLASS) \
public: \
	static CLASS* Create() { \
		return new CLASS(); \
	}

#define SPACE_REFLECTION_CREATE(CLASS) \
	SPACE_CREATE(CLASS); \
public: \
	static void* ReflectionCreate() { \
		return (void*)Create(); \
	}

#define SPACE_REFLECTION_GETNAME(CLASS) \
public: \
	static std::string GetName() { \
		return std::string(#CLASS); \
	}

//public
#define SPACE_REFLECTION_CLASS(CLASS) \
SPACE_REFLECTION_CREATE(CLASS) \
SPACE_REFLECTION_GETNAME(CLASS) \
protected: \
	static const Execution<void()> ReflectionFunc;
#define SPACE_REFLECTION() public Space::Reflection
#define SPACE_REFLECTION_CLASS_DEFINE(CLASS) const Space::Execution<void()> Space::CLASS::ReflectionFunc {[](){Space::Reflection::AddClass(#CLASS,std::bind(&Space::CLASS::ReflectionCreate));}}; \