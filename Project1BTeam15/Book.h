#pragma once
#include <iostream>
#include "date.h"
#include "employee_queue.h"
/*Library Class written by Trevor Klinkenberg
tkndf@mail.umkc.edu*/

using namespace std;
// (name, circulation start date, circulation end date, archived, and queue of employees)
class Book {
public:
	Employee find_priority(list<Employee> employeelist)
	{
		Employee employee = employeequeue.find_top_priority(employeelist);
		return employee;
	}
	string get_name() 
	{return Name;}
	string set_name(string name)
	{
	Name = name;
	return Name;
	}
	Date get_start_date()
	{return startdate;}
	Date set_start_date(Date date)
	{
		startdate = date;
	return startdate;
	}
	Date get_circulation_end_date()
	{return circulationenddate;}
	Date set_circulation_end_date(Date circulation_date)
	{
	circulationenddate = circulation_date;
	return circulationenddate;
	}
	bool get_archived()
	{return archived;}
	bool set_archived(bool Archived)
	{
		archived = Archived;
		return archived;
	}

private:
	string Name;
	Date startdate;
	Date circulationenddate;
	bool archived = false;
	EmployeeQueue employeequeue;
};
