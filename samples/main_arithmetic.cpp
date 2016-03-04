#include "arithmetic.h"
void main()
{
	setlocale(LC_ALL, "Russian");
	char s[256];// = "";
	char c[256];
	bool end = 0;
	int r, len;

	cout << "Вас приветствует Калькулятор, выполняющий вычисления арифметического выражения с вещественными числами" << endl;
	cout << "Допустимые операции: +, -, /, *, ^. " << endl;
	cout << "\nВведите выражение\n";
	cin >> s;
	len = strlen(s);
	s[len] = '\0';
	do
	{
		
		cout << "Выберите действие\n";
		cout << "1. Если Вы хотите проверить на корректность введенных данных\n";
		cout << "2. Если Вы хотите преобразовать выражение в польскую запись\n";
		cout << "3. Если вы хотите вычислить значение выражения\n";
		cin >> r;
		
		switch (r)
		{
		case 1:
		{
				  CheckBrackets(s);  
				  CheckOperations(s);
				  CheckOperandsStandTogether(s);  
				  CheckOperationsStandTogether(s); 
				  CheckOperandBracketStandTogether(s);
				  break;
		}
		case 2:
		{
				  PartitionIntoTokens(s);
				  cout << "\n";
				  ToPolish(s, c);
				  break;
		}
		case 3:
		{
				  PartitionIntoTokens(s);
				  cout << "\n";
				  ToPolish(s, c);
				  cout << "\n";
				  double result = PolishFindResult(c);
				  cout << result;
				  break;
		}

			
		}

		cout << "\n\nЧто Вы хотите делать дальше?\n";
		cout << "Выберите действие\n";
		cout << "1. Рассчитать другое выражение\n";
		cout << "2. Продолжить с текущего выражения\n";
		cout << "3. Выход\n";
		cin >> r;

		switch (r)
		{
		case 1:
		{
				  cout << "\nВведите выражение\n";
				  cin >> s;
				  break;
		}
		case 2: continue;
		case 3: end = 1; break;
		}

	
	} 
	while (end != 1);
	cout << "\nКонец\n";
 
}