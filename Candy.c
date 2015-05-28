int candy(int* ratings, int ratingsSize) {
    if (ratingsSize<=1)
        return ratingsSize;
    
    int candies[ratingsSize], pos, maxRating, l, r, max, sum=0;
    bool AnyMemberChanged;
    
    for (pos=0;pos<ratingsSize; pos++)
        candies[pos]=1;

    do{
        AnyMemberChanged=false;
        for (pos=0;pos<ratingsSize; pos++){
            l = (pos==0)             ? -1:pos-1;
            r = (pos==ratingsSize-1) ? -1:pos+1;
            
            if (l==-1)
                maxRating=r;
            else if (r==-1)
                maxRating=l;
            else if (ratings[r]>ratings[maxRating])
                maxRating = r;
            else
                maxRating = l;
            
            if (ratings[pos]>ratings[maxRating]){
                if (l==-1)
                    max=candies[r];
                else if (r==-1)
                    max=candies[l];
                else if (candies[r]>candies[l])
                    max=candies[r];
                else
                    max=candies[l];
                
                if (max >= candies[pos])
                {
                    candies[pos] = max + 1;
                    AnyMemberChanged=true;
                }
            }
        }
    } while(AnyMemberChanged);
    
    for (pos=0;pos<ratingsSize; pos++)
        sum+=candies[pos];
    return sum;
    
}