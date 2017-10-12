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


	void circulate_book(string book, Date date)
	{

		// Find book and set it's start date of circulation.
		list<Book>::iterator it;
		for ((it) = booklist.begin(); (it) != booklist.end(); (it)++)
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
	void pass_on(string book, Date date)
	{
		// Same as above. gotta find the book first.		
		list<Book>::iterator it; // Book list iterator
		list<Employee>::iterator em; // Employee list iterator
		for ((it) = booklist.begin(); (it) != booklist.end(); (it)++)
		{

			EmployeeQueue employeequeue = (it)->add_Employees(employeelist); //Create employee Queue for each book
			if ((it)->get_name() == book)
			{
			
				Date begin = (it)->get_start_date(); // get the start date of the current book
				Date end = (it)->set_circulation_end_date(date); // set end date to pass to next employee

				// set wait time and retain time for all employees in the list.
				while (end >= begin)
				{
					Employee employee = (it)->find_priority(employeelist);
					// This section needs to be fixed.
					// Cycle through employee list.
					for ((em) = employeelist.begin(); (em) != employeelist.end(); (em)++)
					{
						//Rebuild the current employee object for manipulation.
						Employee build;
						build.set_name((em)->get_name());
						build.set_prirority((em)->get_priority());
						build.set_waiting_time((em)->get_waiting_time());
						build.set_retaining_time((em)->get_waiting_time());
						if (build.get_name() == employee.get_name()) // Find employee and remove from queue now that they have book.
						{
							employeequeue.remove_queue();//remove from queue.
							(em)->set_retaining_time(1 + employee.get_retaining_time());
							
						}
						else
						{
							(em)->set_waiting_time(1 + (em)->get_waiting_time()); // Everyone else waits a day
						}
						
						
					}
					// If we get to the end of the employee list before the last day, archive the book
					if (employeequeue.empty() == true)
					{
						(it)->set_archived(true);
						Book arch;
						arch.set_name((it)->get_name());
						arch.set_circulation_end_date((it)->get_circulation_end_date());
						arch.set_start_date((it)->get_start_date());
						arch.set_archived((it)->get_archived());
						archived.push_back(arch); //Add to archive list
						booklist.erase((it)); // remove from booklist
						return;
					}
					begin.add_days(1);
				}

				if ((it)->get_archived() == false) //  If the book didn't get archived set a new date.
				{
					Book circulate;
					circulate.set_name((it)->get_name());
					circulate.set_start_date((it)->get_circulation_end_date());
					circulate.set_archived((it)->get_archived()); // Set to new start date.
					booklist.push_back(circulate); //Put this book in list with new start date
					booklist.erase((it)); // remove original.
				}
			}

		}

	}


private:

};

