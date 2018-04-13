from optparse import OptionParser
parser = OptionParser("usage: pdfinfo.py [pdf_file]")
(options, args) = parser.parse_args()
if len(args) < 1: 
    print parser.usage
    exit(0)

from pyPdf import PdfFileReader
def printMeta(filename):
    pfile = PdfFileReader(file(filename, "rb"))
    dinfo = pfile.getDocumentInfo()
    print "[*] PDF MetaData For: ", filename
    for item in dinfo:
        print "[+] %s: %s" % (item, dinfo[item])

printMeta(args[0])
