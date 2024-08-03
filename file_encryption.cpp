#include <iostream>
#include <fstream>
#include <string>

void encryptFile(const std::string& filename, const std::string& password)
{
	std::ifstream inputFile(filename, std::ios::binary);
	std::ofstream outputFile(filename + ".encrypted", std::ios::binary);

	if (!inputFile)
	{
		std::cerr << "Error opening the input file." << std::endl;
		return;
	}

	char ch;
	int passwordIndex = 0;
	while (inputFile.get(ch))
	{
		ch ^= password[passwordIndex];
		outputFile.put(ch);

		passwordIndex = (passwordIndex + 1) % password.size();
	}

	inputFile.close();
	outputFile.close();

	std::cout << "File encrypted successfully." << std::endl;
}

void decryptFile(const std::string& filename, const std::string& password)
{
	std::ifstream inputFile(filename, std::ios::binary);
	std::ofstream outputFile(filename.substr(0, filename.size() - 10), std::ios::binary);

	if (!inputFile)
	{
		std::cerr << "Error opening the input file." << std::endl;
		return;
	}

	char ch;
	int passwordIndex = 0;
	while (inputFile.get(ch))
	{
		ch ^= password[passwordIndex];
		outputFile.put(ch);

		passwordIndex = (passwordIndex + 1) % password.size();
	}

	inputFile.close();
	outputFile.close();

	std::cout << "File decrypted successfully." << std::endl;
}

int main()
{
	std::string filename;
	std::string password;

	std::cout << "Enter the filename: ";
	std::getline(std::cin, filename);

	std::cout << "Enter password: ";
	std::getline(std::cin, password);

	std::cout << "Select operation (1: Encrypt, 2: Decrypt): ";
	int operation;
	std::cin >> operation;
	std::cin.ignore();

	if (operation == 1)
	{
		encryptFile(filename, password);
	}
	else if (operation == 2)
	{
		decryptFile(filename + ".encrypted", password);
	}
	else
	{
		std::cout << "Invalid choice. Exiting the program." << std::endl;
		return 0;
	}

	return 0;
}