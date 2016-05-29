class Line(object):
    def __init__(self,aa,b,c):
        self.aa = aa
        self.b = b
        self.c = c
    def __str__(self):
        return str([self.aa,self.b,self.c])

class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        a,b = [Line(0,0,0)],[Line(0,0,0)]
        flag = 0
        for i in x:
            flag = (flag + 1) % 4
            if flag == 1:
                new = Line(b[-1].c,b[-1].aa,b[-1].aa+i)
                if self.check(new,b) == True:
                    return True
                else:
                    a.append(new)
            elif flag == 2:
                new = Line(a[-1].c,a[-1].aa,a[-1].aa-i)
                if self.check(new,a) == True:
                    return True
                else:
                    b.append(new)
            elif flag == 3:
                new = Line(b[-1].c,b[-1].aa,b[-1].aa-i)
                if self.check(new,b) == True:
                    return True
                else:
                    a.append(new)
            else:
                new = Line(a[-1].c,a[-1].aa,a[-1].aa+i)
                if self.check(new,a) == True:
                    return True
                else:
                    b.append(new)
            

        return False

    def check(self,a1,b):
        #print len(b)
        #for i in b:
         #   print i
        #print "a1: %s" % a1

        if len(b) < 2:
            return False

        for i in b[1:-1]:
            if (a1.aa-i.b)*(a1.aa-i.c)<=0:
                if (i.aa-a1.b)*(i.aa-a1.c)<=0:
                    return True
        if a1.aa == 0 and a1.c == 0:
            return True 
        return False
