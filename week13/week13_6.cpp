namespace {
	int g;
} //�̸��� ���� �ʾ����Ƿ� �ٸ� ���Ͽ� ����� ������ �Ѵ�

void Func() {
	g = 5;
}


//��ø�� namespace 

namespace Data {
	namespace User {
		int number;
	}
}

//namespace���� ���� �ο� ����

namespace namespace_name_very_long {
	namespace User {
		int num;
	}
}

namespace Nick = namespace_name_very_long;

int main() {
	//int user_number = Data::number; //����
	int user_number = Data::User::number;
	return 0;

	int newnum = Nick::User::num;
}