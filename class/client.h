#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Client {
private:

public:
	string client_name;						// имя текущего клиента
	string input_file_path;					// путь к файлу для ввода
	string output_file_path;				// путь к файлу для вывода

	/*
	сайд - ноут:
	файл для ввода - файл, в который приложения-клиенты
	записывают свой вывод с соблюдением разметки,
	из этого файла сервер грамотно читает разметку и обрабатывает
	сообщения, выводя их в лог-файл (вывод), откуда клиенты-юзеры
	берут обработанные и размеченные строки и выводят себе в
	консольку (описание для чата)
	*/

	// конструктор для полного замеса данных
	Client(string name, string input, string output) : client_name(name), input_file_path(input), output_file_path(output)
	{
		cout << "Client initialized (cn1) with name \"" << client_name << "\".\nInput file path: \"" << input_file_path << "\".\nOutput file path: \"" << output_file_path << "\".\nHave fun!\n\n\n";
	}

	// конструктор, требующий только файлы ввода/вывода
	Client(string input, string output) : client_name("defaultClientName"), input_file_path(input), output_file_path(output)
	{
		cout << "Client initialized (cn2) with default name \"" << client_name << "\".\nInput file path: \"" << input_file_path << "\".\nOutput file path: \"" << output_file_path << "\".\nHave fun!\n\n\n";
	}
	//-----------------------------------------------------//
	ifstream inFile;
	ofstream outFile;
	//-----------------------------------------------------//
	int openOutputFile() {
		outFile.open(output_file_path, ios::app);

		if (!outFile.is_open()) {
			cout << "\nCould not open the output file.\nPlease check at \"" << input_file_path << "\".";
			return -1;
		}

		outFile << client_name << ": opened output\n";
		cout << "outFile opened.\n";
		return 0;
	}
	void closeOutputFile() {
		outFile << client_name << " closed output\n";
		cout << "outFile closed.\n";
		outFile.close();
	}
	void writeToOutputFile(string message) {
		if (outFile.is_open()) {
			outFile << client_name << ": [" << message << "]\n";
			cout << "Wrote [" << message << "] to outFile\n";
		}
	}
	int writeToOutputFile() {
		if (!outFile.is_open()) {
			cout << "Output file is closed! Open output file and try again.\n";
			return -1;
		}
			string message;
			cin.ignore();
			cout << "Input message:\n";
			getline(cin, message);
			outFile << client_name << ": [" << message << "]\n";
			cout << "Wrote [" << message << "] to outFile\n";
			return 0;
	}
	//-----------------------------------------------------//
	int openInputFile() {
		inFile.open(input_file_path);

		if (!inFile.is_open()) {
			cout << "\nCould not open the input file.\nPlease check at \"" << input_file_path << "\".";
			return -1;
		}

		cout << "Opened and read inFile: \n[";
		int i = 0;
		while (!inFile.eof() && i++ < 2048) cout << char(inFile.get());
		cout << "] end of inFile\n";
		return 0;
	}
	void closeInputFile() {
		cout << "inFile closed.\n";
		inFile.close();
	}

};