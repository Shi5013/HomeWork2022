%参考代码：
%https://ww2.mathworks.cn/help/stats/cluster.html
% 载入数据
clear;
clc;
load('x.mat');
k = 2; 
% 计算前边点与后边点距离
disVector = pdist(x);  % pdist之后的Y是一个行向量，15个元素分别代表X点之间的距离
 
% 转换成方阵
disMatrix = squareform(disVector);
 
% 确定层次聚类树 
treeCluster = linkage(disMatrix);
 
% 可视化聚类树
dendrogram(treeCluster);
 
% 聚类下标
idx = cluster(treeCluster,'maxclust',k); 
 
% 画图
color=['r','g','b','c','m','y'];
figure,
for i=1:k
    plot(x(idx==i,1),x(idx==i,2),'color',color(i),'LineStyle','none','Marker','o')
    hold on
end
title('Hierarchical'); 