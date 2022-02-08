class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg=false;
        if(num<0)
        {
            neg=true;
        }
        num=abs(num);
        vector<long long>count;
        long long m=num;
        while(m!=0){
            long long r=m%10;
            count.push_back(r);
            m/=10;
        }
        num=0;
        if(!neg)
        {
            sort(count.begin(), count.end());
            int c=0, flag=0;
            for(int i=0;i<count.size();i++)
            {
                if(count[i]==0)
                    c++;
                else if(count[i]>0 && flag==0)
                {
                    num=count[i]*pow(10,c);
                    flag=1;
                }
                else
                    num=num*10+count[i];
            }
        }
        else
        {
            sort(count.begin(), count.end(),greater<int>());
            for(int i=0;i<count.size();i++)
                num=num*10+count[i];
            num=-(num);
        }
        return num;        
    }
};
