#!/usr/bin/python
# taxes.py
# calculates your taxes
# single with standard deduction

import sys, argparse
parser = argparse.ArgumentParser(description="calculate your taxes (single with standard deduction)")
parser.add_argument("-s", "--state", dest="state", type=str, default="",
    help="2-letter state code for tax purposes")
parser.add_argument("-c", "--city", dest="city", type=str, default="",
    help="city code for tax purposes")
parser.add_argument("-r", dest="retirement", type=float, default=0.0,
    help="401k contribution")
parser.add_argument("--no-fica", dest="fica", action="store_false", default=True, 
    help="exclude the fica taxes")
parser.add_argument("--old", dest="old", action="store_true", default=False, 
    help="use the old, obama federal tax rates")
parser.add_argument("income", metavar="INCOME", type=float,
    help="annual income before taxes")
args = parser.parse_args()

class Tax:
    def __init__(self, name, deduction, rates, brackets):
        self.name = name
        self.deduction = deduction
        self.rates = rates
        self.brackets = brackets
        self.value = -1

    def calc(self, income):
        i, tax = (0, 0)
        income = max(0, income - self.deduction)
        while income > self.brackets[i]:
            gap = min(income, self.brackets[i + 1]) - self.brackets[i]
            tax += self.rates[i] * gap
            i += 1
        return tax

# federal taxes
federal_tax = Tax(
    name = "federal",
    deduction = 12000,
    rates = [0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37],
    brackets = [0, 9525, 38700, 82500, 157500, 200000, 500000, float("inf")]
)
old_federal_tax = Tax(
    name = "old federal",
    deduction = 6350,
    rates = [0.10, 0.15, 0.25, 0.28, 0.33, 0.35, 0.396],
    brackets = [0, 9525, 38700, 93700, 195450, 424950, 426700, float("inf")]
)

# fica taxes
ss_tax = Tax(
    name = "social security",
    deduction = 0,
    rates = [0.062, 0],
    brackets = [0, 128400, float("inf")]
)
medicare_tax = Tax(
    name = "medicare",
    deduction = 0,
    rates = [0.0145],
    brackets = [0, float("inf")]
)

# state taxes
nys_tax = Tax(
    name = "new york state",
    deduction = 8000,
    rates = [0.0400, 0.0450, 0.0525, 0.0590, 0.0645, 0.0665, 0.0685, 0.0882],
    brackets = [0, 8400, 11600, 13750, 21150, 79600, 212500, 1062650, float("inf")]
)
cali_tax = Tax(
    name = "california state",
    deduction = 4236,
    rates = [0.010, 0.020, 0.040, 0.060, 0.080, 0.093, 0.103, 0.113, 0.123],
    brackets = [0, 7850, 18610, 29372, 40773, 51530, 263222, 315866, 526443, float("inf")]
)

state_taxes = {
    "ny" : nys_tax,
    "ca" : cali_tax,
}

# city taxes
nyc_tax = Tax(
    name = "new york city",
    deduction = 8000,
    rates = [0.02907, 0.03534, 0.03591, 0.03648, 0.03876],
    brackets = [0, 12000, 25000, 50000, 500000, float("inf")]
)

city_code = str.lower(args.city)
city_taxes = {
    "nyc" : nyc_tax,
}

# taxes applied
tax_list = []
taxable_income = args.income - args.retirement

# city gov
city_tax = None
city_code = str.lower(args.city)
if city_code in city_taxes.keys():
    city_tax = city_taxes[city_code]
    city_tax.value = city_tax.calc(taxable_income)
    tax_list.extend([city_tax])

# state gov 
state_tax = None
state_code = str.lower(args.state)
if state_code in state_taxes.keys():
    state_tax = state_taxes[state_code]
    state_tax.value = state_tax.calc(taxable_income)
    tax_list.extend([state_tax])

# take the state and local tax deduction
state_tax = state_tax.value if state_tax else 0
city_tax = city_tax.value if city_tax else 0
salt_deduction = state_tax + city_tax
standard_deduction = old_federal_tax.deduction
old_federal_tax.deduction = max(standard_deduction, salt_deduction)

# federal gov
if not args.old: # Trump Tax Rates
    federal_tax.value = federal_tax.calc(taxable_income)
    tax_list.extend([federal_tax])
else: # Obama Tax Rates
    old_federal_tax.value = old_federal_tax.calc(taxable_income)
    tax_list.extend([old_federal_tax])

if args.fica: # Social Security and Medicare
    ss_tax.value = ss_tax.calc(args.income)
    medicare_tax.value = medicare_tax.calc(args.income)
    tax_list.extend([ss_tax, medicare_tax])


for tax in tax_list:
    print("{0}: {1:.2f}".format(tax.name, tax.value))

# net income after taxes
total_taxes = sum(map(lambda tax: tax.value, tax_list))
net_income = taxable_income - total_taxes

# calc trump tax plan savings
savings = old_federal_tax.calc(taxable_income) - federal_tax.calc(taxable_income)

# tax report
print("") # break
print("income: {0:.2f}".format(args.income))
print("retirement: {0:.2f}".format(args.retirement))
print("total taxes: {0:.2f}".format(total_taxes))
print("trump plan savings: {0:.2f}".format(savings))
print("effective tax rate: {0:.2f}%".format(100 * total_taxes / args.income))
print("net income: {0:.2f}".format(net_income))
