// Homework3.9.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class DivisionByZeroException : public std::exception
{
public:
	const char* what() const override { return "Попытка деления на 0"; }
};

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	double Abs() 
	{
		if (denominator_ == 0) throw DivisionByZeroException();
		return std::sqrt(numerator_ * numerator_ + denominator_ * denominator_);
	}
	double div() 
	{
		if (denominator_ == 0) throw DivisionByZeroException();
		return numerator_ / denominator_;
	}
	double delta = 0.0000001;
	bool operator==(Fraction other) 
	{ 
		return fabs(div() - other.div()) < delta;
		//return Abs() == other.Abs(); 
	}
	bool operator!=(Fraction other) 
	{ 
		return !(*this == other); 
	}
	bool operator>(Fraction other) 
	{
		return Abs() > other.Abs(); 
	}
	bool operator<(Fraction other) 
	{ 
		return other > *this; 
	}
	bool operator>=(Fraction other) 
	{ 
		return !(*this < other); 
	}
	bool operator<=(Fraction other) 
	{ 
		return !(*this > other); 
	}
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

	Fraction f1(4, 3);
	Fraction f2(6, 11);

	try
	{
		f1 == f2;
	}
	catch (const DivisionByZeroException& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
