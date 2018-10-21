figure;
img = imread('/home/whymatter/Pictures/2/Picture 2018-09-15 20-39-03.png');
img = imread('/home/whymatter/Pictures/6/0.png');
img = imread('/home/whymatter/img.png');


img = undistortImage(img, cameraParams2);
imshow(img)

[imagePoints,boardSize] = detectCheckerboardPoints(img);
worldPoints = generateCheckerboardPoints(boardSize,42);



[R,t] = extrinsics(imagePoints,worldPoints,cameraParams2);
imagePoints
worldPoints
R
t
newWorldPoints = cameraParams2.pointsToWorld(R,t,imagePoints);
subplot(2,1,1)
plot(worldPoints(:,1),worldPoints(:,2),'gx');
hold on
plot(newWorldPoints(:,1),newWorldPoints(:,2),'ro');
legend('Ground Truth','Estimates');
hold off
subplot(2,1,2)
plot(imagePoints(:,1), imagePoints(:,2), 'ro');