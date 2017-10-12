#pragma once

#include <iostream>
#include <queue>
#include "employee.h"

using namespace std;
/*Queue to determine prority of Employees
Trevor Klinkenberg tkndf@mail.umkc.edu*/
queue<Employee> employeeQueue;
class EmployeeQueue
{
public:
	Employee find_top_priority(list<Employee> employeeList)
	{		
		Employee empl;
		list<Employee>::iterator it;
		
		for(it = employeeList.begin(); it != employeeList.end(); it++)
		{
			//Silly, but can't dereference the Pointer to the object so I had to rebuild it.
			empl.set_name((it)->get_name());
			empl.set_retaining_time((it)->get_retaining_time());
			empl.set_waiting_time((it)->get_waiting_time());
			// ^^ Just in case they are all 0 will return first member in the list.
			int top_priority = 0;
			int check_prioity  = (it)->get_priority();
			if (check_prioity > top_priority)
			{
				top_priority = check_prioity;
				empl.set_name((it)->get_name());
				empl.set_retaining_time((it)->get_retaining_time());
				empl.set_waiting_time((it)->get_waiting_time()); // Keep track of current employee
			}
		}
		return empl; //Return highest priority employee
	}
	// Front of queue
	Employee front()
	{
		Employee employee = employeeQueue.front();
		return employee;
	}
	//Back of queue
	Employee back()
	{
		Employee employee = employeeQueue.back();
		return employee;
	}
	//Is empty?
	bool empty()
	{
		bool empty = employeeQueue.empty();
		return empty;
	}
	// Add employee to employee queue
	void add_queue(Employee employee)
	{
		employeeQueue.push(employee);		
	}
	// Remove front of queue.
	void remove_queue()
	{
		/*if (!employeeQueue.empty())
		{
			
		}
		*/
		employeeQueue.pop();
		
	}

	EmployeeQueue();
	~EmployeeQueue();

private:
	
	
};

EmployeeQueue::EmployeeQueue()
{
}

EmployeeQueue::~EmployeeQueue()
{
}
