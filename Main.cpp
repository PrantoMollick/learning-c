#include<string>
#include<iostream>
#include <stack>  
#include <vector>

#define PRODUCTION_ROLE_LENGTH  50

int main() {
	char rule1[PRODUCTION_ROLE_LENGTH];
	std::cout << "Enter Your 1st Rule: ";
	std::cin.getline(rule1, PRODUCTION_ROLE_LENGTH);
	int firstArrayLength = strlen(rule1);

	char rule2[PRODUCTION_ROLE_LENGTH];
	std::cout << "Enter Your 2nd Rule: ";
	std::cin.getline(rule2, PRODUCTION_ROLE_LENGTH);
	int secondArrayLength = strlen(rule2);
	int length;
	if (firstArrayLength > secondArrayLength) {
		length = firstArrayLength;
	}
	else {
		length = secondArrayLength;
	}

	char array2[2][PRODUCTION_ROLE_LENGTH];

	int i, j;
	for (i = 0; i < 1; i++) {
		for (j = 0; j <= length; j++) {		
			array2[i][j] = rule1[j];
			array2[i + 1][j] = rule2[j];
		}
	}

	std::string terminalChecking = "+-*/abcdefghijklmnopqrstubwxyz";
	int lenTerminal_checking = terminalChecking.length();

	std::cout << lenTerminal_checking << std::endl;
	
	std::string firstRuleTerminalValue = "";
	std::string firstRuleNonTerminalValue = "";

	std::string secondRuleTerminalValue = "";
	std::string secondRuleNonTerminalValue = "";

	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < length; y++) {
			
			if (y == 1) continue;
			if (y == 2) continue;
			if(x == 0) {
				if (terminalChecking.find(array2[x][y]) != std::string::npos) {
					//std::cout << x << y << array2[x][y] << std::endl;
					firstRuleTerminalValue += array2[x][y];
				}
				else {
					firstRuleNonTerminalValue += array2[x][y];
				}
			} 

			if (x == 1) {
				if (terminalChecking.find(array2[x][y]) != std::string::npos) {
					//std::cout << x << y << array2[x][y] << std::endl;
					secondRuleTerminalValue += array2[x][y];
				}
				else {
					secondRuleNonTerminalValue += array2[x][y];
				}
			}


		}
	}

	std::cout << "First Production Rule Terminal Value is = \"" << firstRuleTerminalValue <<"\"" << std::endl;
	std::cout << "First Production Rule Non Terminal Value is = \"" << firstRuleNonTerminalValue <<"\"" << std::endl << std::endl;

	std::cout << "Second Production Rule Terminal Value is = \"" << secondRuleTerminalValue << "\"" << std::endl;
	std::cout << "Second Production Rule Non Terminal Value is = \"" << secondRuleNonTerminalValue << "\"" << std::endl;

	std::cin.get();
	return 0;

}

