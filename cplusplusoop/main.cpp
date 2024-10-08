#include <iostream>
#include <vector>

class Password {
private: 
	std::string passwordText;
	std::string passwordTextFirstVersion;
	std::vector<int> primeNumbers; 
	std::string primeText;
	std::string normalText;
	int passwordLength;
	bool encrypt = false;

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
		passwordTextFirstVersion = passwordText;
		passwordLength = passwordText.length();
		findPrimes();
	}
	//aHMeTgAmetR
	void getPrimes() {
		for (int prime : primeNumbers) {
			std::cout << prime << std::endl;
		}
	}
	void getPassword() {
		std::cout << "Password: " << passwordText << "\tEncryption: ";
		if (encrypt) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl;
		}
	}
	void encryption() {
		//ebubekir {'b','u','e','i'} --> bueiebkr
		for (int i = 1; i <= passwordLength; i++) {
			if (find(primeNumbers.begin(), primeNumbers.end(), i) != primeNumbers.end()) {
				primeText += passwordText[i - 1];
			}
			else {
				normalText += passwordText[i - 1];
			}
		}
		passwordText = primeText + normalText;
		encrypt = true;
	}
	void unencryption() {
		passwordText = passwordTextFirstVersion;
		encrypt = false;

	}
};


int main() {
	setlocale(LC_ALL, "Turkish");
	std::string sifre;
	std::cout << "*** �ifre kodlay�c� ***" << std::endl;
	std::cout << "�ifre giriniz: ";
	std::cin >> sifre; // kullan�c�dan �ifre girdisi al�n�yor
	Password ps(sifre); // constructor kullan�larak Password class�nda yeni bir obje tan�mlan�yor
	ps.getPrimes(); // girilen �ifrenin uzunlu�una x dersek, 2'den x'e kadar olan asal say�lar� ekrana yazd�r�yoruz
	ps.encryption(); // �ifre kodlan�yor(encryption)
	ps.getPassword(); // �ifre ekrana bas�l�yor
	ps.unencryption(); // �ifre eski haline getiriliyor(unencryption)
	ps.getPassword(); // �ifre ekrana bas�l�yor

	return 0;
}