#include <iostream>
#include <vector> 
#include <string>
class Password {
private: 
	std::string passwordText, startPasswordText,encryptedText,decryptedText;
	std::vector<int> primeNumbers; 
	std::string primeText, normalText;
	int passwordLength;
	void findPrimes() {
		for (int i = 2; i <= passwordLength; i++) {
			bool isPrime = true;
			for (int j = 2; j < i; j++) {
				if (i % j == 0) isPrime = false;
			}
			if (isPrime) primeNumbers.push_back(i);
		}
	}
public:
	Password(std::string _passwordText) {
		passwordText = _passwordText;
		startPasswordText = passwordText;
		passwordLength = passwordText.length();
		findPrimes();
	}
	void PrintPrimes() {
		std::cout << "prime numbers: ";
		for (int i = 0; i < primeNumbers.size(); i++) {
			if (i == primeNumbers.size() - 1) {
				std::cout << primeNumbers.at(i) << std::endl;
			}
			else {
				std::cout << primeNumbers.at(i) << ", ";
			}
		}
	}
	void Encrypt() {
		for (int i = 1; i <= passwordLength; i++) {
			if (find(primeNumbers.begin(), primeNumbers.end(), i) != primeNumbers.end()) {
				primeText += passwordText[i - 1];
			}
			else {
				normalText += passwordText[i - 1];
			}
		}
		encryptedText = primeText + normalText;
		std::cout << "Encrypted password: " << this->encryptedText << std::endl;
	}
	void Decrypt() {
		std::string primePart,nonPrimePart;
		int lenPrimes = primeNumbers.size(); 
		int ip=0, inp = 0;
		nonPrimePart = passwordText.substr(lenPrimes,passwordLength-lenPrimes);
		primePart = passwordText.substr(0,lenPrimes);
		for (int i = 1; i <= passwordLength; i++) {
			if (find(primeNumbers.begin(), primeNumbers.end(), i) != primeNumbers.end()) {
				decryptedText += primePart[ip];
				ip++;
			}
			else {
				decryptedText += nonPrimePart[inp];
				inp++;
			}
		}
		std::cout << "Decrypted password: " << this->decryptedText << std::endl;
	}
};


int main() {
	std::string password;
	std::cout << "*** Password Encypter/Decrypter ***" << std::endl;
	std::cout << "Enter a password: ";
	std::cin >> password; 
	Password ps(password);
	//ps.PrintPrimes(); // x is length of password,this func prints the prime numbers between [2,x]
	short ed;
	std::cout << "1.Encrypt password\n2.Decrypt password\nYour choice: ";
	std::cin >> ed;
	switch (ed) {
	case 1:
		ps.Encrypt();
		break;
	case 2:
		ps.Decrypt();
		break;
	default:
		std::cout << "Error. Invalid input entered." << std::endl;
		break;
	}
	return 0;
}
