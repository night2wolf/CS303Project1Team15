#pragma once
#include <iostream>
#include "date.h"
#include "Book.h"
#include <queue>
#include <list>
#include "employee.h"

using namespace std;
/*Library Class written by Trevor Klinkenberg
tkndf@mail.umkc.edu*/
list<Book> booklist;
list<Employee> employeelist;
list<Book> archived;

class Library
{
public:
	Book add_book(string bookname)
	{
		
		Book book;
		book.set_name(bookname);
		book.set_start_date(Date(1, 1, 1, DateFormat::US));
		book.set_circulation_end_date(Date(1, 1, 1, DateFormat::US));
		//Create list of book objects.
		booklist.push_back(book);
		return book;
	}
	
	Employee add_employee(string employeename)
	{
		Employee employee;
		employee.set_name(employeename);
		employee.set_waiting_time(0);
		employee.set_retaining_time(0);
		// Create list of employee objects		
		employeelist.push_back(employee);
		return employee;
	}
	
	void circulate_book(string book, Date date )
	{
		
		// look up a book object by string.
		list<Book>::iterator it;
		for (it=booklist.begin(); it!=booklist.end(); it++)
		{
			if (it->get_name() == book)
			{
				it->set_archived(false); // TODO; fix this later this should be the "give employee in queue book" function.
				it->set_start_date(date); // set current start date of book
			}
			else
			{
				throw exception::exception("Book not found");
			}

		}
		//TODO: use add_days function in date class

		


		
		
	}
	void pass_on (string book, Date date)
	{
		// look up a book object by string.
		list<Book>::iterator it;
		for (it = booklist.begin(); it != booklist.end(); it++)
		{
			if (it->get_name() == book)
			{
				it->set_archived(false); // TODO; fix this later this should be the "give employee in queue book" function.
				Date begin = it->get_start_date(); // get the start date of the current book
				Date end = it->set_circulation_end_date(date); // set end date to pass to next employee
				int total = end - begin;
			}
			else
			{
				throw exception::exception("Book not found");
			}
			if (true )//Pass on employee list work here.
			{

			}
			else
			{
				it->set_archived(true); //archive that book
				archived.push_back(*it); //Add to archive list
				booklist.remove(*it); // remove from booklist
			}

		}
		//add_days function in date class
		// Implement the below in some form to archive a book.

		
	}


private:

};

