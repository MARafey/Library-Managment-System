#pragma once
#include <iostream>
#include <unordered_map>
#include<iomanip>
#include<string>
#include<fstream>
#include"Queue.h"
#include<windows.h>
#include"Stack.h"
using namespace std;

int number = 1;

Queue<int> books_to_borrow;
Stack<int> issued_books;
Queue<int> returning_book;



bool validPassword(string str)      //checks validity of password
{
	bool a = false;
	bool b = false;
	bool c = false;
	bool d = false;
	if (str.length() == 9)        //for finding length of password 
	{
		a = true;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			b = true;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			c = true;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			d = true;
		}
	}
	return a && b && c && d;
}

class Book
{
public:
	string Title;
	string author;
	string ISBN;
	int id;  
	bool avaliable;

	void inputdata()
	{
		cin.ignore(1);
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
		std::cout << "\t\t\t**	Book Name : ";
		getline(cin, Title);
		std::cout << "\t\t\t**	Author Name : ";
		getline(cin, author);
		std::cout << "\t\t\t**	Book ISBN : ";
		getline(cin, ISBN);
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
		id = number++;
		avaliable = true;
	}
	void cpy(Book obj)
	{
		this->Title = obj.Title;
		this->author = obj.author;
		this->id = obj.id;
		this->ISBN = obj.ISBN;
		this->avaliable = obj.avaliable;
	}
	void display()
	{
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
		std::cout << "\t\t\t**	Book Name : " << left << setw(45) << Title << "**" << std::endl;
		std::cout << "\t\t\t**	Author Name : " << left << setw(45) << author << "**" << std::endl;
		std::cout << "\t\t\t**	Book ISBN : " << left << setw(45) << ISBN << "**" << std::endl;
		std::cout << "\t\t\t**	Book Avaliable : " << left << setw(45) << avaliable << "**" << std::endl;
		std::cout << "\t\t\t**	Book ID : " << left << setw(45) << id << "**" << std::endl;
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
	}
};

class Person
{
public:
	char name[50];
	char email[50];
	char password[11];


	void data()
	{
		string temp;
		string temp2;
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
		std::cout << "\t\t\t**	 First Name : ";
		cin >> temp;
		temp2 = temp + ' ';
		temp = "";
		std::cout << "\t\t\t**	 Last Name : ";
		cin >> temp;
		temp2 += temp;
		strcpy_s(name, temp2.c_str());
		std::cout << "\t\t\t**	Email  : ";
		cin >> temp;
		strcpy_s(email, temp.c_str());
	x:	cout << "\t\t\t**	Password : ";
		cin >> temp;
		strcpy_s(password, temp.c_str());
		if (!validPassword(temp))
		{
			cout << "\t\t\tInvalid password ." << std::endl;
			goto x;
		}
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
	}
	virtual void display()
	{
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
		std::cout << "\t\t\t\tName : " << name << std::endl;
		std::cout << "\t\t\t\tEmail : " << email << std::endl;
		std::cout << "\t\t\t\tPassword : " << password << std::endl;
		std::cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;

	}
	virtual void menu(Stack<Book> &temp) = 0;
	virtual void copy(Person*) = 0;


};



template <class T>
class Node
{
public:
	Book data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(T d)
	{
		data = d;
		next = NULL;

	}

};

unordered_map<int, Book> libary;
Stack<Book> library_saving;