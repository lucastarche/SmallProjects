#Runs the simulation once, shows the plot, and saves it to res.txt. 
import matplotlib.pyplot as plt
from random import randint

# Constants
iterations = int(1e5)
steps = 100
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

amount = [0 for i in range(steps + 1)]

for i in range(iterations):
    x = y = 0
    for j in range(steps):
        val = randint(0, 3)
        x += dx[val]
        y += dy[val]
    dist = abs(x) + abs(y)
    amount[dist] += 1

with open("res.txt", "w") as f:
    f.writelines([(str(amount[i]) + "\n") for i in range(0, steps+1, 2)])

plt.plot([i for i in range(0, steps+1, 2)], [amount[i] for i in range(0, steps+1, 2)])
plt.show()