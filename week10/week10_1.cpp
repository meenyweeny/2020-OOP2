//Ŭ�������� ����ȯ
//��ü���� ����ȯ
//��ü���� ����

#include"docwriter.h"
#include"htmlwriter.h"

int main() {
	/*
	HTMLWriter hw("test.html", "�׽�Ʈ!");
	//����� ����� ������ ��
	//�ʱ�ȭ����Ʈ�� ����ؼ� �Ѱǵ� �θ�� �ڽ��� ���� �������ϱ�
	//����� ������ �ʴ´�
	//�׷��� �θ��� DocWriter(const string& fileName, const string& content);
	//�����ڸ� �� ���� ���� �Ǿ� ������ ��

	hw.Write();
	*/

	/*
	//�θ��ڽİ� casting
	HTMLWriter h("test.html","��ü�� ����");
	DocWriter d;
	//���� �ٸ� Ÿ��

	//���� �ٸ� Ÿ������ ������ �ϸ� casting�� �Ͼ��
	//ex int->short�� ������ 4->2byte�� �پ��
	//float->int�� ������ �Ǽ��κ��� truncation�� �Ͼ�� ����

	//�׷� �� �ΰ����� ���Կ����� �ɱ�?

	//h = d; //1.�ڽİ�ü���ٰ� �θ�ü�� �����ϴ� ��� - > �Ұ���
	//�θ�ü�� �ڽİ�ü���� �� ���� ���� ���������־
	//�� ������ ���� �� ����

	d = h; //2.�θ�ü���ٰ� �ڽİ�ü�� �����ϴ� ��� -> ����
	//�ڽ��� �θ� ��ӹ޾ұ� ������,
	//�θ� ������ �ִ� �͵��� �� ������ �־ ����

	d.Write(); //������ ������ �ִ� Write (DocWriter�� Write)
	//���� ����� �̸��� html���� �ȿ� ����� text �������� ��ϵ�

	h.Write(); //html������ ���Ե�

	*/

	//====================================

	//������, ���۷��� ���� ����ȯ
	/*
	//�Ұ���

	DocWriter dw;
	//HTMLWriter *phw = &dw; //error
	//HTMLWriter &phw2=&dw; //error
	//��� �ڽİ�ü�� �θ�ü�� ���� ��������� �����Ϸ��ϸ� ���������� ���µ�
	//�ڽİ�ü�� �����ִ� (_fontColor ����) ��������� �����Ҷ��ϸ� ������ ����


	//����

	HTMLWriter hwp;
	DocWriter * dwp = &hwp;
	//�ڽ�Ŭ������ 5���� ������� �Ӽ����ִµ�
	//�ű⼭ 2������ ����ų �� �ְ� �ϴ� ������
	DocWriter & dwr = hwp;


	//�θ�Ŭ������ �����ͳ� ���۷��� ��������
	//�ڽ�Ŭ������ �ּҴ��԰� �ڽ�Ŭ������ ������ �����ϴ�
	//�ݴ��� ���� �Ұ����ϴ�
	*/


	//�����͸� �̿��� ���� ����
	/*
	//����(�θ�Ŭ������ Write ����)
	HTMLWriter hp("test.html", "�θ�Ŭ���� ������ �̿�");
	DocWriter * pdw = &hp;
	pdw->Write(); //docwriter�� write�� �����
	//html �������� �����Ѱ��� �ƴ�
	*/


	//�ڽ�Ŭ������ �����Ͱ� �θ�Ŭ������ �����ͷ� ����ȯ�Ǵ�
	//upcast�� �����

	//�ݴ��ǰ�� downcast -> �ȵǴµ� �� �̷����� ����?
	//�������� ��Ȳ�� ����




	//���۷����� �̿��� ���� ����
	
	//����(�θ�Ŭ���� ���۷��� ��� ����)
	HTMLWriter hp2("test.html", "�θ�Ŭ���� ������ �̿�");
	DocWriter & pdw2 = hp2;
	pdw2.Write(); //docwriter�� write�� �����
	//write �޼��� �տ� virtual Ű���� ���̱� ���� test.html ������ docwriter�� write��
	//���� �����־��µ�
	//������Ϸ� ���� docWrite�� write �տ� virtual Ű���� �ϳ� �� �ٿ��ִϱ�
	//HTMLWriter�� write �޼��尡 �� ����ȴ�

	//��Ӱ����� �θ� �޼��尡 virtual�� �Ǿ������� �ڽ��� �������̵��Ǵ�
	//�޼��嵵 �ڵ����� virtual�� ������ �ϱ� �ϴµ�
	//��ӹ��� ���� �׳� virtual�� ���ø� ���ִ°� ���� ���� ��(����)
	

	//�������� �� upcasting �̾���
	//(�ڽİ�ü�� �ּҸ� �θ� ����)



	//�׷��ٸ� down casting��?
	//�������� ��Ȳ���� ����



	HTMLWriter hw2;
	DocWriter*dw2 = &hw2; //upcast
	HTMLWriter * phw2 = (HTMLWriter*)dw2; //down cast
	//�� ���, �ѹ� html ��ü�� �ּҸ� upcast �ߴٰ�
	//�ٽ� downcast
	//->�̷� ��쿣 ����~

	//�̷� ��쿣 dw2�� ����Ű�� �ִ� ���� HTMLWriter�� ��ü��� ���� ����
	//���������� (HTMLWriter*) �̷��� �Ἥ casting ������ ������ ��
	//���� ����Ű�� ����� ��� ��ü���� �˷���� phw2�� dw2�� �ּҸ� �Ѱܹ޾Ƽ�
	//�����ϰ� �ȴ�

	//�̷� Ư���� ��� downcasting�� �����ϴ�


}