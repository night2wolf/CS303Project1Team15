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
	Library library;
	// 		Function to add Books to Library class
	// Adding Debug MSgs to screen
	//cout << "adding Software Engineeing book /n";
	library.add_book("Software Engineering");
	//cout << "adding Chemistry book";
	library.add_book("Chemistry");


	// Function to add Employees to Library class
	//cout << "adding Employees /n";

	library.add_employee("Adam");
	library.add_employee("Sam");
	library.add_employee("Ann");


	// Now that the Employee and Book list are populated They can be iterated and Cycled through.

	// Function Call to Library class
	//cout << "Circulating Chemistry book /n";
	library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));
	//cout << "Circulating software engineering book /n";
	library.circulate_book("Software Engineering", Date(2015, 3, 5, DateFormat::US));

	//Pass on Chemistry book
	//cout << "passing chemistry book /n";
	library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));
	// Book should be archived with this call:
	library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US));

	// Software Engineering pass
	// cout << "passing software engineering book /n";
	library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));




	return 0;
}

