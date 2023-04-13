str = 'ABABA' ;
newstr = lower(str) ;
result = pal1(str , 1 , length(newstr)) ;
if result==1
    fprintf("%s is palindrome.\n" , str) ;
else
    fprintf("%s isn't palindrome.\n" , str) ;
end


function is_pal = pal1(str , l , r)
    if (l>r)
        is_pal = 1 ;
    elseif(str(1 , l)==str(1 , r))
        is_pal = pal1(str , l+1 , r-1) ;
    else
        is_pal = 0 ;
    end
end