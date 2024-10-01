l = int (input("Enter length : "))
b = int (input("Enter breadth : "))
peri = 0
area = 1
diag = 0
choise = int(input("Choose 1 for Perimeter , 2 for Area , 3 for Diagonal "))

if (choise == 1):
  peri = peri + 2*(l+b)
  print (" Perimeter = ",peri)
elif (choise == 2):
  area = area*l*b
  print(" Area = ",area)
elif (choise == 3):
  diag =l*l + b*b
  print ("Diagonal = ",diag)
else:
  print("Choise not found !")