// тесты для вычисления арифметических выражений

#include <gtest.h>
// тесты для вычисления арифметических выражений 
#include <cstring> 
#include <string> 
#include <gtest.h> 
#include "arithmetic.h" 
#include "stack.h"
class ParameterizedStringError : public ::testing::TestWithParam<char* >
{
protected:
	Arifmetics s;
public:
	ParameterizedStringError() 
	{ 
		s.PushStroka(GetParam());
	}
	~ParameterizedStringError() {}
};
class Calculate {
private:
	char a[20]="";
	double b;
public:
	Calculate(char *v,double h) {
		strcpy(a,v);
		b = h;
	}
	Calculate(const Calculate& r) {
		strcpy(a, r.a);
		b = r.b;
	}

	char* string() {
		return a;
	}
	double Res() { return b; }
};

class ParameterizedCalculate : public ::testing::TestWithParam <Calculate >
{
protected:
	Calculate w;
public:
	ParameterizedCalculate() :w (GetParam())
	{

	}
};

Calculate e("332-331", 1);
////// Для параметризованного счёта...
TEST_P(ParameterizedCalculate, can_Calculete_True)
{
	Arifmetics s;
	s.PushStroka(GetParam().string());

	EXPECT_EQ(e.Res(), s.calculate());
}
INSTANTIATE_TEST_CASE_P(Instantiation3,
	ParameterizedCalculate,
	::testing::Values(e));

class ParameterizedStringTrue : public ParameterizedStringError
{
};

char a[] = "@74";
char b[] = "2++";
char z[] = "2--";
char k[] = "(4-32*(32-3)2-4";
char * c[] = { &a[0], &b[0], &z[0], &k[0] };

TEST_P(ParameterizedStringError, can_determinate_eror)
{
	EXPECT_EQ(false,s.Check());
}

INSTANTIATE_TEST_CASE_P(Instantiation1,
	ParameterizedStringError,
	::testing::ValuesIn(c));

TEST_P(ParameterizedStringTrue, can_determinate_True)
{
	EXPECT_EQ(true, s.Check());
}
char a2[] = "(-re+32)";
char b2[] = "2+4*(-32+32)*(+32)";
char z2[] = "(32.32-43)*(+ew)";
char k2[] = "(4-32*32-3)*2-4";
char r2[] = "15/3+(7-2)/5";
char * c2[] = { &a2[0], &b2[0], &z2[0], &k2[0],&r2[0] };

INSTANTIATE_TEST_CASE_P(Instantiation2,
	ParameterizedStringTrue,
	::testing::ValuesIn(c2));



