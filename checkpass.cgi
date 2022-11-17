#!/usr/bin/python
import cgi
import cgitb
import csv

cgitb.enable()

def decrypt_Func(pwd):
  alphabet_sequence = "ezsflrxjovgbikyqahwctmpdnu"
  key = "abcdefghijklmnopqrstuvwxyz"
  text = pwd
  subsituted_str = ""
  for char in text:
      if char.lower() in alphabet_sequence: #for every character in alphabet sequence which is inverted and uses key as input
          subsituted_str += key[alphabet_sequence.find(char.lower())]
      else:
          subsituted_str += char

  return subsituted_str


#instance of Field Storage
form = cgi.FieldStorage()

#get data from fields.
user = form.getvalue('username')
pwd = form.getvalue("pwd")

print("Content-Type: text/html\n")
print("<html>")
print("<head><title> Test </title> </head>")
print("<body> <h1>")

c = 0
with open("../A4/lcA2Wg/users_encrypt.csv", 'r') as csv_file:
  csvreader = csv.reader(csv_file)
  for line in csvreader:
    data1, data2 = line
    if(user == data1 and pwd == decrypt_Func(data2)):
      print("<h1>Your Password Matches</h1>")
      c = 1

if(c == 0):
  print("Wrong user or password")

print("</h1> </body>")
print("</html>")