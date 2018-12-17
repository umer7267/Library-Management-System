#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;

class library{
	public:
		int books = 0;
		string Book_name[100], Author[100];
		int Book_id[100] = {0}, Edition[100] = {0};
	public:
		void enter_book(){
			system("cls");
			cout<<"\n\nEnter Book ID :- ";
			cin>>Book_id[books];
			cout<<"Enter Book Title :- ";
			cin>>Book_name[books];
			cout<<"Enter Author of Book :- ";
			cin>>Author[books];
			cout<<"Enter Edition of Book :- ";
			cin>>Edition[books];
			cout<<"\n\nBook Added Successfully...";
			Sleep(2000);
			system("cls");
			books++;
		}
		int book_details(int id){
			for(int i=0; i<books; i++){
				if(Book_id[i] == id){
					cout<<"\n\n\tBook Details\n\n";
					cout<<"Book ID: "<<Book_id[i]<<endl;
					cout<<"Book Name: "<<Book_name[i]<<endl;
					cout<<"Author Name: "<<Author[i]<<endl;
					cout<<"Book Edition: "<<Edition[i]<<endl;
					cout<<"\n\n\tPress any key to continue...";
					getch();
					system("cls");
					return 1;
				}
			}
			system("cls");
			cout<<"\n\nBook Not Found!";
			Sleep(2000);
			system("cls");
			return 0;
		}
		void display_books(){
			if(books == 0){
				system("cls");
				cout<<"\n\n\tThere is no Book in the library!";
				Sleep(2000);
				system("cls");
				return;
			}
			system("cls");
			cout<<"\n\n"<<setw(40)<<"LIBRARY DATABASE";
			cout<<endl<<endl;
			for(int a=0; a<30; a++)
    			cout<<"*-";
			cout<<endl;
			cout<<setw(15)<<"BOOK ID"<<setw(15)<<"BOOK NAME"<<setw(15)<<"AUTHOR"<<setw(15)<<"EDITION"<<endl;
			for(int b=0;  b<30;  b++)
    			cout<<"*-";
			cout<<endl;
			for(int i=0; i<books; i++){
				cout<<setw(15)<<Book_id[i]<<setw(15)<<Book_name[i]<<setw(15)<<Author[i]<<setw(15)<<Edition[i]<<endl;
			}
			cout<<"\n\n\tPress any key to continue...";
			getch();
			system("cls");
		}
		int match_details(library lib_books){
			int id;
			cout<<"\n\nEnter Book ID :- ";
			cin>>id;
			for(int i=0; i<lib_books.books; i++){
				if(lib_books.Book_id[i] == id){
					Book_id[books] = lib_books.Book_id[i];
					Book_name[books] = lib_books.Book_name[i];
					Author[books] = lib_books.Author[i];
					Edition[books] = lib_books.Edition[i];
					books++;
					cout<<"\n\nBook Name: "<<lib_books.Book_name[i]<<endl;
					cout<<"Author Name: "<<lib_books.Author[i]<<endl;
					cout<<"Book Edition: "<<lib_books.Edition[i]<<endl;
					cout<<"\n\nBook issued...";
					cout<<"\n\nPress any key to continue...";
					getch();
					return 1;
				}
			}
			cout<<"\n\n"<<id<<" ID doesn't Matched any Book...";
			Sleep(2000);
			return 0;
		}
};

class student : public library{
	private:
		int students = 0, id, flag;
		string Student_name[100], Student_dept[100];
		int Student_id[100] = {0}, Student_sem[100] = {0};
	public:
		void issue_book(library books){
			system("cls");
			cout<<"\n\nEnter Student ID :- ";
			cin>>Student_id[students];
			cout<<"Enter Student Name :- ";
			cin>>Student_name[students];
			cout<<"Enter Student Department :- ";
			cin>>Student_dept[students];
			cout<<"Enter Student Semester :- ";
			cin>>Student_sem[students];
			flag = library::match_details(books);
			if(flag == 1){
				system("cls");
				details();	
			}
			students++;
		}
		void details(){
			cout<<"\n\n\tDetails...";
			cout<<"\n\nBook:";
			cout<<"\n\n\tBook ID: "<<library::Book_id[students];
			cout<<"\n\tBook Name: "<<library::Book_name[students];
			cout<<"\n\nIssued To:";
			cout<<"\n\n\tStudent ID: "<<Student_id[students];
			cout<<"\n\tStudent Name: "<<Student_name[students];
			cout<<"\n\tStudent Department: "<<Student_dept[students];
			cout<<"\n\tStudent Semester: "<<Student_sem[students];
			cout<<"\n\n\tPress any key to continue...";
			getch();
		}
		void issued_books(){
			if(students==0){
				system("cls");
				cout<<"\n\n\tNo book issued yet!";
				Sleep(2000);
				system("cls");
			}
			else{
				system("cls");
				cout<<"\n\n\tISSUED BOOKS";
				for(int i=0; i<students; i++){
					if(library::Book_id[i] == 0)
						continue;
					cout<<"\n\nBook "<<i+1<<":";
					cout<<"\n\n\tBook ID: "<<library::Book_id[i];
					cout<<"\n\tBook Name: "<<library::Book_name[i];
					cout<<"\n\tAuthor Name: "<<library::Author[i];
					cout<<"\n\tBook Edition: "<<library::Edition[i];
					cout<<"\n\nIssued To: ";
					cout<<"\n\n\tStudent ID: "<<Student_id[i];
					cout<<"\n\tStudent Name: "<<Student_name[i];
					cout<<"\n\tStudent Department: "<<Student_dept[i];
					cout<<"\n\tStudent Semester: "<<Student_sem[i];
				}
				cout<<"\n\n\tPress any key to continue...";
				getch();
				system("cls");
			}
		}
};

int main(){
	library books;
	student students;
	int choice, issue;
	up:
	cout<<"\n\n\n\tMAIN MENU";
	cout<<"\n\n\t(1) DISPLAY ALL BOOKS";
	cout<<"\n\n\t(2) ENTER A NEW BOOK";
	cout<<"\n\n\t(3) DISPLAY A BOOK DETAILS";
	cout<<"\n\n\t(4) ISSUE A BOOK";
	cout<<"\n\n\t(5) ISSUED BOOKS";
	cout<<"\n\n\t(6) EXIT";
	cout<<"\n\n\tPlease Select Your Option (1-6): ";
	cin>>choice;
	switch(choice){
		case 1:
			books.display_books();
			goto up;
			break;
		case 2:
			books.enter_book();
			goto up;
			break;
		case 3:
			if(books.books == 0){
				system("cls");
				cout<<"\n\n\tThere is no Book in the library!";
				Sleep(2000);
				system("cls");
				goto up;
			}
			int id;
			system("cls");
			cout<<"\n\nENTER THE BOOK ID: ";
			cin>>id;
			books.book_details(id);
			goto up;
			break;
		case 4:
			if(books.books == 0){
				system("cls");
				cout<<"\n\n\tThere is no Book in the library!";
				Sleep(2000);
				system("cls");
				goto up;
			}
			students.issue_book(books);
			system("cls");
			goto up;
			break;
		case 5:
			students.issued_books();
			goto up;
			break;
		case 6:
			return 0;
		default:
			cout<<"\n\n\tWrong Choice! Choose Again!";
			Sleep(2000);
			system("cls");
			goto up;
	}
	return 0;
}
