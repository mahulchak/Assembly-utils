#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
void findStr(string & str, char c, size_t & count, vector<size_t> & vpos);
int main()
{
	string str,strain,var,len;//strain holds strain names,var holds variant types, and len holds variant lengths
	ifstream fin;
	int count = 0;
	size_t spos = 0;
	vector<size_t> vpos;
	fin.open("master_table_d10_doubleton.txt");
	while(getline(fin,str))
	{
		//cout<<str<<endl;
		findStr(str,'\t',spos,vpos);
		cout<<vpos[4]<<"\t"<<vpos[7]<<"\t"<<vpos[12]<<endl;
		strain = str.substr(vpos[3]+1,vpos[4]-vpos[3]-1);
		var = str.substr(vpos[6]+1,vpos[7]-vpos[6]-1);
		len = str.substr(vpos[11]+1,vpos[12]-vpos[11]-1);
		//cout<<str.substr(vpos[3]+1,vpos[4]-vpos[3]-1)<<"\t"<<str.substr(vpos[6]+1,vpos[7]-vpos[6]-1)<<"\t"<<str.substr(vpos[11]+1,vpos[12]-vpos[11]-1)<<endl;
		cout<<strain<<"\t"<<var<<"\t"<<len<<endl;
		vpos.clear();
		
	}
	fin.close();

	return 0;
}

void findStr(string & str, char c, size_t & count, vector<size_t> & vpos)
{
	size_t pos;
	pos = str.find(c,count+1);
	vpos.push_back(pos);
	if(pos < str.size())
	{
		//cout<<pos<<'\t';
		findStr(str,c,pos,vpos);
	}
}
