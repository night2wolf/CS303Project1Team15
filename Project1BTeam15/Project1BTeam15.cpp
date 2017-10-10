// Project1BTeam15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include "Book.h"
#include "date.h"
#include "Library.h"
using namespace std;

/*Main cpp to execute functions. Written by Trevor Klinkenberg,
function calls copied from Project_1.pdf*/

int main()
{
	// This can be removed when done. just had it for initial compile test.
	cout << "hello world";
	//TODO: These Functions are what need to be called and implemented in the main:
	
	
	Library library;
	// 		Function to add Books to Library class
	// Adding Debug MSgs to screen
	cout << "adding Software Engineeing book";
	library.add_book("Software Engineering");
	cout << "adding Chemistry book";
	library.add_book("Chemistry");

	
	// Function to add Employees to Library class
	cout << "adding Employees";
	/*
	library.add_Employee("Adam");
	library.add_employee("Sam");
	library.add_employee("Ann");
	*/

	// Function Call to Library class
	cout << "Circulating Chemistry book";
	library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));
	cout << " Circulating software engineering book";
	library.circulate_book("Software Engineering", Date(2015, 3, 5, DateFormat::US));

	//Pass on Chemistry book
	cout << "passing chemistry book";
	library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));
	// Book should be archived with this call:
	library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US));

	// Software Engineering pass
	cout << "passing software engineering book";
	library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));
	
	


    return 0;
}

