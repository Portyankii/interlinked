module calculator
  use, intrinsic :: iso_c_binding
  implicit none
  contains

  ! Math logic
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

  real(c_double) function divide(x, y) bind(C, name="divide")
      real(c_double), value :: x, y
      divide = x / y
  end function divide

  real(c_double) function squareroot(x) bind(C, name="squareroot")
      real(c_double), value :: x
      squareroot = sqrt(x)
  end function squareroot

  ! possibly broken, 7x + 3x = 15 outputs 1.73 instead of 1.5
  real(c_double) function solve_linear(a, b, c, x_coefficient, y_coefficient) bind(C, name="solve_linear")
      real(c_double), value :: a, b, c, x_coefficient, y_coefficient
      if (x_coefficient /= 0.0_c_double) then
          solve_linear = (c - b * y_coefficient) / a
      else if (y_coefficient /= 0.0_c_double) then
          solve_linear = (c - a * x_coefficient) / b
      else
          solve_linear = huge(0.0_c_double)
      end if
  end function solve_linear

end module calculator
