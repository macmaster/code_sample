import sys
import json
import urllib

# read cmd line url arg
url = sys.argv[1] 
print "retriving", url

# open url
try:
	jurl = urllib.urlopen(url)
	data = jurl.read()
except:
	print "Error: could not open url!"
finally:
	jurl.close()

# open json
jdata = json.loads(data)
print json.dumps(jdata, indent=4)

# parse json for nums
nums = list()
for comment in jdata["comments"]:
	nums.append(int(comment["count"]))

print sum(nums)
