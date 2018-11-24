#include "Document.h"

Document::Document(std::string& s) {
	Text = s;
}

const Document::Ref Document::operator[](std::size_t i) {
	return At(i);
}

const Document::Ref Document::At(std::size_t i) {
	return Text[i];
}

const Document::Ptr Document::Begin() {
	return Text.begin();
}

const Document::Ptr Document::End() {
	return Text.end();
}

std::size_t Document::Size() {
	return Text.size();
}