#pragma once
#include"Libraries.h"
#include "AVL tree.h"


class Student : public Person
{
public:
	Stack<int> s;
	int student_id;

	void data()
	{
		Person::data();
		cout << "**	Student_ID : ";
		cin >> student_id;
	}
	void copy(Person* obj)
	{
		strcpy_s(this->email, obj->email);
		strcpy_s(this->name, obj->name);
		strcpy_s(this->password, obj->password);
	}
	void menu(Stack<Book> &temp)
	{
		int op;
		int id;
		Book obj;
		while (true)
		{
			system("cls");
			system("color 80");
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t1. Return Book" << std::endl;
			cout << "\t\t\t\t2. Borrow Book" << std::endl;
			cout << "\t\t\t\t3. Search Book" << std::endl;
			cout << "\t\t\t\t4. Check Book Status" << std::endl;
			cout << "\t\t\t\t5. Display Books to be issued" << std::endl;
			cout << "\t\t\t\t6. Display Library" << std::endl;
			cout << "\t\t\t\t7. Exit" << std::endl;
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t Your Choice : ";
			cin >> op;
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << std::endl;
			cout << std::endl;
			if (op == 1)
			{
				//obj = s.peek();
				cout << "\n\t\t\tThe book is requested for issueing.\n";
				libary[s.peek()].display();
				returning_book.enqueue(s.peek());
				s.pop();
				system("pause");
			}
			if (op == 2)
			{
				cout << "\t\t\t\t The ID of book : ";
				cin >> id;
				s.push(id);
				s.setposition(books_to_borrow.getsize());
				books_to_borrow.enqueue(id);
				cout << "\n\t\t\tThe book is requested for issueing.\n";
				libary[s.peek()].display();
				system("pause");
			}
			if (op == 3)
			{
				cout << "\t\t\t\t The ID of book : ";
				cin >> id;
				libary[id].display();
				system("pause");
			}
			if (op == 4)
			{
				if (books_to_borrow.peek() == s.peek())
				{
					cout << "\n\t\t\t The book is next in line. \n";
				}
				else if(s.IsEmpty() == 1)
				{
					cout << "\n\t\t\tNo book is in the process of being issued." << endl;
				}
				else
				{ 
					cout << "\n\t\t\tThe book is in the process of being issued." << endl;
					cout << "\n\t\t\t\t\tThe book is " << s.getposition() << " in line. \n";
				}
				system("pause");
			}
			if (op == 5)
			{
				Stack<int> oo;
				while (!s.IsEmpty())
				{
					libary[s.peek()].display();
					oo.push(s.peek());
					s.pop();
				}
				while (!oo.IsEmpty())
				{
					s.push(oo.peek());
					oo.pop();
				}
				system("pause");
			}
			if (op == 6)
			{
				for (auto x : libary) {
					x.second.display();
				}
				system("pause");
			}
			if (op == 7)
			{
				break;
			}
		}

	}
};