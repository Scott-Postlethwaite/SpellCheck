To build the spell application simply navigate to the folder containing the code using the developer command prompt for vs2015 and input:
cl spell.c
Alternatively, there is an included makefile that allows you to compile and run the code by using the nmake command.
the commands are as followed:
nmake compspell (to compile the code)
nmake outputSentenceTestIgnoreCase (to run the program using the sentence_test.txt file outputting to output.txt this ignores case)
nmake outputSentenceTestCaseSensitive (to run the program using the sentence_test.txt file outputting to output.txt while checking for case)

To use the spell application you must input:
'spell' followed by '-i', the name of the input file to read, '-o' and the name of the file you want to write to.
There is also an option to make the spell check case sensitive. to do this you need to add '-c' at the end of the command line arguements.
For example: spell -i sentences_test.txt -o outputfile.txt
Or use the nmake commands as mentioned earlier.