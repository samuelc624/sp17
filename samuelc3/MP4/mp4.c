#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double abs_double(double y)
{
    //Change this to return the absolute value of y i.e |y|
    if (y < 0)
      {
        y=-y;
      }
    return y;
}

double fx_val(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the polynomial at the value x

    return a*x*x*x*x+b*x*x*x+c*x*x+d*x*e;
}

double fx_dval(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the derivative of the polynomial at the value x
    return 4*a*x*x*x+3*b*x*x+2*x*c+d;
}

double fx_ddval(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the double derivative of the polynomial at the value x
    return 12*a*x*x+6*x*b+2*c;
}


double newrfind_halley(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the root found starting from the initial point x using Halley's method

    return 0;
}

int rootbound(double a, double b, double c, double d, double e, double r, double l, double p_l, double first_l, double second_l, double third_l, double fourth_l, double fifth_l, double p_r double first_r, double second_r, double third_r, double fourth_r, double fifth_r, double v_l, double v_r, double upper)
{
    //Change this to return the upper bound on the number of roots of the polynomial in the interval (l, r)
    first_l=a;
    second_l=4*a*l+b;
    third_l=6*a*l*l+3*b*l+c;
    fourth_l=4*a*l*l*l+3*b*l*l+2*c*l+d;
    fifth_l=a*l*l*l*l+b*l*l*l+c*l*l+d*l+e;
      p_l = (first_l)x*x*x*x+(second_l)*x*x*x+(third_l)*x*x+(fourth_l)*x+(fifth_l);
  if ((first_l ^ second_l || first_l ^ third_l || first_l ^ fourth_l || first_l ^ fifth_l) < 0)
      {
        v_l=v_l++;
      }
  if ((second_l ^ third_l || second_l ^ fourth_l || second_l ^ fifth_l) < 0) {
        v_l=v_l++;
      }
  if ((third_l ^ fourth_l || third_l ^ fifth_l) < 0) {
        v_l=v_l++;
      }
  if ((fourth_l ^ fifth_l) < 0) {
        v_l=v_l++;
      }


    first_r=a;
    second_r=4*a*r+b;
    third_r=6*a*r*r+3*b*r+c;
    fourth_r=4*a*r*r*r+3*b*r*r+2*c*r+d;
    fifth_r=a*r*r*r*r+b*r*r*r+c*r*r+d*r+e;
      p_r = (first_r)x*x*x*x+(second_r)*x*x*x+(third_r)*x*x+(fourth_r)*x+(fifth_r);
  if ((first_r ^ second_r || first_r ^ third_r || first_r ^ fourth_r || first_r ^ fifth_r) < 0)
      {
        v_r=v_r++;
      }
  if ((second_r ^ third_r || second_r ^ fourth_r || second_r ^ fifth_r) < 0) {
        v_r=v_r++;
      }
  if ((third_r ^ fourth_r || third_r ^ fifth_r) < 0) {
        v_r=v_r++;
      }
  if ((fourth_r ^ fifth_r) < 0) {
        v_r=v_r++;
      }

    v_l-v_r=upper;

  if (upper < 0)
          {
            upper = -upper;
          }


    return upper;
}

int main(int argc, char **argv)
{
	double a, b, c, d, e, l, r;
	FILE *in;

	if (argv[1] == NULL) {
		printf("You need an input file.\n");
		return -1;
	}
	in = fopen(argv[1], "r");
	if (in == NULL)
		return -1;
	fscanf(in, "%lf", &a);
	fscanf(in, "%lf", &b);
	fscanf(in, "%lf", &c);
	fscanf(in, "%lf", &d);
	fscanf(in, "%lf", &e);
	fscanf(in, "%lf", &l);
	fscanf(in, "%lf", &r);

    //The values are read into the variable a, b, c, d, e, l and r.
    //You have to find the bound on the number of roots using rootbound function.
    //If it is > 0 try to find the roots using newrfind function.
    //You may use the fval, fdval and fddval funtions accordingly in implementing the halleys's method.


    fclose(in);

    return 0;
}
