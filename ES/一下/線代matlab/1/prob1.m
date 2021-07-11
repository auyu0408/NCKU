clc
clear all
A=[2 0 8;1 1 3;-1 4 7]
B=[1,3,4;2 1 3;2 4 1]
disp('AxB')
A*B
disp('A.*B')
A.*B
disp('A./B')
A./B
disp('tr(A+B)')
trace(A+B)

disp('tr(A)+tr(B)')
trace(A)+trace(B)
if trace(A+B)==trace(A)+trace(B)
    disp('so,tr(A*B)=tr(B*A)')
end

disp('tr(A*B)')
trace(A*B)
disp('tr(B*A)')
trace(B*A)
if trace(A*B)==trace(B*A)
    disp('so,tr(A*B)=tr(B*A)')
end