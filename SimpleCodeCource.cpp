#include "Header.h"
//#include "SimpleCodeCource.h"

class Apple;        //Чтобы класс Human, мог видеть Apple.
class myException;

int Fact(int N)
{
	if (N == 0) return 0;
	if (N == 1) return 1;

	cout << N << endl;

	return N * Fact(N - 1);
}

void Pointers()
{
	const int SIZE = 5;
	int arr[SIZE]{ 5,10,15,20,25 };

	for (int i = 0; i < SIZE; i++)
	{
		cout << &arr[i] << endl;
	}

	cout << *(arr + 10) << endl;
}

void SwapPointer(int* pa, int* pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

template <class T>
T SwapAny(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void DynamicArray(int* rows, int* cols)
{
	int row = *rows;                // row - строки, col - колонки
	int col = *cols;                // Разыменовываем полученные значение и создаем из них локальные

	int** arr = new int* [row];     // Выделение памяти для массива указателей

	for (int i = 0; i < row; i++)   // Создание массива указателей для одномерных массивов
	{
		arr[i] = new int[col];      // Выделение памяти для одномерных массивов
	}

	for (int i = 0; i < row; i++)   // Заполнение массива и вывод на экран
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < row; i++)   // Очищение памяти и удаление массива.
	{
		delete[] arr[i];            // очищаем память сначала из всех строчек
	}
	delete[] arr;                   // а затем и сам массив в указателями на эти строчки
}

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void CopyDynamicArray()
{
	int size1Arr = 10;
	int size2Arr = 8;

	int* firstArr = new int[size1Arr];      // Выделяем память под первый массив
	int* secondArr = new int[size2Arr];     // Выделяем память под второй массив
	FillArray(firstArr, size1Arr);
	FillArray(secondArr, size2Arr);

	cout << "First Array: " << endl;
	ShowArray(firstArr, size1Arr);
	cout << "Second Array: " << endl;
	ShowArray(secondArr, size2Arr);

	delete[] firstArr;                      // Очищаем первый массив
	firstArr = new int[size2Arr];           // Выделяем заново под него память с size как у второго массива
	for (int i = 0; i < size2Arr; i++)
	{
		firstArr[i] = secondArr[i];         // Переписываем данные из второго массива в первый
	}

	cout << "First Array: " << endl;
	ShowArray(firstArr, size1Arr);
	cout << "Second Array: " << endl;
	ShowArray(secondArr, size2Arr);

	delete[] secondArr;
	delete[] firstArr;
}

void push_back(int*& arr, int& size, const int value)
{
	int* newarr = new int[size + 1];  // Создаем новый массив с увеличенным размером

	for (int i = 0; i < size; i++)  // Переписываем данные из старого массива в новый
	{
		newarr[i] = arr[i];
	}

	newarr[size] = value;           // Добавляем значение в последний элемент массива
	size++;                         // Указываем, что размер массива увеличился

	delete[] arr;
	arr = newarr;                   // Присваиваем новый указатель на массив
}

void pop_back(int*& arr, int& size)
{
	size--;                         // Уменьшаем размер массива
	int* newarr = new int[size];    // Создаем новый массив

	for (int i = 0; i < size; i++)  // Переписываем данные из старого массива в новый
	{
		newarr[i] = arr[i];
	}

	delete[] arr;
	arr = newarr;                   // Присваиваем новый указатель на массив
}

void push_front(int*& arr, int& size, const int value)
{
	int* newarr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newarr[i + 1] = arr[i];
	}

	newarr[0] = value;
	size++;

	delete[] arr;
	arr = newarr;
}

void pop_front(int*& arr, int& size)
{
	size--;
	int* newarr = new int[size];

	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i + 1];
	}

	delete[] arr;
	arr = newarr;
}

void push_mid(int*& arr, int& size, const int value)
{
	int* newarr = new int[size + 1];
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == 3)
		{
			newarr[i] = value;
			j--;
		}
		else {
			newarr[i] = arr[j];
		}
		j++;
	}

	delete[] arr;
	arr = newarr;
}

void pop_mid(int*& arr, int& size)
{
	size--;
	int* newarr = new int[size];
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == 3)
		{
			newarr[i] = arr[j + 1];
			j++;
		}
		else {
			newarr[i] = arr[j];
		}
		j++;
	}

	delete[] arr;
	arr = newarr;
}

void myStrlen(const char* str)
{
	cout << strlen(str) << endl;
	int counter = 0;

	while (str[counter] != '\0')
	{
		counter++;
	}

	for (int i = 0; ; i++)
	{
		if (str[i] == '\0')
		{
			cout << i << endl;
			break;
		}
	}

	for (; str[counter] != '\0'; counter++)
	{
	}

	cout << counter << endl;;
}


class MyString
{
public:
	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	~MyString()
	{
		delete[] this->str;
	}

	MyString(const MyString& other)             //Конструктор копирования
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	MyString(MyString&& other)             //Конструктор перемещения
	{
		this->length = other.length;
		this->str = other.str;

		other.str = nullptr;
	}

	MyString& operator=(const MyString& other)  //Перегрузка =
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	MyString operator+(const MyString& other)  //Перегрузка +
	{
		MyString newStr;

		int thisLenght = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLenght + otherLength;
		newStr.str = new char[thisLenght + otherLength + 1];

		int i = 0;
		for (; i < thisLenght; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLenght + otherLength] = '\0';

		return newStr;
	}

	bool operator==(const MyString& other)  //Перегрузка ==
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const MyString& other)  //Перегрузка !=
	{
		return !(this->operator==(other));
	}

	char& operator[](int index)
	{
		return this->str[index];
	}

	void Print()
	{
		cout << str << endl;
	}

	int Length()
	{
		return length;
	}

private:
	char* str;
	int length;
};

class Human
{
private:
	//Свойства класса (поля)
	int age;
	string name;
	int humanID;
	static int ID;

public:
	//Конструктор по-умолчанию
	Human()
	{
		age = 0;
		name = "No Name";
		ID++;
		humanID = ID;
	}

	//Перегрузка конструктора
	Human(int age, string name)
	{
		this->age = age;
		this->name = name;
		ID++;
		this->humanID = ID;
		cout << this << endl;
	}

	Human(string name)
	{
		this->name = name;
		this->age = 0;
	}

	//Делигирующий конструктор
	Human(string name, int age) : Human(name)
	{
		this->age = age; //Name берётся из констуктора Human(name);
	}

	//Деструктор
	~Human()
	{
		cout << "Destructor" << this << endl;
	}

	//Конструктор копирования
	Human(const Human& other)
	{
		this->name = other.name;
		this->age = other.age;
		cout << "Copy Constructor" << this << endl;
	}

	//Перегрузка оператора =
	Human& operator= (const Human& other)
	{
		this->name = other.name;
		this->age = other.age;
		cout << "Operator =" << this << endl;

		return *this;
	}

	void PrintInfo()                        //Метод (функция)
	{
		cout << "Name: " << name << "\tAge: " << age << endl;
	}

	void SetAge(int valueAge)               //Сеттер
	{
		age = valueAge;
	}

	void SetName(string name)
	{
		this->name = name;
	}

	string GetName()
	{
		return name;
	}

	int GetAge()                            //Геттер
	{
		return age;
	}

	int GetID()
	{
		return humanID;
	}

	//Определение методов вне класса
	void TakeApple(Apple& apple);
};

int Human::ID = 0;          //Объявление статической переменной

class Apple
{
private:
	int weight;
	string color;
	//Статическое поле класса
	static int count;
public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		count++;
	}

	static int GetCount()
	{
		return count;
	}

	//Статический метод класса
	static void ChangeColor(Apple& apple, string color)
	{
		apple.color = color;
	}
	//нестатический метод класса
	void ChangeColorNoStatic(string color)
	{
		this->color = color;
	}

	//Дружественный метод класса
	friend void Human::TakeApple(Apple& apple);
};

int Apple::count = 0;       //Объявление статической переменной

//Определение методов вне класса
void Human::TakeApple(Apple& apple)
{
	cout << "Take Apple " << endl << "Weight: " << apple.weight << "\tColor: " << apple.color << endl;
}

//Наследование классов
class Student : public Human
{
public:
	int group;

	void Learn()
	{
		cout << "I'm learning!" << endl;
	}
private:

};

//Наследование унаследованного класса
class ExteramuralStudent : public Student
{
public:
	void Learn()
	{
		cout << "I'm learning like exteramural" << endl;
	}
};

class Point
{
private:
	int x;
	int y;

public:
	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Print()
	{
		cout << "X: " << this->x << "\t" << "Y: " << this->y << endl;
	}

	//Перегрузка оператора ==
	bool operator ==(const Point& other)
	{
		/*if (this->x == other.x && this->y == other.y)
		{
			return true;
		}
		else
		{
			return false;
		}*/

		return this->x == other.x && this->y == other.y;
	}

	//Перегрузка оператора !=
	bool operator !=(const Point& other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	//Перегрузка оператора +
	Point operator +(const Point& other)
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;


		return result;
	}

	//Перегрузка префиксного инкремента
	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}

	//Перегрузка постфиксного инкремента 
	//Определение методов вне класса
	Point& operator++(int value);

	//Дружественная функция
	friend void ChangeX(Point& value);

	//Перегрузка операторов ввода-вывода (<< и >>)
	friend ostream& operator<<(ostream& os, const Point& point);
	friend istream& operator>>(istream& is, Point& point);
};

Point& Point::operator++(int value)         //Определение методов вне класса
{
	Point temp(*this);
	this->x++;
	this->y++;
	return temp;
}

void ChangeX(Point& value)  //Дружественная функция
{
	value.x = 0;
}

class MyClass
{
private:
	int Size;
	int arr[5]{ 5,10,15,20,25 };
public:
	int* data;

	//Конструктор
	MyClass(int size)
	{
		this->Size = size;
		this->data = new int[size]; //Выделяем динамически память для массива

		for (int i = 0; i < size; i++)  //Заполняем массив элементами
		{
			data[i] = i;
		}
	};

	//Конструктор копирования
	MyClass(const MyClass& other)
	{
		this->Size = other.Size;
		this->data = new int[other.Size];

		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	//Деструктор
	~MyClass()
	{
		delete[] data;
	};

	//Перегрузка оператора индексирования
	int& operator[](int index)
	{
		return arr[index];
	}
};

//Внешний и внутренний класс
class Image
{
public:
	void GetImageInfo()
	{
		for (int i = 0; i < LENGTH; i++)
		{
			//Обращаемся к каждому объекту массива объектов
			cout << pixels[i].GetInfo() << endl;
		}
	}

private:
	//Внутренний класс
	class Pixel
	{
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}

		string GetInfo()
		{
			return "Pixel: R= " + to_string(r) + "\tG= " + to_string(g) + "\tB= " + to_string(g);
		}

	private:
		int r;
		int g;
		int b;
	};

	static const int LENGTH = 5;

	//Объект Pixel в виде массива
	Pixel pixels[LENGTH]
	{
		Pixel(0,4,65),
		Pixel(4,14,10),
		Pixel(111,4,24),
		Pixel(244,244,14),
		Pixel(111,179,64),
	};
};
class A
{
public:
	A()
	{
		cout << "Constructor A" << endl;
	}

	A(string msg)
	{
		this->msgOne = msg;
	}

	void PrintMsg()
	{
		cout << msgOne << endl;
	}

	string msgOne = "First Message";
private:
	string msgTwo = "Second Message";
protected:
	string msgThree = "Third Message";
};
class B : public A
{
public:
	//Констуктор вызывающий перегруженный конструктор А
	B() :A("New message")
	{

	}

	void PrintMessage()
	{
		cout << msgOne << endl;
		cout << msgThree << endl;
	}
};

//Абстрактный класс
class Weapon
{
public:
	//Чисто виртуальная функция
	virtual void Shoot() = 0;

	void Foo()
	{
		cout << "Foo()" << endl;
	}

};
class Gun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}
};
class SubmachineGun : public Gun
{
public:
	//Переопределенный виртуальный метод класса Gun
	void Shoot() override
	{
		cout << "BANG BANG BANG!" << endl;
	}
};
class Player
{
public:
	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}
};

//Интерфейс (чисто виртуальный класс)
class IBicycle
{
public:
	virtual void Turn() = 0;
	virtual void Ride() = 0;
};
class SimpleBicycle : public IBicycle
{
public:
	void Turn() override
	{
		cout << "Turn SimpleBicycle" << endl;
	}
	void Ride() override
	{
		cout << "Go Ride SimpleBicycle" << endl;
	}
};
class Rider
{
public:
	void RideOn(IBicycle& bicycle)
	{
		cout << "Let's go Ride!" << endl;
		bicycle.Ride();
		cout << "Don't forget to turn" << endl;
		bicycle.Turn();
	}
};

//Перегрузка операторов ввода-вывода (<< и >>)
ostream& operator<<(ostream& os, const Point& point)
{
	os << point.x << " " << point.y;
	return os;
}
istream& operator>>(istream& is, Point& point)
{
	is >> point.x >> point.y;
	return is;
}

//Свой класс исключений
class myException : public exception
{
public:
	myException(const char* msg, int dataState) : exception(msg)
	{
		this->dataState = dataState;
	}

	int getDataState()
	{
		return dataState;
	}
private:
	int dataState;
};

void exceptFoo(int value)
{
	if (value < 0)
	{
		throw exception("Number is negative");
	}
	if (value == 0)
	{
		throw "Number is = 0";
	}
	if (value == 1)
	{
		throw myException("myException: Number is equals 1", value);
	}

	cout << "Number is: " << value << endl;
}

class PC
{
public:
	//Enum
	enum PCState
	{
		ON,
		OFF,
		SLEEP
	};

	void SetState(PCState state) { this->state = state; }
	PCState GetState() { return state; }

private:
	PCState state;
};

template<typename T>
class templateClass
{
public:
	templateClass(T value)
	{
		this->value = value;
	}

	void DataTypeSize()
	{
		cout << sizeof(value) << endl;
	}
protected:
	T value;
};

template<typename T>
class templateInfo : public templateClass<T>
{
public:
	templateInfo(T value) : templateClass<T>(value)
	{
		//this->value = value;
	}
	void ShowTypeName()
	{
		cout << typeid(this->value).name() << endl;
	}
};

template<typename T>
class Printer
{
public:
	void Print(T value)
	{
		cout << value << endl;
	}
};

template<>
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << ":" << value << ":" << endl;
	}
};

namespace FirstNamespace
{
	void Foo()
	{
		cout << "Visible only in this namespace" << endl;
	}

	int a;

	class test
	{
	public:
		void Foo()
		{
			cout << "Visible in namespace and class only" << endl;
		}
	private:
		int b;
	};
}

struct MyStruct
{
	int a;
	void Print(int a)
	{
		this->a = a;
	}
};

template<typename T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)
	{
		this->ptr = ptr;
		cout << "Constructor" << endl;
	}

	~SmartPointer()
	{
		delete ptr;
		cout << "Destructor" << endl;
	}

	T& operator*()
	{
		return *ptr;
	}

private:
	T* ptr;
};

//Односвязный список
template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();
	void push_back(T data);
	void push_front(T data);
	void clear();
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();
	int GetSize() { return Size; }

	T& operator[] (const int index);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);			//Изначально создается объект, куда передаётся текущий head
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;		//Временная переменная в которую записываем значение предыдущего элемента, после которого вставляем данные

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;		//Полученный адрес следующего элемента в предыдущем помещаем во временную переменную
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);		//Помещаем адрес следующего элемента в новый элемент
		previous->pNext = newNode;									//Помещаем адрес нового элемента в предыдущий элемент

		Size++;
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;		//Временная переменная в которую записываем значение предыдущего элемента, после которого вставляем данные

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;		//Полученный адрес следующего элемента в предыдущем помещаем во временную переменную
		}

		Node<T>* toDelete = previous->pNext;		//Запоминаем адрес того элемента, который собираемся удалить.
		previous->pNext = toDelete->pNext;			//Перемещаем адрес из удаляемого элемента в предыдущий, чтобы предыдущий указывал на следующий

		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void PrintList(const list<T>& lst)
{
	for (auto it = lst.cbegin(); it != lst.cend(); ++it)
	{
		cout << *it << endl;
	}
}

void ThreadWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID thread = " << this_thread::get_id() << "\t ThreadWork\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

void ThreadWorkParam(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "Thread Started" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "A + B = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "Thread Stopped" << endl;
}

//=================MAIN=================//
int main()
{
	//int a = 5, b = 6, size = 10;
	//const char* str = "Hello";




	// queue, priority_queue
	/*
	queue<int> q;
	q.push(10);									//Вставляет элемент в конец очереди
	q.push(20);
	q.push(30);
	q.push(40);
	cout << "Last element: " << endl;
	cout << q.back() << endl;					//Показать последний элемент
	cout << "First element: " << endl;
	cout << q.front() << endl;					//Показать первый элемент

	cout << "QUEUE" << endl;
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}

	priority_queue<int, vector<int>> pqvec;
	pqvec.push(40);
	pqvec.push(90);
	pqvec.push(10);
	pqvec.push(50);
	cout << "First element: " << endl;
	cout << pqvec.top() << endl;				//Можно увидеть только первый элемент, последний нельзя

	cout << "PRIORITY_QUEUE" << endl;
	while (!pqvec.empty())
	{
		cout << pqvec.top() << endl;
		pqvec.pop();
	}
	*/

	// Threads with params
	/*
	thread th(ThreadWorkParam, 1, 2);									//Указывается название функции для передачи в поток и через , указываются параметры

	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID thread = " << this_thread::get_id() << "\t Main\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();
	*/

	// Stack
	/*
	stack<int> st;
	st.push(10);					//Создает копию и копирует в стек
	st.emplace(15);					//Сразу создает объект в стеке
	st.emplace(20);
	st.emplace(25);
	cout << st.top() << endl;		//Показать верхний элемент стека
	st.pop();
	cout << st.top() << endl;

	auto ast = st._Get_container();	//В основе стека лежит deque, который можно извлечь и использовать как обычный deque
	cout << ast[2] << endl;

	cout << "Stack with List: " << endl;
	stack<int, list<int>> stlist;	//Ограничить лист методами стэка
	stlist.emplace(5);
	stlist.emplace(12);
	while (!stlist.empty())			//Извлекать каждый элемент и выводить его на экран
	{
		cout << stlist.top() << endl;
		stlist.pop();
	}

	auto bst = stlist._Get_container();
	bst.push_back(11);
	*/

	// Thread
	/*
	thread th(ThreadWork);
	thread th2(ThreadWork);
	//th.detach();														//Удалить поток, когда программа завершена, не дожидаясь завершения самого потока.

	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID thread = " << this_thread::get_id() << "\t Main\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();															//Дождаться завершения выполнения потока.
	th2.join();

	this_thread::sleep_for(chrono::milliseconds(1000));					//Ожиданеие потока 1 сек.
	cout << this_thread::get_id() << endl;								//Вывод ID текущего потока
	*/

	// STL Map
	/*
	pair<int, string> p = { 0, "Phone" };
	cout << p.first << endl;
	cout << p.second << endl;

	map<int, string> myMap;
	myMap.insert(make_pair(1, "Keyboard"));			//Варианты вставок элементов в map
	myMap.insert(pair<int, string>(2, "Laptop"));
	myMap.insert(p);
	myMap.emplace(3, "Monitor");

	auto it = myMap.find(2);						//Поиск элементов в map
	if (it != myMap.end())							//В случае, если элемент не будет найден, то без if будет ошибка при обращении к it->second
	{
		cout << it->second << endl;
	}
	else
	{
		cout << "Element NOT found" << endl;
	}

	myMap[3] = "Mouse";
	cout << "Element in []: ";
	cout << myMap[3] << endl;
	myMap[22] = "Lamp";								//Создаст новый элемент, если не найдет его в map
	*/

	// typedef
	/*
	int_vector myVector = { 1,2,3 };
	float_vector myVector2 = { 1.3f, 2.0f, 3.0f };
	*/

	// STL Set
	/*
	set<int> mySet = { 5,1,12 };
	auto result0 = mySet.insert(9);			//Вставится по правилу бинарного дерева, в result вернётся значение и true/false

	int value;
	cout << "Enter a number for find: " << endl;
	cin >> value;

	if (mySet.find(value) != mySet.end())	//Поиск элемента
	{
		cout << "Number " << value << " is found!" << endl;
	}
	else
	{
		cout << "Number " << value << " is NOT found!" << endl;
	}

	auto result1 = mySet.erase(12);			//Возвращает 1 или 0 при удалении

	for (auto& el : mySet)
	{
		cout << el << endl;
	}

	multiset<int> mulSet = { 1,1,5,1,12 };

	auto result2 = mulSet.lower_bound(1);	//Вернёт указатель на первый найденный элемент
	auto result3 = mulSet.upper_bound(1);	//Вернёт указатель на следующий элемент после 1 (по возрастанию)
	auto result4 = mulSet.equal_range(1);   //Вернёт данные от upper_bound до lower_bound

	for (auto& el : mulSet)
	{
		cout << el << endl;
	}
	*/

	// STL Deque
	/*
	deque<int> dq = { 1,3,4 };			//Что-то между list и vector
	dq.push_back(66);
	dq.push_front(99);					//По факту не копирует массив, а просто указывает на новую ячейку памяти
	for (int &element : dq)
	{
		cout << element << endl;
	}
	*/

	// STL Array
	/*
	array<int, 4> arr = { 1,2,3,4 };
	try
	{
		cout << arr.at(11);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	for (auto element : arr)
	{
		cout << element << endl;
	}
	*/

	// STL forward_list
	/*
	forward_list<int> fl = { 1,2,3,4 };
	forward_list<int>::iterator it = fl.before_begin();
	fl.insert_after(it, 999);
	for (auto element : fl)
	{
		cout << element << endl;
	}
	*/

	//for each
	/*
	list<int> myList = { 10,9,8,7,6,5 };
	int arr[] = { 1,2,3,4,5 };

	for (const auto& i : myList)
	{
		//i = -1;
		cout << i << endl;
	}
	*/

	// STL Iterators
	/*
	vector<int> arr{ 10,20,30,40 };
	vector<int>::iterator it = arr.begin();
	cout << *it << endl << endl;
	*it = 50;												//Вставка значений на указатель
	cout << *it << endl << endl;
	it++;													//Арифметика указателей
	cout << *it << endl << endl;

	cout << "Full Vector Array: " << endl;
	for (auto i = arr.begin(); i!=arr.end(); i++)			//Итерирование по элементам
	{
		*i = rand()%100;									//Позволяет изменять значения
		cout << *i << endl;
	}

	cout << endl << "Const Iterator" << endl;
	for (vector<int>::const_iterator it = arr.cbegin(); it != arr.cend(); it++)			//Константный итератор, только просмотр элементов
	{
		cout << *it << endl;
	}

	cout << endl << "Reverse Iterator" << endl;
	for (vector<int>::reverse_iterator it = arr.rbegin(); it != arr.rend(); it++)		//Реверсивный итератор
	{
		cout << *it << endl;
	}

	it = arr.begin();
	cout << "Current Iterator: " << *it << endl;
	advance(it, 2);											//Смещение итератора
	cout << "Advance Iterator: " << *it << endl;
	*/

	// STL List
	/*
	list<int> myList = {10,20,3000, 20, 20};
	myList.push_back(5);
	myList.push_front(151);

	cout << endl << "Our List: " << endl;
	for (auto it = myList.begin(); it != myList.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl << "Sorted List: " << endl;
	myList.sort();										//Сортировка от наименьшего к наибольшему
	PrintList(myList);

	cout << endl << "Unique List: " << endl;
	myList.unique();									//Удаление дубликатов которые идут последовательно
	PrintList(myList);

	cout << endl << "Reverse List: " << endl;
	myList.reverse();									//Перевернуть значения в листе
	PrintList(myList);

	cout << endl << "Insert in iterator: " << endl;
	auto it = myList.begin();
	++it;
	advance(it, 3);										//Сдвинуть итератор на 3 элемента (++it; ++it; ++it; по факту)
	myList.insert(it, 1488);							//Вставить элемент по итератору
	PrintList(myList);

	cout << endl << "Erase and Remove: " << endl;
	myList.erase(it);									//Удалить элемент по итератору.
	myList.remove(10);									//Удаление элемента по значению.
	PrintList(myList);

	cout << endl << "Assign: " << endl;
	myList.assign(3, 666);								//Переписать лист на 3 элемента и инициализировать их 666
	PrintList(myList);

	cout << endl << "Assign other List: " << endl;
	list<int> myList2 = { 1, 2, 3, 4, 5 };
	myList.assign(myList2.begin(), myList2.end());		//Скопировать значения из одного листа в другой
	PrintList(myList);
	*/

	// auto
	/*
	auto a = 1;
	auto b = 1.14;
	auto c = true;
	auto d = "hello";
	auto f = 'q';

	vector<int> myVector = { 11,2,4 };
	vector<int>::iterator it = myVector.begin();	//Итератор
	auto it2 = myVector.begin();					//Тоже итератор, но с auto

	for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		cout << *it << endl;
	}

	for (auto it = myVector.begin(); it != myVector.end(); it++)
	{
		cout << *it << endl;
	}
	*/

	// STL Vector
	/*
	vector<int> myVector = {0,1,2,3};
	myVector.push_back(10);
	myVector.push_back(15);
	myVector.push_back(2);
	myVector.push_back(5);
	myVector[0] = 1000;

	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	try
	{
		myVector.at(10);		//Обработка исключения, если выйдем за границы массива
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	myVector.pop_back();
	cout << "size of vector: " << myVector.size() << endl;
	cout << "capacity of vector: " << myVector.capacity() << endl;

	myVector.reserve(100);		//Зарезервировать размер вектора (массива) на 100 элементов
	cout << "size of vector: " << myVector.size() << endl;
	cout << "new capacity of vector: " << myVector.capacity() << endl;

	myVector.shrink_to_fit();	//Очистить неиспользуемые ячейки памяти вектора
	cout << "size of vector: " << myVector.size() << endl;
	cout << "new capacity of vector: " << myVector.capacity() << endl;

	cout << "Vector is null: " << myVector.empty() << endl;

	myVector.resize(20, 0);		//Обновляем количество зарезервированных мест для элементов и инициализируем их 0.

	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	cout << "size of vector: " << myVector.size() << endl;
	cout << "new capacity of vector: " << myVector.capacity() << endl;
	*/

	// Односвязный список
	/*
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(22);

	cout << "Size of list: " << lst.GetSize() << endl;
	cout << "Second element is: " << lst[2] << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "Element " << i << " = " << lst[i] << endl;
	}

	lst.pop_front();
	cout << "Size of list: " << lst.GetSize() << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "Element " << i << " = " << lst[i] << endl;
	}

	lst.clear();
	cout << "Size of list: " << lst.GetSize() << endl;

	lst.push_front(1);
	lst.push_front(100);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "Element " << i << " = " << lst[i] << endl;
	}

	cout << "Insert new element." << endl;
	lst.insert(69, 1);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "Element " << i << " = " << lst[i] << endl;
	}

	cout << "Remove element." << endl;
	lst.removeAt(1);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "Element " << i << " = " << lst[i] << endl;
	}

	cout << "Remove last element." << endl;
	lst.pop_back();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "Element " << i << " = " << lst[i] << endl;
	}
	*/

	// auto_ptr | unique_ptr | shared_ptr
	/*
	auto_ptr<int> ap1(new int(5));
	auto_ptr<int> ap2(ap1);
	cout << *ap2.get() << endl; //Получить данные

	unique_ptr<int> up1(new int(6));
	unique_ptr<int> up2;
	up2.swap(up1);              //Поменять местами up2 и up1
	int* p = up2.get();         //Присвоить в сырой указатель
	cout << *p << endl;
	up2.reset();                //Очистить up2

	int SIZE = 5;
	cin >> SIZE;
	int* arr = new int[SIZE] {1, 2, 3, 4, 5};
	shared_ptr<int[]> sp1(arr); // shared_ptr<int[]> p1(new int[SIZE] {1,2,3,4,5});
	for (int i = 0; i < SIZE; i++)
	{
		sp1[i] = rand() % 10;
		cout << sp1[i] << endl;
	}
	*/

	// Умные указатели (smart pointers)
	/*
	SmartPointer<int> pointer = new int(50);
	*pointer = 15151;
	cout << *pointer << endl;
	*/

	// Специализация шаблонного класса
	/*
	Printer<string> a;
	a.Print("Hello World");
	Printer<int> b;
	b.Print(123);
	*/

	// Наследование шаблонного класса
	/*
	int a = 2;
	templateInfo<int> b(a);
	b.DataTypeSize();       //Вызов метода класса-родителя
	b.ShowTypeName();
	*/

	// Шаблонный класс
	/*
	Point a;
	templateClass<Point> b(a);
	b.DataTypeSize();
	*/

	// namespace
	/*
	FirstNamespace::Foo();
	FirstNamespace::a = 0;
	FirstNamespace::test te;
	te.Foo();
	*/

	// Enum
	/*
	PC pc;
	pc.SetState(PC::PCState::SLEEP);
	switch (pc.GetState())
	{
	case PC::PCState::OFF:
		cout << "Off" << endl;
		break;
	case PC::PCState::ON:
		cout << "On" << endl;
		break;
	case PC::PCState::SLEEP:
		cout << "Sleep" << endl;
		break;
	}
	*/

	// Throw (Обработка исключений), несколько catch и свой класс exception
	/*
	try
	{
		cout << "If number is negative, it will be exception" << endl;
		cout << "If number is zero, it will be exception too" << endl;
		cout << "If number is 1, it will be exception" << endl;
		cout << endl;
		exceptFoo(1);
		cout << "If you see this text, all went good" << endl;
	}
	catch (myException& ex)
	{
		cout << ex.what() << endl;
		cout << ex.getDataState() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Fail: " << ex.what() << endl;
	}
	catch (const char* ex)
	{
		cout << "Fail: " << ex << endl;
	}
	catch (...)
	{
		cout << "Something went wrong." << endl;
	}
	*/

	// Try/Catch
	/*
	string fileName = "myF.txt";                                //Ошибка в названии файла
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);       //Поключение исключений к классу ifstream
	try
	{
		fin.open(fileName);
		cout << "File is open" << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	*/

	// Перегрузка операторов ввода-вывода (<< и >>)
	/*
	Point po(5, 4);
	cout << po;
	cin >> po;
	cout << po;
	*/

	// Чтение/запись данных через fstream
	/*
	fstream fs;
	fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Failed to open file" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		cout << "Enter a '1' for InputData, '2' for ReadData" << endl;
		string str;
		int value;
		cin >> value;
		if (value == 1)
		{
			cout << "Enter text for Input in File: " << endl;

			cin >> str;
			fs << str << "\n";
		}
		if (value == 2)
		{
			cout << "Data in File: " << endl;
			while (!fs.eof())
			{
				str = "";
				fs >> str;
				cout << str << endl;
			}
		}
	}
	fs.close();
	*/

	// Чтение/запись объекта класса в файл
	/*
	string fileName = "myFile.txt";
	//Чтение
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "Error to open file" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		Point pnt;
		while (fin.read((char*)&pnt, sizeof(Human)))
		{
			pnt.Print();
		}
	}
	fin.close();

	//Запись
	Point point(5, 10);
	ofstream fout;
	fout.open(fileName, ofstream::app);     //ofstream::app - append (Добавить к текущему файлу данные, а не перезаписать)
	if (!fout.is_open())
	{
		cout << "Error to open file" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		fout.write((char*)&point, sizeof(Point));
	}
	fout.close();
	*/

	// Загрузка данных из файла
	/*
	string fileName = "myFile.txt";
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "Error to open file" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		string str;
		char arrCh[50];
		while (!fin.eof())
		{
			str = "";
			//fin.getline(arrCh, 50);       //Внутренний метод, считает строку в массив char с указанием длины строки
			//getline(fin, str);            //Считывать всю строку, до символа \n
			fin >> str;                     //Считывать строку до пробела
			cout << str << endl;
		}

		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();
	*/

	// Сохранение данных в файл
	/*
	string fileName = "myFile.txt";
	ofstream fout;
	fout.open(fileName, ofstream::app);     //ofstream::app - append (Добавить к текущему файлу данные, а не перезаписать)
	if (!fout.is_open())
	{
		cout << "Error to open file" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		fout << "String\n";
		fout << 555;
	}
	fout.close();
	*/

	// Интерфейсы
	/*
	Rider rider;
	SimpleBicycle bike;
	rider.RideOn(bike);
	*/

	// Виртуальные функции
	/*
	Gun gun;
	SubmachineGun machinegun;
	machinegun.Foo();
	Player player;
	player.Shoot(&gun); //&machinegun
	Weapon* weapon = &machinegun;  //&gun
	weapon->Shoot();
	*/

	// Вызовы конструкторов при наследовании
	/*
	B b;
	b.PrintMsg();
	*/

	// Модификаторы доступа
	/*
	B b;
	b.PrintMessage();
	cout << b.msgOne << endl;
	*/

	// Наследование классов
	/*
	Student st;
	st.SetName("Ivan");
	cout << "My nane is: " << st.GetName() << endl;
	st.Learn();

	ExteramuralStudent extSt;
	extSt.SetName("Max");
	cout << "My nane is: " << extSt.GetName() << endl;
	extSt.Learn();
	*/

	// Ображение к внутреннему классу, через внешний.
	/*
	Image picture;
	picture.GetImageInfo();
	*/

	// Статические поля класса
	/*
	Apple apple(100, "Green");
	Apple apple2(150, "Red");
	Apple apple3(200, "Blue");
	cout << apple.count << endl;
	cout << Apple::count << endl;
	*/

	// Вызов дружественного метода другого класса
	/*
	Apple apple(150, "red");
	Human human(19, "Max");
	human.TakeApple(apple); //Human может видеть поля Apple, т.к. TakeApple дружественная для Apple.
	*/

	// Вызов дружественной функции
	/*
	Point a(5, 12);
	a.Print();
	ChangeX(a);
	a.Print();
	*/

	// Перегрузка оператора индексирования
	/*
	MyClass a(5);
	cout << a[3] << endl;
	*/

	// Перегрузка оператора +
	/*
	Point a(5, 9);
	Point b(10, 1);
	Point c = a + b;
	*/

	// Стрим, свой класс string
	/*
	MyString str("HELLO");
	MyString str2("WORLD");
	MyString result;
	result = str + str2;
	result.Print();
	cout << "==: " << (str == str2) << endl;
	cout << "!=: " << (str != str2) << endl;
	cout << "[]: " << str[0] << endl;
	str.Print();
	str[1] = 'Q';
	str.Print();
	*/

	// Перегрузка оператора == и !=
	/*
	Point a(5, 9);
	Point b(10, 1);
	bool result = (a == b);
	result = (a != b);
	*/

	// Объект класса (экземпляр)
	//Human firstHuman(18, "Max");    

	// Констуктор копирования
	//MyClass a(5);
	//MyClass b(a);

	// Перегрузка конструкторов по умолчанию
	//Human aa(22, "Alex");
	//Human bb(13, "Kane");
	//Human cc;

	// Перегрузка оператора =
	//bb = aa = cc;

	// Указатель на функцию
	/*
	void(*fooPointer)();
	fooPointer = Pointers;
	fooPointer();

	void(*fooPointer2)(int *first, int *second);
	fooPointer2 = SwapPointer;
	fooPointer2(&a, &b);
	*/

	// Рекурсия, факториал.
	//cout << Fact(5) << endl;   

	// Массив как указатель
	//Pointers();

	// Поменять местами 2 значения с помощью указателей   
	//SwapPointer(&a, &b); 

	// Поменять местами 2 любых значения с помощью ссылок      
	//SwapAny(a, b);          

	// Динамический двумерный массив
	//DynamicArray(&a, &b);      

	// Скопировать динамический массив
	//CopyDynamicArray();         

	// Увеличиваем массив на 1 и добавляем значение в конец массива
	//push_back(arr, size, 10);             

	// Уменьшаем массив на 1 и удаляем последнее значение
	//pop_back(arr, size);                  

	// Увеличиваем массив на 1 и добавляем значение в начало массива
	//push_front(arr, size, 111);           

	// Уменьшаем массив на 1 и удаляем первое значение
	//pop_front(arr, size);                 

	// Увеличиваем массив на 1 и добавляем значение в середину массива
	//push_mid(arr, size, 111);             

	// Уменьшаем массив на 1 и удаляем значение из середины
	//pop_mid(arr, size);                   

	// Заполнить массив случайными элементами
	//FillArray(arr, size);                 

	// Вывести массив на экран
	//ShowArray(arr, size);                 

	// Подсчёт количества символов в строке char
	//myStrlen(str);                        

	// Приведение типов
	/*
	double c = 33.3;
	double d = (int)c;
	cout << c << endl;          //33.3
	cout << d << endl;          //33
	int a = 1;
	cout << a+c << end;;        //34.3
	cout << int(a+c) << endl;   //34
	*/

	return 0;
}
