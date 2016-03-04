#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 100000000;

template <class ValType>
class TStack
{
protected:
	ValType *pMem;
	int Size;                                            // размер стека
	int Top;                                             // индекс последнего занятого в мем
	//int Mem[Size]; //

public:
	TStack(int s);                                       // конструктор инициализатор
	TStack(const TStack &s);                             // конструктор копирования
	~TStack();                                           // деструктор
	int GetSize() const { return Size; }                 // 
	//int GetTopIndex() const { return Top; }              // получить индекс последнего занятого элемета
	int GetNextIndex(int index) { return ++index; }
	int GetPrevIndex(int index) { if (index != 0) return index--; else throw "Стек пуст"; }
	bool IsEmpty() const;                            //проверка на пустоту
	bool IsFull() const;                             //проверка на переполненность
	void Put(const ValType n);                       //положить в стек
	ValType GetTopElem();                            //взять из стека без удаления
	ValType GetDelTopElem();                         //взять из стека с удалением
	void Print();                                    //печать значений

	bool operator==(const TStack &s) const;  // сравнение
	bool operator!=(const TStack &s) const;  // сравнение
	TStack& operator=(const TStack &s);     // присваивание

	//TStack  operator+(const ValType &val);   // 
	//TStack  operator-(const ValType &val);   // 
};
	

template <class ValType>
TStack<ValType>::TStack(int s)
{
	if (s < 0 || s > MAX_STACK_SIZE)
		throw "Неправильный размер стека";

	pMem = new ValType[s];
	Size = s;
	Top = -1;

	for (int i = 0; i < Size; i++)
		pMem[i] = 0;

}
template <class ValType> 
TStack<ValType>::TStack(const TStack<ValType> &s) // конструктор копирования
{
	Size = s.GetSize();
	Top = s.Top;
	pMem = new ValType[Size];

	for (int i = 0; i < Size; i++)
		pMem[i] = s.pMem[i];
}
template <class ValType>
TStack<ValType>::~TStack()
{
	delete[] pMem;
}
template <class ValType>
bool TStack<ValType>::IsEmpty() const //проверка на пустоту
{
	bool res = 0;
	if (Top == -1)
		res = 1;
	return res;
} 
template <class ValType>
bool TStack<ValType>::IsFull() const //проверка на переполненность
{
	bool res = 0;
	if (Top == Size - 1)
		res = 1;
	return res;
}
template <class ValType>
void TStack<ValType>::Put(const ValType n) //положить в стек
{
	if (pMem == NULL)
		throw "Память не выделяется";
	else if (IsFull())
		throw "Переполнение стека";
	else
	{
		//Top = GetNextIndex(Top);
		pMem[++Top] = n;
		//DataCount++;
	}
} 
template <class ValType>
ValType TStack<ValType>::GetTopElem() //взять из стека без удаления
{
	ValType temp = -1;
	if (pMem == NULL)
		throw "Память не выделяется";
	else if (IsEmpty())
	throw "Стек пуст";
	else
	{
		temp = pMem[Top];
		//DataCount--;
	}
	return temp;
};
template <class ValType>
ValType TStack<ValType>::GetDelTopElem() //взять из стека с удалением
{
	ValType temp = -1;
	if (pMem == NULL)
		throw "Память не выделяется";
	else if (IsEmpty())
	throw "Стек пуст";
	else
	{
		temp = pMem[Top--];
		//Top = GetPrevIndex(Top);
		//DataCount--;
	}
	return temp;
}
template <class ValType>
void TStack<ValType>::Print() //печать значений
{
	for (int i = 0; i < Size; i++)
		printf("%d", pMem[i]);
	printf("\n");
}

template <class ValType> // сравнение
bool TStack<ValType>::operator==(const TStack &s) const
{
	bool res = 1;
	if (Size != s.GetSize())
	{
		res = 0;
		//break;
	}
	else
	for (int i = 0; i < Size; i++)
	if (pMem[i] != s.pMem[i])
	{
		res = 0;
		break;
	};
	return res;
}

template <class ValType> // сравнение
bool TStack<ValType>::operator!=(const TStack &s) const
{
	bool res = 0;
	if (Size != s.GetSize())
	{
		res = 1;
		//break;
	}
	else
	for (int i = 0; i < Size; i++)
	if (pMem[i] != s.pMem[i])
	{
		res = 1;
		break;
	};
	return res;
}
template <class ValType> // присваивание
TStack<ValType>& TStack<ValType>::operator=(const TStack &s)
{
	if (this != &s)
	{
		if (Size != s.GetSize())
		{
			delete[] pMem;
			pMem = new ValType[s.GetSize()];
		}
		Size = s.GetSize();
		Top = s.Top;
		for (int i = 0; i < Size; i++)
			pMem[i] = s.pMem[i];
	}
	return *this;
}