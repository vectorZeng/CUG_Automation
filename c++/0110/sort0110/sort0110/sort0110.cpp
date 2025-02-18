#include<iostream>
#include<string>
#include<fstream>


using namespace std;  

#define ORIGINAL_FILE "��ѧ����Ӣ��.txt"
#define ADDED_FILE "����C����˼��.txt"
#define MERGED_FILE "MergedFile337.txt"
#define SORTED_FILE "SortedFile337.txt"

class Student {
public:
	friend void loadStudentFile(const string& filename, Student students[], int count);


private:
	string m_Id; // ѧ��
	string m_Name; // ����
	int m_Math; // ��ѧ
	int m_Physics; // ����
	int m_English; // Ӣ��
	int m_Basic; // ����
	int m_C; // C����
	int m_Mind; // ˼��

public:
	// ���캯��
	Student() : m_Id(""), m_Name(""), m_Math(0), m_Physics(0), m_English(0), m_Basic(0), m_C(0), m_Mind(0) {}

	Student(string id, string name, int math, int physics, int english, int basic, int c, int mind)
		:m_Id(id), m_Name(name), m_Math(math), m_Physics(physics), m_English(english), m_Basic(basic), m_C(c), m_Mind(mind) {
	}

	// ��ȡѧ��
	string getId() {
		return m_Id;
	}
	// ��ȡ����
	string getName() {
		return m_Name;
	}
	// ��ȡ���Ƴɼ�
	int getMath() {
		return m_Math;
	}
	int getPhysics() {
		return m_Physics;
	}
	int getEnglish() {
		return m_English;
	}
	int getBasic() {
		return m_Basic;
	}
	int getC() {
		return m_C;
	}
	int getMind() {
		return m_Mind;
	}

	// �ܷ�
	int getTotalScore()
	{
		return m_Math + m_Physics + m_English + m_Basic + m_C + m_Mind;
	}

	// �鿴��Ϣ
	void showInfo()
	{
		cout << m_Id << " " << m_Name << " "
			<< m_Math << " " << m_Physics << " "
			<< m_English << " " << m_Basic << " "
			<< m_C << " " << m_Mind << " "
			<< getTotalScore() << endl;
	}
};

// ��ȡԭʼ�ļ�
int loadStudentFile(const string& filename, Student students[])
{
	// ¼ȡ�ļ�
	ifstream file;
	file.open(filename, ios::in);

	string id, name;
	int math, physics, english;
	int basic = 0;
	int c = 0;
	int mind = 0;
	// ��¼ѧ������
	int count = 0;

	// ����
	while (file >> id >> name >> math >> physics >> english) {
		students[count] = Student(id, name, math, physics, english, basic, c, mind);
		count++;
	}

	file.close();
	return count;
}

void loadStudentFile(const string& filename, Student students[], int count)
{
	ifstream file2;
	file2.open(filename, ios::in);

	if (!file2.is_open()) {
		cerr << "�޷��򿪸����ļ���" << filename << endl;
		return;
	}

	string id, name;
	int math = 0;
	int physics = 0;
	int english = 0;
	int basic = 0;
	int c = 0;
	int mind = 0;

	// ��ȡ�����ļ����ϲ���Ϣ
	while (file2 >> id >> name >> basic >> c >> mind) {
		for (int i = 0; i < count; i++) {
			if (students[i].getId() == id) {
				students[i].m_Basic = basic;
				students[i].m_C = c;
				students[i].m_Mind = mind;
				break;
			}
		}
	}

	file2.close();
}

// д���ļ�
void saveFile(const string& filename, Student students[], int& count)
{
	ofstream file;
	file.open(filename, ios::out);
	file << "ѧ��\t" << "����\t" << "��ѧ\t" << "����\t" << "Ӣ��\t" << "����\t" << "C���� " << "˼��\t" << "�ܷ�" << endl;
	for (int i = 0; i < count; i++)
	{
		file << students[i].getId() << " " << students[i].getName() << " "
			<< students[i].getMath() << " " << students[i].getPhysics() << " "
			<< students[i].getEnglish() << " " << students[i].getBasic() << " "
			<< students[i].getC() << " " << students[i].getMind() << " "
			<< students[i].getTotalScore() << endl;

	}

	file.close();
}

// д���ļ�
void saveSortedFile(const string& filename, Student students[], int& count, float avg)
{
	ofstream file;
	file.open(filename, ios::out);
	file << "ѧ��\t" << "����\t" << "��ѧ\t" << "����\t" << "Ӣ��\t" << "����\t" << "C���� " << "˼��\t" << "�ܷ�" << endl;
	for (int i = 0; i < count; i++)
	{
		if (students[i].getTotalScore() > avg + 10) {
			file << students[i].getId() << " " << students[i].getName() << " "
				<< students[i].getMath() << " " << students[i].getPhysics() << " "
				<< students[i].getEnglish() << " " << students[i].getBasic() << " "
				<< students[i].getC() << " " << students[i].getMind() << " "
				<< students[i].getTotalScore() << endl;
		}


	}

	file.close();
}

// ���������ð������
void bubbleSort(Student students[], int& count, float average)
{
	Student temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (students[j].getTotalScore() < students[j + 1].getTotalScore()) {
				temp = students[j + 1];
				students[j + 1] = students[j];
				students[j] = temp;
			}
		}
	}
	saveSortedFile(SORTED_FILE, students, count, average);
	cout << "����ɹ�����鿴�ļ���SortedFile350.txt��!" << endl;
}

// ����ƽ����
float calculateAverage(Student students[], int& count)
{
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += students[i].getTotalScore();
	}
	return sum / count;
}


int main()
{
	Student students[200];
	int studentCount = loadStudentFile(ORIGINAL_FILE, students);

	loadStudentFile(ADDED_FILE, students, studentCount);

	saveFile(MERGED_FILE, students, studentCount);
	cout << "�ϲ��ɹ�����鿴�ļ���MergedFile350.txt����" << endl;

	float avg = calculateAverage(students, studentCount);
	cout << "��ƽ����Ϊ��" << avg << endl;

	bubbleSort(students, studentCount, avg);

	for (int i = 0; i < studentCount; i++) {
		if (students[i].getTotalScore() > avg + 10) {
			students[i].showInfo();
		}
	}

	return 0;
}
