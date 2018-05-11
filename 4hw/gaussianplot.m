%%
%2.d
M=4.0;
N=4.0;
[X,Y] = meshgrid(0:0.1:8,0:0.1:8);
%F = 2-exp((2*pi/M).*X*j)-exp((2*pi/N).*Y*j);
F=sqrt((2-cos(2*pi/M*X)-cos(2*pi/N*Y)).^2+(sin(2*pi/M*X)+sin(2*pi/N*Y)).^2);
surf(X,Y,F)
title("PLOT OF |H(U,V)| with M==4")
%%
%3.B
figure;
M=4.0;
N=4.0;
[X,Y] = meshgrid(0:0.1:4,0:0.1:4);
%F=abs(2*(cos(2*pi/M*X)+cos(2*pi/N*Y)+cos(2*pi*(Y/N+X/M))+cos(2*pi*(-Y/N+X/M)))-8);
F=abs(2*cos(2*pi/M*X)+2*cos(2*pi/N*Y)-4);
surf(X,Y,F)
title("Laplacian with -4 in the middle")
