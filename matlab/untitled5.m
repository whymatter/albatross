files = dir('/home/whymatter/Pictures/cup_images_handy/');

eod = size(files);
eod = eod(1);

num_images = eod - 2;
num_cols = floor(sqrt(num_images));
num_rows = ceil(num_images / num_cols);
num_last_col = mod(num_images, num_cols);

figure;

for i = 3:eod
    subplot(num_rows, num_cols, i - 2);
    img = imread(strcat(files(i).folder, '/', files(i).name));
    [BW,img]=createMask(img);
    imshow(img);
    %title(files(i).name);
end

