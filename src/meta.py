#! /bin/py

from random import *
from math import exp
import numpy as np
import matplotlib.pyplot as plt
import pygraphviz as pgv


temperature = 6000000
min_temperature = 0.01

height = 5
width = 5

nb_mouv = 0
nb_mouv_max = height * width * 1000

nb_iteration = 0

cost = 5


objectif = (height - 1) * width  * 2 * cost #200

composant = [[1, 3, 5, 7, 9],
             [2, 4, 6, 8, 10],
             [11, 13, 15, 17, 19],
             [12, 14, 16, 18, 20],
             [21, 22, 23, 24, 25]]


neighbours =[     [2,  6], [ 1,  3,  7,  0],     [ 2,  4,  8],     [ 3,  5,  9],     [ 4, 10],
             [1,   7, 11], [ 2,  6,  8, 12], [ 3,  7,  9, 13], [ 4,  8, 10, 14], [ 5,  9, 15],
             [6,  12, 16], [ 7, 11, 13, 17], [ 8, 12, 14, 18], [ 9, 13, 15, 19], [10, 14, 20],
             [11, 17, 21], [12, 16, 18, 22], [13, 17, 19, 23], [14, 18, 20, 24], [15, 19, 25],
                 [16, 22],     [17, 21, 23],     [18, 22, 24],     [19, 23, 25],     [20, 24]]




def find_abs_neigh(neigh):
    list_abs = []
    for elt in neigh:
        for i in range(5):
            for j in range(5):
                if elt == composant[i][j]:
                    list_abs.append(i)
    return list_abs


def find_ord_neigh(neigh):
    list_ord = []
    for elt in neigh:
        for i in range(5):
            for j in range(5):
                if elt == composant[i][j]:
                    list_ord.append(j)
    return list_ord

def display():
    for i in range(5):
        for j in range(5):
            plt.plot([find_abs_neigh(neighbours[composant[i][j] -1])], [find_ord_neigh(neighbours[composant[i][j] -1])], 'o')
    plt.show()



def find_neighbours_dist(comp, x, y):
    dist = 0
    for i in range(0, width):
        for j in range (0, height):
            if (composant[i][j] in neighbours[comp - 1]):
                dist += (abs(x - i) + abs(y - j)) * cost

    return dist

def save_graph(file_name):
    file = open(file_name , "w")
    file.write("graph metaheuristique {\n")

    for i in range(5):
        for j in range(5):
            file.write("\t")
            file.write(str(composant[i][j]))
            file.write(' [\n\t\tlabel="')
            file.write(str(composant[i][j]))
            file.write('"\n')
            file.write('\t\tpos="')
            file.write(str((i + 1) * 60))
            file.write(",")
            file.write(str((j + 1) * 60))
            file.write('"\n\t]\n')

            if (composant[i][j] % 5):
                file.write("\t")
                file.write(str(composant[i][j]))
                file.write(" -- ")
                file.write(str(composant[i][j] + 1))
                file.write(";\n")
            if (composant[i][j] < 21):
                file.write("\t")
                file.write(str(composant[i][j]))
                file.write(" -- ")
                file.write(str(composant[i][j] + 5))
                file.write(";\n")

    file.write("}")



def compute_distance():
    total = 0
    for i in range(0, width):
        for j in range (0, height):
            total += find_neighbours_dist(composant[i][j], i, j)
    return total / 2


def swap(x1, y1, x2, y2):
    tmp = composant[x1][y1]
    composant[x1][y1] = composant[x2][y2]
    composant[x2][y2] = tmp


def recuit(temperature, nb_mouv, nb_iteration):
    non_changement = 0
    while (temperature > min_temperature and nb_mouv < nb_mouv_max):
        tmp_dist = compute_distance()
        print(temperature)
        print(tmp_dist)
        randx1 = randint(0, 4)
        randy1 = randint(0, 4)

        randx2 = randint(0, 4)
        randy2 = randint(0, 4)

        if (randx1 != randx2 or randy1 != randy2):
            swap(randx1, randy1, randx2, randy2)
            new_dist = compute_distance()
            if (new_dist <= tmp_dist or random() < exp((tmp_dist - new_dist) / temperature)):
                nb_mouv += 1
                nb_iteration += 1
                non_changement = 0
            else:
                swap(randx2, randy2, randx1, randy1)
                nb_iteration += 1
                non_changement += 1

            if (new_dist == 200):
               break

            if (nb_mouv % 12 == 0 or nb_iteration % 100 == 0):
                temperature *= 0.99

    print("nb mouvement : ",nb_mouv)
    print("nb mouvement max : ", nb_mouv_max)
    print("non changement : ", non_changement)
    print("temperature finale : ", temperature)
    print("distance finale : ", compute_distance())


save_graph("in.dot")
recuit(temperature, nb_mouv, nb_iteration)
#display()
#plt.show()
save_graph("out.dot")


"""
nb mouvement :  13850
nb mouvement max :  25000
non changement :  400
temperature finale :  1.2974582767527778
distance finale :  200.0
"""
