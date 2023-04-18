#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

string inp = "C:\\Users\\sobir\\source\\repos\\NewRepo\\textFiles\\0.txt";
string outp = "C:\\Users\\sobir\\source\\repos\\NewRepo\\textFiles\\1.txt";
ofstream outFile;
ifstream inFile;

void openOutput() {
	outFile.open(outp, ios::app);
	outFile << "Client opened output\n";
	cout << "Opened output\n";
}
void closeOutput() {
	outFile << "Client closed output\n";
	cout << "Closed output\n";
	outFile.close();
}
void writeToOutput(string message) {
	if (outFile.is_open()) {
		outFile << message << endl;
		cout << "Wrote [" << message << "] to outFile\n";
	}
}
void writeToOutput() {
	if (outFile.is_open()) {
		string message;
		cin.ignore();
		cout << "Input message:\n";
		getline(cin, message);
		outFile << message << endl;
		cout << "Wrote [" << message << "] to outFile\n";
		}
	}

void openInput() {
	inFile.open(inp);
	cout << "inFile: \n[";
	int i = 0;
	while (!inFile.eof() && i++ < 2048) cout << char(inFile.get());
	cout << "] end of inFile\n";
}
void closeInput() {
	cout << "inFile closed by Client\n";
	inFile.close();
}


enum Commands {
	open_input_file = '0',
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
	MoveWindow(console, 500, 30, 450, 600, TRUE);

	cout << "client\n";
	while (1) {
		char inp;
		cin >> inp;
		switch (inp) {
		case open_input_file:	// 0
			openInput();
			break;
		case close_input_file:	// 1
			closeInput();
			break;
		case open_output_file:	// 2
			openOutput();
			break;
		case write_output_file:	// 3
			writeToOutput();
			break;
		case close_output_file:	// 4
			closeOutput();
			break;
		case exit_program:		// 5
			if (inFile.is_open()) inFile.close();
			if (outFile.is_open()) outFile.close();
			return 0;
		default:
			break;
		}
	}

}
