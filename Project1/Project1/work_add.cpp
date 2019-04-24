#include<iostream>
using namespace std;
template <class datatype>
class seqlist
{
private:
	datatype *data;
	int maxsize; //maxsize Ϊ���Ա�������ܳ���
	int last; //last Ϊ���Ա��б�βԪ�ص��±�
public:
	seqlist() //���� 100 ��Ԫ�ص����Ա�Ĺ��캯��
	{
		maxsize = 100;
		data = new datatype[maxsize];
		last = -1; //last Ϊ-1 ��ʾΪ�ձ�
	}
	seqlist(int sz) //���� sz ��Ԫ�ص����Ա�Ĺ��캯��
	{
		if (sz > 0)
			maxsize = sz;
		else
			maxsize = 100;
		data = new datatype[maxsize];
		last = -1; //last Ϊ-1 ��ʾΪ�ձ�
	}
	bool isempty() { return last == -1 ? true : false; } //�пձ�
	bool isfull() { return last == maxsize - 1; } //�б���
	int length() { return last + 1; } //���
	bool getdata_address(int i, datatype &x) //ͨ�������������ݱ�����ַ�ķ���ȡԪ��
	{
		i--;
		if (i >= 0 && i <= last)
		{
			x = data[i];
			return true;
		}
		else
		{
			cout << "�Ƿ�λ�ö�ȡԪ�أ����ܶ�ȡ��\n";
			return false;
		}
	}
	int getdata(int i) //ֱ��ͨ�����ȡԪ��
	{
		i--;
		int x;
		if (i >= 0 && i <= last)
		{
			x = data[i];
			return x;
		}
		else
		{
			cout << "�Ƿ�λ�ö�ȡԪ�أ����ܶ�ȡ��\n";
			return false;
		}
	}
	bool get_prior(int i, datatype &x); //ȡǰ��Ԫ��
	bool get_succ(int i, datatype &x); //ȡ���Ԫ��
	bool replace(int i, datatype x) //�û�Ԫ��
	{
		i--;
		if (i >= 0 && i <= last)
		{
			data[i] = x;
			return true;
		}
		else
		{
			cout << "�Ƿ�λ���޸�Ԫ�أ������޸ģ�\n";
			return false;
		}
	}
	bool insert_data(int i, datatype x); //����Ԫ��
	bool delete_data(int i); //ɾ��Ԫ��
	void print_list(); //��ʾ��������Ԫ��
	int find_data(datatype x); //����Ԫ��
	void sort(); //����Ԫ��
	~seqlist() //��������
	{
		delete[] data;
	}
};
template<class datatype>
bool seqlist<datatype>::insert_data(int i, datatype x) //���Ա��Ԫ�ز��뺯��
{
	if (isfull()) //�ж�������
	{
		cout << "�����������ܲ��룡\n";
		return false;
	}
	if (i >= 1 && i <= last + 2) //�ж�����λ�� i �ĺϷ���
	{
		int j;
		//�� i ���� j ��Ԫ��ѭ������һ���洢λ��
		for (j = last; j >= i - 1; j--)
			data[j + 1] = data[j];
		data[j + 1] = x; //x ��Ϊ���Ա��е� i ��Ԫ��
		last++; //���Ա�ĳ��ȼ� 1
		return true;
	}
	else
	{
		cout << "����λ�ô��󣬲��ܲ��룡\n";
		return false;
	}
};
template<class datatype>
bool seqlist<datatype>::delete_data(int i) //���Ա��ɾ��Ԫ�غ���
{
	if (isempty()) //�ж���շ�
	{
		cout << "���ѿգ�����ɾ����\n";
		return false;
	}
	if ((i >= 1) && (i <= last + 1)) //�ж�ɾ��λ�� i �ĺϷ���
	{
		//�� i+1 ���� n ��Ԫ��ѭ��ǰ��һ���洢λ��
		for (int j = i - 1; j < last; j++)
			data[j] = data[j + 1];
		last--; //���Ա�ĳ��ȼ� 1

		return true;
	}
	else
	{
		cout << "ɾ��λ�ô��󣬲���ɾ����\n";
		return false;
	}
};
template<class datatype>
void seqlist<datatype>::print_list() //��ӡ������Ա�������Ԫ��
{
	datatype x;
	for (int i = 0; i <= last; i++)
	{
		getdata_address(i + 1, x);
		cout << x << " ";
	}
	cout << endl;
};

int main() {
	seqlist<int> linear_list1(10); //��������Ϊ 100 �Ŀձ�
	seqlist<int> linear_list2(10); //��������Ϊ 100 �Ŀձ�
	seqlist<int> linear_list3(10); //��������Ϊ 100 �Ŀձ�
	int i= 1;
	int j= 1;
	int k= 1;
	for (int a = 0; a < 6; a++)
	{
		linear_list1.insert_data(a + 1, (a + 1) * 100);
	}
	for (int a = 0; a < 5; a++)
	{
		linear_list2.insert_data(a + 1, (a + 1) * 100);
	}
	int linear_list1_length = linear_list1.length();
	int linear_list2_length = linear_list2.length();
	int linear_list3_length = linear_list3.length();
	linear_list1.print_list();
	linear_list2.print_list();
	linear_list3.print_list();
	do {
		if (linear_list1.getdata(i) < linear_list2.getdata(j)) {
			int a1 = linear_list1.getdata(i);
			linear_list3.insert_data(k, a1);
			i++;
			k++;
		}
		else if (linear_list1.getdata(i) > linear_list2.getdata(j)) {
			int a2 = linear_list1.getdata(i);
			linear_list3.insert_data(k, a2);
			j++;
			k++;
		}
		else {
			int a3 = linear_list1.getdata(i) + linear_list2.getdata(j);
			linear_list3.insert_data(k, a3);
			i++;
			j++;
			k++;
		}
		linear_list3.print_list();

	} while ( (i< (linear_list1_length+1)) && (j< (linear_list2_length+1)));
	
	if (i == (linear_list1_length + 1)) {
		for (j; j <= linear_list2_length;j++) {
			int a4 = linear_list2.getdata(j);
			linear_list3.insert_data(k, a4);
			k++;
		}
	}
	else if (j == (linear_list2_length + 1)) {
		for (i; i <= linear_list1_length; i++) {
			int a5 = linear_list1.getdata(i);
			linear_list3.insert_data(k, a5);
			k++;
		}
	}
	linear_list3.print_list();
	system("pause");
	return 0;
}