
row=640;  col=480;
fin=fopen('cat.raw','r');
I1=fread(fin,row*col,'uint8=>uint8'); 
I1=reshape(I1,row,col);
I1=I1';
figure
imshow(I1)

%histogram(I1);
%%
I2=medfilt2(I1);
figure
imshow(I2)
title("median");

%%
I3=imfilter(I1, ones(9)/81, 'symmetric');
figure
imshow(I3)
title("mean");
%%
subplot(1,3,1);
histogram(I1); 
title("orginal"); 
%%
subplot(1,3,2);
histogram(I2); 
title("median");
subplot(1,3,3);
histogram(I3);  
title("mean")