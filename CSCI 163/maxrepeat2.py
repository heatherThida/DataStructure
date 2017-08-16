#import algorithm
#

a=[2,1,3,4,2,1,3,2,4,5,5]

a=sorted(a)

distinct_list,quantity,compare=[],[],[]
b=a;
for j in range(1,len(b)):
  if b[j-1]!=b[j]:
    distinct_list.append(b[j-1])
    if b[j]==a[-1] and a[-1] not in distinct_list: #if last value not in distinct list
      distinct_list.append(b[j])
      
count =0;


for j in distinct_list:
  for t in a:
    if j==t:
      count+=1 
  quantity.append(count)
  count=0
print(quantity)

for a in range(0,len(distinct_list)):
  my_tuple=distinct_list[a],quantity[a]
  compare.append(my_tuple)

pair = max(compare,key=lambda x:x[1]) # max frequent number is 2, occuring 3 times
print (pair[0])

