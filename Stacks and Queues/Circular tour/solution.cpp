/*This is a function problem.You only need to complete the function given below*/
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   int start=0,end=1;
   int curr=p[0].petrol-p[0].distance;
   while(start!=end || curr<0)
   {
       while(curr<0 && start!=end)
       {
           curr=curr+p[start].distance-p[start].petrol;
           start=(start+1)%n;
           if(start==0)
            return -1;
       }
       curr+=(p[end].petrol-p[end].distance);
       end=(end+1)%n;
   }
   return start;
}
