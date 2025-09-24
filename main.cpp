#include <iostream>
#include <string> 

using namespace std;

int main()
{
	// inicjacja zminnych
	int dec;
	int op;
	int rest;
	int len;
	int i;
	string bin;

	cout << "Aby zamienic z DEC na BIN wpisz 1, a z BIN na DEC wpisz 2: ";
	cin >> op;


	// switch odpowiada za wybranie operacji na podstawie int op
	switch (op)
	{
	case 1: // op = 1
		cout << "Podaj liczbe dziesietna do przeliczenia: ";
		cin >> dec;

		while (dec > 0)
		{
			rest = dec % 2; // dzielimy z reszta
			bin = to_string(rest) + bin; // reszte zapisujemy do stringu (dlatego do stingu żeby była poprawna koleność cyfr)
			dec /= 2; // dzielimy przez 2 aby pętla była skończona
		};

		cout << "BIN: \n" << bin;
		break;
	case 2: // op = 2
		cout << "Podaj liczbe binarna do przeliczenia: ";
		cin >> bin;

		dec = 0;
		len = bin.size(); // długość stringa bin
		i = 0;

		while (i < len) // pętla która działa aż i (index) będzie mniejeszy od długośći stringa
		{
			if (bin[i] == '1') // jeśli dana cyfra w indexie to 1 idź dalej
			{
				int pozycja = len - 1 - i; // obracamy index 
				/*
					przykład

					index w c++

					i = 0   → '1' problem jest taki że zaczyna się tutaj gdzie kończy sie liczba binarna
					i = 1   → '0'
					i = 2   → '1'
					i = 3   → '1'

					rozwiązanie 
					inicjacja pozycji = długość - 1 - pozycja aktualna indexu 
					to obraca cały index jak poniżej

					bin = "1011"
					cyfry:   '1'   '0'   '1'   '1'
					pozycja:  3     2     1     0
				*/
				dec = dec + (1 << pozycja);
				/*
					operator (<<) przesuwa bit w lewo
					1 << pozycja = 2^pozycja

					jeśli bin[i] == '1' to w tej pozycji binarnej
					dodajemy odpowiednią potęgę dwójki do liczby dziesiętnej

					przykład

					pozycja = 3 → (1 << 3) = 8
					pozycja = 1 → (1 << 1) = 2
					pozycja = 0 → (1 << 0) = 1
				*/

			}
			i = i + 1;
		}

		cout << "DEC: \n" << dec;
		break;
	default: // jesli op != 1 || 2
		cout << "Bledny input!";
		break;
	}
	return 0;
}