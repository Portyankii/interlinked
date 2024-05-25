module calculator
    use, intrinsic :: iso_c_binding
    implicit none
    contains

    ! math logic
      real(c_double) function add(a, b) bind(C, name="add")
        real(c_double), value :: a, b
        add = a + b
      end function add
  
      real(c_double) function subtract(a, b) bind(C, name="subtract")
        real(c_double), value :: a, b
        subtract = a - b
      end function subtract
  
      real(c_double) function multiply(a, b) bind(C, name="multiply")
        real(c_double), value :: a, b
        multiply = a * b
      end function multiply

      real(c_double)function divide(a, b) bind(C, name="divide")
        real(c_double), value :: a, b
        divide = a / b
    end function divide
! why the hell will you not work >:(
    real(c_double)function squareroot(a) bind(c, name="squareroot")
        real(c_double), intent(in) :: a
        if (a < 0.0) then
          print *, "Error: Negative input"
        else
        squareroot = sqrt(a)
        end if
end function squareroot
         
        
        
        
  end module calculator
  