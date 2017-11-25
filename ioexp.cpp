#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<unsigned long int> pos;
	string str;
	
	ifstream fin;
	ofstream fout;
	fout.open("test.txt");
	cout<<fout.tellp()<<endl;
	fout<<"2L,";
	cout<<fout.tellp()<<endl;
	//pos.push_back(fout.tellp());
	fout<<123456;
	cout<<fout.tellp()<<endl;
	//pos.push_back(fout.tellp());
	fout<<",";
	fout<<7891011;
	cout<<fout.tellp()<<endl;
	//pos.push_back(fout.tellp());
	fout<<endl;
	pos.push_back(fout.tellp());
	cout<<fout.tellp()<<endl;
	fout<<"2L,234566,321445"<<endl;
	fout.close();
	fin.open("test.txt");
	//seekg(fin.beg,0);
	//getline(str,pos[1]-pos[0]-1);
	getline(fin,str);
	cout<<str<<endl;
	//seekg(fin.beg,pos[1]);
	//getline(str,pos[2]-pos[1]);
	//cout<<str;
	streampos so;
	so = fin.beg+pos[0];
	fin.seekg(so);
	getline(fin,str);
	cout<<str<<endl;
	fin.close();

	return 0;
}
