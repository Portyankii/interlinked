module calculator
    use, intrinsic :: iso_c_binding
    implicit none
    contains

    ! math logic
      real(c_double) function add(x, y) bind(C, name="add")
        real(c_double), value :: x, y
        add = x + y
      end function add
  
      real(c_double) function subtract(x, y) bind(C, name="subtract")
        real(c_double), value :: x, y
        subtract = x - y
      end function subtract
  
      real(c_double) function multiply(x, y) bind(C, name="multiply")
        real(c_double), value :: x, y
        multiply = x * y
      end function multiply

      real(c_double)function divide(x, y) bind(C, name="divide")
        real(c_double), value :: x, y
        divide = x / y
    end function divide
! why the hell will you not work >:(
    real(c_double)function squareroot(x) bind(c, name="squareroot")
        real(c_double), value :: x
        squareroot = sqrt(x)
    end function squareroot
         
        
        
        
  end module calculator
  