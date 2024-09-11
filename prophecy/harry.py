from cs50 import sql
import csv

def create_houses(house,houses,head):

       count =0
       for h in houses:
           if h["house"] == house:
            count += 1
       if count ==0:
            houses.append({"house":house, "head":head})

def create_students(name,students):

             students.append({"student_name": name})


def relationships(relationship,name,house):
     relationship.append({"student_name": name, "house": house})


db= sql(sqlite:///roster.db)


students =[]
houses = []
relationship = []

with open("students.csv","r") as file :
    reader = csv.DictReader(file)


    for row in reader :
        house = row["house"]
        name = row["student_name"]
        head = row["head"]
        create_houses(house,houses,head)
        create_students(name,students)
        relationships(relationship,name,house)

for student in students:

     db.execute("INSERT INTO new_students(student_name) VALUE(?)",student["student_name"] )

for rel in relationship:

     db.execute("INSERT INTO relationship(student_id,house_id)  VALUE((SELECT id FROM students WHERE student_name =? ),(SELECT id FROM houses WHERE house= ?))",rel["student_name"],rel["house"])

for house in houses:

     db.execute("INSERT INTO houses(house,head)  VALUE(?,?)",house["house"],house["head"] )
