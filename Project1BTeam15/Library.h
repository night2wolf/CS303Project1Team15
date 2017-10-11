#pragma once
#include <iostream>
#include "date.h"
#include "Book.h"
#include <queue>
#include <list>
#include "employee.h"
#include "employee_queue.h"
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
		book.set_start_date(Date(1977, 1, 1, DateFormat::US));
		book.set_circulation_end_date(Date(1977, 1, 1, DateFormat::US));		
		//Create list of book objects.
		booklist.push_back(book);
		booklist.front();
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
		
		// Find book and set it's start date of circulation.
		list<Book>::iterator it;
		for ((it)=booklist.begin(); (it)!=booklist.end(); (it)++)
		{
			if ((it)->get_name() == book)
			{				
				// Employee employee = (it)->find_priority(employeelist); // no point in this being here
				(it)->set_start_date(date); // set current start date of book
				return;
			}
			

		}
			throw std::exception("Book not found"); // If we can't find the book we end up here.
		
	}
	void pass_on (string book, Date date)
	{
		// Same as above. gotta find the book first.		
		list<Book>::iterator it; // Book list iterator
		list<Employee>::iterator em; // Employee list iterator
		for ((it) = booklist.begin(); (it) != booklist.end(); (it)++)
		{
			if ((it)->get_name() == book)
			{				
				 //Return Employee with highest priority.				
				Date begin = (it)->get_start_date(); // get the start date of the current book
				Date end = (it)->set_circulation_end_date(date); // set end date to pass to next employee
				int total = end - begin; //Total time book is in circulation.
				// set wait time and retain time for all employees in the list.
				for ((em) = employeelist.begin(); (em) != employeelist.end(); (em) ++)
				{
					Employee employee = (it)->find_priority(employeelist);
					if ((em)->get_name() == employee.get_name()) // find employee and set how long they held onto the book
					{
						(em)->set_retaining_time(total);
					}
					Employee pr;
					//Rebuild Current Employee cause dereferencing the pointer breaks things.
					pr.set_name((em)->get_name());
					pr.set_retaining_time((em)->get_retaining_time());
					pr.set_waiting_time((em)->get_waiting_time());
					if(employee.get_priority() == pr.get_priority()) // so we don't add wait time to the current holder.
					{							
						pr.set_waiting_time(pr.get_waiting_time());
					}
					else
					{
						pr.set_waiting_time(total);
					}
				}
			}
			
			/* Need some logic here for archiving the book....
			if (true )//Pass on employee list work here.
			{

			}
			else
			{
				(it)->set_archived(true); //archive that book
				archived.push_back(*it); //Add to archive list - Heads up this won't work. dereferencing an iterator is not pretty
				booklist.erase(it); // remove from booklist
			}
			*/
		}
		

		
	}


private:

};

