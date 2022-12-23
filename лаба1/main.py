import numpy as np
import operator
import re
pre_matrix1 = []
pre_matrix2 = []
data1 = []
data2 = []
data1 = np.genfromtxt('C:\\Users\\alena\\source\\repos\\пп1\\matrix1.txt',
                      delimiter=" ", dtype=int)
data2 = np.genfromtxt('C:\\Users\\alena\\source\\repos\\пп1\\matrix2.txt',
                      delimiter=" ", dtype=int)
size = 100
for elem in data1:
    pre_matrix1.append(elem)
for elem in data2:
    pre_matrix2.append(elem)
matrix1 = np.matrix(pre_matrix1, dtype=int)
matrix2 = np.matrix(pre_matrix2, dtype=int)
matrix_res_py = np.dot(matrix1, matrix2)
data_res = np.genfromtxt('C:\\Users\\alena\\source\\repos\\пп1\\matrix3.txt',
                      delimiter=" ", dtype=int)
pre_matrix_res_cpp = []
for elem in data_res:
    pre_matrix_res_cpp.append(elem)
matrix_res_cpp = np.matrix(pre_matrix_res_cpp, dtype=int)
if (np.array_equal(matrix_res_py, matrix_res_cpp)):
    print("Nice, equal")
else:
    print("Nope, you dump proger")
