I = checkerboard(64,4,4);
K = (I > 0.5);
I2=K*1.0;


K=uint8(K*200);
figure
I2=im2double(K);
subplot(2,3,1);
imshow(I2)
subplot(2,3,2);
histogram(K);
title('Original histogram');
lap=[1 1 1;1 -8 1;1 1 1];
I3=conv2(K,lap);
subplot(2,3,3)
histogram(I3);
title('After filtering');
%%
aa=zeros(512,256);
bb=200*ones(512,256);
K2= [uint8(aa),uint8(bb)];
I4=im2double(K2);
subplot(2,3,4);
imshow(I4)

subplot(2,3,5);
histogram(K2);
lap=[1 1 1;1 -8 1;1 1 1];
I3=conv2(I4,lap);
subplot(2,3,6)
histogram(I3);