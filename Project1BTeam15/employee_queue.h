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
		Employee employee = (*it); // Just in case they are all 0 will return first member in the list.
		for(it = employeeList.begin(); it != employeeList.end(); it++)
		{
			
			int top_priority = 0;
			int check_prioity  = (it)->get_priority();
			if (check_prioity > top_priority)
			{
				top_priority = check_prioity;
				 employee = (*it); // Keep track of current employee
			}
		}
		return employee; //Return highest priority employee
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
