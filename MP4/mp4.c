/*
This program works through several functions: abs_double, fx_val, fx_dval, fx_ddval. These are primarily used in the halley function in the giant formula provided to us in the MP4 wiki. If
the difference is less than .000001, it returns the value. We increment by .5 everytime. If the root returned in Budan's theorem is 0, there are no roots in the polynomial. Otherwise, there
are either no roots found or it will print out the list of roots.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double abs_double(double y)
{
	if (y<0){
		y=-y;
		}
    //Change this to return the absolute value of y i.e |y|
    return y;
}

double fx_val(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the polynomial at the value x
    return a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
}

double fx_dval(double a, double b, double c, double d, double e, double x)
{
	//Change this to return the value of the derivative of the polynomial at the value x
    return 4*a*x*x*x+3*b*x*x+2*c*x+d;
}
double fx_ddval(double a, double b, double c, double d, double e, double x)
{
    //Change this to return the value of the double derivative of the polynomial at the value x
    return 12*a*x*x+6*b*x+2*c;
}

double newrfind_halley(double a, double b, double c, double d, double e, double x)
{
	int i = 0;
	int flag = 0;
double prev_x = x;
double new_x;
    for (i=0; i<10000; i++){
		            new_x = prev_x - (2*fx_val(a,b,c,d,e,prev_x)*fx_dval(a, b,c,d,e,prev_x))/((2*(abs_double(fx_dval(a,b,c,d,e,prev_x)))*(abs_double(fx_dval(a,b,c,d,e,prev_x))))-fx_val(a,b,c,d,e,prev_x)*fx_ddval(a,b,c,d,e,prev_x));
	   if (abs_double((new_x-prev_x))<0.000001){
			    return new_x;
      			    flag = 1;
			             break;
                            }
		prev_x = new_x;
		}
/*
Follow the formula and loop continuously (basically forever). Once the difference between new_x and prev_x is less than .000001, return new_x and break.
*/
    //Change this to return the root found starting from the initial point x using Halley's method
	if (flag == 0){
	return 8013.60561;}
}

int rootbound(double a, double b, double c, double d, double e, double r, double l)
{
    double first_l, second_l, third_l, fourth_l, fifth_l, first_r, second_r, third_r, fourth_r, fifth_r, upper;
		int v_l, v_r

    //Change this to return the upper bound on the number of roots of the polynomial in the interval (l, r)
    first_l=a;
    second_l=4*a*l+b;
    third_l=6*a*l*l+3*b*l+c;
    fourth_l=4*a*l*l*l+3*b*l*l+2*c*l+d;
    fifth_l=a*l*l*l*l+b*l*l*l+c*l*l+d*l+e;

  if ((first_l * second_l) < 0)
      {
        v_l++;
      }
  if ((second_l * third_l) < 0) {
        v_l++;
      }
  if ((third_l * fourth_l) < 0) {
        v_l++;
      }
  if ((fourth_l * fifth_l) < 0) {
        v_l++;
      }
/*
Adds 1 to v_l as long as there is a sign difference between each coefficient.
*/

    first_r=a;
    second_r=4*a*r+b;
    third_r=6*a*r*r+3*b*r+c;
    fourth_r=4*a*r*r*r+3*b*r*r+2*c*r+d;
    fifth_r=a*r*r*r*r+b*r*r*r+c*r*r+d*r+e;
  if ((first_r * second_r) < 0)
      {
        v_r++;
      }
  if ((second_r * third_r) < 0) {
        v_r++;
      }
  if ((third_r * fourth_r) < 0) {
        v_r++;
      }
  if ((fourth_r * fifth_r) < 0) {
        v_r++;
      }

			/*
			Adds 1 to v_r as long as there is a sign difference between each coefficient.
			*/

    upper = v_l-v_r;
    upper = abs_double(upper);
/*
Take difference of v_l and v_r and take absolute value.
*/
    return upper;

}

int main(int argc, char **argv)
{
	double a, b, c, d, e, l, r;
	double x, rootz, sam;
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
    rootz = rootbound(a,b,c,d,e,r,l);
    	if (rootz==0)
			{
    		printf("The polynomial has no roots in the given interval.\n");
    		fclose(in);
    		return 0;
    		}
    else
		{
    for (l; l<=r; l+=0.5)
		{
    	x=l;
 	sam = newrfind_halley(a,b,c,d,e,x);
 	if (sam == 8013.60561)
		{
				printf("No roots found.\n");
 		}
 	else
		{
 				printf("Root found: %lf \n", sam);
 		}
    	}
    fclose(in);
    return 0;
    }
}
