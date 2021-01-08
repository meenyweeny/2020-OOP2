//클래스간의 형변환
//객체간의 형변환
//객체간의 대입

#include"docwriter.h"
#include"htmlwriter.h"

int main() {
	/*
	HTMLWriter hw("test.html", "테스트!");
	//상속을 지우면 에러가 남
	//초기화리스트를 사용해서 한건데 부모와 자식의 연이 끊어지니까
	//제대로 돌지를 않는다
	//그래서 부모의 DocWriter(const string& fileName, const string& content);
	//생성자를 쓸 수가 없게 되어 오류가 남

	hw.Write();
	*/

	/*
	//부모자식간 casting
	HTMLWriter h("test.html","객체간 대입");
	DocWriter d;
	//서로 다른 타입

	//서로 다른 타입으로 대입을 하면 casting이 일어난다
	//ex int->short에 넣으면 4->2byte로 줄어듦
	//float->int에 넣으면 실수부분이 truncation이 일어나며 들어간다

	//그럼 위 두가지의 대입연산이 될까?

	//h = d; //1.자식객체에다가 부모객체를 대입하는 경우 - > 불가능
	//부모객체는 자식객체보다 더 적은 값을 가지ㅏ고있어서
	//그 값들을 받을 수 없다

	d = h; //2.부모객체에다가 자식객체를 대입하는 경우 -> 가능
	//자식은 부모를 상속받았기 때문에,
	//부모가 가지고 있는 것들을 다 가지고 있어서 가능

	d.Write(); //본인이 가지고 있는 Write (DocWriter의 Write)
	//실제 열어보면 이름만 html이지 안에 기록은 text 내용으로 기록됨

	h.Write(); //html문서가 삽입됨

	*/

	//====================================

	//포인터, 레퍼런스 간의 형변환
	/*
	//불가능

	DocWriter dw;
	//HTMLWriter *phw = &dw; //error
	//HTMLWriter &phw2=&dw; //error
	//사실 자식객체가 부모객체가 가진 멤버변수에 접근하려하면 오류날일이 없는데
	//자식객체만 갖고있는 (_fontColor 같은) 멤버변수에 접근할라하면 오류가 생김


	//가능

	HTMLWriter hwp;
	DocWriter * dwp = &hwp;
	//자식클래스는 5개의 멤버변수 속성이있는데
	//거기서 2가지만 가리킬 수 있게 하는 포인터
	DocWriter & dwr = hwp;


	//부모클래스의 포인터나 레퍼런스 변수에는
	//자식클래스의 주소대입과 자식클래스의 대입이 가능하다
	//반대의 경우는 불가능하다
	*/


	//포인터를 이용한 문서 생성
	/*
	//가능(부모클래스의 Write 동작)
	HTMLWriter hp("test.html", "부모클래스 포인터 이용");
	DocWriter * pdw = &hp;
	pdw->Write(); //docwriter의 write가 실행됨
	//html 포맷으로 저장한것은 아님
	*/


	//자식클래스의 포인터가 부모클래스의 포인터로 형변환되는
	//upcast가 실행됨

	//반대의경우 downcast -> 안되는데 왜 이런말이 있음?
	//예외적인 상황이 있음




	//레퍼런스를 이용한 문서 생성
	
	//가능(부모클래스 레퍼런스 사용 가능)
	HTMLWriter hp2("test.html", "부모클래스 포인터 이용");
	DocWriter & pdw2 = hp2;
	pdw2.Write(); //docwriter의 write가 실행됨
	//write 메서드 앞에 virtual 키워드 붙이기 전엔 test.html 문서는 docwriter의 write를
	//통해 찍혀있었는데
	//헤더파일로 가서 docWrite의 write 앞에 virtual 키워드 하나 딱 붙여주니까
	//HTMLWriter의 write 메서드가 잘 실행된다

	//상속관계의 부모 메서드가 virtual로 되어있으면 자식의 오버라이딩되는
	//메서드도 자동으로 virtual로 동작을 하긴 하는데
	//상속받을 때도 그냥 virtual로 명시를 해주는게 제일 좋긴 함(관례)
	

	//위에까진 다 upcasting 이었다
	//(자식객체의 주소를 부모가 받은)



	//그렇다면 down casting은?
	//예외적인 상황에서 가능



	HTMLWriter hw2;
	DocWriter*dw2 = &hw2; //upcast
	HTMLWriter * phw2 = (HTMLWriter*)dw2; //down cast
	//이 경우, 한번 html 객체의 주소를 upcast 했다가
	//다시 downcast
	//->이런 경우엔 가능~

	//이런 경우엔 dw2가 가리키고 있는 것이 HTMLWriter의 객체라는 것을 몰라서
	//명시적으로 (HTMLWriter*) 이렇게 써서 casting 해주지 않으면 모름
	//내가 가리키는 대상은 어느 객체인지 알려줘야 phw2가 dw2의 주소를 넘겨받아서
	//동작하게 된다

	//이런 특수한 경우 downcasting이 가능하다


}