#include "class.h"

int main() {
	
	int user = 0, action;
	City* cities = new City[26];
	Date today;
	vector<People> vaccination;
	for (int i = 0; i < 26; i++) { cities[i].setSign(i); }

	while(1){
		cout << "\n�i�Ш̷ӱz��������ܡj\n\n[0] �@�����  [1] ��F�H��  [2]����: "; cin >> user;

		if (user == 0) {			//�@�����
			if (vaccination.size() == 0) {
				cout << "\n�eĵ�i�f��Ʈw�S�����!" << endl;
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
				cout << "\n�eĵ�i�f�ͤ�Ψ����Ҧr����J���~" << endl;
				continue;
			}
			else {
				cout << vaccination[index] ;
				vaccination[index].changeInfo();
				cout << "\n�i�ثe����j: " << vaccination[index].setPriority(cities) << endl;
				cout << "\n==================================================================" << endl;
			}
			//for (int i = 0; i < vaccination.size(); i++) cout << vaccination[i]._ID << endl;


		}
		else if (user == 1) {		//��F�H��
			
			do {
				cout << "\n�i�п�J�������j: (xxxx/xx/xx �άO oooo.oo.oo): "; cin >> today;
			} while (isInvalidDate(today));
		
			char region;
			cout << "\n�i�п�J�Ҧb�����j:\n"
				"A.�x�_�� �@B.�x���� �@C.�򶩥� �@D.�x�n���@ E.�������@ F.�x�_��\n"
				"G.�y���� �@H.��鿤 �@I.�Ÿq�� �@J.�s�˿� �@K.�]�߿��@ L.�x����\n"
				"M.�n�뿤 �@N.���ƿ� �@O.�s�˥� �@P.���L���@ Q.�Ÿq���@ R.�x�n��\n"
				"S.������ �@T.�̪F�� �@U.�Ὤ�� �@V.�x�F���@ W.�������@ X.���\n"
				"Y.�����s �@Z.�s����" << endl;
			cin >> region;
			do {
				cout << "\n�i�п���ʧ@�j:\n"; 
				cout << "[0] ����  [1] �s�W���ت̸��  [2] �s�W�̭]���: "; cin >> action;
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