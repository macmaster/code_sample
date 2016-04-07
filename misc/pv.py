import os
import optparse

def clear():
    """clears the system console
    on windows machines      """
    os.system("cls")

def pv(r, cf):
    """calculates the present value of a list of
    cash flows. Use an interest rate % for r and
    a list of cash flows for cf starting at t = 1"""
    
    if not isinstance(r, (int, long, float, complex)):
        print "use a number for r (interest rate)"
        return None
    
    if not isinstance(cf, list):
        print "use a list for cf (cash flows)"
        return None

    else: # perform present value calculation

        # calc interest rate and discount factor
        r /= 100.0
        v = 1 / (1 + r)

        # calc present value
        value = 0
        for i in range(len(cf)):
            value += cf[i] * (v ** (i+1))
        return value

def main():
    parser.add_option("-r")
    if (len(args) < 2):
        print "invalid number of arguments \n\
        python pv.py <interest rate> <"
        
if __name__ == "__main__":
    main()
        

