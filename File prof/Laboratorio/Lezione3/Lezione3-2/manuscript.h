#include <iostream>
#include "printable.h"

using namespace std;

//#pragma once
#ifndef MANUSCRIPT_H
#define MANUSCRIPT_H
// classe derivata da Printable
class Manuscript : public Printable
{
private:
	string author;
	string title;

public:
	 Manuscript(string author, string title) : author{ author }, title{ title } {}
     
	 /*
	 * Deafult constructor
	 */
	 //Book() : author{ "" }, title{ "" } {}; 
	 Manuscript() = default; //default constructor
	 
   	
	/*
	*  Override the default destructor
	*/
	~Manuscript() { cout << "object destructed" << endl; }

	string getAuthor() const 
	{
		return this->author;
	}

	string getTitle() const 
	{
		return this->title;
	}

	void setAuthor(const string author)
	{
		this->author = author;
	}

	void setTitle(const string title)
	{
		this->title = title;
	}	

	// override della funzione definita nella classe base "printable"
	string getLabel() const override
	{
		return "Author: " + this->getAuthor() + ". Title: " + this->getTitle() + ". ";
	}
	
	//== operator overloading (deve avere un solo argomento)
	bool operator==(const Manuscript& r) const
	{		
		return (r.getAuthor() == this->getAuthor() && r.getTitle() == this->getTitle());
	}
	
	//>
	bool operator>(const Manuscript& r) const
	{
		return this->getTitle() > r.getTitle();
	}

	//<< overloading (deve essere friend per accedere ai membri privati della classe)
	friend ostream& operator<<(ostream& os, const Manuscript& m)
	{
		os << m.getLabel();
		return os;
	}


	/*
     *  Override the default copy constructor

     Manuscript(const Manuscript& manu) : author{ "Copied " + manu.author }, title{ "Copied " + manu.title} {}

     *  Override the default move constructor

     Manuscript(Manuscript&& manu) : author{ "Move Source Author" + manu.author }, title{ "Moved Source Title" + manu.title } {}
    */

	/*
	//operators copy and move constructor overloading
	Manuscript& operator=(const Manuscript&) 
	{
		//do copy
		return *this; 
	}
	Manuscript& operator=(Manuscript&&) 
	{ 
		//do move
		return *this;
	}
	*/
};

#endif


