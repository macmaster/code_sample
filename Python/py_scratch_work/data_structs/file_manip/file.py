# python file practice
# Ronny MacMaster


# 7.1 shout.py
# read through a file and
# print the contents of the file (line by line)all in upper case.
# Executing the program will look as follows: python shout.py
def upper_read():
    for line in open("text.txt"):
        print "%s \t Length = %d" %(line.upper().rstrip(), len(line))

def main():
    upper_read()

if __name__ == "__main__" : main()
    
