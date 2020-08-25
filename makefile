all: compspell outputSentenceTestIgnoreCase outputSentenceTestCaseSensitive clean

compSpell:
	cl spell.c
	
outputSentenceTestIgnoreCase:
	cl spell.c
	spell -i sentences_test.txt -o output.txt
	
outputSentenceTestCaseSensitive:
	spell -i sentences_test.txt -o output.txt -c
	
clean:
	del*.obj
	del*.exe