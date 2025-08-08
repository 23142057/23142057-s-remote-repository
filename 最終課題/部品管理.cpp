#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>

using namespace std;

struct robotparts {
public:
	string type;
	string usedname;
	int currentnumber;
	string url;
	string typenumber;
	int price;
	int standard;

	robotparts(const string& partstype, const string& partsusedname, int partscurrentnember, const string& partsurl,
		const string& partstypenumber, int partsprice, int partsstandard)
		: type(partstype), usedname(partsusedname), currentnumber(partscurrentnember), url(partsurl),
		typenumber(partstypenumber), price(partsprice), standard(partsstandard) {
	}

	void entry();
	void edit();
	void show();
	void suggestion();
	bool operator<(const robotparts& other) const {
		return typenumber < other.typenumber;
	}

};

ostream& operator<<(ostream& os, const robotparts& part) {//�s�����i�p�̃I�y���[�^�[
	os << part.usedname << " (�݌�: " << part.currentnumber << ", ��{��: " << part.standard << ", URL: " << part.url << ", �^��: " << part.typenumber << ")";
	return os;
}

set<robotparts> partsset;


void robotparts::entry() {//���i�o�^�֐�
	cout << "���i�^�C�v�A�ʏ́A���݂̍݌ɐ��AURL�A�^�ԁA�Q�l���i(�~/��)�A��{���̏��œ���" << endl;

	string partstype;
	string partsusedname;
	int partscurrentnumber;
	string partsurl;
	string partstypenumber;
	int partsprice;
	int partsstandard;

	cout << "���i�^�C�v�@";
	cin >> partstype;
	cout << "�ʏ́@";
	cin >> partsusedname;
	cout << "���݂̍݌ɐ��@";
	cin >> partscurrentnumber;
	cout << "URL�@";
	cin >> partsurl;
	cout << "�^�ԁ@";
	cin >> partstypenumber;
	cout << "�Q�l���i�i�~/�j�@";
	cin >> partsprice;
	cout << "�W�����@";
	cin >> partsstandard;

	ofstream outfile("���i�\.txt", ios_base::app);
	outfile << partstype << " "
		<< partsusedname << " "
		<< partscurrentnumber << " "
		<< partsurl << " "
		<< partstypenumber << " "
		<< partsprice << " "
		<< partsstandard << endl;


	partsset.emplace(partstype, partsusedname, partscurrentnumber,
		partsurl, partstypenumber, partsprice, partsstandard);

	cout << "�o�^���������܂���" << endl;

}//���i�o�^�֐�

void robotparts::edit() {//���i�ҏW�֐�
	cout << "�ҏW���������i�̒ʏ̂ƍ��� ( �݌ɐ� or URL or ���i or �W���� )����͂��Ă�������" << endl;
	string targetUsedName;
	int changeNumber;
	string newURL;
	int newprice;
	int newstandard;
	string changething;
	cin >> targetUsedName >> changething;

	ifstream infile("���i�\.txt");
	vector<robotparts> allParts;
	bool found = false;

	if (changething == "�݌ɐ�") {
		cout << "�ύX������́i���炷�ꍇ�͕��̐��j" << endl;
		cin >> changeNumber;
		while (!infile.eof()) {
			string type, usedname, url, typenumber;
			int currentnumber, price, standard;

			infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
			if (infile.fail()) break;

			if (usedname == targetUsedName) {
				currentnumber += changeNumber;
				found = true;
			}

			allParts.emplace_back(type, usedname, currentnumber, url, typenumber, price, standard);
		}
		infile.close();
		if (!found) {
			cout << "�w�肳�ꂽ���i��������܂���ł����B" << endl;
			return;
		}

		ofstream outfile("���i�\.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "�݌ɐ����X�V���܂����B" << endl;
	}

	else if (changething == "URL") {
		cout << "�V����URL�����" << endl;
		cin >> newURL;
		while (!infile.eof()) {
			string type, usedname, url, typenumber;
			int currentnumber, price, standard;

			infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
			if (infile.fail()) break;

			if (usedname == targetUsedName) {
				url = newURL;
				found = true;
			}

			allParts.emplace_back(type, usedname, currentnumber, url, typenumber, price, standard);
		}
		infile.close();
		if (!found) {
			cout << "�w�肳�ꂽ���i��������܂���ł����B" << endl;
			return;
		}

		ofstream outfile("���i�\.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "URL���X�V���܂����B" << endl;
	}
	else if (changething == "���i") {
		cout << "�V�������i�i�~/�j�����(���p)" << endl;
		cin >> newprice;
		while (!infile.eof()) {
			string type, usedname, url, typenumber;
			int currentnumber, price, standard;

			infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
			if (infile.fail()) break;

			if (usedname == targetUsedName) {
				price = newprice;
				found = true;
			}

			allParts.emplace_back(type, usedname, currentnumber, url, typenumber, price, standard);
		}
		infile.close();
		if (!found) {
			cout << "�w�肳�ꂽ���i��������܂���ł����B" << endl;
			return;
		}

		ofstream outfile("���i�\.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "���i���X�V���܂����B" << endl;
	}
	else if (changething == "�W����") {
		cout << "�V�����W���������(���p)" << endl;
		cin >> newstandard;
		while (!infile.eof()) {
			string type, usedname, url, typenumber;
			int currentnumber, price, standard;

			infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
			if (infile.fail()) break;

			if (usedname == targetUsedName) {
				standard = newstandard;
				found = true;
			}

			allParts.emplace_back(type, usedname, currentnumber, url, typenumber, price, standard);
		}
		infile.close();
		if (!found) {
			cout << "�w�肳�ꂽ���i��������܂���ł����B" << endl;
			return;
		}

		ofstream outfile("���i�\.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "�W�������X�V���܂����B" << endl;
	}
	else {
		cout << "���݂��Ȃ����ڂł�" << endl;
	}
}//���i�ҏW�֐�


void robotparts::show() {
	cout << "�Q�Ƃ������p�[�c�Q( all or lack or ���i�^�C�v)�����" << endl;
	string showparts;
	cin >> showparts;
	ifstream infile("���i�\.txt");
	bool found = false;

	if (showparts == "all") {
		cout<<"���i�^�C�v�A�ʏ́A���݂̍݌ɐ��AURL�A�^�ԁA�Q�l���i(�~/��)�A��{��" << endl;
		string line;
		while (getline(infile, line)) {
			cout << line <<	endl;
		}
		infile.close();

	}

	else if (showparts == "lack") {
		vector<robotparts>lackparts;
		bool found = false;

		while (!infile.eof()) {
			string type, usedname, url, typenumber;
			int currentnumber, price, standard;

			infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
			if (infile.fail()) break;

			if (currentnumber <= standard) {
				lackparts.emplace_back(type, usedname, currentnumber, url, typenumber, price, standard);
				found = true;
			}
		}
		infile.close();
		if (!found) {
			cout << "�s�����Ă��镔�i�͌�����܂���ł����B" << endl;
			return;
		}

		cout << "�s�����Ă��镔�i�͈ȉ��̒ʂ�ł�" << endl;
		for (auto it = lackparts.begin(); it != lackparts.end(); ++it) {
			cout << *it << "\n ";
		}
		cout << endl;
	}
	else {
		vector<robotparts>showtypeparts;
		bool found = false;
		while (!infile.eof()) {
			string type, usedname, url, typenumber;
			int currentnumber, price, standard;

			infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
			if (infile.fail()) break;

			if (type == showparts) {
				showtypeparts.emplace_back(type, usedname, currentnumber, url, typenumber, price, standard);
				found = true;
			}
		}
		infile.close();
		if (!found) {
			cout << "�w�肳�ꂽ���i��������܂���ł����B" << endl;
			return;
		}
		cout << "���͂��ꂽ���i�͈ȉ��̒ʂ�ł�" << endl;
		for (auto it = showtypeparts.begin(); it != showtypeparts.end(); ++it) {
			cout << *it << "\n";
		}
		cout << endl;
	}
}

void robotparts::suggestion() {
	int supportmoney;
	ifstream infile("���i�\.txt");
	cout << "�����z�����" << endl;
	cin >> supportmoney;
	bool found = false;

	while (!infile.eof()) {
		string type, usedname, url, typenumber;
		int currentnumber, price, standard;

		infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
		if (infile.fail()) break;

		if (currentnumber <= standard) {
			int needmoney = price * (standard - currentnumber);
			found = true;
		}
	}
	infile.close();
}


int main() {
	const string partstype;
	const string partsusedname;
	int partscurrentnumber = 0;
	const string partsurl;
	const string partstypenumber;
	int partsprice = 0;
	int partsstandard = 0;

	robotparts Part{ partstype,partsusedname,partscurrentnumber,partsurl,
					 partstypenumber,partsprice,partsstandard };

	string acttype;
	cout << "���s�^�C�v( entry(�o�^) or show(�{��) or edit(�ҏW) )�����" << endl;
	cin >> acttype;
	if (acttype == "entry") {
		Part.entry();
	}
	else if (acttype == "show") {
		Part.show();
	}
	else if (acttype == "edit") {
		Part.edit();
	}

	else {
		cout << "�s���Ȏ��s�^�C�v�ł��B" << endl;
	}

	return 0;
}