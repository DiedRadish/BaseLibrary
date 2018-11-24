#include "Parser.h"

#include<vector>
#include<iostream>

#include"Error.h"

Parser::Parser(Command tCmd, Document tDoc):Cmd(tCmd), Doc(tDoc) {
}

void Parser::Lexer() {
	std::size_t pos = 0;
	for(; pos < Doc.Size();) {
		Word tWord;

		switch(Doc[pos]) {
		case ' ':
			for(pos++; pos < Doc.Size() && Doc[pos] == ' '; pos++) {
			}
			break;
		case '/':
			tWord.Type = Word::WordType::Module;
			for(pos++; pos < Doc.Size() && Doc[pos] != ' '; pos++) {
				tWord.Text += Doc[pos];
			}
			Words.push_back(tWord);
			break;
		case '-':
			tWord.Type = Word::WordType::Arg;
			for(pos++; pos < Doc.Size() && Doc[pos] != ' '; pos++) {
				tWord.Text += Doc[pos];
			}
			Words.push_back(tWord);
			break;
		case '\"':
			tWord.Type = Word::WordType::Value;
			for(pos++; pos < Doc.Size() && Doc[pos] != '\"'; pos++) {
				tWord.Text += Doc[pos];
			}
			pos++;
			Words.push_back(tWord);
			break;
		default:
			tWord.Type = Word::WordType::Value;
			for(; pos < Doc.Size() && Doc[pos] != ' '; pos++) {
				tWord.Text += Doc[pos];
			}
			Words.push_back(tWord);
			break;
		}
	}
}

void Parser::Syntax() {
	std::size_t pos = 0;
	if(Words.size() < 1 || Words[0].Type != Word::WordType::Module) {
		Report("Module Name.", ReportType::Error);
	}
}

void Parser::Parse() {
	Lexer();
	Syntax();
}