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
	std::cout << "*** Þifre kodlayýcý ***" << std::endl;
	std::cout << "Þifre giriniz: ";
	std::cin >> sifre; // kullanýcýdan þifre girdisi alýnýyor
	Password ps(sifre); // constructor kullanýlarak Password classýnda yeni bir obje tanýmlanýyor
	ps.getPrimes(); // girilen þifrenin uzunluðuna x dersek, 2'den x'e kadar olan asal sayýlarý ekrana yazdýrýyoruz
	ps.encryption(); // þifre kodlanýyor(encryption)
	ps.getPassword(); // þifre ekrana basýlýyor
	ps.unencryption(); // þifre eski haline getiriliyor(unencryption)
	ps.getPassword(); // þifre ekrana basýlýyor

	return 0;
}