# Assembly-utils
Some useful programs for genome assemblies with long molecules

These are some simple programs that can be handy in a genome assembly project (especially those with long molecules).
Each program code has a couple of lines in its header that describes what the program does. You'll need the gcc compiler (freely available for Unix systems)

These can be compiled simply by :

	$ g++ -Wall -std=c++0x bax_for_quiver.cpp -o bax4quiv
	$ g++ -Wall -std=c++0x convert_fasta_names.cpp -o convertFaNames
	$ g++ -Wall -std=c++0x fasplitter.cpp -o fasplitter
	$ g++ -Wall -std=c++0x report_stats.cpp -o report_read_stats
	$ g++ -Wall -std=c++0x runca_faformatter.cpp -o runcaFaFormatter
	$ g++ -Wall -std=c++0x xtrac-contig.cpp -o xtrac-contig


to know how to run each program, 

	$ ./foo 

(where foo is the specific program)

Notes:
-These are quick and dirty codes, so they are not optimized for time or memory.
-If you are looking for a simple utility that is not listed here, let me know. 
-If you have a comment/question, please email me.
