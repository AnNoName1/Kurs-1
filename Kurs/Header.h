#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
bool is_mty(ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}
bool is_fnd(string A,string B) {
	auto l = A.find(B);
	return l <=A.size();
}

class Client
{
	friend class ClientManager;
	string name;
	string adress;
	string PNumber;
	int num;
	bool ifAnIndividual;

public:
	string getNm()
	{
		return name;
	}
	string getAd()
	{
		return adress;
	}
	string getPN()
	{
		return PNumber;
	}
	bool getIfAn() {
		return ifAnIndividual;
	}
	int getNum() {
		return num;
	}
	friend ostream& operator<<(ostream& os, Client const& cl);
	friend istream& operator>>(istream& is, Client& cl);
protected:
	void setNm(string Nm = "default name")
	{
		name = Nm;
	}
	void setAd(string ad)
	{
		adress = ad;
	}
	void setPN(string Pn)
	{
		PNumber = Pn;
	}
	void setIfAnIn(bool ifAnIn)
	{
		ifAnIndividual = ifAnIn;
	}
	void setNum(int num)
	{
		this->num = num;
	}
};
ostream& operator<<(ostream& os, Client const& cl)
{
	os << cl.num << " "<<cl.name << " " << cl.adress << " " <<cl.PNumber<< " " << cl.ifAnIndividual;
	return os;
}
istream& operator>>(istream& is, Client& cl)
{
	is >> cl.name >> cl.adress >> cl.PNumber  >> cl.ifAnIndividual;
	return is;
}
class ClientManager : Client
{
	vector <Client> ClList;


	struct cmpNm {
		bool operator()(Client A, Client B) const { return A.getNm() < B.getNm(); }
	}cmpnm;
	struct cmpAd {
		bool operator()(Client A, Client B) const { return A.getAd() < B.getAd(); }
	}cmpad;
	struct cmpPN {
		bool operator()(Client A, Client B) const { return A.getPN() < B.getPN(); }
	}cmppn;

public:
	void DeleteClient(int num)
	{
		if (num <= ClList.size())  ClList.erase(ClList.begin() + num - 1);
		else cout << "No client with such number" << endl;
	}
	vector<Client> FindClient(string sp)
	{
		vector<Client> fnd;
		for (int i = 0; i < ClList.size(); i++) {
			if (is_fnd(ClList[i].getNm(), sp) || is_fnd(ClList[i].getAd(), sp) ||
				is_fnd(to_string(ClList[i].getNum()), sp) || is_fnd(ClList[i].getPN(), sp))
			{
				fnd.push_back(ClList[i]);
			}
		}
		return fnd;
	}
	vector <Client> SortBy(int opt)
	{
		vector<Client> Cl = ClList;
		switch (opt) {
			case 1:
			{
				sort(Cl.begin(), Cl.end(), cmpnm);
				break;
			}
			case 2:
			{
				sort(Cl.begin(), Cl.end(),cmpad);
				break;
			}
			case 3:
			{
				sort(Cl.begin(), Cl.end(), cmppn);
				break;
			}
		}
		return Cl;
	}


	void CreateNewClient(string Nm, string Ad, string PN, bool ifAnIn)
	{
		Client L;
		L.setNm(Nm);
		L.setAd(Ad);
		L.setPN(PN);
		L.setIfAnIn(ifAnIn);
		L.setNum(ClList.size() + 1);
		ClList.push_back(L);
	}
	void SaveBase() 
	{
		remove("Base.txt");
		ofstream fout;
		fout.open("Base.txt");
		fout << ClList.size() << endl;
		for (int i = 0; i < ClList.size(); i++) {
			fout << ClList[i]<<endl;
		}
		fout.close();
	}
	void LoadBase()
	{
		ifstream fin;
		fin.open("Base.txt");
		if (!fin.is_open()) 
		{
			cout << "file not opened" << endl;
			return;
		}
		
		
		if (is_mty(fin)) 
		{
			cout << "Fill the file first" << endl;
			return;
		}
		else cout << "Base loaded" << endl;
		int n;
		fin >> n;
		ClList.erase(ClList.begin(),ClList.end());
		for (int i = 0; i < n; i++) 
		{
			Client A;
			fin >> A;
			this->CreateNewClient(A.getNm(), A.getAd(),A.getPN(), A.getIfAn());
		}
		fin.close();
	}
};

#endif
