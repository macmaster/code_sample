# python file practice
# Ronny MacMaster


# 7.1 shout.py
# read through a file and
# print the contents of the file (line by line)all in upper case.
# Executing the program will look as follows: python shout.py
def upper_read():
    count = 0
    file_name = raw_input("Enter the file name: ")
    try:
        for line in open(file_name):
            count += 1
        return "There were %d subject lines in %s" % (count, file_name)
    except:
        if file_name.lower() == "easter egg":
            return "you have been punk'd!!"
        else:
            return "File cannot be opened: %s" % (file_name)

def main():
    print upper_read()

if __name__ == "__main__" : main()
    
