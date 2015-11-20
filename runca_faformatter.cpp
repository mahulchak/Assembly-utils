//This is an utility to remove newline characters present within a fasta sequence, as present in contigs fasta file created by celera aassembler.
//The utility can also introduce newline characters, essentially generating a fasta format that is present in CA generated contigs fasta file.
//Use join/split switch to join or split the fasta

	#include<iostream>
	#include<fstream>
	#include<string>
	#include<cstdlib>
	#include<cstring>
	using namespace std;
	
	void split_seq(ofstream & fout,string str,int n);
 
	int main(int argc, char *argv[])
	{
		if(argc ==1)
		{
		cerr<<"Usage: "<<argv[0]<<" join/split input.fasta output.fasta char_per_line"<<endl;
		exit(EXIT_FAILURE);
		}
	string str,str1;
	str1="";
	ifstream fin;
	ofstream fout;
	fin.open(argv[2]);
	fout.open(argv[3]);
	const int charN = stoi(string(argv[4]),nullptr);
	if(argv[1][0] == 'j')
	{
		while(getline(fin,str))  // this function removes newlines present within a fasta sequence
		{
			if(str[0] == '>')
			{
				if(!str1.empty())
				{fout<<str1<<endl; // when a fasta header is encountered, spit out the joined sequence. then spit out the fasta header:str.
			 //cout<<str1.size()<<endl;
				str1="";
				}
			fout<<str<<endl;
			}
			if(str[0] != '>') // when a fasta header is not in the input, keep joining the fasta lines
			{
			str1.append(str);
			}
		
		}
	}

	if(argv[1][0] == 's')
	{
		while(getline(fin,str))
		{
			if(str[0] == '>')
			{fout<<str<<endl;}
			if(str[0]!= '>')
			{split_seq(fout,str,charN);}
		}
	}
	fout<<str1<<endl;
	fin.close();
	fout.close();
	}
		
	void split_seq(ofstream & fout, string str,int n) // this function divides a fasta sequence into lines of 70 bases each
	{
	unsigned int i =0;
	unsigned int j;
		while (i<str.size())
		{fout<<str[i];
		 j = i+1;
		 if(j%n == 0) //earlier version had 70 in place of n
		 fout<<'\n';
		i++;
		}
	if(j%n != 0)
	fout<<endl;
	}
