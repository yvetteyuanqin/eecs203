clear all;
close all;
row=640;  col=480;
fin=fopen('triangle.raw','r');
I1=fread(fin,row*col,'uint8=>uint8'); 
I1=reshape(I1,row,col);
I1=I1';
figure
imshow(I1)

%%
%convolve a Laplacian filter
kernel = 1 * ones(3);
kernel(2,2) = -8;  % Now kernel = [-1,-1,-1; -1,8,-1; -1,-1,-1]
I2 = conv2(double(I1), kernel, 'same');%same uses

MIN=min(I2(:));
I2=I2-MIN;
MAX=max(I2(:));
I2=I2*(255.0/MAX);
I2forsharp=I2;
Ilap=I2/255.0;
%I2=imfilter(Ilap, kernel, 'conv');
figure
imshow(Ilap)
title("Laplacian");
%%
%cantrast
Isharp=double(I1)-Ilap;

MIN=min(Isharp(:))
Isharp=Isharp-MIN;
MAX=max(Isharp(:))
Isharp=Isharp*(255.0/MAX);
MIN=min(Isharp(:))
MAX=max(Isharp(:))
Isharp=Isharp/255.0;
% kernel2=zeros(3);
% kernel2(2,2)=1;
% kernelsharp=kernel2-kernel;
% Isharp = conv2(double(I1), kernelsharp, 'same');%same uses
% 
% MIN=min(Isharp(:));
% Isharp=Isharp-MIN;
% MAX=max(Isharp(:));
% Isharp=I2*(255.0/MAX);
% Isharp=uint8(Isharp);
% % Isharp=Isharp/255.0;
% 
% 
% Isharp=im2double(Isharp);
figure
imshow(Isharp)
title("Sharpened");
%%
%fourier
 figure
% Y = fft2(I1);
% imshow(abs(fftshift(Y)))
f = abs(fft2(I1));
shiftedf = fftshift(f);
imshow(log(1+abs(shiftedf)), []);

% F=fft2(I1);
% F2=fftshift(F);
% figure,imshow(log(1+abs(F2)),[]) 
