#Shows the file created by walk.cpp and/or walk.py. Prevents from rerunning the simulation each time.
import matplotlib.pyplot as plt

with open("res.txt") as f:
    i = 0
    x_list = []
    y_list = []
    for line in f:
        x_list.append(i)
        y_list.append(int(line))
        i += 2

    plt.plot(x_list, y_list)


plt.show()