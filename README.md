# Library-Managment-System

* The code is written in C++ programming language.
* The code consists of a main() function which is the entry point of the program.
* The program uses several header files such as File Handling.h, AVL tree.h, Queue.h, Libraries.h, Student.h, Librarian.h, and conio.h.
* The main() function creates several objects including Person, Student, Librarian, Book, and Stack<Book> objects.
* The program reads data from the "Number.txt" file using an fstream object and stores it in the number variable.
* The program reads data from the "Library.dat" binary file using an ifstream object and stores it in the library_saving queue.
* The program uses a while loop to transfer the books from the library_saving queue to the libary map and a Stack object named temp.
* The program creates a char variable named ch, a bool variable named flag, and a string variable named text.
* The program outputs the text in the text variable using a for loop and Sleep() function to create a time delay.
* The program uses a while loop to display a menu and receive input from the user.
* If the user chooses option 1, the program creates a Librarian object and displays a login or register menu.
* If the user chooses the login option, the program prompts the user to enter their email and password and calls the Search() function to validate the input.
* If the user enters the correct email and password, the program displays the librarian menu and returns to the main menu.
* If the user enters incorrect login information, they are given three attempts to login before being locked out.
* If the user chooses the register option, the program prompts the user to enter their data and calls the write() function to store the data in the "Librarian" file.
* If the user chooses option 2, the program creates a Student object and displays a menu.
* If the user chooses option 3, the program exits.
* Libraries included: iostream, unordered_map, iomanip, string, fstream, windows.h.
* Defined variables: number, books_to_borrow, issued_books, returning_book.
* Defined function validPassword to check the validity of password entered.
* Defined two classes, Book and Person.
* Book class has the following public data members: Title, author, ISBN, id, avaliable. It also has three member functions: inputdata, cpy, and display.
* Person class has the following public data members: name, email, password. It also has two member functions: data and display.
* Within the data function of Person class, the user is prompted to enter their name, email, and password. Password is checked for validity using the validPassword function.
* The display function for Person class outputs the name, email, and password of the person.
* Various data structures are used including Queue and Stack.
  
  This code seems to be implementing a class called Librarian which is derived from a base class Person.

The Librarian class has a data member called tree of type AVL* which is a pointer to an AVL tree. The AVL tree is likely used to store the library books, and the Librarian class has methods to perform operations on the AVL tree such as inserting, deleting, and searching for books.

The menu method is used to display a menu of options for the user to interact with the library. The user can add books, delete books, search for books, display all books in the library, display books within a range of IDs, and approve or dismiss book issue and return requests.

The Add_book method prompts the user to input details about a book, creates a Book object, inserts it into the AVL tree, and pushes it onto a stack called library_saving.

There are also references to other data structures such as Stack, Queue, and map, but without seeing their implementation it's not possible to fully understand their purpose within this code.
