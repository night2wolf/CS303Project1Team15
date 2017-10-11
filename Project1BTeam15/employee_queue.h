#pragma once

#include <iostream>
#include <queue>
#include "employee.h"

using namespace std;


class EmployeeQueue
{
public:
	Employee find_top_priority(list<Employee> employeeList)
	{		
		list<Employee>::iterator it;
		Employee empl;
		; // Just in case they are all 0 will return first member in the list.
		for(it = employeeList.begin(); it != employeeList.end(); it++)
		{
			//Silly, but can't dereference the Pointer to the object so I had to rebuild it.
			empl.set_name((it)->get_name());
			empl.set_retaining_time((it)->get_retaining_time());
			empl.set_waiting_time((it)->get_waiting_time());
			int top_priority = 0;
			int check_prioity  = (it)->get_priority();
			if (check_prioity > top_priority)
			{
				top_priority = check_prioity;
				empl.get_name() = (it)->get_name();
				empl.set_retaining_time((it)->get_retaining_time());
				empl.set_waiting_time((it)->get_waiting_time()); // Keep track of current employee
			}
		}
		return empl; //Return highest priority employee
	}


	EmployeeQueue();
	~EmployeeQueue();

private:
	queue<Employee> employeeQueue;
	
};

EmployeeQueue::EmployeeQueue()
{
}

EmployeeQueue::~EmployeeQueue()
{
}
