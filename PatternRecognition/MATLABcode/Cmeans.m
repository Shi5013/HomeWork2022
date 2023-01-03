clear
clc
%载入数据，绘图。
load('x.mat');
load('male.mat');
load('female.mat');
figure;
plot(male(:,1),male(:,2),'color','b','LineStyle','none','Marker','o');
hold on;
plot(female(:,1),female(:,2),'color','r','LineStyle','none','Marker','o');
hold on;
xlabel('身高/cm');
ylabel('体重/kg');
k = 2;%类别数选择

%初始质心坐标选择
%C=1
%matric=[170,54];

%C = 2;
matric=[163,60;153,42];%01
%matric=[183,75;170,54];%02
%matric=[183,75;153,42];%03

%C = 3;
%matric=[183,75;170,54;153,42];

%C = 4;
%matric=[183,75;170,54;163,60;153,42];

%C = 5;
%matric=[183,75;170,54;163,60;153,42;172,60];

%真正的代码就这一句，如果不能用封装函数，需要重写。
[idx,cen,sumD,D] = kmeans(x,k,'Start',matric);

%silhouette(x,idx); %轮廓值/轮廓系数---衡量聚类分析好坏的一个指标

%把图像画出来
color=['r','g','b','c','m','y'];


figure,
for i=1:k
    plot(x(idx==i,1),x(idx==i,2),'color',color(i),'LineStyle','none','Marker','o')
    hold on
end
xlabel('身高/cm');
ylabel('体重/kg');
title('C-means'); 

% %计算J_e 1
% J_e = 0;
% for j=1:k
%     J_tmp = [x(idx == i,1)-cen(i,1) x(idx == i,2)-cen(i,2)];
%     J_e = J_e + sum(sum(J_tmp.^2));
% end

%计算J_e 2
J_e = norm(sumD);


%显示质心坐标
% plot(cen(:,1),cen(:,2),'Color','k','LineStyle','none','Marker','*')
% hold off
% grid on


%%绘制J_e与类别数关系图
% Je = [7.2171e+03,1.9466e+03,903.2275,562.9040,370.8981];
% c=[1,2,3,4,5];
% figure;
% plot(c,Je,'LineWidth',1.5);
% xlabel('类别数')
% ylabel('J_e')
% title('J_e与类别数关系图')
