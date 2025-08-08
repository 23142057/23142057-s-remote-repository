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
	void truemoney();
	bool operator<(const robotparts& other) const {
		return typenumber < other.typenumber;
	}

};

ostream& operator<<(ostream& os, const robotparts& part) {//不足部品用のオペレーター
	os << part.usedname << " (在庫: " << part.currentnumber << ", 標準個数: " << part.standard << ", URL: " << part.url << ", 型番: " << part.typenumber << ")";
	return os;
}

set<robotparts> partsset;


void robotparts::entry() {//部品登録関数
	cout << "部品タイプ、通称、現在の在庫数、URL、型番、参考価格(円/個)、標準個数の順で入力" << endl;

	string partstype;
	string partsusedname;
	int partscurrentnumber;
	string partsurl;
	string partstypenumber;
	int partsprice;
	int partsstandard;

	cout << "部品タイプ　";
	cin >> partstype;
	cout << "通称　";
	cin >> partsusedname;
	cout << "現在の在庫数　";
	cin >> partscurrentnumber;
	cout << "URL　";
	cin >> partsurl;
	cout << "型番　";
	cin >> partstypenumber;
	cout << "参考価格（円/個）　";
	cin >> partsprice;
	cout << "標準個数　";
	cin >> partsstandard;

	ofstream outfile("部品表.txt", ios_base::app);
	outfile << partstype << " "
		<< partsusedname << " "
		<< partscurrentnumber << " "
		<< partsurl << " "
		<< partstypenumber << " "
		<< partsprice << " "
		<< partsstandard << endl;


	partsset.emplace(partstype, partsusedname, partscurrentnumber,
		partsurl, partstypenumber, partsprice, partsstandard);

	cout << "登録が完了しました" << endl;

}//部品登録関数

void robotparts::edit() {//部品編集関数
	cout << "編集したい部品の通称と項目 ( 在庫数 or URL or 価格 or 標準個数 )を入力してください" << endl;
	string targetUsedName;
	int changeNumber;
	string newURL;
	int newprice;
	int newstandard;
	string changething;
	cin >> targetUsedName >> changething;

	ifstream infile("部品表.txt");
	vector<robotparts> allParts;
	bool found = false;

	if (changething == "在庫数") {
		cout << "変更数を入力（減らす場合は負の数）" << endl;
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
			cout << "指定された部品が見つかりませんでした。" << endl;
			return;
		}

		ofstream outfile("部品表.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "在庫数を更新しました。" << endl;
	}

	else if (changething == "URL") {
		cout << "新しいURLを入力" << endl;
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
			cout << "指定された部品が見つかりませんでした。" << endl;
			return;
		}

		ofstream outfile("部品表.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "URLを更新しました。" << endl;
	}
	else if (changething == "価格") {
		cout << "新しい価格（円/個）を入力(半角)" << endl;
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
			cout << "指定された部品が見つかりませんでした。" << endl;
			return;
		}

		ofstream outfile("部品表.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "価格を更新しました。" << endl;
	}
	else if (changething == "標準個数") {
		cout << "新しい標準個数を入力(半角)" << endl;
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
			cout << "指定された部品が見つかりませんでした。" << endl;
			return;
		}

		ofstream outfile("部品表.txt", ios::trunc);
		for (const auto& part : allParts) {
			outfile << part.type << " " << part.usedname << " " << part.currentnumber << " "
				<< part.url << " " << part.typenumber << " " << part.price << " " << part.standard << endl;
		}
		outfile.close();

		cout << "標準個数を更新しました。" << endl;
	}
	else {
		cout << "存在しない項目です" << endl;
	}
}//部品編集関数


void robotparts::show() {
	cout << "参照したいパーツ群( all or lack or 部品タイプ)を入力" << endl;
	string showparts;
	cin >> showparts;
	ifstream infile("部品表.txt");
	bool found = false;

	if (showparts == "all") {
		cout<<"部品タイプ、通称、現在の在庫数、URL、型番、参考価格(円/個)、標準個数" << endl;
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
			cout << "不足している部品は見つかりませんでした。" << endl;
			return;
		}

		cout << "不足している部品は以下の通りです" << endl;
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
			cout << "指定された部品が見つかりませんでした。" << endl;
			return;
		}
		cout << "入力された部品は以下の通りです" << endl;
		for (auto it = showtypeparts.begin(); it != showtypeparts.end(); ++it) {
			cout << *it << "\n";
		}
		cout << endl;
	}
}

void robotparts::truemoney() {
	int currentmoney;
	ifstream infile("部品表.txt");
	bool found = false;
	cout << "現在の資金（円）を入力（半角）" << endl;
	cin >> currentmoney;

	while (!infile.eof()) {
		string type, usedname, url, typenumber;
		int currentnumber, price, standard;

		infile >> type >> usedname >> currentnumber >> url >> typenumber >> price >> standard;
		if (infile.fail()) break;

		if (currentnumber <= standard) {
			int partmoney = price * (standard - currentnumber);
			 currentmoney -= partmoney;
			found = true;
		}
	}
	infile.close();
	cout << "現在の実質的な資金は　" <<currentmoney<<"円　です。" << endl;
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
	cout << "実行タイプ( entry(登録) or show(閲覧) or edit(編集) or truemoney(実質資金) )を入力" << endl;
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
	else if (acttype == "truemoney") {
		Part.truemoney();
	}

	else {
		cout << "不明な実行タイプです。" << endl;
	}

	return 0;
}