#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;

class to_do_list {
protected:
	size_t end_list = 0;
	string task[50];
	bool line_task_fillet[50];
	string status[50];
public:
	void start() {
		for (int i = 0; i < 50; i++) {
			line_task_fillet[i] = false;
		}
	}
};

class new_task : protected to_do_list{
public:
	void operator()(string message_task) {
		bool ready = false;
		int i = 0;
		while (ready == false) {
			if (line_task_fillet[i] == true) {
				i++;
				
			}
			else if (line_task_fillet[i] == false) {
				task[i] = message_task;
				line_task_fillet[i] = true;
				status[i] = "Not ready";
				cout << "Задача создана"<< endl;
				end_list++;
				ready = true;
			}
		}
	}

};


class print_task : protected to_do_list{
public:
	void operator()() {
		for (int i = 0; i < end_list; i++) {
			if (line_task_fillet[i] = true) {
				cout << i << ". " << task[i] << "\t" << status[i] << endl	;
			}
		}
	}
};

class change_status : protected to_do_list {
public:
	void operator()(int i) {
		status[i] = "Ready";
	}
};

int chase() {
	int chase = 0;
	cout << "1.Новая задача\n 2. Изменить статус \n 3.Вывести задачи \n Введите номер команды:";
	cin >> chase;
	cout << endl;
	return chase;
	}





int main() {
	setlocale(LC_ALL,"ru");
	to_do_list list;
	list.start();
	print_task print;
	change_status change;
	new_task newtask;
	cout << "Добро пожаловать в To Do Лист" << endl;
	bool exit = false;
	while (exit != true) {
		int chase_return = chase();
		if (chase_return == 1) {
			cout << "Какая задача на этот раз?:";
			string task;
			cin >> task;
			cout << endl;
			newtask(task); 
		}
		if (chase_return == 2) {
			int i = 0;
			print();
			cout << "Введите номер вашей задачи:";
			cin >> i;
			cout << endl;
			change(i);
		}
		if (chase_return == 3) {
			print();
		}
		if (chase_return < 0 || chase() > 3) {
			cout << "Ошибка: не правильна введена задача" << endl;
		}
		chase_return = 0;
		cout << "Хотите выйти? ";
		cin >> exit; 
		cout << endl;
	}

	return 0;
}