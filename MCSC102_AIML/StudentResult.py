class Student:
    def __init__(self, name, roll, sem, course):
        self.name = name
        # self.age = age
        self.roll = roll
        self.sem = sem
        self.course = course
        self.marks = {}
        self.total = 0
        # self.average = 0
        self.percentage = 0
        self.n = 0
    def inputMarks(self):
        self.n = int(input("Enter Number of Subjects : "))
        for i in range(self.n):
            sub = input("Enter Subject Name : ")
            mrk = float(input(f"Enter marks for subject {sub} out of 100 : "))
            self.marks[sub] = mrk
    def calculateResult(self):
        # Iterate over the values
        for i in self.marks.values():
            self.total += i
        self.percentage  = self.total/(self.n)

    def displayResult(self):
        print(f"Student Name : {self.name} | Roll No: {self.roll} | Semester : {self.sem} | Course : {self.course}")
        print("RESULTS : ")
        for key, value in self.marks.items():
            print(f"{key} : {value}")
        print(f"Total : {self.total} | Percentage : {self.percentage}%")
        print()

def studInput():
    name = input("Student Name : ")
    roll = input("Enter Roll Number : ")
    sem = int(input("Enter Semester : "))
    course = input("Enter Course : ")
    student = Student(name, roll, sem, course)
    student.inputMarks()
    return student

def main():
    stList = []
    while True:
        print()
        print("Press 1 for Student Entry")
        print("Enter 2 to See Results")
        print("Enter 0 to exit")
        choice = int(input("Enter your choice : "))
        match choice :
            case 1:
                st = studInput()
                st.calculateResult()
                stList.append(st)
            case 2:
                print("All Students Results : -----")
                for i in stList:
                    i.displayResult()
            case 0:
                break
                exit(0)
            case _:
                print("Please Enter Valid Input ")

main()
