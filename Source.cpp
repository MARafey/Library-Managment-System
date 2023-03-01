#include"File Handling.h"
#include"AVL tree.h"
#include"Queue.h"
#include"Libraries.h"
#include"Student.h"
#include"Librarian.h"
#include <conio.h>

int main()
{
	Person* z;
	Student obj;
	Librarian obj2;
	char op;
	string pass, gmail;

	Book bbbb;
	Stack<Book> temp;

	fstream wri;

	wri.open("Number.txt");
	wri >> number;
	while (wri>>number) { //read data from file object and put it into string.
	}
	wri.close();


	Book temp2;
	ifstream fin("Libary.dat", ios::binary);
	while (fin.read((char*)&temp2, sizeof(temp2)))
	{
		library_saving.push(temp2);
	}
	fin.close();

	while (!library_saving.IsEmpty())
	{
		bbbb = library_saving.peek();

		libary[bbbb.id] = library_saving.peek();

		temp.push(library_saving.peek());

		library_saving.pop();
	}
	char ch;
	bool flag = 1;
	string text = "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n\t\t\t\t\tWelcome To BSE 3's Virtual Library\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n";
start:	system("cls");
	    system("color 16");
		
	for (int i = 0; i < text.length(); i++)
	{
		std::cout << text[i];
		//to control time delay modify number
		if(flag)
		Sleep(5);//<==
	}
	flag = 0;
	while (true)
	{
		
		

		cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
		cout << "\t\t\t\t 1. Libraian " << std::endl;
		cout << "\t\t\t\t 2. Student " << std::endl;
		cout << "\t\t\t\t 3. Exit " << std::endl;
		cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
		cout << "\t\t\t\t Your Choice : ";
		cin >> op;
		if (op == '1')
		{
			system("cls");
			system("color 72");
			z = new Librarian;
		xx:			cout << "\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t 1. Login " << std::endl;
			cout << "\t\t\t\t 2. Register " << std::endl;
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t Your Choice : ";
			cin >> op;
			if (op == '1')
			{
				int a = 0;
				while (a < 3)
				{
					cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
					cout << "\t\t\t\tEnter your mail : ";
					cin >> gmail;
					cout << "\t\t\t\tEnter your password : ";
					cin >> pass;
					//ch = _getch();
					//while (ch != 13) {//character 13 is enter
					//	pass.push_back(ch);
					//	cout << '*';
					//	ch = _getch();
					//}

					if (1 == Search<Librarian>("Librarian", gmail, pass))
					{
						system("cls");
						system("color 72");

						z->menu(temp);
						goto start;
					}
					else
					{
						a++;
						cout << "Please try again you have " << 3 - a << " chances left." << std::endl;
					}
					if (a == 3)
					{
						cout << "You have exhaused all your chances you will be locked out of the store now :) " << std::endl;
					}
				}
				exit(0);
				cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			}
			else if (op == '2')
			{
				z->data();
				obj2.copy(z);
				write<Librarian>("Librarian", obj2);
				goto start;
			}
			else
			{
				cout << "\t\t\t\t INVALID INPUT TRY AGAIN ...... " << std::endl;
				goto xx;
			}

		}
		else if (op == '2')
		{
			system("cls");
			system("color 80");
			z = new Student;
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t 1. Login " << std::endl;
			cout << "\t\t\t\t 2. Register " << std::endl;
			cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			cout << "\t\t\t\t Your Choice : ";
			cin >> op;
			if (op == 1)
			{
				int a = 0;
				while (a < 3)
				{
					cout << "\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
					cout << "\t\t\t\tEnter your mail : ";
					cin >> gmail;
					cout << "\t\t\t\tEnter your password : ";
					cin >> pass;
					//ch = _getch();
					//while (ch != 13) {//character 13 is enter
					//	pass.push_back(ch);
					//	cout << '*';
					//	ch = _getch();
					//}
					if (Search<Student>("Student", gmail, pass))
					{
						system("cls");
						system("color 80");
						z->menu(temp);
						goto start;
					}
					else
					{
						a++;
						cout << "\t\t\t\tPlease try again you have " << 3 - a << " chances left." << std::endl;
					}
					if (a == 3)
					{
						cout << "\t\t\t\tYou have exhaused all your chances you will be locked out of the store now :) " << std::endl;
					}
				}
				exit(0);
				cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
			}
			else if (op == '2')
			{
				z->data();
				obj.copy(z);
				write<Student>("Student", obj);
				goto start;
			}
			else
			{
				cout << "\t\t\t\t INVALID INPUT TRY AGAIN ...... " << std::endl;
				cin.get();
				goto xx;
			}
		}
		else if (op == '3')
		{

		wri.open("Number.txt", 'w');
		wri << number;
		wri.close();
			exit(1);
		}
		else
		{
		system("cls");
		cout << "\n\t\t\t\tInvalid Input! Try again.\n";
		
		}
	
	}
}

