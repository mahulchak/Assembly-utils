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
	cerr<<"Usage: "<<argv[0]<<" seq_file.fasta start_cord end_cord concat(Y/N)?"<<endl;
	exit(EXIT_FAILURE);
	}

//const int length = stoi(string(argv[2]),nullptr);
const int start = strtod(argv[2],NULL) -1; //because sequence starts at 1 and not 0
const int end = strtod(argv[3],NULL) -1;

string str,name,new_str,trim_str,fname, tempName;
size_t found;

	ifstream fin;
	fin.open(argv[1]);
	fname = string(argv[1]);
	if(fname.find('.') != string::npos)
	{
		found = fname.find(".fa");
		fname = fname.substr(0,found); //strip the filename suffix from the file name
	}
	ofstream fout;
	//fout.open("trimmed.fasta");

	while(getline(fin,str))
	{
		if(str[0] == '>')
		{
			name = str;
			if(string(argv[4]) == "N")
			{
				tempName = fname + "_p1.fasta";
				fout.open(tempName.c_str());
				fout<<name<<"_part1"<<endl;
			}
		}
		else
		{
			if(start == 0)
			{
				new_str = "";
			}
			if(start != 0)
			{
				new_str = str.substr(0,start);
			}
			trim_str = str.substr(end,(str.size()-end));
			if(string(argv[4]) == "N")
			{
				fout<<new_str<<endl;
				fout.close();
				tempName = fname + "_p2.fasta";
				fout.open(tempName.c_str());
				fout<<name<<"_part2"<<endl;
				fout<<trim_str<<endl;
				fout.close();
			}
			if(string(argv[4]) == "Y")
			{
				new_str.append(trim_str);
				tempName = fname + "_p1.fasta";
				fout.open(tempName.c_str());
				fout<<name<<endl;
				fout<<new_str<<endl;
				fout.close();
			}
			tempName = fname + "_excised.fasta";
			fout.open(tempName.c_str());
			fout<<name<<"_excised"<<endl;
			if(start ==0)
			{
				fout<<str.substr(start,(end-start))<<endl;
			}
			if(start != 0)
			{
				fout<<str.substr(start-1,(end-start))<<endl;
			}
			fout.close();
		}
	}
fin.close();
fout.close();
return 0;	
}

