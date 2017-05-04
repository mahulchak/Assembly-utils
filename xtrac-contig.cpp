#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<map>

using namespace std;



	int main(int argc, char *argv[] )
	{
		if(argc<2)
		{
		cerr<<"Usage: "<<argv[0]<<" list_of_contigs formatted_fasta"<<endl;
		exit(EXIT_FAILURE);
		}
		string sq_name,sq;
		map<string,string> seq2name;
		std::map<string,string>::iterator it;
		ifstream ctg_lst;
		ifstream asm_ctg;
		ofstream fout;
		ctg_lst.open(argv[1]);
		asm_ctg.open(argv[2]);
		fout.open("asm.new.fasta");
 		
			while(getline(asm_ctg,sq))
			{
				if(sq[0] == '>')
				{
					sq_name = sq;
				}	
				if(sq[0] != '>')
				{
					seq2name[sq_name].append(sq);
				}
			}
		
						
			while(getline(ctg_lst,sq_name))
			{
				it = seq2name.find(sq_name);
				if(it != seq2name.end())
				{
				fout<<it->first<<endl;
				fout<<it->second<<endl;
				}				
			}	
		ctg_lst.close();
		asm_ctg.close(); 
		fout.close();
	return 0;
	}



