#!/usr/bin/env python
#--*--coding:utf8--*--
'''要修改，使得空间是O(1)的，'''
global permu
permu=[]
def _permutation(invertation):
    '''Construct a permutation from 1 to N,by the invertation table of
        a permutation.'''
    if(isinstance(invertation, list)):
        length=len(invertation)
        permu=[]
        for i in range(0, length):
            permu.insert(invertation[i], length-i)
#        print permu
    else:
        print "Type error"

def gerninvertation(scale):
    '''Construct a inversed table generator.The table's scale is determinded by
    argument 'scale'.'''
    invertation=[]
    for i in range(scale):
        invertation.append(0)
    yield invertation
    try:
        while True:
            invertation=add(invertation,1)
            yield invertation
    except FlowOverError:
        print "It's over.!"


#    limit=reduce(lambda x,y:x*y,range(1,scale+1))
#    print limit
#    i=1
#    while i<=limit:
#        if i==1:
#            i=i+1
#
#        else:
#            try:
#                invertation=add(invertation,1)
#            except FlowOverError:
#                print "It's over.!"
#            i=i+1
#            yield invertation


def add(invertation,lens=1):
    '''An inversed table is seen as a number,but on the i-th bit i-th number
    system,we emulate the add operation.'''
    length=len(invertation)

#we need the following gaurd variable.The 'flag' marks the state whether we
#should stop calculating.'index' mark which bit we are.forward marks how much
#we should carrying forward.
    flag=0
    index=0
    forward=1
#if addition has done (flag==0),stop.
    while flag==0 and (index < length):

        if invertation[index]+forward < index+1:
            invertation[index]=invertation[index]+forward
            flag=1
        else:
            a, b=divmod(invertation[index]+forward,index+1)
            invertation[index]=b
            forward=a
            index = index+1
    if flag==0:
        raise FlowOverError
    else:
        return invertation

def permutation(scale):
    generator=gerninvertation(scale)
    try:
        while True:
            invertation=generator.next()
            _permutation(invertation)
    except StopIteration:
        print "permutation has print over."
        return 0

class FlowOverError(BaseException):
    def __init__(self):
        print "FlowOverError"

if __name__=='__main__':
    permutation(23)