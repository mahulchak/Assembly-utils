#include<iostream>
#include<fstream>
#include<string>
#include"qmerge.h"
using namespace std;

	int main(int argc, char *argv[])
	{
			
		if(argc ==1)
		{cerr<<"Usage: "<<argv[0]<<" input.fasta output.fasta"<<endl;
		exit(EXIT_FAILURE);
		}	
		string str,str1;
		ifstream fin;
		fin.open(argv[1]);
		ofstream fout;
		fout.open(argv[2]);
		while(getline(fin,str))
		{
			if(str[0] == '>')
			{
				str1 = xtractcol(str,' ',1);
				fout<<str1<<endl;
			}
			else
			{
				fout<<str<<endl;
			}			
		}
		fin.close();
		fout.close();
	}

