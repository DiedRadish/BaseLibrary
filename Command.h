#pragma once

#include<vector>
#include<map>
#include<string>
#include<cstdint>

class Limit {
};

class Arg {
public:
	std::vector<std::string> Values;
	std::vector<Limit> Limits;
};

class Module {
public:
	std::map<std::string, Arg> Args;
};

class Command {
public:
	std::string Name;
	std::map<std::string, Module> Modules;
};
