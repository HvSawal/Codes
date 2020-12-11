#Least Significant Bit
def solution(S):
  n = int(S)
  count = 0
  #Check for LSB (least significant bit)
  #in the binary rep of the number
  while n>1:
    #if LSB is *0
    if n%2==0:
      n=n//2
    
    #if end bits 01
    elif n%4==1:
      n-=1
    elif n==3:
      n-=1
    
    #if end bits 11
    else:
      n+=1
    count+=1
  return count

print(solution('14'))
