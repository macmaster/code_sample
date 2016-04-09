# comm_grade.py
# calculates your grade in fagelson's EE 333T class
# adjust using source code
#
# Author: Ronny Macmaster
# Date: 4/8/16

class Assignment:
    """ Assignment Type for my 333T assignments. """
    def __init__(self, name="", grade=0, weight=0):
        """ Create a new assignment object.
        :param string name: name of the assignment
        :param float grade: grade percentage on assignment ex. 95 for 95%
        :param float weight: weight of assignment on total grade ex 5 for 5%
        :return nothing"""
        self.name = str(name)
        self.grade = float(grade)
        self.weight = float(weight)

def main():
    assignments = list()
    
    # team / individual assignments
    assignments.append(Assignment("job packet", 100, 10))
    assignments.append(Assignment("proposal memo", 0, 7))
    assignments.append(Assignment("proposal presentation", 0, 5))
    assignments.append(Assignment("networking presentation", 0, 5))
    assignments.append(Assignment("ethics memo", 0, 10))
    assignments.append(Assignment("research memo", 0, 5))
    assignments.append(Assignment("team plan", 0, 8))
    assignments.append(Assignment("design review presentation", 0, 10))
    assignments.append(Assignment("problem statement", 0, 20))
    
    # participation
    assignments.append(Assignment("participation 1", 0, 8))
    assignments.append(Assignment("participation 2", 0, 12))

    grade = 0
    weight = 0
    for a in assignments:
        grade  += a.grade
        weight += a.weigt

    try:
        grade = ((grade/float(weight)) * 100)
        print "your grade is %.2f" % grade
    except:
        print "no grade in the class yet"
        
if __name__ == "__main__":
    main()

        
