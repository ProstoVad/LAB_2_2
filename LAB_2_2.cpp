#include <iostream>
#include <cmath>
using namespace std;

class Atr {
public:
	long int int_part;
	unsigned int float_part;
	Atr() { //конструктор по умолчанию
		int_part = 0;
		float_part = 0;
	}
	Atr(long int int_part, unsigned int float_part) { //конструктор с параметрами 
		this->int_part = int_part;
		this->float_part = float_part;
	}

	friend ostream& operator<< (ostream& out, const Atr& atr);
	friend istream& operator>> (istream& is, const Atr& atr);
};

ostream& operator<<(ostream& out, Atr& atr) {
	out << atr.int_part << "," << atr.float_part << endl;
	return out;
}

istream& operator>>(istream& is, Atr& atr) {
	is >> atr.int_part >> atr.float_part;
	return is;
}

//Создать базовый класс с закрытыми полями, где операции 
//реализуются как методы класса

class drobi {
private:
	int smint;
	int smfl;
	int one = 0;
	float SUMFLOAT(drobi zn) {
		smfl = this->atr.float_part + zn.atr.float_part;
		if (smfl >= 10) {
			smfl -= 10;
			one += 1;
		}
		return smfl;
	}

	int SUMINT(drobi zn) {
		smint = ((this->atr.int_part + zn.atr.int_part) + one);
		return smint;
	}

	int MULINT(drobi zn) {
		double x;
		double y;
		double z;
		double sum;
		x = this->atr.int_part * zn.atr.int_part;
		y = this->atr.int_part * 0.1 * zn.atr.float_part;
		z = this->atr.float_part * 0.1 * zn.atr.int_part;
		sum = x + y + z;
		sum = (int)sum;
		return sum;
	}

	float MULFLOAT(drobi zn) {
		double y;
		double z;
		double sum;
		double w;
		double intpart;
		y = this->atr.int_part * 0.1 * zn.atr.float_part;
		z = this->atr.float_part * 0.1 * zn.atr.int_part;
		sum = y + z;
		double fractpart = modf(sum, &intpart);
		fractpart = unsigned(fractpart * pow(10, 2));
		w = this->atr.float_part * zn.atr.float_part + fractpart;
		return w;
	}

public:
	Atr atr;

	drobi() { // конструктор без аргументов 
		cin >> atr;
	}

	drobi(long int int_part, unsigned int float_part = 5) {
		//конструктор со списком инициализации и значениями по умолчанию
		this->atr.int_part = int_part;
		this->atr.float_part = float_part;
	}

	void getatr() { //вывод состояния атрибутов
		cout << atr;
	}

	drobi operator + (drobi zn){ //перегрузки операторов
		return drobi(SUMINT(zn), SUMFLOAT(zn));
	}

	drobi operator * (drobi zn){
		return drobi(MULINT(zn), MULFLOAT(zn));
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	drobi drob1(3, 2);	
	drob1.getatr();
	drobi drob2(2);
	drobi drob3;
	cout << endl;

	drobi drob4 = drob1 + drob3;
	drob4.getatr();
	drobi drob5 = drob1 * drob3;
	drob5.getatr();
}
