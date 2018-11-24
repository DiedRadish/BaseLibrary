#pragma once

#include"Document.h"
#include"Command.h"

class Parser {
private:
	Command Cmd;
	Document Doc;
private:
	std::vector<Word> Words;

public:
	Parser(Command tCmd, Document tDoc);
	~Parser() = default;
private:
	void Lexer();
	void Syntax();
	void Check();
	void Parse();
};

class Word {
public:
	enum class WordType {
		Module,
		Arg,
		Value
	};
public:
	std::string Text;
	WordType Type;
};