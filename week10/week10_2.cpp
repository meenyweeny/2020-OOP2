#include"docwriter.h"
#include"htmlwriter.h"

int main() {

	//접근 제어 (protected, private)
	/*
	HTMLWriter hw;
	DocWriter * pdw = &hw;
	HTMLWriter * phw = (HTMLWriter*)pdw;

	phw->Write(); //HTMLWriter의 Write()
	//phw가 HTMLWriter의 포인터고 주소를 받은 것도 그 type이므로
	//phw가 궁극적으로 받은 것은 hw와 같은 주소

	//DocWriter의 멤버변수들을 private으로 바꾸면
	//이걸 접근할 수 없어서 에러가 난다
	//자식임에도 불구하고 접근불가란 것
	*/

}