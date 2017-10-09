#pragma once
#include <iostream>
#include "date.h"
#include "Book.h"
#include <queue>
using namespace std;


class Library
{
public:
	Book add_book(string bookname)
	{
		Book book;
		book.set_name(bookname);
		book.set_start_date(Date(1977, 1, 1, DateFormat::US));
		book.set_circulation_end_date(Date(1977, 1, 1, DateFormat::US));
		return book;
	}
	string add_employee(string employeename)
	{
		//Employee employee
		//employee.set_name = employeename
		//
		//
		//return employee
	}
	void circulate_book(string book, Date date )
	{
		//Need a way to look up a book object by string.
	}
	void pass_on (string book, Date date)
	{}


private:

};

