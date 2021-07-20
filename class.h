#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
class City;
class vaccine;
class Date;
class People;
int isInvalidDate(Date date);

class vaccine {
friend ostream& operator<< (ostream& os, vaccine& vac){
	cout << "amount: " << vac._amount ;
	return os;
}
public:
	vaccine();
	int _type, _amount;
};

class Date {
friend istream& operator>> (istream& is, Date& dt){
	char ch;
	cin >> dt._y >> ch >> dt._m >> ch >> dt._d;
	return is;
}
friend ostream& operator<< (ostream& os, Date& dt){
	cout<< dt._y << "/" << dt._m << "/" << dt._d;
	return os;
}
public:
	Date();
	Date(int y, int m, int d);
	bool operator==(Date date) {
		if (date._y == _y && date._m == _m && date._d == _d) return true;
		return false;
	}
	int _y, _m, _d;
};

class People {
friend ostream& operator<<(ostream& output, People p) {
	cout << "\n---------------------------------------------" << endl;
	cout << "  姓名: " << p._name << endl;
	cout << "  性別: ";
	if (p._gender == 1) cout << "男" << endl;
	else cout << "女" << endl;
	cout << "  生日: " << p._birthday << endl;
	cout << "  年齡: " << p._age._y << "歲" << p._age._m << "個月" << endl;
	cout << "---------------------------------------------" << endl;

	return output;
}
public:
	People();
	bool check(People checker);
	void countAge(Date);
	void inputInfo(Date);
	void AdminInputInfo(Date);
	void changeInfo();
	void setCategory();
	int setPriority(City* & cities);
	int _category;
	string _ID;

private:
	string _name;
	string _phone;
	int _job, _gender;	//1:男	2.女
	bool _disease;
	Date _birthday, _age;
};

class City {
public:
	City();
	struct cmp {
		bool operator()(const People a, const People b) {
			return a._category > b._category;
		}
	};
	void setVac();
	vaccine getVac(int v);
	void outVac();
	void setSign(int ch);
	const char getSign();
	vaccine _vacInCIty[2];
	priority_queue< People, vector<People>, cmp > priority_MDN;
	priority_queue< People, vector<People>, cmp > priority_AZ;
	int find(priority_queue< People, vector<People>, cmp >&, const People);


private:
	char _citySign;

};




