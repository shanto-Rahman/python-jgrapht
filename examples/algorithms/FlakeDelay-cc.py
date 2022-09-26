# -*- coding: utf-8 -*-

"""
Connected Components
====================

In this example we demostrate how to find connected components in undirected
graphs.
"""

# %%
# Start by importing the package.

import pytest
import jgrapht
import jgrapht.algorithms.connectivity as cc
import jgrapht.drawing.draw_matplotlib as drawing
import jgrapht.algorithms.cycles as cycles
import matplotlib.pyplot as plt
import sys
import csv

#from jgrapht import create_graph
#from jgrapht.utils import create_vertex_supplier, create_edge_supplier

#from jgrapht.io.importers import parse_csv, read_csv
#from jgrapht.io.exporters import write_csv, generate_csv




# %%
# We start by creating a graph with 4 connected components. 

g = jgrapht.create_graph(directed=False, allowing_multiple_edges=True,  allowing_self_loops=True,   any_hashable=True)
#g = jgrapht.create_graph(directed=False, allowing_multiple_edges=True,  allowing_self_loops=True,   any_hashable=True)
# 
'''input_string = """A1,A2
A2,A3
A3,A4
A4,A1
A7,A8
A9,A11
"""

print(g.vertices)
parse_csv(g, input_string)
print(set(g.vertices))
print(set(g.edges))'''

file_name_input = sys.argv[1]

nodeList = set()
edgeList = []
with open(file_name_input,'r') as rf:
    reader=csv.reader(rf, delimiter=',')
    for row in reader:
        #print(len(row))
        source=row[0];
        nodeList.add(source)

        for i in range(1,len(row)):
            #print(row[0], row[i])
            nodeList.add(row[i])
            edge= row[0]+","+row[i]
            #print (edge)
            edgeList.append(edge)

#print("node List=", nodeList)


print ("append done *********")
for i in nodeList:
    g.add_vertex(i)

for edge in edgeList:
    print(edge)
    nodes = edge.split(",")
    g.add_edge(nodes[0],nodes[1])

print(g)

# %%
# Then, we execute the connected components algorithm.

is_connected, connected_components_it = cc.is_connected(g)
connected_components = list(connected_components_it)

# %%
# The result is a tuple which contains whether the graph is connected and 
# an iterator over the connected components.
# 
print('is connected: {}'.format(is_connected))

for i, cc in enumerate(connected_components):
    print('Connected component {}: {}'.format(i, cc))


# %%
# Ploting the graph with a circular layout and separate color per connected
# component.
#positions = drawing.layout(g, name="circular", seed=17)
#print('**************', positions)
#vertex_labels = {v:str(v) for v in g.vertices}
#print('*************************',vertex_labels)
#colors = ['red', 'blue', 'green', 'yellow']
#for cc, color in zip(connected_components, colors):
#    drawing.draw_jgrapht_vertices(g, positions=positions, vertex_list=cc, vertex_color=color)

#drawing.draw_jgrapht_vertex_labels(g, positions=positions, labels=vertex_labels)
#drawing.draw_jgrapht_edges(g, positions=positions)

#plt.show()
