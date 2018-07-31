#include"Execution.h"
#include"Macro.h"
#include"Reflection.h"
#include"Singleton.h"

SPACE_BEGIN
//单例类
class A {
	SPACE_SINGLETON_CLASS(A);

public:
	int a = 0;
	void add() {
		a++;
	}
};

//反射
class B: SPACE_REFLECTION() {
	SPACE_REFLECTION_CLASS(B);

public:
	int b = 0;
	void AddB() {
		b++;
	}
};
SPACE_REFLECTION_CLASS_DEFINE(B);

//反射
class C:SPACE_REFLECTION() {
	SPACE_REFLECTION_CLASS(C);
public:
	int c = 8616;
	void AddC() {
		c++;
	}
};
SPACE_REFLECTION_CLASS_DEFINE(C);
SPACE_END

SPACE_NAMESPACE;
void TestA() {
	SPACE_SINGLETON_GET(A)add();
}

void TestBC() {
	B* t = Reflection::CreateClass<B>();
	B* t2 = Reflection::CreateClass<B>("C"); //严重错误
}

int main(int argc, char* argv[]) {
	TestA();
	TestBC();
	return 0;
}