A = [2 1 -1 ; -3 -1 2 ; -2 1 2]
B = [8 -11 -3]'
x = mygauss(A , B)

function x = mygauss(A , B)
    x = A\B ;
end