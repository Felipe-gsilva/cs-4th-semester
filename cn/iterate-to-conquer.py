import numpy as np
import matplotlib.pyplot as plt
import sympy as sp  


# @title **Método da Bisseção**
f = lambda x: x + 2
a = 20
b = -20
p = 1e-10

def bissecao(f, a, b, p):
    if f(a) * f(b) >= 0:
        print("O intervalo falha no Teorema A.")
        return None

    while abs((b - a) / 2.0) > p:
        c = (a + b) / 2.0
        
        if f(c) == 0:
            return c
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2.0

solucao = bissecao(f, a, b, p)
if solucao is not None:
    print(f"Solução aproximada: {solucao}")


# Atividade 2
# a)
p = 1e-4
a = 0
b = 1

fig, ax = plt.subplots(figsize=(10, 10))

ax.spines['bottom'].set_position('zero')
ax.spines['left'].set_position('zero')

ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)

arrow_fmt = dict(markersize=4, color='black', clip_on=False)
ax.plot((1), (0), marker='>', transform=ax.get_yaxis_transform(), **arrow_fmt)
ax.plot((0), (1), marker='^', transform=ax.get_xaxis_transform(), **arrow_fmt)

x= np.linspace(-5,3,100)  
y = np.exp(x) - 5*x + 2
plt.plot(x,y, color = "red", linestyle = "-", linewidth = "2")  

plt.show()   #exibição do gráfico

f = lambda x: np.exp(x) - 5*x + 2

solucao = bissecao(f, a, b, p)
if solucao is not None:
    print(f"Solução aproximada: {solucao}")

# b)
fig, ax = plt.subplots(figsize=(10, 10))

ax.spines['bottom'].set_position('zero')
ax.spines['left'].set_position('zero')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
arrow_fmt = dict(markersize=4, color='black', clip_on=False)
ax.plot((1), (0), marker='>', transform=ax.get_yaxis_transform(), **arrow_fmt)
ax.plot((0), (1), marker='^', transform=ax.get_xaxis_transform(), **arrow_fmt)

x= np.linspace(0,5,100)  #definindo o intervalo de plotagem do gŕafico
y = (2**(x-2)) - (3**(3-x))
plt.plot(x,y, color = "red", linestyle = "-", linewidth = "2")  #plotagem do gráfico

plt.show()  

f = lambda x: (2**(x-2)) - (3**(3-x))
p = 1e-2
a = 2
b = 3

solucao = bissecao(f, a, b, p)
if solucao is not None:
    print(f"Solução aproximada: {solucao}")


# @title **Método de Newton-Raphson**
x = sp.symbols('x')

f_ = x
df_ = sp.diff(f_expr, x) 

f = sp.lambdify(x, f_, 'numpy')
df = sp.lambdify(x, df_, 'numpy')

p = 1e-5
x0 = 2

def newtonraphson(f, df, x, p):
    y = x - f(x) / df(x)
    if abs(y - x) < p:
        return y
    return newtonraphson(f, df, y, p)


solucao = newtonraphson(f, df, x0, p)
print(f"Solução aproximada: {solucao}")



# Atividade 4
# a)

fig, ax = plt.subplots(figsize=(10, 10))

ax.spines['bottom'].set_position('zero')
ax.spines['left'].set_position('zero')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
arrow_fmt = dict(markersize=4, color='black', clip_on=False)
ax.plot((1), (0), marker='>', transform=ax.get_yaxis_transform(), **arrow_fmt)
ax.plot((0), (1), marker='^', transform=ax.get_xaxis_transform(), **arrow_fmt)

x= np.linspace(0,5,100)  
y = (2**(x-2)) - (3**(3-x))
plt.plot(x,y, color = "red", linestyle = "-", linewidth = "2") 

plt.show()   #exibição do gráfico

f_ = np.exp(-x**2)*np.sin(x) - 2 + x**2
df_ = sp.diff(f_, x) 

f = sp.lambdify(x, f_, 'numpy')
df = sp.lambdify(x, df_, 'numpy')
p = 1e-8

solucao = newtonraphson(f_, df_, 2 ,p)
print(f"Solução aproximada: {solucao}")


# b)
x = sp.symbols('x')

f_ = x*sp.ln(2 - x) + x**2 - 3
df_ = sp.diff(f_, x)

f = sp.lambdify(x, f_, 'numpy')
df = sp.lambdify(x, df_, 'numpy')

fig, ax = plt.subplots(figsize=(10, 10))
ax.spines['bottom'].set_position('zero')
ax.spines['left'].set_position('zero')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)

arrow_fmt = dict(markersize=4, color='black', clip_on=False)
ax.plot((1), (0), marker='>', transform=ax.get_yaxis_transform(), **arrow_fmt)
ax.plot((0), (1), marker='^', transform=ax.get_xaxis_transform(), **arrow_fmt)

x_vals = np.linspace(-5, 5, 100)
y_vals = f(x_vals)
plt.plot(x_vals, y_vals, color="red", linestyle="-", linewidth=2)

plt.show()

x0 = -2
p = 1e-7

solution = newtonraphson(f, df, x0, p)
print(f"Solução aproximada: {solution}")


# Atividade 5
n = A.shape[0]
L = np.eye(n)
U = np.zeros((n, n))

def fatoracaoLU(A):
    n = A.shape[0]
    L = np.eye(n)
    U = np.zeros((n, n))

    for i in range(n):
        # Preenche a matriz U
        for k in range(i, n):
            U[i, k] = A[i, k] - np.sum(L[i, :i] * U[:i, k])

        # Preenche a matriz L
        for k in range(i+1, n):
            if U[i, i] == 0:
                raise ValueError("Fatoração LU não é possível sem pivoteamento, pois U[i, i] é zero.")
            L[k, i] = (A[k, i] - np.sum(L[k, :i] * U[:i, i])) / U[i, i]
    
    return L, U
        
A = np.array([[2, -1, -2],
              [-4, 6, 3],
              [-4, -2, 8]], dtype=float)

L, U = fatoracaoLU(A) 
print(f"L = {L}", "\n\n", f"U = {U}")

A = np.array([[-2, 5, 2, 1],
              [1, 1, 1, -3],
              [9, 6, -2, 4],
              [-2, 1, 0, 7]], dtype=float)

L, U = fatoracaoLU(A) 
print(f"L = {L}", "\n\n", f"U = {U}")
