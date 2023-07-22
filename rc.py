# Python code for Josephus Problem
#from stringprep import c6_set

def Josh(person, k, index):
   
  # Base case , when only one person is left
  if len(person) == 1:
    print(person[0])
    return
  c = index
  # find the index of first person which will die
  index = ((index+k))%(len(person))
  #print (index)
  if c<(len(person)):
    print ( person[c] ,"kills", person[index] )
  else:
    print ( person[c-2] ,"kills",person[index] )
    
   # remove the first person which is going to be killed
  
  person.pop(index)
  
  # recursive call for n-1 persons
  Josh(person,k,index)
 
# Driver Program to test above function
n = int(input()) # specific n and k  values for original josephus problem
k = int(input())
#k-=1   # (k-1)th person will be killed

index = 0
 
# fill the person vectors
person=[]
for i in range(1,n+1):
  person.append(i)

Josh(person,k,index)

