# geouniv.py
# uses the API at:
# http://python-data.dr-chuck.net/geojson
#
# obtains place_id for a user input university
# Author: Ronny Macmaster

import json
import urllib

serviceurl = "http://python-data.dr-chuck.net/geojson?"

# api request
try:
	# prompt university
	university = raw_input("Enter your university: ")
	url = serviceurl + urllib.urlencode({"sensor":"false", "address":university})
	print url # api request url
	jurl = urllib.urlopen(url)
	jdata = jurl.read()
	jdata = json.loads(jdata)
	# print json.dumps(jdata, indent=4)
except:
	print "Error, could not retrive url!"
finally:
	jurl.close()

# return place id
print "place_id: ", jdata["results"][0]["place_id"]
