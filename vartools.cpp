#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
void findStr(string & str, char c, size_t & count, vector<size_t> & vpos);
vector<string> splitField(string & str,char c);//split the contents of a field that are delimited by a char.
bool comparElem(vector<string> & vs, char s);

int main()
{
	string str,strain,var,len;//strain holds strain names,var holds variant types, and len holds variant lengths
	ifstream fin;
	int count = 0;
	size_t spos = 0;
	vector<size_t> vpos;
	vector<string> vstr;

	fin.open("master_table_d10_doubleton.txt");
	while(getline(fin,str))
	{
		//cout<<str<<endl;
		findStr(str,'\t',spos,vpos);
		//cout<<vpos[4]<<"\t"<<vpos[7]<<"\t"<<vpos[12]<<endl;
		strain = str.substr(vpos[3]+1,vpos[4]-vpos[3]-1);
		var = str.substr(vpos[6]+1,vpos[7]-vpos[6]-1);
		len = str.substr(vpos[11]+1,vpos[12]-vpos[11]-1);
		//cout<<str.substr(vpos[3]+1,vpos[4]-vpos[3]-1)<<"\t"<<str.substr(vpos[6]+1,vpos[7]-vpos[6]-1)<<"\t"<<str.substr(vpos[11]+1,vpos[12]-vpos[11]-1)<<endl;
		//cout<<strain<<"\t"<<var<<"\t"<<len<<endl;
		vstr = splitField(strain,';');
		//cout<<"\t"<<comparElem(vstr,'c')<<"\t";
		vstr = splitField(var,';');
		cout<<"\t"<<comparElem(vstr,'c')<<"\t";
		splitField(len,';');
		vpos.clear();
		
	}
	fin.close();

	return 0;
}
////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////
vector<string> splitField(string & str, char c)
{
	size_t pos =1, pos1 =0;
	vector<string> vs;
	string tempstr;
	while(pos1 <str.size())
	{
		pos1 = str.find(c,pos);
		if(pos1 < str.size())
		{
			tempstr = str.substr(pos-1,pos1-pos+1);
			pos = pos1+1;
			cout<<tempstr<<"\t";
			vs.push_back(tempstr);
		}
		
	}
	tempstr = str.substr(pos);
	vs.push_back(tempstr);
	cout<<tempstr<<endl;
	
	return vs;
}
//////////////////////////////////////////////////////////////////////////
bool comparElem(vector<string> & vs, char s)
{
	bool diff = false;
	for(unsigned int i= 1; i<vs.size();i++)
	{
		if(s == 'c') //if s is char
		{
			if(vs[i] != vs[i-1])
			{
				diff = true;
				break;
			}
		}
		if(s == 'i')
		{
			if(stoi(vs[i],nullptr) != stoi(vs[i-1],nullptr))
			{
				diff = true;
				break;
			}
		}
	}
	return diff;
}	
	
