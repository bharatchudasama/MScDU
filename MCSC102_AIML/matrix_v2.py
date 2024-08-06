import numpy as np

def main():
    while True:
        print()
        print("Enter 0 to Exit Program")
        print("Press 1 for Addition")
        print("Press 2 for Multiplication")
        print("Press 3 for Transpose")
        print("Press 4 for Rank of a Matrix")
        
        choice = int(input("Enter Your Choice : "))
        match choice:
            case 0 :
                print("Thanks For Using My Program ")
                print("\t\t\t--- Jishnu")
                exit(0)
            case 1 :
                a = int(input("Enter Number of Rows : "))
                b = int(input("Enter Number of Columns : "))
                
                # Matrix Input
                print("Enter The First Matrix : ", end='')
                mat1 = inputMatrix(a, b)
                print("Enter The Second Matrix : ", end='')
                mat2 = inputMatrix(a, b)
                ans = matrixAdd(mat1, mat2, a, b)
                print("Resultant Matrix : ")
                print(ans)
            case 2 :
                a = int(input("Number of Rows in First Matrix : "))
                b = int(input("Enter Column Count of First and Row Count of Second Matrix :"))
                c = int(input("Number of Columns in Second Matrix : "))
                # Matrix Input
                print("Enter The First Matrix : ", end='')
                mat1 = inputMatrix(a, b)
                print("Enter The Second Matrix : ", end='')
                mat2 = inputMatrix(b, c)
                ans = matrixMult(mat1, mat2, a, b, c)
                print("Resultant Matrix : ")
                print(ans)
            case 3 :
                a = int(input("Enter Number of Rows : "))
                b = int(input("Enter Number of Columns : "))
                mat = inputMatrix(a, b)
                ans = matrixTranspose(mat, a, b)
                print("Resultant Matrix : ")
                print(ans)
            case 4 :
                print("This Function is Currently Under Maintainance :(")
                # exit(0)
            case _:
                print("Enter a Valid Choice Please :)")
                # exit(0)
    
def inputMatrix(a, b):
    print("REQUIRED Row :", a, "Column :", b)
    mat = np.zeros((a, b))
    for i in range(a):
        # s = input().split(' ')
        # print(s) FOR DEBUG
        for j in range(b):
            mat[i][j] = int(input(f"Enter Element of Row {i+1} and Column {j+1} : "))
    return mat
    
def matrixAdd(mat1, mat2, a, b):
    ans = np.zeros((a, b))
    for i in range(a):
        for j in range(b):
            ans[i][j] = mat1[i][j] + mat2[i][j]
    return ans

def matrixMult(mat1, mat2, a, b, c):
    ans = np.zeros((a, c))
    for i in range(a):
        for j in range(c):
            sum = 0
            for k in range(b):
                sum += mat1[i][k] * mat2[k][j]
            ans[i][j] = sum
            
    return ans

def matrixTranspose(mat, a, b):
    ans = np.zeros((b, a))
    # return 0
    for i in range(b):
        for j in range(a):
            ans[i][j] = mat[j][i]
    return ans

# x = y = np.ones((3, 4))
# z = matrixAdd(x, y, 3, 4)
# print(z)
# print(inputMatrix(2, 3))
main()


