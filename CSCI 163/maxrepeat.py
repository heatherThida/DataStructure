import random

items = [1, 2, 3, 4, 5, 5, 5, 5, 5,2, 2 ]
# shuffle the items
random.shuffle(items)

print("shuffled items: ", items)

majority_elem = items[0]
print(majority_elem)
count = 1
for i in range(1,len(items)):
   if items[i] == majority_elem:
        count += 1
        print("after item == major count is: %s " %  count + "major is: %d " % majority_elem)
   else: 
        count -= 1
        print("now hit else and count-1 is: %s" % count)
        if count == 0:
            majority_elem = items[i]
            count = 1
            print("count ==0 and major now is: %d " % majority_elem)
print("majority element : %d" % majority_elem )
