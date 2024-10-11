#include "encipher.h"

void encipher(unsigned int num_rounds,unsigned long* v,unsigned long* k)
{
 unsigned long v0=v[0],v1=v[1],i;
 unsigned long sum=0,delta=0x9e3779b9;
 for(i=0;i<num_rounds;i++)
 {
   v0 +=(((v1<<4)^(v1>>5))+v1)^(sum+k[sum&3]);
   sum +=delta;
   v1 +=(((v0<<4)^(v0>>5))+v0)^(sum+k[(sum>>11)&3]);
 }
 v[0]=v0;v[1]=v1;
}