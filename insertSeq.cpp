//the first length characters are output as trim01 and last (tot_len - len) characters are output as the original seq name

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;



int main(int argc, char*argv[])

{

	if(argc ==1)
	{
	cerr<<"Usage: "<<argv[0]<<" reference.fasta to_be_inserted.fasta start_cord end_cord?"<<endl;
	exit(EXIT_FAILURE);
	}

//const int length = stoi(string(argv[2]),nullptr);
const int start = strtod(argv[3],NULL) -1; //because sequence starts at 1 and not 0
const int end = strtod(argv[4],NULL) -1;

	string str,name,insertSeq,str_first,str_sec,newSeq,tempSeq;
	ifstream fin,fin1;
	fin.open(argv[1]);
	fin1.open(argv[2]);
	ofstream fout;
	fout.open("corrected.fasta");
	
	while(getline(fin1,str))
	{
		if(str[0] != '>')
		{
			insertSeq = str;
		}
	}
fin1.close();
cout<<"Length of the insert is "<<insertSeq.size()<<endl;
	while(getline(fin,str))
	{
		if(str[0] == '>')
		{
			name = str;
			
		}
		else
		{
			str_first = str.substr(0,start);
			str_sec = str.substr(end,(str.size()-end));
			tempSeq = str_first.append(insertSeq);
			newSeq = tempSeq.append(str_sec);
			fout<<name<<endl;
			fout<<newSeq<<endl;
		}
	}
fin.close();
fout.close();
cout<<"Your corrected sequence is "<<newSeq.size()<<" bp long"<<endl;
return 0;	
}

