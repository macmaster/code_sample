## pv.py
# Calculates the present value of a cash flow
# Author: Ronny Macmaster
# Date: 4/6/2016

import os
from optparse import OptionParser

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
    # parse command line args
    parser = OptionParser()
    parser.add_option("-r", "--rate", help="interest rate")
    parser.add_option("-c", "--cashflow", help="cash flow delited by ,")
    (options, args) = parser.parse_args()

    try: # convert interest rate
        rate = float(options.rate)
    except:
        print "please enter a valid % interest rate!"
        print "ex. -r 1"
        exit()
    try: #convert cashflow
        cashflow = map(float, options.cashflow.split(","))
    except:
        print "please enter a valid cashflow string of floats!"
        print "ex. -c 1,2,3,4,5"
        exit()

    print "present value: " + "%.2f" % pv(rate, cashflow)
    
    
if __name__ == "__main__":
    main()
        
