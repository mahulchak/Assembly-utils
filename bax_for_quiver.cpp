//Use this utility to create fofn files to run quiver

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

string filename(string str);

int main(int argc, char *argv[])
{

	if(argc ==1)
	{
		cerr<<"Usage: "<<argv[0]<<" bax_list.fofn output_path"<<endl;
		exit(EXIT_FAILURE);
	}
ifstream fin;
ofstream fout;

string str,str2;

fin.open(argv[1]);
int count = 0;
	while (!fin.eof())

	{
	count++;
	getline(fin,str);

	if(!str.empty())
	{

	str2 = filename(str);
	if (count %3 ==1)
	fout.open(str2.c_str());
	fout <<string(argv[2])<<str<<endl;
	if(count %3 == 0)
	fout.close();
}
cout << count<<endl;
}
fin.close();

return 0;
}


string filename(string str)

{ string name;
name = "abcde";

for (int i=0; i<5;i++)

{ name[i]=str[50+i];
}

name = name+".fofn";

return name;
}
