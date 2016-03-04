#include "arithmetic.h" 
#include <stdio.h>
#include <stdlib.h>

bool CheckBrackets(char* s)  // проверка скобок
{
	TStack<int> br(256);

	int arr[MAX_STR_LEN][2];
	int errors = 0, n = 0, j = 0, m = 1;

	bool res = 1;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			br.Put(m++);
		}
		else if (s[i] == ')')
		{
			if (br.IsEmpty())
			{
				res = 0;
				//cout << "Ошибка. Ненужная закрывающая скобка в позиции " << i << "\n";
				
				n++;
				arr[j][0] = 0;
				arr[j++][1] = m++;
				errors++;

				//break;
			}
			else
			{
				n++;
				arr[j][0] = br.GetDelTopElem();
				arr[j++][1] = m++;
			}
		}
	}

	if (br.IsEmpty() != 1)
	{
		res = 0;
		cout << "Ошибка. Ненужная открывающая скобка в позиции " << br.GetTopElem() << "\n";
	}

	while (!br.IsEmpty())
	{
		n++;
		arr[j][0] = br.GetDelTopElem();
		arr[j++][1] = 0;
		errors++;
	}
	
	printf("Wrong brackets: %d\n", errors);
	for (int i = 0; i < n; i++)
	{
		printf("%d   ", arr[i][0]);
		printf("%d\n", arr[i][1]);
	}
	
	cout << res;
	return res;
}

bool CheckOperations(char* s) //проверка стоят ли знаки операций в начале/конце
{
	char operation[] = "-+*/";
	bool res = 1;
	int len = strlen(s);

	for (int i = 0; i < 3; i++)
	{
		if (s[0] == operation[i])
		{
			cout << "Ошибка. Выражение начинается со знака операции\n";
			res = 0;
			break;
		}
		if (s[len - 1] == operation[i])
		{
			cout << "Ошибка. Выражение заканчивается знаком операции\n";
			res = 0;
			break;
		}
	}
	
	cout << res;
	return res;
}

bool CheckOperationsStandTogether(char* s) //проверка операций,стоящих подряд 
{
	char operation[] = "-+*/";
	int len = strlen(s);
	bool res = 1;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < 3; j++)
		if (s[i] == operation[j])
		{
			for (int j = 0; j < 3; j++)
			if (s[i + 1] == operation[j])
			{
				cout << "Ошибка. Операции стоят друг за другом в позициях " << i << " & " << i + 1 << "\n";
				res = 0;
				break;
			}
		}
	}

	cout << res;
	return res;
}
bool CheckOperandsStandTogether(char* s)  //проверка операндов,стоящих подряд
{
	char operand[] = "abcdefghijklmnopqrstuvwxyz";
	int len = strlen(s);
	bool res = 1;
	for (int i = 0; i < len-1; i++) 
	{
		for (int j = 0; j < 25; j++)
		if (s[i] == operand[j])
		{
			for (int j = 0; j < 25; j++)
				if (s[i + 1] == operand[j])
				{
					cout << "Ошибка. Операнды стоят друг за другом в позициях " << i << " & " << i + 1 << "\n";
					res = 0;
					break;
				}
		}
	}

	cout << res;
	return res;
}
bool CheckOperandBracketStandTogether(char* s)  //проверка операндов и операций,стоящих подряд
{
	char operand[] = "abcdefghijklmnopqrstuvwxyz";
	int len = strlen(s);
	bool res = 1;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < 25; j++)
		if ((s[i] == operand[j])&&(s[i + 1] == '('))
			{
			cout << "Ошибка. Операнд стоит перед скобкой в положении " << i << "\n";
				res = 0;
				break;
			}
		for (int j = 0; j < 25; j++)
		if ((s[i] == ')') && (s[i + 1] == operand[j]))
		{
			cout << "Ошибка. Операнд стоит после скобки в положении " << i+1 << "\n";
			res = 0;
			break;
		}
		for (int j = 0; j < 25; j++)
			if ((s[i] == '(') && (s[i + 1] == '-'))
			{
				cout << "Унарный минус после открывающей скобки " << i << "\n";
				res = 0;
				break;
			}
	}

	cout << res;
	return res;
}

void PartitionIntoTokens(char *s) //разделение на лексемы
{
	//
	int i, j = 0, k = 0, ind, iend;
	char operation[] = "-+*/";
	char operand[] = "abcdefghijklmnopqrstuvwxyz";
	char number[] = "0123456789";
	int len = strlen(s);
	char c[256];
	char lexem[32];

	i = 0;
	j = 0;
	ind = 0;
	while (i<len)
	{
		if ((s[i] == ' '))
		{
			iend = i;
			lexem[j] = '\0'; 
			if (strlen(lexem) > 0)
			{
				for (k = 0; k<strlen(lexem); k++)
				{
					c[ind] = lexem[k];
					ind++;
				}
				c[ind] = ' ';
				ind++;
			}
			i = iend + 1;
			lexem[0] = '\0';
			j = 0;
		}
		else if ((s[i] == '-') ||
			(s[i] == '+') ||
			(s[i] == '*') ||
			(s[i] == '/'))
		{
			iend = i;
			lexem[j] = '\0';
			for (k = 0; k < strlen(lexem); k++)
			{
				c[ind] = lexem[k];
				ind++;
			}
			c[ind] = ' ';
			ind++;
			c[ind] = s[i];
			ind++;
			c[ind] = ' ';
			ind++;
			i = iend + 1;
			lexem[0] = '\0';
			j = 0;
		}
		else
		{
			lexem[j] = s[i];
			i++;
			j++;
		}
	}
	lexem[j] = '\0';
	if (strlen(lexem) > 0)
	{
		for (k = 0; k < strlen(lexem); k++)
		{
			c[ind] = lexem[k];
			ind++;
		}
	}
	c[ind] = '\0';
	for (int i = 0; i < strlen(c); i++)
		cout << c[i];
}
int Priority(char ch)  //определение приоритета операций
{
	int res = -1;
	if (ch == '(')
		res = 0;
	if (ch == ')')
		res = 1;
	if ((ch == '-') || (ch == '+'))
		res = 2;
	if ((ch == '*') || (ch == '/'))
		res = 3;
	return res;
}
void ToPolish(char *s, char *c) //перевод в польскую запись
{
	int i, j = 0;
	TStack<char> op(30);
	//char c[256]; // output string

	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
		{
			if ((op.IsEmpty()) || (Priority(s[i]) > Priority(op.GetTopElem())))
				op.Put(s[i]);
			else
			{
				while ((op.IsEmpty() != true) && (Priority(s[i]) <= Priority(op.GetTopElem())))
					c[j++] = op.GetDelTopElem();
				op.Put(s[i]);
					
			}
		}
		else if (s[i] == '(') 
			op.Put(s[i]);
		else if (s[i] == ')')
		{
			while (op.GetTopElem() != '(')
			{
				c[j] = op.GetTopElem();
				j++;
				op.GetDelTopElem();
			}
			if (op.GetTopElem() == '(')
				op.GetDelTopElem();
		}
		else //if ((s[i] != '+') || (s[i] != '-') || (s[i] != '*') || (s[i] != '/')||(s[i] != '(')||(s[i] != ')'))//(isdigit(s[i])) || (isalpha(s[i])))
		{
			c[j] = s[i];
			j++;
			if (i < len - 1) 
			{
				if ((isdigit(s[i + 1]) == 0) && (s[i + 1]!='.'))
				{
					c[j] = ' ';
					j++;
				}
			}
			else
			{
					c[j] = ' ';
					j++;
			}
		}
		   
	}
	
	
	    while (op.IsEmpty() != true)
	    {
		   c[j] = op.GetDelTopElem();
		   j++;
	    }
	c[j] = '\0';

	for (int j = 0; j < strlen(c); j++)
		cout << c[j];
}

double PolishFindResult(char *s) //вычисляет значение выражения
{
	int i = 0;
	string lexem;
	TStack<double> op(30);
	double res, a, b, c;
	bool e=0;

	for (int i = 0; i < strlen(s); i++)
	{
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
		{
			if (s[i] == '+')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();
				c = a + b;
				op.Put(c);
			}
			if (s[i] == '-')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();
				c = b - a;
				op.Put(c);
			}
			if (s[i] == '*')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();
				c = a * b;
				op.Put(c);
			}
			if (s[i] == '/')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();

				if (a == 0)
				{
					cout << "Ошибка деления на ноль" << endl;
					return 0;
				}
				else
				{
					c = b / a;
				}

				op.Put(c);
			}
		}
		else if (s[i] != ' ')
		{
			if (isalpha(s[i]))
			{
				cout << "Введите значение переменной\n";
				cin >> a;//scanf("%f", &a);
				op.Put(a);
			}
			else 
			{
				lexem = lexem + s[i];
				//a = stod(lexem);
				//op.Put(a);
				if (s[i + 1] == ' ')
				{
					a = stod(lexem);
					op.Put(a);
					lexem = ""; // clear string
					continue;
				}
			}
		}
	}
	
	res = op.GetDelTopElem();
	if (op.IsEmpty())
		e = 1;
	return res;
}