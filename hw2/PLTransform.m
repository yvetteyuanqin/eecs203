
r = linspace(0,255,256);

figure(1)

c = 255/(255^0.4)
s1 = c* r.^0.4;
plot(r,s1,'r')
hold on
c = 255/(255^2.5)
s2 = c* r.^2.5;
plot(r,s2,'g')
axis([0 255 0 255])
title('red curve: r = 0.4, green curve: r =2.5')
xlabel('Input:r')
ylabel('Output: S')

%% write into csv file
newdata = [r',s1',s2'];
csvwrite('original_0.4_2.5.csv',newdata)
