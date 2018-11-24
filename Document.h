#pragma once

#include<string>

class Document {
public:
	using Ptr = std::string::iterator;
	using Ref = char&;
private:
	std::string Text;

public:
	Document(std::string& s);
	~Document() = default;
public:
	const Ref operator[](std::size_t i);
	const Ref At(std::size_t i);
	const Ptr Begin();
	const Ptr End();
	std::size_t Size();
};