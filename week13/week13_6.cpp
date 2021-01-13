namespace {
	int g;
} //이름을 적지 않았으므로 다른 파일에 숨기는 역할을 한다

void Func() {
	g = 5;
}


//중첩된 namespace 

namespace Data {
	namespace User {
		int number;
	}
}

//namespace에도 별명 부여 가능

namespace namespace_name_very_long {
	namespace User {
		int num;
	}
}

namespace Nick = namespace_name_very_long;

int main() {
	//int user_number = Data::number; //오류
	int user_number = Data::User::number;
	return 0;

	int newnum = Nick::User::num;
}