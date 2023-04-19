#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "C:\Users\sobir\source\repos\NewRepo\class\client.h"
using namespace std;

class ServerClient : public Client{
private:
	short clients_count = 0;				// количество УЖЕ ЗАПУЩЕННЫХ приложений-клиентов
	vector <string> connected_clients;		// вектор, содержащий имена УЖЕ ПОДКЛЮЧЁННЫХ приложений-клиентов
	
public:

	ServerClient(string input, string output) :Client(input, output) {

	}
	ServerClient(string name, int count, string input, string output) :Client(name, input, output) {

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

