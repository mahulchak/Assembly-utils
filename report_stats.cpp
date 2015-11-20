//can be used to calculate read stats from any fastq file. especially useful for PacBio type datasets

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

	int get_NX(vector<int> qual, float x, long int gSize);


	int main(int argc, char * argv[])
	{
		if(argc == 1) 
		{cerr<<"Usage: "<<argv[0]<<" read file"<<endl;
		}
	string str;
	ifstream fin;
	fstream fout;
	vector<int> qual;
	long int gSize = 0;
	int count = 0;
	fin.open(argv[1]);
	
		while(getline(fin,str))
		{
		count++;
			if(count%4 == 0)	
			{
			
			qual.push_back(str.size());
			gSize = gSize + str.size();
			
			}
		
		}
	
	cout<<"There are "<<qual.size()<<" sequences"<<endl;
	cout<<"Total no. of bases "<<gSize<<endl;

	sort(qual.begin(),qual.end());
		if(argv[2])
		{
		gSize = atoi(argv[2]);
		gSize = gSize *100;
		cout<<gSize<<endl;
		cout<<"NG40 is "<<get_NX(qual,0.4,gSize)<<endl;
		cout<<"NG25 is "<<get_NX(qual,0.25,gSize)<<endl;
		}
		else
		{
		cout<<"Longest sequence is "<<qual[qual.size()-1]<<endl;	
		cout<<"N50 is "<<get_NX(qual,0.5,gSize)<<endl;
		cout<<"N40 is "<<get_NX(qual,0.4,gSize)<<endl;
		cout<<"N25 is "<<get_NX(qual,0.25,gSize)<<endl;
		}
	fin.close();
	fout.close();
	}



	int get_NX(vector<int> qual,float x, long int gSize)
	{
	
	long int t_gSize = gSize * x; // t_gSize is x fraction of the genomesize
	long int t_size = 0;               // t_size is for storing incrementing genomesize with addition of more and more sequences
	int nx = 0;
	int tot_seq = qual.size() -1;
		while(tot_seq>0)
		{
		t_size = t_size + qual[tot_seq];
			if(t_size > t_gSize || t_size == t_gSize )
			{nx = qual[tot_seq];
			break;
			}
		tot_seq = tot_seq-1;
		}
	return nx;
	}
	 
 

