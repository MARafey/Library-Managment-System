#pragma once
#include"Libraries.h"
#include "AVL tree.h"


class Librarian : public Person
{
public:
	AVL* tree;
	void copy(Person* obj)
	{
		strcpy_s(this->email, obj->email);
		strcpy_s(this->name, obj->name);
		strcpy_s(this->password, obj->password);
	}
	void data()
	{
		Person::data();
	}
	void menu(Stack<Book> &temp)
	{
		int op;
		int id;
		int low, high;

		while (!temp.IsEmpty())
		{
			tree = insert(temp.peek(), tree);
			temp.pop();
		}

		while (true)
		{
			system("cls");
			system("color 72");

			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t1. Insert Book" << std::endl;
			cout << "\t\t\t\t2. Delete Book" << std::endl;
			cout << "\t\t\t\t3. Search Book" << std::endl;
			cout << "\t\t\t\t4. Display Library" << std::endl;
			cout << "\t\t\t\t5. Display Book in range" << std::endl;
			cout << "\t\t\t\t6. Book Issue approval" << std::endl;
			cout << "\t\t\t\t7. Book Return approval" << std::endl;
			cout << "\t\t\t\t8. Exit" << std::endl;
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t Your Choice : ";
			cin >> op;
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << std::endl;
			cout << std::endl;
			if (op == 1)
			{
				Librarian::Add_book(tree);
				cin.get();
			}
			if (op == 2)
			{
				cout << "\t\t\t\t The ID of book : ";
				cin >> id;
				Librarian::Delte_book(id, tree);
				system("pause");
			}
			if (op == 3)
			{
				cout << "\t\t\t\t The ID of book : ";
				cin >> id;
				Librarian::display_id(id, tree);
			}
			if (op == 4)
			{
				Librarian::display_All(tree);
			}
			if (op == 5)
			{
				cout << "\t\t\t\t The low ID of book : ";
				cin >> low;
				cout << "\t\t\t\t The High ID of book : ";
				cin >> high;
				Librarian::display_id_range(low, high, tree);

			}
			if (op == 6)
			{
				cout << "\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*BOOK TO BE ISSUED-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
				while (!books_to_borrow.isEmpty())
				{
					cout << "\t\t\tBook to be issued : " << books_to_borrow.peek() << std::endl;
					AVLPointSearchID(tree, books_to_borrow.peek());
					borrow(tree, books_to_borrow.peek());
					cout << "\t\t\t Approved {1} or Dismiss {0} : ";
					cin >> low;
					if (low == 1)
					{
						issued_books.push(books_to_borrow.peek());
					}
					books_to_borrow.dequeue();
				}

			}
			if (op == 7)
			{
				cout << "\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*BOOK BEING RETURNED-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
				while (!returning_book.isEmpty())
				{
					cout << "\t\t\tBook to be returned : " << returning_book.peek() << std::endl;
					AVLPointSearchID(tree, books_to_borrow.peek());
					returning(tree, returning_book.peek());
					returning_book.dequeue();
					Sleep(1000);
					cout << "==========>RETURNED....." << endl;
					cin.get();
				}
			}
			if (op == 8)
			{
				while (!library_saving.IsEmpty())
				{
					write<Book>("Libary", library_saving.peek());
					library_saving.pop();
				}
				break;
			}
		}

	}
	void Add_book(AVL*& p)
	{
		Book b;
		b.inputdata();
		p = insert(b, p);
		library_saving.push(b);
		libary[b.id] = b;
		cout << "\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*BOOK ADDED-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
	}
	void Delte_book(int id, AVL*& p)
	{
		p = delete_node(id, p);
		libary.erase(id);
		cout << "\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*BOOK Removed-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
	}
	void display_All(AVL* p)
	{
		AVLPostOrderTransversal(p);
		system("pause");
	}
	void display_id(int id, AVL* p)
	{
		AVLPointSearchID(p, id);
		system("pause");
	}
	void display_id_range(int low, int high, AVL* p)
	{
		AVLRangeSearchID(p, low, high);
		system("pause");
	}
};