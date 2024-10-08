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
	std::cout << "*** sifre kodlayýcý ***" << std::endl;
	std::cout << "sifre giriniz: ";
	std::cin >> sifre; // kullanicidan sifre girdisi aliniyor
	Password ps(sifre); // constructor kullanilarak Password classinda yeni bir obje tanimlaniyor
	ps.getPrimes(); // girilen sifrenin uzunluguna x dersek, 2'den x'e kadar olan asal sayilari ekrana yazdiriyoruz
	ps.encryption(); // sifre kodlaniyor(encryption)
	ps.getPassword(); // sifre ekrana basiliyor
	ps.unencryption(); // sifre eski haline getiriliyor(unencryption)
	ps.getPassword(); // sifre ekrana basiliyor

	return 0;
}
