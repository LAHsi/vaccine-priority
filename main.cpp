#include "class.h"

int main() {
	
	int user = 0, action;
	City* cities = new City[26];
	Date today;
	vector<People> vaccination;
	for (int i = 0; i < 26; i++) { cities[i].setSign(i); }

	while(1){
		cout << "\n【請依照您的身分選擇】\n\n[0] 一般民眾  [1] 行政人員  [2]結束: "; cin >> user;

		if (user == 0) {			//一般民眾
			if (vaccination.size() == 0) {
				cout << "\n〔警告〕資料庫沒有資料!" << endl;
				continue;
			}
			int index = 0;
			People p;
			p.inputInfo(today);
			auto it = vaccination.begin();
			for (; it != vaccination.end(); it++) {
				if ((*it).check(p)) break; 
				index++;
			}
			if (it == vaccination.end()) {
				cout << "\n〔警告〕生日或身分證字號輸入錯誤" << endl;
				continue;
			}
			else {
				cout << vaccination[index] ;
				vaccination[index].changeInfo();
				cout << "\n【目前順位】: " << vaccination[index].setPriority(cities) << endl;
				cout << "\n==================================================================" << endl;
			}
			//for (int i = 0; i < vaccination.size(); i++) cout << vaccination[i]._ID << endl;


		}
		else if (user == 1) {		//行政人員
			
			do {
				cout << "\n【請輸入今日日期】: (xxxx/xx/xx 或是 oooo.oo.oo): "; cin >> today;
			} while (isInvalidDate(today));
		
			char region;
			cout << "\n【請輸入所在縣市】:\n"
				"A.台北市 　B.台中市 　C.基隆市 　D.台南市　 E.高雄市　 F.台北縣\n"
				"G.宜蘭縣 　H.桃園縣 　I.嘉義市 　J.新竹縣 　K.苗栗縣　 L.台中縣\n"
				"M.南投縣 　N.彰化縣 　O.新竹市 　P.雲林縣　 Q.嘉義縣　 R.台南縣\n"
				"S.高雄縣 　T.屏東縣 　U.花蓮縣 　V.台東縣　 W.金門縣　 X.澎湖縣\n"
				"Y.陽明山 　Z.連江縣" << endl;
			cin >> region;
			do {
				cout << "\n【請選取動作】:\n"; 
				cout << "[0] 結束  [1] 新增接種者資料  [2] 新增疫苗資料: "; cin >> action;
				if (action == 1) {
					People person;
					person.AdminInputInfo(today);
					vaccination.push_back(person);
				}
				else if (action == 2) cities[region-'A'].setVac();
				else continue;
			} while (action);

		}
		else return 0;
	}

	return 0;
}