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
			
			EmployeeQueue employeequeue = (it)->add_Employees(employeelist); //Create employee Queue for each book
			if ((it)->get_name() == book)
			{
				//Return Employee with highest priority.				
				Date begin = (it)->get_start_date(); // get the start date of the current book
				Date end = (it)->set_circulation_end_date(date); // set end date to pass to next employee
				int total = end - begin; //Total time book is in circulation.
				// set wait time and retain time for all employees in the list.
				while (end >= begin)
				{
					for ((em) = employeelist.begin(); (em) != employeelist.end(); (em)++)
					{
						Employee employee = (it)->find_priority(employeelist);
						if ((em)->get_name() == employee.get_name()) // find employee and add a day to how long they held the book
						{
							(em)->set_retaining_time(1 + (em)->get_retaining_time());
							Employee empl = employeequeue.front();
							if (empl.get_name() == employee.get_name()) // Make sure that employee is the front of queue
							{
								employeequeue.remove_queue(); //remove from queue.
							}
						}
						else
						{
							(em)->set_waiting_time(1 + (em)->get_waiting_time()); // Everyone else waits a day
						}

						if ((em)->get_priority() >= employee.get_priority()) // Re-evaluate if we need to give the book to someone else.
						{
							(em)->set_retaining_time(1 + (em)->get_retaining_time());
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
							archived.push_back(arch); //Add to archive list - Heads up this won't work. dereferencing an iterator is not pretty
							booklist.erase(it); // remove from booklist
						}
					}
						
					}
					begin.add_days(1);
				}
			}
		
		}		


private:

};

