clc
clear all
A=[3 1 2 5 6;5 2 5 3 2;7 5 2 3 2;4 6 8 5 4]
ColumnSpaceOfA=colspace(sym(A))
RowSpaceOfA=colspace(sym(A'))
NullSpaceOfA=null(sym(A))
ColumnSpaceOfAT=colspace(sym(A'))
RowSpaceOfAT=colspace(sym(A))
NullSpaceOfAT=null(sym(A'))