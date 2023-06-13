#include <bits/stdc++.h>
using namespace std;

class Fraction {
public:

	Fraction(const int num = 0, const int den = 1);
	Fraction(const Fraction &other) = default;
	~Fraction() = default;
	string toString() const;
	
	Fraction& operator+=(int a);
	friend bool operator==(const Fraction &left, const Fraction &rigth);
	friend const Fraction operator+(const Fraction &left, const Fraction &right);

private:
    void reduce();
	int _numeratotr;
	int _denomenator;
};

 

Fraction::Fraction(const int num, const int den) {
	if (den == 0) throw invalid_argument("denomenator can't be zero");
	
	_numeratotr = num;
	_denomenator = den;
	
	reduce();
}

string Fraction::toString() const {

	if (_numeratotr == 0) return "0";
	
	if (_denomenator == 1) return to_string(_numeratotr);
	
	return to_string(_numeratotr) + "/" + to_string(_denomenator);
}

void Fraction::reduce() {
	auto gcd = __gcd(abs(_numeratotr), _denomenator);
	
	if (gcd != 1) {
		_numeratotr /= gcd;
		_denomenator /= gcd;
	}

}

Fraction& Fraction::operator+=(int a) {

    _numeratotr += a * _denomenator;
    reduce();
	return *this;
}

bool operator==(const Fraction &left, const Fraction &right) {

	int lcm = __detail::__lcm(left._denomenator, right._denomenator);
	
	int numerator1 = left._numeratotr * lcm/left._denomenator;
	int numerator2 = right._numeratotr * lcm/right._denomenator;
	
	return numerator1 == numerator2;
}

const Fraction operator+(const Fraction &left, const Fraction &right) {

    Fraction d;
    
    int lcm = __detail::__lcm(left._denomenator, right._denomenator);
    int numerator1 = left._numeratotr * lcm/left._denomenator;
	int numerator2 = right._numeratotr * lcm/right._denomenator;
    
    d._denomenator = lcm;
    d._numeratotr = numerator1 + numerator2;
    
    return d;
}

int main() {
	Fraction a(0, 10);
	Fraction b(2, 5);
	cout << a.toString() << " " << b.toString() << " " << (a == b) << "\n";
	
	a += 2;

	Fraction c(40, 20);

	cout << a.toString() << " " << c.toString() << " " << (a == c)  << "\n";
	
	auto d = a + b;
	
	cout << d.toString() << " " << "\n";

}