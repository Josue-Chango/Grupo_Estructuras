%Matrices y vectores 

%Con el ";" se guarda en memoria
A = [1,2,3;4,5,6;7,8,9];

%Sin el ";" solo imprime
B = [1,2,3;4,5,6;7,8,9]

%Matriz de ceros
Z = zeros(3,4)

%Matriz de unos
O = ones(2,5)

%Matriz identidad
I = eye(4)

%Matriz Randómica entre ceros y unos
R = rand(3,3)

%Matriz Random
N= randn(3,3)

L = randi (10,3,4)

%Vector Fila
V = 1:10

%Vector Columna consultaaaaaaa!!!!!!

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Matriz aleatoria del 1 al 6 de 2x3
M = reshape(1:6,2,3)

%mATRIZ DIAGONAL 
D = diag([1 2 3 4])

%Concatenar matrices

S = [1 2;3 4]
J = [5 6; 7 8]

W = [S J]
X = [S;J]

%Matriz que dan el mismo resultado sumando todos sus lados
C = magic(4)
disp(sum(C, 2)); %Me da la suma de todos los lados 

%Matriz de Hilbert 

H = hilb(3)

%Transforma la matriz en una triangular superior
triu(A)

%Transforma la matriz en una triangular inferior

tril(A)

%Encuentra los valores propios de un a matriz

eig(A)

%Para sacar el determinante
det(A)

