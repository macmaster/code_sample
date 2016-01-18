# list.py
# Ronny MacMaster

# chop()
# strip the first and last values of a list
# modify the list
# return: None
def chop(my_list):
    del my_list[0]
    del my_list[-1]
    return None
    
# middle()
# strip the first and last values of a list
# do not modify the list
# return: list of all except the first and last elements
def middle(my_list):
    return my_list[1:-1]


def main():
    my_list = [1,"go","sell",42,3.14]
    print type(my_list), "my_list: ", my_list, "\n"
    
    print "middle(): ", middle(my_list)
    print "my_list after middle(): "
    print type(my_list), "my_list: ", my_list, "\n"

    print "chop(): ", chop(my_list)
    print "my_list after chop(): "
    print type(my_list), "my_list: ", my_list, "\n"
    

if __name__ == "__main__" : main()
    
