%plot three heaviest sample
for i=1:10
    edges=[0.5:1:trainsize+0.5];
    N=histcounts(index_lw(i,:),edges);
    [bb,ii]=sort(N);
    ii3=ii(trainsize-2:trainsize);
    figure
    
    for j=1:3
        subplot(1,3,j)
        imshow(reshape(train_images(ii3(j),:),28,28).')
        title([' digit',num2str(i),':',num2str(j),' hardest examples'])
    end
end
