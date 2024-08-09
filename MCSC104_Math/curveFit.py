import numpy as np
import matplotlib.pyplot as plt

def estimate_coef(x, y, M):
    n = np.size(x)
    Num = np.sum(y*(x**M))
    Den = np.sum(x**(2*M))
    A = Num/Den
    return A

def plot_regression(x, y, A, M):
    plt.scatter(x, y, color='m', marker='o', s=30)
    y_pred = A*(x**M)
    plt.plot(x, y_pred, color='g')
    plt.show()

def main():
    M=2
    x = np.array([0.2, 0.4, 0.6, 0.8, 1.0])
    y = np.array([0.196, 0.785, 1.7665, 3.1405, 4.9075])
    A = estimate_coef(x, y, M)
    print(f"Estimated coeff : {A}")
    plot_regression(x, y, A, M)

main()

