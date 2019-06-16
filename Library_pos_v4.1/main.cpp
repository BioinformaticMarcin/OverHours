// stefan_biblo.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct date {
	int rok;
	int miesiac;
	int dzien;
};
struct book {
	int ID;
	string tytul;
	string iautor;
	string nautor;
	string kat;
	date data;
	string iwyp = "n/a";
	string nwyp = "n/a";
	string inne = "y";
	struct book *next;
	struct book *prev;
};

book *head = NULL;
book *tail = NULL;


void dodajnakoniec(int tab)   //KONIEC
{
	system("cls");

	book *el = new book;

	el->ID = tab;

	cout << "Podaj:" << endl << endl;

	cout << "tytul:" << endl;
	cin >> el->tytul;
	cout << "--------------\n";

	cout << "imie autora:\n";
	cin >> el->iautor;
	cout << "--------------\n";

	cout << "nazwisko autora:\n";
	cin >> el->nautor;
	cout << "--------------\n";

	cout << "kategorie:\n";
	cin >> el->kat;
	cout << "--------------\n";

	el->data.dzien = 0;
	el->data.miesiac = 0;
	el->data.rok = 0;

	el->next = NULL;
	el->prev = tail;
	tail = el;

	if (el->prev) el->prev->next = el;
	else head = el;
}
void usun(book *w)
{
	int c;
	if (w == 0)
	{
		cout << "brak danych";
		Sleep(2000);
		return;
	}
	cout << "Aby usunac po: " << endl << "ID nacisnij - 1" << endl << "tytule - 2" << endl << endl << "1/2: ";
	cin >> c;

	if (c == 1)
	{
		int a;
		system("cls");
		cout << "Aby usunac po ID" << endl << "wpisz wartosc: ";
		cin >> a;
		if (a < 60 && a >0)
		{
			while (w)
			{
				if (w->ID == a)
				{
					if (w->prev)
					{
						w->prev->next = w->next;
						w->next->prev = w->prev;
					}
					if (w->next == NULL)
					{
						head = w->next;
						tail = w->prev;
					}
					else
					{
						head = w->next;
						w->next->prev = head;
					}

					delete w;
					cout << "pomyslnie usunieto!";
					Sleep(2000);
					return;
				}
				else
				{
					w = w->next;
					continue;
				}
			}

		}
		cout << "Nie ma ksiazki o podanym ID";
		Sleep(2000);
		return;
	}
	if (c == 2)
	{
		string a;
		int b;
		system("cls");
		cout << "Aby usunac po tytule" << endl << "wpisz tytul: ";
		cin >> a;
		while (w)
		{
			if (a == w->tytul)
			{
				if (w->prev)
				{
					w->prev->next = w->next;
					w->next->prev = w->prev;
				}
				if (w->next == NULL)
				{
					head = w->next;
					tail = w->prev;
				}
				else
				{
					head = w->next;
					w->next->prev = head;
				}

				delete w;
				cout << "pomyslnie usunieto!";
				Sleep(2000);
				return;
			}
			else
			{
				w = w->next;
				continue;
			}
		}
		cout << "Nie ma ksiazki o podanym tytule";
		Sleep(2000);
		return;
	}
	else
	{
		cout << "Tylko 1 lub 2";
		Sleep(2000);
		return;
	}
}
void edytuj(book *w)
{
	int c;
	if (w == 0)
	{
		cout << "brak danych";
		Sleep(2000);
		return;
	}
	cout << "Aby edytowac po: " << endl << "ID nacisnij - 1" << endl << "tytule - 2" << endl << endl << "1/2: ";
	cin >> c;

	if (c == 1)
	{
		int a, znak;
		system("cls");
		cout << "Aby edytowac po ID" << endl << "wpisz wartosc: ";
		cin >> a;
		if (a < 60 && a >0)
		{
			while (w)
			{
				if (w->ID == a)
				{
					cout << "Podaj:" << endl << endl;

					cout << "tytul:" << endl;
					znak = 0;
					znak = _getch();
					if (znak != 13)
					{
						cin >> w->tytul;
						cout << "--------------" << endl;
					}
					cout << "imie autora:" << endl;
					znak = 0;
					znak = _getch();
					if (znak != 13)
					{
						cin >> w->iautor;
						cout << "--------------" << endl;
					}
					cout << "nazwisko autora:" << endl;
					znak = 0;
					znak = _getch();
					if (znak != 13)
					{
						cin >> w->nautor;
						cout << "--------------" << endl;
					}
					cout << "kategorie:" << endl;
					znak = 0;
					znak = _getch();
					if (znak != 13)
					{
						cin >> w->kat;
						cout << "--------------" << endl;
					}
					cout << "pomyslnie edytowano!";
					Sleep(2000);
					return;
				}
				else
				{
					w = w->next;
					continue;
				}
			}

		}
		cout << "Nie ma ksiazki o podanym ID";
		Sleep(2000);
		return;
	}
	if (c == 2)
	{
		int b, znak;
		string a;
		system("cls");
		cout << "Aby edytowac po tytule" << endl << "wpisz tytul: ";
		cin >> a;
		while (w)
		{
			if (a == w->tytul)
			{
				cout << "Podaj:" << endl << endl;

				cout << "tytul:" << endl;
				znak = 0;
				znak = _getch();
				if (znak != 13)
				{
					cin >> w->tytul;
					cout << "--------------" << endl;
				}
				cout << "imie autora:" << endl;
				znak = 0;
				znak = _getch();
				if (znak != 13)
				{
					cin >> w->iautor;
					cout << "--------------" << endl;
				}
				cout << "nazwisko autora:" << endl;
				znak = 0;
				znak = _getch();
				if (znak != 13)
				{
					cin >> w->nautor;
					cout << "--------------" << endl;
				}
				cout << "kategorie:" << endl;
				znak = 0;
				znak = _getch();
				if (znak != 13)
				{
					cin >> w->kat;
					cout << "--------------" << endl;
				}
				cout << "pomyslnie edytowano!";
				Sleep(2000);
				return;
			}
			else
			{
				w = w->next;
			}
		}

	}
	cout << "Nie ma ksiazki o podanym ID";
	Sleep(2000);
	return;
}
void zmienstatus(book *w)
{
	int c;
	if (w == 0)
	{
		cout << "brak danych";
		Sleep(2000);
		return;
	}
	system("cls");
	cout << "Aby zmienic status po: \nID nacisnij - 1\ntytule - 2\n\n 1/2: ";
	cin >> c;

	if (c == 1)
	{
		int a, znak, x;
		char nt;
		system("cls");
		cout << "Aby zmienic po ID" << endl << "wpisz wartosc: ";
		cin >> a;
		if (a < 60 && a > 0)
		{
			while (w)
			{
				if (w->ID == a)
				{
					cout << "Podaj:" << endl << endl;

					cout << "date:" << endl;
					cout << "\tdzien: ";
					znak = 0;
					znak = _getch();
					if (znak != 13)
						cin >> w->data.dzien;

					cout << "\tmiesiac: ";
					znak = 0;
					znak = _getch();
					if (znak != 13)
						cin >> w->data.miesiac;

					cout << "\trok: ";
					znak = 0;
					znak = _getch();
					if (znak != 13)
						cin >> w->data.rok;
					cout << "--------------" << endl;

					cout << "Imie wypozyczajacego: ";
					znak = 0;
					znak = _getch();
					if (znak != 13)
					{
						cin >> w->iwyp;
						cout << "--------------" << endl;
					}
					cout << "Nazwisko wypozyczajacego: ";
					znak = 0;
					znak = _getch();
					if (znak != 13)
					{
						cin >> w->nwyp;
						cout << "--------------" << endl;
					}
					cout << "wpisz x, aby oznaczyc wypozyczona ksiazke" << endl;
					cin >> w->inne;

					cout << "pomyslnie zaktualizowano";
					Sleep(2000);
					return;

				}
				else
				{
					w = w->next;
				}
			}
			cout << "Nie ma ksiazki o podanym ID";
			Sleep(2000);
			return;
		}
	}
	if (c == 2)
	{
		int b, znak;
		string a;
		system("cls");
		cout << "Aby zmienic status po tytule\nwpisz tytul: ";
		cin >> a;
		while (w)
		{
			if (a == w->tytul)
			{
				cout << "Podaj:" << endl << endl;
				cout << "date:" << endl;

				cout << "\tdzien: ";
				znak = 0;
				znak = _getch();
				if (znak != 13)
					cin >> w->data.dzien;

				cout << "\tmiesiac: ";
				znak = 0;
				znak = _getch();
				if (znak != 13)
					cin >> w->data.miesiac;

				cout << "\trok: ";
				znak = 0;
				znak = _getch();
				if (znak != 13)
					cin >> w->data.rok;
				cout << "--------------" << endl;

				cout << "Imie wypozyczajacego: ";
				znak = 0;
				znak = _getch();
				if (znak != 13)
				{
					cin >> w->iwyp;
					cout << "--------------" << endl;
				}
				cout << "nazwisko wypozyczajacego: ";
				znak = 0;
				znak = _getch();
				if (znak != 13)
				{
					cin >> w->nwyp;
					cout << "--------------" << endl;
				}
				cout << "wpisz x, aby oznaczyc wypozyczona ksiazke";
				cin >> w->inne;

				cout << "pomyslnie zaktualizowano";
				Sleep(2000);
				return;
			}
			else
			{
				w = w->next;
			}
		}
		cout << "Nie ma ksiazki o podanym tytule";
		Sleep(2000);
		return;
	}
}
void wyszukaj(book *w)
{
	int c;
	if (w == 0)
	{
		cout << "brak danych";
		Sleep(2000);
		return;
	}
	cout << "Aby wyszukac po: " << endl << "ID nacisnij - 1" << endl << "tytule - 2" << endl << "nazwisku - 3" << endl << endl << "1 / 2 / 3: ";
	cin >> c;

	if (c == 1)
	{
		int a;
		system("cls");
		cout << "Aby wyszukac po ID" << endl << "wpisz wartosc: ";
		cin >> a;
		if (a < 60 && a >0)
		{
			while (w)
			{
				if (w->ID == a)
				{
					cout << w->ID << " ";
					cout << w->tytul << " ";
					cout << w->iautor << " ";
					cout << w->nautor << " ";
					cout << w->kat << " ";
					cout << w->data.dzien << " " << w->data.miesiac << " " << w->data.rok << " ";
					cout << w->iwyp << " ";
					cout << w->nwyp << " ";
					cout << endl;

					return;
				}
				else
				{
					w = w->next;
				}
			}

		}
		cout << "Nie ma ksiazki o podanym ID";
		Sleep(2000);
		return;
	}
	if (c == 2)
	{
		string a;
		system("cls");
		cout << "Aby wyswietlic po tytule" << endl << "wpisz tytul: ";
		cin >> a;
		while (w)
		{
			if (a == w->tytul)
			{
				cout << w->ID << " ";
				cout << w->tytul << " ";
				cout << w->iautor << " ";
				cout << w->nautor << " ";
				cout << w->kat << " ";
				cout << w->data.dzien << " " << w->data.miesiac << " " << w->data.rok << " ";
				cout << w->iwyp << " ";
				cout << w->nwyp << " ";
				cout << endl;

				return;
			}
			w = w->next;
		}
		cout << "Nie ma ksiazki o podanym tytule";
		Sleep(2000);
		return;
	}
	if (c == 3)
	{
		string a;
		system("cls");
		cout << "Aby wyswietlic po nazwisku" << endl << "wpisz nazwisko wypozyczajacego: ";
		cin >> a;
		while (w)
		{
			if (a == w->nwyp)
			{
				cout << w->ID << " ";
				cout << w->tytul << " ";
				cout << w->iautor << " ";
				cout << w->nautor << " ";
				cout << w->kat << " ";
				cout << w->data.dzien << " " << w->data.miesiac << " " << w->data.rok << " ";
				cout << w->iwyp << " ";
				cout << w->nwyp << " ";
				cout << endl;

				return;
			}
			w = w->next;
		}
		cout << "Nie ma ksiazki wypozyczonej przez ta osobe";
		Sleep(2000);
		return;
	}
	else
	{
		cout << "Tylko 1, 2 lub 3";
		Sleep(2000);
		return;
	}
}
void wyswietl(book *w)
{
	while (w)
	{
		cout << w->ID << " ";
		cout << setw(10) << w->tytul << " ";
		cout << setw(10) << w->iautor << " ";
		cout << setw(10) << w->nautor << " ";
		cout << setw(10) << w->kat << " ";
		cout << setw(2) << w->data.dzien << " / " << setw(2) << w->data.miesiac << " / " << setw(2) << w->data.rok << " ";
		cout << setw(10) << w->iwyp << " ";
		cout << setw(10) << w->nwyp << " ";
		cout << endl;

		w = w->next;
	}
}
void zapis(book *w)
{
	fstream plik("bazaksiazki.txt", ios::out);

	while (w)
	{
		plik << w->ID << " ";
		plik << w->tytul << " ";
		plik << w->iautor << " ";
		plik << w->nautor << " ";
		plik << w->kat << " ";
		plik << w->data.dzien << " " << w->data.miesiac << " " << w->data.rok << " ";
		plik << w->iwyp << " ";
		plik << w->nwyp << " ";
		plik << w->inne;

		if (w->next)
			plik << endl;

		w = w->next;
	}
	plik.close();
}
void wczytaj(book *w)
{
	if (w)
	{
		w->next = NULL;
		tail->prev = NULL;
	}

	ifstream plik;
	plik.open("bazaksiazki.txt", ios::in);

	if (plik.good())
	{
		cout << "Wczytuje plik..." << endl;

		while (plik.good())
		{
			book *el = new book;

			plik >> el->ID;
			//cout << el->ID << " ";
			plik >> el->tytul;
			//cout << el->tytul << " ";
			plik >> el->iautor;
			//cout << el->iautor << " ";
			plik >> el->nautor;
			//cout << el->nautor << " ";
			plik >> el->kat;
			//cout << el->kat << " ";

			plik >> el->data.dzien;
			//cout << el->data.dzien << " ";
			plik >> el->data.miesiac;
			//cout << el->data.miesiac << " ";
			plik >> el->data.rok;
			//cout << el->data.rok << " ";

			plik >> el->iwyp;
			//cout << el->iwyp << " ";
			plik >> el->nwyp;
			//cout << el->nwyp << " ";
			plik >> el->inne;
			//cout << el->inne << " ";

			//cout << endl;

			el->next = NULL;
			el->prev = tail;
			tail = el;

			if (el->prev) el->prev->next = el;
			else head = el;
			if (!plik.good()) { return; }
		}
	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
		return;
	}
}
void wyswietlwypoz(book *w)
{
	while (w)
	{
		if (w->inne == "x")
		{
			cout << w->ID << " ";
			cout << w->tytul << " ";
			cout << w->iautor << " ";
			cout << w->nautor << " ";
			cout << w->kat << " ";
			cout << w->data.dzien << " / " << w->data.miesiac << " / " << w->data.rok << " ";
			cout << w->iwyp << " ";
			cout << w->nwyp << " ";
			cout << endl;
		}
		w = w->next;
	}
}

int main()
{
	char x; //case'y
	int i, a = 1;
	char nt;

	int tab[60];
	for (i = 59; i >= 0; i--)
	{
		tab[i] = a;
		a++;
	}
	i = 59;

	cout << "Witaj w programie Ksiazki v4.1";
	Sleep(2000);

	while (1)
	{
		system("cls");
		cout << "Oto menu, wybierz funkcje, nacisnij odpowiedni znak, a nastepnie nacisnij enter\n";
		cout << "1) Dodaj nowa ksiazke\n"; //DONE
		cout << "2) Usun ksiazke\n"; //done
		cout << "3) Edytuj ksiazke\n"; //DONE
		cout << "4) Zmien status ksiazki\n"; //DONE
		cout << "5) Wyszukaj ksiazke\n"; //DONE
		cout << "6) Wyswietl baze\n"; //DONE
		cout << "7) Wyswietl ksiazki wypozyczone\n"; //done
		cout << "8) Zapisz na dysku\n";
		cout << "9) Odczytaj z pliku\n";
		cout << "x) Koniec pracy\n\n";

		cout << "Opcja: ";
		cin >> x;

		switch (x)
		{
		case '1': //DODAJ NOWA KSIAZKE
			do
			{
				dodajnakoniec(tab[i]);

				i--;
				if (i > 59)i = 59;

				do
				{
					system("cls");
					cout << "Wpisz:" << endl << "n - aby wyjsc do menu" << endl << "t - aby dodac kolejna pozycje" << endl << endl << "n/t: ";
					cin >> nt;
					if ((nt == 'n') || (nt == 't'))x = 0;
					else x = 1;
				} while (x == 1);
			} while (nt == 't');
			break;

		case '2':
			usun(head);
			i++;
			break;

		case '3':
			edytuj(head);
			break;

		case '4':
			zmienstatus(head);
			break;

		case '5': //WYSZUKIWANIE
			wyszukaj(head);
			_getch();
			break;

		case '6':   //WYSWIETLANIE BAZY KSIAZEK ...PO TYTULACH
			wyswietl(head);
			cout << "\nAby kontynuowac, nacisnij dowolny klawisz";
			_getch();
			break;


		case '7': //WYSWIETLANIE WYPOZ KSIAZEK
			wyswietlwypoz(head);
			_getch();
			break;

		case '8': //ZAPIS
			system("cls");
			zapis(head);
			cout << "pomyslnie zapisano\n\n ...Aby kontynuowac, nacisnij dowolny klawisz";
			_getch();

			break;

		case '9':  //ODCZYT
			wczytaj(head);
			cout << "Pomyslnie wczytano!\n\nAby kontynuowac, nacisnij dowolny klawisz";
			_getch();
			break;

		case 'x':
			system("cls");
			cout << "Do widzenia!";
			Sleep(2000);
			return 0;
		}
	}
}

