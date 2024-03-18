def circuit(n, r):
    if n == 1:
        return r
    else:
        return 1 / (1 / r + 1 / circuit(n - 1, r))

print(circuit(1, 2))
print(circuit(2, 2))
print(circuit(3, 2))
print(circuit(4, 2))
print(circuit(5, 2))
