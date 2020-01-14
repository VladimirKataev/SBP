import os
import io
#print("Hello World\n")



try: #------------------------------Open Manifest File-----------------------
	manFile = open("manifest.txt",'r')
except IOError:
	print("Manifest file not found.\nCreate '''manifest.txt''' appropriately\n")
	quit()


#----------------------------------Var declaration--------------------------
headerBody = ""
headerName = ""
footerBody = ""

bodyNames = []
bodyFiles = []
bodies = []


#-------------------------Man file parsing, header/footer creation--------
for line in manFile:
	print(line)

	if(line.startswith("GlobalHeader=")): #Finding Header
		headerName = line[line.find('=')+2:len(line)-2]
		print(headerName + " set to header filename\n")
		try:
			headFile = open(headerName)
			headerBody = headFile.read() #Filling headerBody
			headFile.close()
		except:
			print(headerName + " doesn't exist.\n")

	elif(line.startswith("GlobalFooter=")):
		footerName = line[line.find('=')+2:len(line)-2]
		print(footerName + " set to footer filename\n")
		try:
			footerFile = open(footerName)
			footerBody = footerFile.read() #Filling footerBody
			footerFile.close()
		except:
			print(footerName + " doesn't exist.\n")
	else:
		bodyNames.append(line[0:line.find("=")])
		print("Added "+ line[0:line.find("=")] + " to bodyNames.\n")
		try:
			bodyFiles.append(open(line[line.find('=')+2:len(line)-2]))
			bodies.append(bodyFiles[-1].read())
			bodyFiles[-1].close()
		except:
			print("File didn't exist.\n")


a = 0
for page in bodies:
	#page = headerBody + page + footerBody
	fileOut = open(bodyNames[a]+".html", "w")
	fileOut.write(headerBody + page + footerBody)
	fileOut.close()
	a += 1
