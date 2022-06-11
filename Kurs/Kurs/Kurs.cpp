#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	ClientManager pr;
	int propNum = 4;
	
	string ans;
	while (true) 
	{
		cout << "(1)create Client" << endl << "(2)sort" << endl <<
			"(3)delete client" << endl << "(4)search client" << endl << "(5)Quit" <<
			endl << "(6)load client base" << endl << "(7)save client base" << endl;
		cin >> ans;
		if (is_number(ans)) { cout << "Not a number" << endl; continue; }
		switch (stoi(ans))
		{
		case 1:
		{
			cout << "enter client properties" << endl;
			vector<string> anw(propNum);
			for (int i = 0; i < propNum; i++)
			{
				cin >> anw[i];
			}
			pr.CreateNewClient(anw[0], anw[1], anw[2], anw[3] == "1");
			break;
		}
		case 2:
		{
			cout << "sort by:" << endl << "1)Name" << endl << "2)Phone Number" << endl <<
				"3)Adress" << endl << "4)Personal number" << endl;
			string an;
			cin >> an;
			if (is_number(an)) { cout << "Not a number" << endl; break;}
			vector<Client> A = pr.SortBy(stoi(an));
			for (int i = 0; i < A.size(); i++) {
				cout << A[i] << endl;
			}
			break;
		}
		case 3:
		{
			cout << "enter number of client you want to delete" << endl;
			int an;
			cin >> an;
			pr.DeleteClient(an);
			break;
		}
		case 4:
		{
			cout << "enter client's name/phone number/adress/personal number" << endl;
			string an;
			cin >> an;
			vector<Client> Ar = pr.FindClient(an);
			int nn = Ar.size();
			if (nn == 0)
			{
				cout << "no clients found" << endl;
			}
			else {
				cout << "found " << nn << " clients with such properties:" << endl;
				for (int i = 0; i < Ar.size(); i++) {
					cout << Ar[i] << endl;
				}
			}
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		case 6:
		{
			pr.LoadBase();
			
			break;
		}
		case 7:
		{
			pr.SaveBase();
		}
		}
	}
	return 0;
}
/*
	Victor Krushovice,6 88005553535 1
	Sanek Krushovice,7 89005553535 0
	Kolya Moskovskaya,13 84958858585 1
	Roman Novoslobodskaya,45K2 81234567890 0
*/
