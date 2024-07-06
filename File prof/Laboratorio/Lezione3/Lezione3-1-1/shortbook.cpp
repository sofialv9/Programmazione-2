// Implementazione metodi della classe

#include <iostream>
#include "shortbook.h"

using namespace std;

ShortBook::ShortBook(string title, string author) : title{ title }, author{ author } {}
string ShortBook::getTitle() const { return title; }
string ShortBook::getAuthor() const { return author; }