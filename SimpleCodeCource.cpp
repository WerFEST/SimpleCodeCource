#include "Header.h"

using namespace FirstNamespace;

void multiplyInt(int a)
{
	a *= 2;
	cout << "multiplyInt \t" << a << endl;
}

void decideInt(int a)
{
	a /= 2;
	cout << "decideInt \t" << a << endl;
}

void DoWork(vector<int>& vc, vector<function<void(int)>> funcVect)
{
	for (auto e1 : vc)
	{
		for (auto &fel : funcVect)
		{
			fel(e1);
		}
	}
}

void DoWork2(vector<int>& vc, function<void(int)> funcVect)
{
	for (auto e1 : vc)
	{
		funcVect(e1);
	}
}


int main()
{
	// Namespaces
	/*
	FirstNamespace::Foo();
	FirstNamespace::test t;
	t.Foo();
	*/





	// Return Thread value with Lambda
	/*
	int result;
	thread th([&result]() {
		result = ThreadWorkParam(5, 10);
		});

	for (int i = 0; i < 10; i++)
	{
		cout << "Main Thread" << endl;
		this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	th.join();
	cout << "Result: " << result << endl;
	*/

	// Lambda-Function
	/*
	vector<int> vcc = { 1,2,3,4,56,19,100 };
	function<void(int)> fVec;

	auto afVec = [](int a) {
		cout << "Lambda: \t" << a << endl;
	};
	DoWork2(vcc, afVec);

	int p = 0;
	DoWork2(vcc, [&p](int a)
		{
			cout << "Lambda: \t" << a << "\t p: \t" << p << endl;
		});
	*/

	// std::function
	/*
	function<void()> f;
	f = FirstNamespace::Foo;
	f();

	vector<int> vcc = { 1,2,3,4,56,19,100 };
	vector<function<void(int)>> fVector;
	fVector.emplace_back(multiplyInt);
	fVector.emplace_back(decideInt);
	DoWork(vcc, fVector);
	*/

	// Thread with return
	/*
	int q = 10;
	int d = 5;
	thread th(ThreadWorkParam, q, d);

	for (int i = 0; i < 10; i++)
	{
		cout << "Main Thread" << endl;
		this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	th.join();
	cout << q << endl;
	*/

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
	int a = 1, b = 2;
	thread th(ThreadWorkParam, a, b);									//Указывается название функции для передачи в поток и через , указываются параметры

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

	//int result = Fact(5);					//Рекурсия, факториал
	
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
	//myStrlen("str");

	return 0;
}
