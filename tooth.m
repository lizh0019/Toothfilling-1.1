for filenumber=1:6,
num=char(48+filenumber);
sfilename=strcat('d:\tooth\tooth',num,'.jpg');
I=imread(sfilename);
I=double(I);
I1=I(60:180,30:110,:);
I1=mean(mean(I1));
%white=reshape(I1,1,3);
white=[224,224,194];
for m=1:size(I,1),
   for n=1:size(I,2),
      s=0;
      for r=1:size(I,3),
         s=s+(I(m,n,r)-white(r))^2;
      end
      if s>20000,%threshold
         I(m,n,:)=[255,0,0];
      end
   end
end
dfilename=strcat('d:\tooth\tooth',num,'.bmp');
imwrite(I/255,dfilename);
end