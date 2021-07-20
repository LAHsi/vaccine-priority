#include "class.h"

/*---Date---------------------------------------------------*/
Date::Date() {
	_y = _m = _d = 0;
}
Date::Date(int y, int m, int d) {
	_y = (y > 0) ? y : 0;
	_m = (m > 0 && m <= 12) ? m : 0;
	_d = (d > 0 && d <= 31) ? d : 0;
}

/*---vaccine-------------------------------------------------
* int _type, _amount;
-----------------------------------------------------------*/

vaccine::vaccine() {
	_amount = 0;
	_type = 0;
}

/*---people--------------------------------------------------
 *	string name, ID;
 *	char* phone;
 *	int job, age, gender, priority, category;
 *  bool disease
 *	Date birthday;
 -----------------------------------------------------------*/
People::People() {
	_job = _category = 99;
	_gender = -1;
	_disease = 0;
}

bool People::check(People checker) {
	if (_ID == checker._ID && _birthday == checker._birthday) return true;
	return false;
}
void People::inputInfo(Date today) {
	cout << "\n�i�п�J�������ҡj:\n" << endl;
	cout << "�����Ҧr��: " ; cin >> _ID;
	cout << "�ͤ�: (xxxx/xx/xx �άO oooo.oo.oo): " ; 
	cin >> _birthday;
	_gender = _ID[1] - '0';
}
void People::AdminInputInfo(Date today) {
	cout << "\n�i�п�J�H�U��T�j:\n" << endl;
	cout << "�m�W: " ; cin >> _name;
	cout << "�����Ҧr��: "; cin >> _ID;
	cout << "�ͤ�: (xxxx/xx/xx �άO oooo.oo.oo): " ; 
	cin >> _birthday;
	while (isInvalidDate(_birthday)) {
		cout << "�ͤ�: (xxxx/xx/xx �άO oooo.oo.oo): ";
		cin >> _birthday;
	}
	cout << "�q�ܸ��X: "; cin >> _phone;
	_gender = _ID[1] - '0';
	countAge(today);
}
void People::setCategory() {
	if (_job < 10) {
		switch (_job) {
		case 0:
			_category = 1; break;
		case 1:
			_category = 2; break;
		case 2:
			_category = 3; break;
		case 3:
			_category = 3; break;
		case 4:
			_category = 4; break;
		case 5:
			_category = 5; break;
		case 6:
			_category = 6; break;
		case 7:
			_category = 7; break;
		case 8:
			_category = 7; break;
		case 9:
			_category = 7; break;
		default: break;
		}
	}
	else{
		if (_age._y >= 65 && _job == 10) _category = 6;
		else if (_age._y >= 75) _category = 6;
		else if (_age._y >= 55 && _age._y <= 64 && _job == 10) _category = 8;
		else if (_age._y >= 65 && _age._y <= 74) _category = 8;
		else if (_age._y >= 19 && _age._y <= 64)_category = 9;
		else if (_disease) _category = 9;
		else _category = 10;
	}
	cout << "\n==[��" << _category << "��]==" << endl << endl;
}
void People::countAge(Date today) {
	Date birthday = _birthday;
	if (birthday._d > today._d) today._m = (today._m - 1) % 12;
	if (birthday._m > today._m) { today._y--; today._m += 12; }
	_age._m = (today._m - birthday._m) % 12;
	_age._y = (today._y >= birthday._y) ? today._y - birthday._y : 0;
}
int People::setPriority(City*& cities) {
	int type;
	char region;
	cout << "\n�i�п�ܱ��ئa�ϡj:\n"
			"A.�x�_�� �@B.�x���� �@C.�򶩥� �@D.�x�n���@ E.�������@ F.�x�_��\n"
			"G.�y���� �@H.��鿤 �@I.�Ÿq�� �@J.�s�˿� �@K.�]�߿��@ L.�x����\n"
			"M.�n�뿤 �@N.���ƿ� �@O.�s�˥� �@P.���L���@ Q.�Ÿq���@ R.�x�n��\n"
			"S.������ �@T.�̪F�� �@U.�Ὤ�� �@V.�x�F���@ W.�������@ X.���\n"
			"Y.�����s �@Z.�s����" << endl;
	cin >> region;

	while(1) {
		cout << "\n�i�п�ܬ̭]�����j: \n\n[1]���w��  [2]AZ : "; cin >> type;
		if (type == 1) {
			if (cities[region - 'A'].find(cities[region - 'A'].priority_MDN, *this) == -1) {
				cities[region - 'A'].priority_MDN.push(*this);
				int pri = cities[region - 'A'].find(cities[region - 'A'].priority_MDN, *this);
				cities[region - 'A']._vacInCIty[0]._amount--;
				cout << "\n==================================================================" << endl << endl;
				cout << "�i��e" << region << "(��/��)�����w�Ǭ̭]�ƶq�j: " << cities[region - 'A']._vacInCIty[0]._amount << endl;
				if (pri > cities[region - 'A']._vacInCIty[0]._amount)cout << "�eĵ�i�f��e" << region << "(��/��)�����w�Ǭ̭]�ƶq����" << endl;
				return pri;
			}
			else {
				cout << "\n==================================================================" << endl << endl;
				cout << "�e�w�ӽСf" << endl;
				return cities[region - 'A'].find(cities[region - 'A'].priority_MDN, *this);
			}
		}
		else if (type == 2) {
			if (cities[region - 'A'].find(cities[region - 'A'].priority_AZ, *this) == -1) {
				cities[region - 'A'].priority_AZ.push(*this);
				int pri = cities[region - 'A'].find(cities[region - 'A'].priority_AZ, *this);
				cities[region - 'A']._vacInCIty[1]._amount--;
				cout << "\n==================================================================" << endl << endl;
				cout << "��e" << region << "(��/��)��AZ�̭]�ƶq: " << cities[region - 'A']._vacInCIty[1]._amount << endl;
				if (pri > cities[region - 'A']._vacInCIty[1]._amount)
					cout << "�eĵ�i�f��e" << region << "(��/��)��AZ�̭]�ƶq����" << endl;
				return pri;
			}
			else {
				cout << "\n==================================================================" << endl << endl;
				cout << "�e�w�ӽСf" << endl;
				return cities[region - 'A'].find(cities[region - 'A'].priority_AZ, *this);
			}

		}
		else {
			cout << "�eĵ�i�f��J���~!" << endl;
		}
	} 
}

void People::changeInfo() {

	cout << "\n�i�п�ܨ����j: (�H�̤W���������D�A���i����)\n\n"
			"[0] ��ƤH��\n"
			"[1] �����Φa��F�����̤H��\n"
			"[2] ���̮ȱJ�u�@�H���B���̨����r�p\n"
			"[3] ��Ŵ�f�u�@�H��\n"
			"[4] �~��H���B�N���a�X�ꤧ�B�ʭ��ο��\n"
			"[5] �~�Ǳw�̡B���Ӿ��c���@��\n"
			"[6] ����\n"
			"[7] �x�H�B��w��줧��¾�H���Bĵ��\n"
			"[8] �B��έ��x�~��\n"
			"[9] ����¾�H�U�Ǯձ�¾���u\n"
			"[10]����\n"
			"[11]��L"<< endl;
	cin >> _job ;
	cout << "\n�i�O�_���u���e�f�έ��j�˯f�j: \n[0]�S�� [1]��: " ;
	cin >> _disease;
	setCategory();
}

/*---City--------------------------------------------------
* char _citySign;
* vaccine _vacInCIty[2];
-----------------------------------------------------------*/

City::City() {
	_citySign = '?';
	_vacInCIty[0]._type = 1;
	_vacInCIty[0]._amount = 0;
	_vacInCIty[1]._type = 2;
	_vacInCIty[1]._amount = 0;

}
void City::setVac() {
	int kind;
	cout << "\n�i�п�ܳ]�w���̭]�����j: \n\n[1]���w��  [2]AZ" << endl; cin >> kind;
	cout << "\n�i�п�J�̭]�ƶq�j: " << endl; cin >> _vacInCIty[kind-1]._amount;
}
vaccine City::getVac(int v) { return _vacInCIty[v]; }
void City::outVac() {
	for (int i = 0; i < 2; i++) {
		cout << i << "  amount: " << _vacInCIty[i]._amount << endl;
	}
}

void City::setSign(int ch) {
		_citySign = 'A' + ch;
}
const char City::getSign() { return _citySign; }

int City::find(priority_queue< People, vector<People>, cmp > &pq, const People p){

	priority_queue< People, vector<People>, cmp > cpy_pq = pq;
	for (int i = 0; !cpy_pq.empty(); i++) {
		if (cpy_pq.top()._ID == p._ID) return i+1;
		cpy_pq.pop();
	}
	return -1;
}

/*---functions--------------------------------------------------
* char _citySign;
* vaccine _vacInCIty;
-----------------------------------------------------------*/

int isInvalidDate(Date date) {
	int dayarray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (date._y % 4 == 0 && date._y % 100 > 0 || date._y % 400 == 0)
		dayarray[1] = 29;
	if (date._d <= dayarray[date._m - 1] && date._d >= 1 && date._m <= 12 && date._m > 0 && date._y > 0) return 0; //True
	else {
		cout << "\n�eĵ�i�f�����J���~!" << endl;
		return 1; //False
	}
}

