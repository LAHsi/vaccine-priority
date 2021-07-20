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
	cout << "\n【請輸入身分憑證】:\n" << endl;
	cout << "身分證字號: " ; cin >> _ID;
	cout << "生日: (xxxx/xx/xx 或是 oooo.oo.oo): " ; 
	cin >> _birthday;
	_gender = _ID[1] - '0';
}
void People::AdminInputInfo(Date today) {
	cout << "\n【請輸入以下資訊】:\n" << endl;
	cout << "姓名: " ; cin >> _name;
	cout << "身分證字號: "; cin >> _ID;
	cout << "生日: (xxxx/xx/xx 或是 oooo.oo.oo): " ; 
	cin >> _birthday;
	while (isInvalidDate(_birthday)) {
		cout << "生日: (xxxx/xx/xx 或是 oooo.oo.oo): ";
		cin >> _birthday;
	}
	cout << "電話號碼: "; cin >> _phone;
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
	cout << "\n==[第" << _category << "類]==" << endl << endl;
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
	cout << "\n【請選擇接種地區】:\n"
			"A.台北市 　B.台中市 　C.基隆市 　D.台南市　 E.高雄市　 F.台北縣\n"
			"G.宜蘭縣 　H.桃園縣 　I.嘉義市 　J.新竹縣 　K.苗栗縣　 L.台中縣\n"
			"M.南投縣 　N.彰化縣 　O.新竹市 　P.雲林縣　 Q.嘉義縣　 R.台南縣\n"
			"S.高雄縣 　T.屏東縣 　U.花蓮縣 　V.台東縣　 W.金門縣　 X.澎湖縣\n"
			"Y.陽明山 　Z.連江縣" << endl;
	cin >> region;

	while(1) {
		cout << "\n【請選擇疫苗種類】: \n\n[1]莫德納  [2]AZ : "; cin >> type;
		if (type == 1) {
			if (cities[region - 'A'].find(cities[region - 'A'].priority_MDN, *this) == -1) {
				cities[region - 'A'].priority_MDN.push(*this);
				int pri = cities[region - 'A'].find(cities[region - 'A'].priority_MDN, *this);
				cities[region - 'A']._vacInCIty[0]._amount--;
				cout << "\n==================================================================" << endl << endl;
				cout << "【當前" << region << "(縣/市)的莫德納疫苗數量】: " << cities[region - 'A']._vacInCIty[0]._amount << endl;
				if (pri > cities[region - 'A']._vacInCIty[0]._amount)cout << "〔警告〕當前" << region << "(縣/市)的莫德納疫苗數量不足" << endl;
				return pri;
			}
			else {
				cout << "\n==================================================================" << endl << endl;
				cout << "〔已申請〕" << endl;
				return cities[region - 'A'].find(cities[region - 'A'].priority_MDN, *this);
			}
		}
		else if (type == 2) {
			if (cities[region - 'A'].find(cities[region - 'A'].priority_AZ, *this) == -1) {
				cities[region - 'A'].priority_AZ.push(*this);
				int pri = cities[region - 'A'].find(cities[region - 'A'].priority_AZ, *this);
				cities[region - 'A']._vacInCIty[1]._amount--;
				cout << "\n==================================================================" << endl << endl;
				cout << "當前" << region << "(縣/市)的AZ疫苗數量: " << cities[region - 'A']._vacInCIty[1]._amount << endl;
				if (pri > cities[region - 'A']._vacInCIty[1]._amount)
					cout << "〔警告〕當前" << region << "(縣/市)的AZ疫苗數量不足" << endl;
				return pri;
			}
			else {
				cout << "\n==================================================================" << endl << endl;
				cout << "〔已申請〕" << endl;
				return cities[region - 'A'].find(cities[region - 'A'].priority_AZ, *this);
			}

		}
		else {
			cout << "〔警告〕輸入錯誤!" << endl;
		}
	} 
}

void People::changeInfo() {

	cout << "\n【請選擇身分】: (以最上面身分為主，不可重複)\n\n"
			"[0] 醫事人員\n"
			"[1] 中央及地方政府防疫人員\n"
			"[2] 防疫旅宿工作人員、防疫車隊駕駛\n"
			"[3] 航空港口工作人員\n"
			"[4] 外交人員、代表國家出國之運動員或選手\n"
			"[5] 洗腎患者、長照機構照護者\n"
			"[6] 孕婦\n"
			"[7] 軍人、國安單位之文職人員、警察\n"
			"[8] 運輸及倉儲業者\n"
			"[9] 高中職以下學校教職員工\n"
			"[10]原住民\n"
			"[11]其他"<< endl;
	cin >> _job ;
	cout << "\n【是否有罕見疾病及重大傷病】: \n[0]沒有 [1]有: " ;
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
	cout << "\n【請選擇設定之疫苗種類】: \n\n[1]莫德納  [2]AZ" << endl; cin >> kind;
	cout << "\n【請輸入疫苗數量】: " << endl; cin >> _vacInCIty[kind-1]._amount;
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
		cout << "\n〔警告〕日期輸入錯誤!" << endl;
		return 1; //False
	}
}

