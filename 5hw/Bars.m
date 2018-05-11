clear all;close all;
%%
%create the bar image
graylevel1=240;
graylevel2=10;
bar=ones(210,7)*graylevel1;
inter=ones(210,17)*graylevel2;
topbott=ones(17,233);
barimg=repmat([bar,inter],1,9);
barimg=[inter,barimg];
barimg=[topbott;barimg;topbott];
% imshow(uint8(barimg));
%%
%apply filter
%3*3,7*7,9*9 arithmatic mean filter
figure(1);

%

subplot(2,2,1);

imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
h = 1/3*ones(3,1);
H = h*h';
Iamean = filter2(H,barimg);
imshow(uint8(Iamean));
title("3*3 filtered img");
%
subplot(2,2,3);
h = 1/7*ones(7,1);
H = h*h';
Iamean = filter2(H,barimg);
imshow(uint8(Iamean));
title("7*7 filtered img");
%
subplot(2,2,4);
h = 1/9*ones(9,1);
H = h*h';
Iamean = filter2(H,barimg);
imshow(uint8(Iamean));
title("9*9 filterd img");
%%
%3*3,7*7,9*9 geometric mean filter
figure(2);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
h=ones(3,3);
Igmean = imfilter(log(barimg), h, 'replicate');
Igmean = exp(Igmean);
Igmean = Igmean .^ (1/numel(h));
imshow(uint8(Igmean));
title("3*3 filtered img");
%
subplot(2,2,3);
h=ones(7,7);
Igmean = imfilter(log(barimg), h, 'replicate');
Igmean = exp(Igmean);
Igmean = Igmean .^ (1/numel(h));
imshow(uint8(Igmean));
title("7*7 filtered img");
%
subplot(2,2,4);
h=ones(9,9);
Igmean = imfilter(log(barimg), h, 'replicate');
Igmean = exp(Igmean);
Igmean = Igmean .^ (1/numel(h));
imshow(uint8(Igmean));
title("9*9 filterd img");

%%
%3*3,7*7,9*9 harmonic mean filter
figure(3);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
title("3*3 filtered img");
%
subplot(2,2,3);
title("7*7 filtered img");
%
subplot(2,2,4);
title("9*9 filterd img");

%%
%3*3,7*7,9*9 contrageometric mean filter G=1
figure(4);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
title("3*3 filtered img");
%
subplot(2,2,3);
title("7*7 filtered img");
%
subplot(2,2,4);
title("9*9 filterd img");

%%
%3*3,7*7,9*9 contrageometric mean filter G=-1
figure(5);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
title("3*3 filtered img");
%
subplot(2,2,3);
title("7*7 filtered img");
%
subplot(2,2,4);
title("9*9 filterd img");

%%
%3*3,7*7,9*9 median filter
figure(6);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
Imedian=medfilt2(barimg,[3 3]);
imshow(uint8(Imedian))
title("3*3 filtered img");
%
subplot(2,2,3);
Imedian=medfilt2(barimg,[7 7]);
imshow(uint8(Imedian))
title("7*7 filtered img");
%
subplot(2,2,4);
Imedian=medfilt2(barimg,[9 9]);
imshow(uint8(Imedian))
title("9*9 filterd img");

%%
%3*3,7*7,9*9 max filter
figure(7);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
title("3*3 filtered img");
%
subplot(2,2,3);
title("7*7 filtered img");
%
subplot(2,2,4);
title("9*9 filterd img");

%%
%3*3,7*7,9*9 min filter
figure(8);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
Imax = ordfilt2(barimg,9,ones(3,3));
imshow(uint8(Imax));
title("3*3 filtered img");
%
subplot(2,2,3);
Imax = ordfilt2(barimg,49,ones(7,7));
imshow(uint8(Imax));
title("7*7 filtered img");
%
subplot(2,2,4);
Imax = ordfilt2(barimg,81,ones(9,9));
imshow(uint8(Imax));
title("9*9 filterd img");

%%
%3*3,7*7,9*9 midpoint filter
figure(9);
%

subplot(2,2,1);
imshow(uint8(barimg));
title("original img");
%
subplot(2,2,2);
Imin = ordfilt2(barimg,1,ones(3,3));
imshow(uint8(Imin));
title("3*3 filtered img");
%
subplot(2,2,3);
Imin = ordfilt2(barimg,1,ones(7,7));
imshow(uint8(Imin));
title("7*7 filtered img");
%
subplot(2,2,4);
Imin = ordfilt2(barimg,1,ones(9,9));
imshow(uint8(Imin));
title("9*9 filterd img");


