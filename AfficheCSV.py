#! /bin/python3
import csv
import matplotlib.pyplot as plt
import numpy as np
import sys

print("Lecture de ", sys.argv[1]);
csvReader = csv.reader(open(sys.argv[1]), delimiter=';')
dataArray = np.zeros([2900, 4144], int)
for i, rowText in enumerate(csvReader) :
    dataArray[i, :] = np.array([int(x) for x in rowText[:-1]])

print("Affichage");
fig = plt.figure()
fig.add_axes()
ax = plt.gca()
ax.imshow(dataArray)
plt.show()
