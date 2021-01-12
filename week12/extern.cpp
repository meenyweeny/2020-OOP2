#include<iostream>
using namespace std;

int ga = 1000;
static int gk = 100;

void func() {
	cout << "외부 함수" << endl;
}

static void static_func() {
	cout << "static 외부 함수" << endl;
}