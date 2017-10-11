#pragma once
#include <iostream>
#include "date.h"

using namespace std;

// Employee class(name, waiting time, and retaining time , Priority)

class  Employee
{
public:
	string get_name()
	{return name;}
	string set_name(string Name)
	{
		name = Name;
		return name;
	}
	int get_waiting_time()
	{return waiting_time;}
	int set_waiting_time(int Waiting_time)
	{
		waiting_time = Waiting_time;
		return waiting_time;
	}
	int get_retaining_time()
	{return retaining_time;}
	int set_retaining_time(int Retaining_time)
	{
		retaining_time = Retaining_time;
		return retaining_time;
	}
	int get_priority()
	{
		priority = waiting_time - retaining_time;
		return priority;
	}

private:
	string name;
	int waiting_time;
	int retaining_time;
	int priority;
};

