X = zeros(960*10, 1);
Y = zeros(960*10, 1);
inv_intr = inv(cameraParams.IntrinsicMatrix);

for x = 1:960
    for y = 1:10
        U = [undistortPoints([x-1, y-1], cameraParams),40];
        P = U/cameraParams.IntrinsicMatrix;
        X(x+(y-1)*960, 1) = P(1);
        Y(x+(y-1)*960, 1) = P(2);
    end
end

scatter(X, Y)