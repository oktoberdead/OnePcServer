#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

class ServerClient {
private:
	short clients_count = 0;				// количество УЖЕ ЗАПУЩЕННЫХ приложений-клиентов
	vector <string> connected_clients;		// вектор, содержащий имена УЖЕ ПОДКЛЮЧЁННЫХ приложений-клиентов
	
public:
	string server_name;						// имя приложения-сервера
	string input_file_path;					// путь к файлу для ввода
	string output_file_path;				// путь к файлу для вывода

	/*
	сайд - ноут:
	файл для ввода - файл, в который приложения-клиенты
	записывают свой вывод с соблюдением разметки,
	из этого файла мы грамотно читаем разметку и обрабатываем
	сообщения, выводя их в лог-файл (вывод), откуда клиенты
	берут обработанные и размеченные строки и выводят себе в
	консольку (описание для чата)
	*/

	// конструктор для полного замеса данных
	ServerClient(string name, short running_clients, string input, string output): server_name(name), clients_count(running_clients), input_file_path(input), output_file_path(output) 
	{

	}

	// конструктор, требующий только файлы ввода/вывода
	ServerClient(string input, string output): server_name("defaultServerName"), input_file_path(input), output_file_path(output) 
	{

	}
	//-----------------------------------------------------//
	ifstream inFile;
	ofstream outFile;
	//-----------------------------------------------------//
	void openOutputFile() {
		outFile.open(output_file_path, ios::app);
		outFile << "Server opened output\n";
		cout << "Opened output\n";
	}
	void closeOutputFile() {
		outFile << "Server closed output\n";
		cout << "Closed output\n";
		outFile.close();
	}
	void writeToOutputFile(string message) {
		if (outFile.is_open()) {
			outFile << message << endl;
			cout << "Wrote [" << message << "] to outFile\n";
		}
	}
	void writeToOutputFile() {
		if (outFile.is_open()) {
			string message;
			cin.ignore();
			cout << "Input message:\n";
			getline(cin, message);
			outFile << message << endl;
			cout << "Wrote [" << message << "] to outFile\n";
		}
	}
	//-----------------------------------------------------//
	void openInputFile() {
		inFile.open(input_file_path);
		cout << "inFile: \n[";
		int i = 0;
		while (!inFile.eof()&&i++ < 2048) cout << char(inFile.get());
		cout << "] end of inFile\n";
	}
	void closeInputFile() {
		cout << "inFile closed by Server\n";
		inFile.close();
	}

};

enum Commands {
	open_input_file,
	close_input_file,
	open_output_file,
	write_output_file,
	close_output_file,
	exit_program
};

int main()
{
	HWND console = GetConsoleWindow();
	system("MODE CON COLS=50 LINES=35");
	MoveWindow(console, 30, 30, 450, 600, TRUE);

	string outp = "C:\\Users\\sobir\\source\\repos\\NewRepo\\textFiles\\0.txt";
	string inp = "C:\\Users\\sobir\\source\\repos\\NewRepo\\textFiles\\1.txt";
	ServerClient Server("Server", 1, inp, outp);

	cout << "server\n";
	
	while (1) {
		int inp;
		cin >> inp;
		switch (inp) {
		case open_input_file:
			Server.openInputFile();
			break;
		case close_input_file:
			Server.closeInputFile();
			break;
		case open_output_file:
			Server.openOutputFile();
			break; 
		case write_output_file:
			Server.writeToOutputFile();
				break;
		case close_output_file:
			Server.closeOutputFile();
			break;
		case exit_program:
			if (Server.inFile.is_open()) Server.inFile.close();
			if (Server.outFile.is_open()) Server.outFile.close();
			return 0;
		}
	}

}

