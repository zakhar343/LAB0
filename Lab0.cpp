#include <iostream>
#include "Array.h"
#include "List.h"
#include "Sequence.h"

using namespace std;

template<typename T>
void my_realloc(T *arr, int size, int new_size);

template<typename T>
struct node{
	T cell;
	struct node *next=NULL;
};

template<typename T>
void Test(Sequence <T> *a);

int main(){
	int e,d,f,g;
	List<int> a;
	Array<int> b;
	int c=0;
	cout << "Введите, с чем хотите работать\n1)Массив\n2)Список";
	cin >> g;
	switch(g){
	case 1:
	cout << "Введите, что хотите сделать\n1)Работать с последовательностью\n2)Тестировать программу";
		cin >> e;
		if(e==1)do{
		cout << "Введите, что хотите сделать\n1)Добавить элемент в начало\n2)Добавить элемент в конец\n3)Вывести длину последовательности\n4)Вывести первый элемент\n5)Вывести последний элемент\n6)Вывести элемент по номеру\n7)Вставить элемент на i позицию\n8)Удалить элемент\n9)Выделить подпоследовательность\n10)Вывести последовательность\n11)Завершить программу\n";
		cin >> c;
		switch(c){
		case 1:
			cout << "Enter element\n";
			cin >> d;
			b.Prepend(d);
			break;
		case 2:
			cout << "Enter element\n";
			cin >> d;
			b.Append(d);
			break;
		case 3:
			cout << b.GetLength() << "\n";
			break;
		case 4:
			cout << b.GetFirst() << "\n";
			break;
		case 5:
			cout << b.GetLast() << "\n";
			break;
		case 6:
			cout << "Enter index\n";
			cin >> d;
			cout << b.Get(d) << "\n";
			break;
		case 7:
			cout << "Enter index\n";
			cin >> d;
			cout << "Enter element\n";
			cin >> f;
			b.InsertAt(d,f);
			break;
		case 8:
			cin >> d;
			b.Remove(d);
			break;
		case 9:
			cout << "Enter start index\n";
			cin >> d;
			cout << "Enter end index\n";
			cin >> f;
			b.GetSubsequence(d,f);
			break;
		case 10:
			b.print();
			break;
		}
	}while (c<11);
		if(e==2)Test(&b);
	break;
	case 2:
		cout << "Введите, что хотите сделать\n1)Работать с последовательностью\n2)Тестировать программу";
		cin >> e;
		if(e==1)do{
		cout << "Введите, что хотите сделать\n1)Добавить элемент в начало\n2)Добавить элемент в конец\n3)Вывести длину последовательности\n4)Вывести первый элемент\n5)Вывести последний элемент\n6)Вывести элемент по номеру\n7)Вставить элемент на i позицию\n8)Удалить элемент\n9)Выделить подпоследовательность\n10)Вывести последовательность\n11)Завершить программу\n";
		cin >> c;
		switch(c){
		case 1:
			cout << "Enter element\n";
			cin >> d;
			a.Prepend(d);
			break;
		case 2:
			cout << "Enter element\n";
			cin >> d;
			a.Append(d);
			break;
		case 3:
			cout << a.GetLength() << "\n";
			break;
		case 4:
			cout << a.GetFirst() << "\n";
			break;
		case 5:
			cout << a.GetLast() << "\n";
			break;
		case 6:
			cout << "Enter index\n";
			cin >> d;
			cout << a.Get(d) << "\n";
			break;
		case 7:
			cout << "Enter index\n";
			cin >> d;
			cout << "Enter element\n";
			cin >> f;
			a.InsertAt(d,f);
			break;
		case 8:
			cout << "Enter element\n";
			cin >> d;
			a.Remove(d);
			break;
		case 9:
			cout << "Enter start index\n";
			cin >> d;
			cout << "Enter end index\n";
			cin >> f;
			a.GetSubsequence(d,f);
			break;
		case 10:
			a.print();
			break;
		}
	}while (c<11);
		if(e==2)Test(&a);
	break;
	}
	return 0;
}

template<typename T>
void Test(Sequence <T> *a){
    bool flag=1;
    cout << "Длина начальной последовательности = " << a->GetLength();
    if(a->GetLength()==0)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Добавляем элемент 51\n";
    a->Append(51);
    cout << "Длина последовательности = " << a->GetLength();
    if(a->GetLength()==1)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Первый элемент последовательности = " << a->GetFirst();
    if(a->GetFirst()==51)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Последний элемент последовательности = " << a->GetLast();
    if(a->GetLast()==51)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Нулевой элемент последовательности = " << a->Get(0);
    if(a->Get(0)==51)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Добавляем элемент 33 в начало\n";
    a->Prepend(33);
    cout << "Длина последовательности = " << a->GetLength();
    if(a->GetLength()==2)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Первый элемент последовательности = " << a->GetFirst();
    if(a->GetFirst()==33)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Последний элемент последовательности = " << a->GetLast();
    if(a->GetLast()==51)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Первый по индексу элемент последовательности = " << a->Get(1);
    if(a->Get(1)==51)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Добавляем элемент 12 на место c индексом 1\n";
    a->InsertAt(1,12);
    cout << "Длина последовательности = " << a->GetLength();
    if(a->GetLength()==3)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Первый элемент последовательности = " << a->GetFirst();
    if(a->GetFirst()==33)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Последний элемент последовательности = " << a->GetLast();
    if(a->GetLast()==51)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Элемент последовательности с индексом 1 = " << a->Get(1);
    if(a->Get(1)==12)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Выделяем подпоследовательность с индексами 1-2\n";
    a->Remove(33);
    cout << "Длина последовательности = " << a->GetLength();
    if(a->GetLength()==2)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Первый элемент последовательности = " << a->Get(0) << "\nВторой элемент последовательности = " << a->Get(1);
    if((a->Get(1)==51) and (a->Get(0)==12))
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Удаляем элемент 51\n";
    a->Remove(51);
    cout << "Длина последовательности = " << a->GetLength();
    if(a->GetLength()==1)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Первый элемент последовательности = " << a->GetFirst();
    if(a->GetFirst()==12)
		cout << " - Правильно\n";
    else{
		cout << " - Неправильно\n";
		flag=0;}
    cout << "Последний элемент последовательности = " << a->GetLast();
    if(a->GetLast()==12)
		cout << " - Правильно\n";
	else{
		cout << " - Неправильно\n";
		flag=0;}
    if(flag==1) cout << "======ТЕСТ ПРОЙДЕН УСПЕШНО======"; else cout << "======ТЕСТ HE ПРОЙДЕН======";
};

template<typename T>
void my_realloc(T *arr, int size, int new_size)
{
    T *new_arr = new T [new_size];
    size = size < new_size ? size : new_size;
 
    for (int i = 0; i < size; ++i)
        new_arr[i] = arr[i];
    arr = new_arr;
};