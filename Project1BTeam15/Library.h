#pragma once
#include <iostream>
#include "date.h"
#include "Book.h"
#include <queue>
#include <list>>

using namespace std;
/*Library Class written by Trevor Klinkenberg
tkndf@mail.umkc.edu*/
list<Book> booklist;
//TODO: Need Employee class for this.
// list<Employee> employeelist;
class Library
{
public:
	Book add_book(string bookname)
	{
		
		Book book;
		book.set_name(bookname);
		book.set_start_date(Date(1, 1, 1, DateFormat::US));
		book.set_circulation_end_date(Date(1, 1, 1, DateFormat::US));
		booklist.push_back(book);
		return book;
	}
	/*
	// TODO: Need Employee class for this
	string add_employee(string employeename)
	{
		//Employee employee
		//employee.set_name = employeename
		//
		//
		//return employee
	}
	*/
	void circulate_book(string book, Date date )
	{
		//TODO: Need a way to look up a book object by string.


		//TODO: use add_days function in date class



		// The below Push pop taken from lecture notes for implementing a queue with a linked list.
		/*
		void push(const Book& books) 
		{

			if (front_of_queue == NULL) {
				back_of_queue = new Node(item, NULL);
				front_of_queue = back_of_queue;
			}
			else {
				back_of_queue->next = new Node(item, NULL);
				back_of_queue = back_of_queue->next;
			}
			num_items++;
		}
		void pop() {
			Node* old_front = front_of_queue;
			front_of_queue = front_of_queue->next;

			if (front_of_queue == NULL) {
				back_of_queue = NULL;
			}

			delete old_front;
			num_items--;
		}
		*/
		
		
	}
	void pass_on (string book, Date date)
	{
		//add_days function in date class
		//This should be emplyoyee list when employee class is created...
		if (booklist.empty())
		{
			Book front_book = booklist.front();
				front_book.set_archived(true);
		}
	}


private:

};

