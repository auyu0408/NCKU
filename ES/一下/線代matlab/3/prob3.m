clc
clear all
A=[0 1 1 1 1 1 1;1 0 1 0 0 0 1;1 1 0 1 0 0 0;1 0 1 0 1 0 0;1 0 0 1 0 1 0;1 0 0 0 1 0 1;1 1 0 0 0 1 0]
detA=det(A)
LessOrEqualTo5Ways=A+(A^2)+(A^3)+(A^4)+(A^5)
LessOrEqualTo5from1to7=LessOrEqualTo5Ways(1,7)
edges=trace(A^2)/2
triangles=trace(A^3)/6
