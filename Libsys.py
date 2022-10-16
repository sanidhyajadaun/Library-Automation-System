print(" ")
print("\n\t\t********Library Management System********")
print(" ")

book_info=['Data Structures','Operating Systems','Neural Networks','Compiler Design','Robotics Algo','Cloud Computing','Big Data','Cyber Security']
book_count=[2,2,2,2,2,2,2,2]

Check=1

while(Check==1):
	print("\nEnter your user Choice :- \n1. Librarian \n2. Teacher \n3. Student")
	x=int(input("Enter choice : "))
	if x==1:
		print("\nBooks Name \tBooks Count")
		for i in range(len(book_count)):
			print(book_info[i],"\t",book_count[i])

	elif x==2:
		print("\nHello Sir/Ma'am!!!!")
		print("Please enter your choice :- \n1. Book Issue \n2. Book Return")
		y=int(input("\nEnter choice : "))

		if(y==1):
			print("\nBooks Name")
			for i in range(len(book_info)):
				print(i+1,'.',book_info[i])
			print(" ")
			print("Choose the book you want to issue")
			z=int(input("Enter Book Number : "))
			print(book_info[z-1],"is being issued......")
			print(" ")
			print("Thank you, Visit Again!!!!!")
			book_count[z-1] = book_count[z-1]-1
			#print(book_count[z-1])
		
		elif y==2:
			print("\nBooks Name")
			for i in range(len(book_info)):
				print(i+1,'.',book_info[i])
			print(" ")
			print("Choose the book you want to return")
			z=int(input("Enter Book Number : "))
			print(book_info[z-1],"is being returned......")
			print(" ")
			print("Thank you, Visit Again!!!!!")
			book_count[z-1] = book_count[z-1]+1
			#print(book_count[z-1])

	elif x==3:
		print("\nHello Student!!!!")
		print("Please enter your choice :- \n1. Book Issue \n2. Book Return")
		g=int(input("\nEnter choice : "))

		if g==1:
			for i in range(len(book_info[0:5])):
				print(i+1,'.',book_info[i])
			print(" ")
			print("Choose the book you want to issue")
			z=int(input("Enter Book Number : "))
			print(book_info[z-1],"is being issued......")
			print(" ")
			print("Thank you, Visit Again!!!!!")
			book_count[z-1] = book_count[z-1]-1
			#print(book_count[z-1])

		elif g==2:
			for i in range(len(book_info[0:5])):
				print(i+1,'.',book_info[i])
			print(" ")
			print("Choose the book you want to return")
			z=int(input("Enter Book Number : "))
			print(book_info[z-1],"is being returned......")
			print(" ")
			print("Thank you, Visit Again!!!!!")
			book_count[z-1] = book_count[z-1]+1
			#print(book_count[z-1])

	print("\nDo you want to continue ?? \n1. Yes\n2. No")
	Check=int(input("\nEnter the choice : "))



