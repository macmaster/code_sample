from optparse import OptionParser
parser = OptionParser("usage: %prog -i <ip_file> -H <hosts>")
parser.add_option("-i", "--ips", dest="ips", help="ip file")
parser.add_option("-H", "--hosts", dest="hosts", help="hosts file")
(options, args) = parser.parse_args()

import socket
from contextlib import nested
with open(options.ips) as ips:
    with open(options.hosts, "w") as hosts:
        hosts.write("host, ip\n")
        for hacker in ips:
            try:
                host = socket.gethostbyaddr(hacker.strip("\n"))
                print host
                print "{0}, {1}".format(host[0], host[2])
                hosts.write("{0}, {1}\n".format(host[0], host[2]))
            except Exception, e:
                print e

