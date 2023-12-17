#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <stdlib.h>
using namespace std;

class to_do_list {
protected:
	int end_list = 0;
	string task[50];
	bool line_task_fillet[50];
	string status[50];
public:
	int operator()(){
	int chase = 0;
	cout << "1.Новая задача\n 2. Изменить статус \n 3.Вывести задачи \n Введите номер команды:";
	cin >> chase;
	cout << endl;
	return chase;
	}
	
	
	void start() {
		for (int i = 0; i < 50; i++) {
			line_task_fillet[i] = false;
		}
	}

	auto new_task(string message_task) {
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
		return task[i];
	}
	
		void print() {
		for (int i = 0; i < end_list; i++) {
			if (line_task_fillet[i] == true) {
				cout << i << ". " << task[i] << "\t" << status[i] << endl	;
			}
		}
	}

		void change_status(int i) {
		status[i] = "Ready";
		cout << "Статус задачи успешно изменен" << endl;
	}

	
};

void create_file(){
	char sys;
	cout << "Введите первую букву системы системы:";
	cin >> sys;
	cout << endl;
	if (sys == 'w' ){
	system("NUL> todo_list.txt");
			}
if (sys == 'l'){
	system("touch todo_list.txt");
		}
		else {
			cout << "Такая система не поддерживается или не правильно введена система ): \nСохранение в файл невозможно"<< endl;
			}

	}


int main() {
	setlocale(LC_ALL,"ru");
	to_do_list list;
	list.start();
	string task = "";
	bool exit = false;
	int ans_chase = 0;
	fstream file;
	file.open("todo_list.txt");
	create_file();
	while (exit == false){
		ans_chase = list();
		if (ans_chase == 1){
			cout << "Какая новая задача?";
			cin >> task;
			cout << endl;
			file << list.new_task(task) << " \t Not ready" <<endl; 
			task = "";
			}
			if (ans_chase == 3){
				list.print();
			}
			if (ans_chase == 2){
				list.print();
				cout << "Выберите задачу:";
				int answer = 0;
				cin >> answer;
				cout << endl;
				list.change_status(answer);
				}
			else{
	cout << "Хотите выйти? (1)";
		cin >> exit;
		cout << endl;
	}
}
file.close();
	return 0;
}
