import xml.etree.ElementTree as et

data = '''
<person>
	<name>Ronny</name>
	<phone type="intl">
		+1 808 206 1614
	</phone>
	<email hide="yes"/>
</person>'''

tree = et.fromstring(data)
print "Name: ", tree.find("name").text
print "Attr: ", tree.find("email").get("hide")

