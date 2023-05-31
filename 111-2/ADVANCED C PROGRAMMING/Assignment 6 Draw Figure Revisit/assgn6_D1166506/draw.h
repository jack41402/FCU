#ifndef ASSGN6_D1166506_DRAW_H
#define ASSGN6_D1166506_DRAW_H

class Draw
{
    protected:
        char *name ; // Name of the figure.
        int width ; // Width of drawing board.
        int height ; // Height of drawing board.
        char **board ; // Pointer of the drawing board.

    public:
        Draw () ;
        Draw (const Draw &) ;
        Draw(const std::string & , const int & , const int &) ;
        ~Draw() ;
        virtual void info () const = 0 ;
        virtual void drawBoard () = 0 ;
        virtual void printBoard () const = 0 ;
};

#endif //ASSGN6_D1166506_DRAW_H
