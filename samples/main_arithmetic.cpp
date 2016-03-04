#include "arithmetic.h"
void main()
{
	setlocale(LC_ALL, "Russian");
	char s[256];// = "";
	char c[256];
	bool end = 0;
	int r, len;

	cout << "��� ������������ �����������, ����������� ���������� ��������������� ��������� � ������������� �������" << endl;
	cout << "���������� ��������: +, -, /, *, ^. " << endl;
	cout << "\n������� ���������\n";
	cin >> s;
	len = strlen(s);
	s[len] = '\0';
	do
	{
		
		cout << "�������� ��������\n";
		cout << "1. ���� �� ������ ��������� �� ������������ ��������� ������\n";
		cout << "2. ���� �� ������ ������������� ��������� � �������� ������\n";
		cout << "3. ���� �� ������ ��������� �������� ���������\n";
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

		cout << "\n\n��� �� ������ ������ ������?\n";
		cout << "�������� ��������\n";
		cout << "1. ���������� ������ ���������\n";
		cout << "2. ���������� � �������� ���������\n";
		cout << "3. �����\n";
		cin >> r;

		switch (r)
		{
		case 1:
		{
				  cout << "\n������� ���������\n";
				  cin >> s;
				  break;
		}
		case 2: continue;
		case 3: end = 1; break;
		}

	
	} 
	while (end != 1);
	cout << "\n�����\n";
 
}