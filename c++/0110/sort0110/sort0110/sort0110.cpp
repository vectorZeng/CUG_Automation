#include<iostream>
#include<string>
#include<fstream>


using namespace std;  

#define ORIGINAL_FILE "数学物理英语.txt"
#define ADDED_FILE "导论C语言思修.txt"
#define MERGED_FILE "MergedFile337.txt"
#define SORTED_FILE "SortedFile337.txt"

class Student {
public:
	friend void loadStudentFile(const string& filename, Student students[], int count);


private:
	string m_Id; // 学号
	string m_Name; // 名字
	int m_Math; // 数学
	int m_Physics; // 物理
	int m_English; // 英语
	int m_Basic; // 导论
	int m_C; // C语言
	int m_Mind; // 思修

public:
	// 构造函数
	Student() : m_Id(""), m_Name(""), m_Math(0), m_Physics(0), m_English(0), m_Basic(0), m_C(0), m_Mind(0) {}

	Student(string id, string name, int math, int physics, int english, int basic, int c, int mind)
		:m_Id(id), m_Name(name), m_Math(math), m_Physics(physics), m_English(english), m_Basic(basic), m_C(c), m_Mind(mind) {
	}

	// 获取学号
	string getId() {
		return m_Id;
	}
	// 获取名字
	string getName() {
		return m_Name;
	}
	// 获取单科成绩
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

	// 总分
	int getTotalScore()
	{
		return m_Math + m_Physics + m_English + m_Basic + m_C + m_Mind;
	}

	// 查看信息
	void showInfo()
	{
		cout << m_Id << " " << m_Name << " "
			<< m_Math << " " << m_Physics << " "
			<< m_English << " " << m_Basic << " "
			<< m_C << " " << m_Mind << " "
			<< getTotalScore() << endl;
	}
};

// 读取原始文件
int loadStudentFile(const string& filename, Student students[])
{
	// 录取文件
	ifstream file;
	file.open(filename, ios::in);

	string id, name;
	int math, physics, english;
	int basic = 0;
	int c = 0;
	int mind = 0;
	// 记录学生个数
	int count = 0;

	// 输入
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
		cerr << "无法打开附加文件：" << filename << endl;
		return;
	}

	string id, name;
	int math = 0;
	int physics = 0;
	int english = 0;
	int basic = 0;
	int c = 0;
	int mind = 0;

	// 读取附加文件并合并信息
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

// 写入文件
void saveFile(const string& filename, Student students[], int& count)
{
	ofstream file;
	file.open(filename, ios::out);
	file << "学号\t" << "姓名\t" << "数学\t" << "物理\t" << "英语\t" << "导论\t" << "C语言 " << "思修\t" << "总分" << endl;
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

// 写入文件
void saveSortedFile(const string& filename, Student students[], int& count, float avg)
{
	ofstream file;
	file.open(filename, ios::out);
	file << "学号\t" << "姓名\t" << "数学\t" << "物理\t" << "英语\t" << "导论\t" << "C语言 " << "思修\t" << "总分" << endl;
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

// 排序输出（冒泡排序）
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
	cout << "排序成功！请查看文件“SortedFile350.txt”!" << endl;
}

// 计算平均分
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
	cout << "合并成功！请查看文件“MergedFile350.txt”！" << endl;

	float avg = calculateAverage(students, studentCount);
	cout << "总平均分为：" << avg << endl;

	bubbleSort(students, studentCount, avg);

	for (int i = 0; i < studentCount; i++) {
		if (students[i].getTotalScore() > avg + 10) {
			students[i].showInfo();
		}
	}

	return 0;
}
