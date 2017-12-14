// реализация пользовательского приложения
#include <iostream> 
#include "stack.h"
#include <cstring>
#include "arithmetic.h"

int main()
{
	char b[5] = "";
	do {
		system("cls");
		Arifmetics a;
		a.SetStroka();
		if ((a.Check()) == true) {
			a.Lexem();
			int t;
			do {
				system("cls");
				cout << "set stroca" << endl;
				cout << a.GetOnestring();
				cout << "vse normalno";
				a.PrintLexem();
				 t = a.SetVariable();
				 a.Polsky();
				 a.PrintPolsky();
				cout<< endl<< "calculate" << endl;
				cout << a.calculate()<<endl;
				if (t!=0) {
					cout << "perecalculate?";
					cin >> b;
				}
			} while ((t!=0)&&(!strcmp(b, "yes")));
		}
		else  cout << "vse ne normalno"<<endl;
		cout << "Postorim?";
		cin >> b;
	} while (!strcmp(b,"yes"));
	system("cls");  


	return 0;
}

