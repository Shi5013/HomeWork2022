clear;
load('x.mat');
k=3;%分类类别数
m=1.5;%m值的选择
[center,U,obj_fcn] = fcm(x,k,m);

maxU = max(U); 

%画图
color=['r','g','b','c','m','y']; 
figure;
for i=1:k
    plot(x(U(i,:) == maxU,1),x(U(i,:) == maxU,2),'marker','o','LineStyle','none','color',color(i));
    hold on;
end

plot(center(:,1),center(:,2),'Color','k','LineStyle','none','Marker','*')

%随迭代次数变化
figure
plot(obj_fcn)
title('Objective Function Values')   
xlabel('Iteration Count')

hold off;
grid on;
