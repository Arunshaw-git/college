import csv

people=[]
with open('large.csv') as file:
    reader = csv.DictReader(file)
    for p in reader:
        people.append(p)
str=[]
for peep in people[1]:
    if 
    str.append(peep)

print(str)

