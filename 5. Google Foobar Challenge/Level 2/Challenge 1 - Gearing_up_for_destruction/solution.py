from fractions import Fraction
def solution(pegs):
  pegLength = len(pegs)
  if pegLength<=1:
    return [-1,-1]
  
  even = True if (pegLength%2==0) else False
  sum = (-1*pegs[0] + pegs[pegLength-1]) if even else (-1*pegs[0]-pegs[pegLength-1])

  if pegLength>2:
    for i in range(1, pegLength-1):
      sum += 2 * (-1)**(i+1) * pegs[i]

  r_0 = Fraction(2 * (sum/3 if even else sum)).limit_denominator()

  if r_0<2:
    return [-1,-1]
  
  curr_r = r_0
  for i in range(0,pegLength-2):
    diff_r = pegs[i+1]-pegs[i]
    next_r = diff_r - curr_r
    if curr_r<1 or next_r<1:
      return [-1,-1]
    else:
      curr_r = next_r
  
  return [r_0.numerator, r_0.denominator]

pegs = [4, 17, 50]
print(solution(pegs))