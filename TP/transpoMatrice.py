a = int(input('nbr de ligne de la matrice :'))
b=int(input('nbr de colonne de la matrice :'))

matrice = []
transpo =  []

print('matrice')
for i in range(a):
    ligneI=[]
    for j in range(b):
        ligneI.append(int(input("Entrer la valeur :")))
    matrice.append(ligneI)

for i in range(b):
    ligneI=[]
    for j in range(a):
        ligneI.append(matrice[j][i])
    transpo.append(ligneI)

print("Matrice=",matrice)
print("Transpo=",transpo)
