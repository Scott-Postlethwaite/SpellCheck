/*Name of Author: Scott Postlethwaite
Date of Last Modification: 24/02/2017

Purpose of Program: A spell check tool that reads from a user specified input file and
checks each word in the file against a seperate dictionary file.
If the word is not found in the dictionary file both the word and it's line number
will be printed to an output file.*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *documentname, *outputname;
int caseSensitive =0;
//this takes the command line arguements with -i.. being the input and -o.. being the output
void fileNames(int argc, char **numberOfArgs)
{	
	for(int i = 0; i < argc; i++)
	{
		//the text after -i is stored to be used later to open the text doccument
		if(strcmp(numberOfArgs[i], "-i") == 0)
		{
			documentname = numberOfArgs[i + 1];
		}
		//the text after -o will be stored to be written to as the output file
		else if(strcmp(numberOfArgs[i], "-o") == 0)
		{	
			outputname = numberOfArgs[i + 1];
		}
		else if(strcmp(numberOfArgs[i], "-c") == 0)
			caseSensitive = 1;
	}	
}

int main (int argc, char **argv)
{
	//the filenames are passed through to the main method
	fileNames(argc, argv);
	
	FILE *dictionary, *document, *output;
	
	//the dictionaryfile is opened to dictionary
	dictionary = fopen("dictionary.txt", "r");
	
	//the filename of the command line arguements are opened into document and output.
	document = fopen(documentname, "r");
	
	//the output file is set with the write permission
	output = fopen(outputname, "w");

	char data[45440];
	char word[45440];
	int linecounter = 1;
	
	//the first while loop takes the individual lines from the document
	while (fgets(data, 45440, document) != NULL)
    {	
		char delim[5] = {' ', '?', ',', '\n', '.'};
		
		char * filedata;
		//the line is split into seperate tokens eliminating the deliminary to be checked against the dictionary
		filedata = strtok (data, delim);
		//this runs for each word in the line
		while (filedata != NULL)
		{
		//the filedata is converted to lower case to allow checking with the dictionary
			int c = 0;
 
			if (caseSensitive == 0){
				while (filedata[c] != '\0') 
				{
					if (filedata[c] >= 'A' && filedata[c] <= 'Z') 
					{
						// + 32 changes the letter to lower case
						filedata[c] = filedata[c] + 32;
					}
					c++;
				}
			}
			//the flag is innitialised so that mispelt words can be outputed by the program
			int flag = 0;
		
			while (fgets(word, 45440, dictionary) != NULL)
			{
				flag = 0;
				
				if (caseSensitive == 0){
				//dictionary words are converted to lower case in order to spell check
				int d = 0;
	 
				while (word[d] != '\0') 
				{
					if (word[d] >= 'A' && word[d] <= 'Z') 
					{
						word[d] = word[d] + 32;
					}
					d++;
				}
				}
				//this removes the new line characters without the need for tokenisation
				char * pos;
				if ((pos=strchr(word, '\n')) != NULL)
					*pos = '\0';
				//the strings are compared and the result is stored in check
				int check = strcmp(word, filedata);
				//this confirms the word is spelt correct
				if (check == 0)
				{
					flag = 1;
					break;
				}
			}
					
			//this only prints if the word is mispelt
			if (flag == 0)
			{
				//this writes to the output file
				fprintf(output, "line number %d\n", linecounter);
				fprintf(output, "%s\n", filedata);
			}
			
			rewind(dictionary);
			filedata = strtok(NULL, delim);
		}
		linecounter++;
	}
	
	fclose(dictionary);
	fclose(document);
	fclose(output);
	return 0;
}