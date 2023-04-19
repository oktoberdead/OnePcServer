#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "..\..\class\client.h"
using namespace std;

string inp = "..\\..\\textFiles\\0.txt";
string outp = "..\\..\\textFiles\\1.txt";


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
	Client UserClient("User", inp, outp);

	
	while (1) {
		char inp;
		cin >> inp;
		switch (inp) {
		case open_input_file:	// 0
			UserClient.openInputFile();
			break;
		case close_input_file:	// 1
			UserClient.closeInputFile();
			break;
		case open_output_file:	// 2
			UserClient.openOutputFile();
			break;
		case write_output_file:	// 3
			UserClient.writeToOutputFile();
			break;
		case close_output_file:	// 4
			UserClient.closeOutputFile();
			break;
		case exit_program:		// 5
			if (UserClient.inFile.is_open()) UserClient.inFile.close();
			if (UserClient.outFile.is_open()) UserClient.outFile.close();
			return 0;
		default:
			break;
		}
	}
	



}
