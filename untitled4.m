img_nbr = 1;

ldata = gTruth.LabelData.cup{img_nbr};
img = imread(gTruth.DataSource.Source{img_nbr});

cutted = img(ldata(2):ldata(2)+ldata(4), ldata(1):ldata(1)+ldata(3),:);

imshow(cutted);