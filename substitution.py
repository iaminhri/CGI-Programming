# #!C:\Program Files\Python311\python
# import cgi
# import cgitb
# import csv

#Run the program: py substitution.py -e "Hello World" zyxwvutsrqponmlkjihgfedcba
#to Decrypt: py substitution.py -d "Hello World" zyxwvutsrqponmlkjihgfedcba

import sys

if( len(sys.argv) <= 3):
    print("Argument: substitution.py: argv: -e/-d | argv : String input | argv: Substitution Cipher Key")
    exit()

alphabet_sequence = "abcdefghijklmnopqrstuvwxyz"

if(len(sys.argv) == 4):
    if(sys.argv[1] == "-e"):
        key = sys.argv[3]
        text = sys.argv[2]
        subsituted_str = ""
        for char in text:
            if char.lower() in alphabet_sequence: #for every character in alphabet sequence
                subsituted_str += key[alphabet_sequence.find(char.lower())] #substitues from key value using the same index method.
            else:
                subsituted_str += char #else keeps the same character.

        print(subsituted_str)
    elif(sys.argv[1] == "-d"):
        alphabet_sequence = sys.argv[3] #inverted
        key = "abcdefghijklmnopqrstuvwxyz" #inverted
        text = sys.argv[2]
        subsituted_str = ""
        for char in text:
            if char.lower() in alphabet_sequence: #for every character in alphabet sequence which is inverted and uses key as input
                subsituted_str += key[alphabet_sequence.find(char.lower())]
            else:
                subsituted_str += char

        print(subsituted_str)
    else:
        print("Please correct argument: substitution.py -e/-d inputText CipherKey")
