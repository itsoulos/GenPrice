        integer function getdimension()
                getdimension=2
        end

        subroutine getleftmargin(x)
        double precision x(2)
        x(1)=-5.0
        x(2)=-5.0
        end

        subroutine getrightmargin(x)
        double precision x(2)
        x(1)= 5.0
        x(2)= 5.0
        end

        double precision function funmin(x)
        double precision x(2)
        funmin=4*x(1)**2-2.1*x(1)**4+(x(1)**6)/3.0+x(1)*x(2)-
     c       4*x(2)**2+4*x(2)**4
        end

        subroutine granal(x,g)
        double precision x(2)
        double precision g(2)
        g(1)=8.0*x(1)-8.4*x(1)**3+2*x(1)**5+x(2)
        g(2)=x(1)-8*x(2)+16*x(2)**3
        end

