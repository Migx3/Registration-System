#include <iostream>
#include <fstream>
#include <string>

void clearConsole() {
	system("cls");
}

void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	while (clock() < startClock + secondsAhead);
	return;
}


void menuSystem() {

	std::cout << "1: Register " << '\n';
	std::cout << "2: Login " << '\n';
	std::cout << "3: Exit" << '\n' << '\n';
	std::cout << "[?]: ";
}


void registerSystem(std::string& username, std::string& password) {
	clearConsole();
	std::cout << "Select a username: " << '\n';
	std::cin >> username;

	std::cout << "Select a password: " << '\n';
	std::cin >> password;

	std::ofstream file(username + ".txt");
	file << username << '\n' << password;
	file.close();
	clearConsole();
	std::cout << "Login created!" << '\n';
	sleep(2);
	clearConsole();
}


void loginSystem(std::string& username, std::string& password) {
	clearConsole();
	std::string un, pw;
	std::cout << "Enter username: ";
	std::cin >> username;

	std::cout << "Enter password: ";
	std::cin >> password;

	std::ifstream read(username + ".txt");
	std::getline(read, un);
	std::getline(read, pw);

	if (un == username && pw == password) {
		clearConsole();
		std::cout << "Successfully logged in.";
		sleep(2);
	}

	else {
		clearConsole();
		std::cout << "Incorrect data.";
		sleep(1);
		clearConsole();
	}
	clearConsole();
}


int main() {
	char menu;
	std::string username;
	std::string password;

	menuSystem();
	std::cin >> menu;

	if (menu == '1') {
		registerSystem(username, password);
		return main();
	}

	else if (menu == '2') {
		loginSystem(username, password);
		return main();
	}

	else if (menu == '3') {
		EXIT_SUCCESS;
	}

	else {
		std::cout << "Invalid choice.";
	}
	return 0;
}
